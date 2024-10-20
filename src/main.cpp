#include <iostream>
#include <opencv2/opencv.hpp>

#include "app/image_analysis_strategy_selector.hpp"
#include "app/image_analyzer.hpp"
#include "app/notifier.hpp"
#include "app/video_provider.hpp"
#include "core/an_event_producer.hpp"
#include "core/event_manager.hpp"

int main()
{
    cv::Mat image;
    cv::namedWindow("Video Player");
    app::VideoProvider video_provider{};
    core::EventManager event_manager{};
    core::AnEventProducer event_producer{&event_manager};
    app::ImageAnalysisStrategySelector strategy_selector{&event_producer};
    app::ImageAnalyzer image_analyzer{&event_manager, &strategy_selector};

    app::Notifier logger{&event_manager};

    if (!video_provider.isOk()) {
        std::cout << "No video stream detected" << std::endl;
        system("pause");
        return -1;
    }

    while (true) {
        if (!video_provider.getFrame(image)) {
            break;
        }
        if (!image_analyzer.processFrame(image)) {
            std::cout << "Image analysis module could not process frame!" << std::endl;
        }

        cv ::imshow("Video Player", image);
        char c =
            (char)cv::waitKey(5);  // Allowing 25 milliseconds frame processing time and initiating break condition//
        if (c == 27) {             // If 'Esc' is entered break the loop//
            break;
        }
    }

    return 0;
}