#include "app/detector.hpp"

#include <opencv2/opencv.hpp>
#include <vector>

namespace app {
Detector::Detector(core::AnEventProducer* event_producer) : event_producer_{event_producer}, bounding_box_{}
{
}

bool Detector::detectRedObject(const cv::Mat& image)
{
    cv::Mat hsvFrame, mask, result;
    cv::cvtColor(image, hsvFrame, cv::COLOR_BGR2HSV);

    cv::Mat lowerRedMask, upperRedMask;
    cv::inRange(hsvFrame, cv::Scalar(0, 150, 150), cv::Scalar(10, 255, 255), lowerRedMask);
    cv::inRange(hsvFrame, cv::Scalar(160, 150, 150), cv::Scalar(180, 255, 255), upperRedMask);

    mask = lowerRedMask | upperRedMask;

    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(7, 7));
    cv::morphologyEx(mask, mask, cv::MORPH_OPEN, kernel);
    cv::morphologyEx(mask, mask, cv::MORPH_CLOSE, kernel);

    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(mask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    if (contours.empty()) {
        return false;
    }

    size_t largestContourIndex = 0;
    double maxArea = 0;
    for (size_t i = 0; i < contours.size(); ++i) {
        double area = cv::contourArea(contours[i]);
        if (area > maxArea) {
            maxArea = area;
            largestContourIndex = i;
        }
    }

    cv::Rect boundingBox = cv::boundingRect(contours[largestContourIndex]);
    if (boundingBox.width >= 50 && boundingBox.height >= 50) {
        bounding_box_ = boundingBox;
        return true;
    }

    return false;
}

bool Detector::process(cv::Mat& image)
{
    // Perform object detection (find a red object with minimum size of 50x50 pixels)
    if (detectRedObject(image)) {
        event_producer_->produceEvent(core::Event{core::EventType::OBJECT_FOUND, new cv::Rect(bounding_box_)});
    }

    return true;
}

}  // namespace app
