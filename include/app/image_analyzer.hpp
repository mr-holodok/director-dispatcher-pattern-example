#ifndef SIMPLE_EXAMPLE_INCLUDE_APP_IMAGE_ANALYZER_HPP
#define SIMPLE_EXAMPLE_INCLUDE_APP_IMAGE_ANALYZER_HPP

#include "core/i_event_subscription_service.hpp"
#include "core/i_image_analysis_strategy.hpp"
#include "core/i_image_analysis_strategy_selector.hpp"
#include "core/i_subscriber.hpp"

namespace app {

class ImageAnalyzer final : public core::ISubscriber {
  public:
    ImageAnalyzer(core::IEventSubscriptionService* event_subscription_service,
                  core::IImageAnalysisStrategySelector* strategy_selector);
    ~ImageAnalyzer() final = default;

    void onEvent(core::Event event) final;
    bool processFrame(cv::Mat& image);

  private:
    core::IEventSubscriptionService* event_subscription_service_;
    core::IImageAnalysisStrategySelector* strategy_selector_;
    core::IImageAnalysisStrategy* strategy_;
};

}  // namespace app

#endif  // SIMPLE_EXAMPLE_INCLUDE_APP_IMAGE_ANALYZER_HPP
