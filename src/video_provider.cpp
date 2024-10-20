#include "app/video_provider.hpp"

namespace app {

// CAP_V4L is the Video for Linux API, it is optional, may use CAP_ANY as well
VideoProvider::VideoProvider() : capture_(0, cv::CAP_V4L)
{
}

VideoProvider::~VideoProvider()
{
    capture_.release();
}

bool VideoProvider::isOk() const
{
    return capture_.isOpened();
}

bool VideoProvider::getFrame(cv::Mat& frame)
{
    capture_ >> frame;
    return !frame.empty();
}

}  // namespace app
