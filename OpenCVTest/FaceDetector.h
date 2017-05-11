#pragma once
#include "IObservable.h"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"



class FaceDetector: public IObservable
{
public:
	FaceDetector();
	~FaceDetector() = default;

	void DetectAndDisplay(const cv::Mat& frame);
private:
	cv::CascadeClassifier face_cascade;
	std::string face_cascade_name;
};
