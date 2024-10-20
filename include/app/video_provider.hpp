#ifndef SIMPLE_EXAMPLE_INCLUDE_APP_VIDEO_PROVIDER_HPP
#define SIMPLE_EXAMPLE_INCLUDE_APP_VIDEO_PROVIDER_HPP

#include <opencv2/opencv.hpp>

namespace app {

class VideoProvider {
  public:
    VideoProvider();
    ~VideoProvider();

    bool getFrame(cv::Mat& frame);
    bool isOk() const;

  private:
    cv::VideoCapture capture_;
};

}  // namespace app

#endif  // SIMPLE_EXAMPLE_INCLUDE_APP_VIDEO_PROVIDER_HPP
