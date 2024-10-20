#include "app/image_analyzer.hpp"

namespace app {

ImageAnalyzer::ImageAnalyzer(core::IEventSubscriptionService* event_subscription_service,
                             core::IImageAnalysisStrategySelector* strategy_selector)
    : event_subscription_service_{event_subscription_service},
      strategy_selector_{strategy_selector},
      strategy_{strategy_selector_->getDefaultStrategy()}
{
    event_subscription_service_->addSubscription(this, core::EventType::OBJECT_FOUND);
    event_subscription_service_->addSubscription(this, core::EventType::OBJECT_LOST);
}

void ImageAnalyzer::onEvent(core::Event event)
{
    strategy_ = strategy_selector_->selectStrategyForEvent(event);
}

bool ImageAnalyzer::processFrame(cv::Mat& image)
{
    if (!strategy_) {
        return false;
    }

    return strategy_->process(image);
}

}  // namespace app
