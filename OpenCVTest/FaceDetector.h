#pragma once
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"



class FaceDetector
{
public:
	FaceDetector();
	~FaceDetector();
	void DetectAndDisplay(cv::Mat frame);

	cv::CascadeClassifier face_cascade;
	std::string face_cascade_name = "D:/opencv/sources/data/haarcascades/haarcascade_frontalface_alt.xml";
	std::string window_name = "Capture - Face detection";
private:
};
