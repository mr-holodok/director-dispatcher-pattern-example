#ifndef SIMPLE_EXAMPLE_INCLUDE_APP_TRACKER_HPP
#define SIMPLE_EXAMPLE_INCLUDE_APP_TRACKER_HPP

#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>

#include "core/an_event_producer.hpp"
#include "core/i_image_analysis_strategy.hpp"

namespace app {

class Tracker final : public core::IImageAnalysisStrategy {
  public:
    Tracker(core::AnEventProducer* event_producer, cv::Rect bounding_box);
    ~Tracker() final = default;

    bool process(cv::Mat& image) final;

  private:
    core::AnEventProducer* event_producer_;
    cv::Rect bounding_box_;
    bool is_initialized_;
    cv::Ptr<cv::Tracker> tracker_;
};

}  // namespace app

#endif  // SIMPLE_EXAMPLE_INCLUDE_APP_TRACKER_HPP
