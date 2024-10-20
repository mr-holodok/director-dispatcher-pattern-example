#include "app/image_analysis_strategy_selector.hpp"

#include "app/detector.hpp"
#include "app/tracker.hpp"

namespace app {

ImageAnalysisStrategySelector::ImageAnalysisStrategySelector(core::AnEventProducer* event_producer)
    : event_producer_{event_producer}
{
}

core::IImageAnalysisStrategy* ImageAnalysisStrategySelector::selectStrategyForEvent(core::Event event)
{
    switch (event.getType()) {
        case core::EventType::OBJECT_FOUND:
            return new Tracker(event_producer_, *((cv::Rect*)event.getData()));
        case core::EventType::OBJECT_LOST:
            return new Detector(event_producer_);
        default:
            return getDefaultStrategy();
    }
}

core::IImageAnalysisStrategy* ImageAnalysisStrategySelector::getDefaultStrategy()
{
    return new Detector(event_producer_);
}

}  // namespace app
