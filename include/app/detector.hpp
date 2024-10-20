#ifndef SIMPLE_EXAMPLE_INCLUDE_APP_DETECTOR_HPP
#define SIMPLE_EXAMPLE_INCLUDE_APP_DETECTOR_HPP

#include "core/an_event_producer.hpp"
#include "core/i_image_analysis_strategy.hpp"

namespace app {

class Detector final : public core::IImageAnalysisStrategy {
  public:
    Detector(core::AnEventProducer* event_producer);
    ~Detector() final = default;

    bool process(cv::Mat& image) final;
    bool detectRedObject(const cv::Mat& image);

  private:
    core::AnEventProducer* event_producer_;
    cv::Rect bounding_box_;
};

}  // namespace app

#endif  // SIMPLE_EXAMPLE_INCLUDE_APP_DETECTOR_HPP
