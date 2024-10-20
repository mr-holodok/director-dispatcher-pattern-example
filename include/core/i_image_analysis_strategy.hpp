#ifndef SIMPLE_EXAMPLE_INCLUDE_CORE_I_IMAGE_ANALYSIS_STRATEGY_HPP
#define SIMPLE_EXAMPLE_INCLUDE_CORE_I_IMAGE_ANALYSIS_STRATEGY_HPP

#include <opencv2/opencv.hpp>

#include "core/event_type.hpp"

namespace core {

class IImageAnalysisStrategy {
  public:
    virtual bool process(cv::Mat& image) = 0;
    virtual ~IImageAnalysisStrategy() = default;
};

}  // namespace core

#endif  // SIMPLE_EXAMPLE_INCLUDE_CORE_I_IMAGE_ANALYSIS_STRATEGY_HPP
