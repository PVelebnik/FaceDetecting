#include "FaceDetector.h"
#include <iostream>

FaceDetector::FaceDetector()
	: face_cascade_name ("D:/opencv/sources/data/haarcascades/haarcascade_frontalface_alt.xml")
	, window_name ("Capture - Face detection")
{
}

FaceDetector::~FaceDetector()
{
}

void FaceDetector::DetectAndDisplay(cv::Mat frame)
{
	std::vector<cv::Rect> faces;
	cv::Mat frame_gray;

	cvtColor(frame, frame_gray, cv::COLOR_BGR2GRAY);

	// Detect faces
	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));

	size_t ic = 0; // ic is index of current element
	int ac = 0; // ac is area of current element

	for (ic = 0; ic < faces.size(); ic++) // Iterate through all current elements (detected faces)
	{
		cv::Point pt1(faces[ic].x, faces[ic].y); // Display detected faces on main window - live stream from camera
		cv::Point pt2((faces[ic].x + faces[ic].width), (faces[ic].y + faces[ic].height));
		rectangle(frame_gray, pt1, pt2, cv::Scalar(0, 255, 0), 2, 8, 0);
	}

	imshow("original", frame_gray);
}