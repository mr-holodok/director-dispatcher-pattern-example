#include "app/tracker.hpp"

namespace app {

Tracker::Tracker(core::AnEventProducer* event_producer, cv::Rect bounding_box)
    : event_producer_{event_producer}, bounding_box_{bounding_box}
{
    // Create a KCF (Kernelized Correlation Filters) tracker
    tracker_ = cv::TrackerKCF::create();
    is_initialized_ = false;
}

bool Tracker::process(cv::Mat& image)
{
    if (!is_initialized_) {
        // Initialize the tracker with the bounding box
        tracker_->init(image, bounding_box_);
        is_initialized_ = true;
    } else {
        // Update the tracker with the new frame
        if (!tracker_->update(image, bounding_box_)) {
            // If the tracker fails to update, the object is considered lost
            event_producer_->produceEvent(core::Event{core::EventType::OBJECT_LOST});
            return true;
        }
    }

    // pen the bounding box on the image
    cv::rectangle(image, bounding_box_, cv::Scalar(0, 0, 255), 2);
    return true;
}

}  // namespace app
