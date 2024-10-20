#ifndef SIMPLE_EXAMPLE_INCLUDE_APP_IMAGE_ANALYSIS_STRATEGY_SELECTOR_HPP
#define SIMPLE_EXAMPLE_INCLUDE_APP_IMAGE_ANALYSIS_STRATEGY_SELECTOR_HPP

#include "core/an_event_producer.hpp"
#include "core/i_image_analysis_strategy_selector.hpp"

namespace app {

class ImageAnalysisStrategySelector final : public core::IImageAnalysisStrategySelector {
  public:
    ImageAnalysisStrategySelector(core::AnEventProducer* event_producer);
    ~ImageAnalysisStrategySelector() final = default;

    core::IImageAnalysisStrategy* selectStrategyForEvent(core::Event event) final;
    core::IImageAnalysisStrategy* getDefaultStrategy() final;

  private:
    core::AnEventProducer* event_producer_;
};

}  // namespace app

#endif  // SIMPLE_EXAMPLE_INCLUDE_APP_IMAGE_ANALYSIS_STRATEGY_SELECTOR_HPP
