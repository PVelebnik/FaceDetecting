#include "FaceDetector.h"
#include <iostream>

namespace
{
	const double scale_factor = 1.1; //Parameter specifying how much the image size is reduced at each image scale.
	const int min_neighbors = 2; //Parameter specifying how many neighbors each candidate rectangle should have to retain it.
	const int flags = 0 | cv::CASCADE_SCALE_IMAGE;
	const cv::Scalar color = cv::Scalar(0, 255, 0);
	const int thickness = 2;
	const int line_type = 8;
	const int shift = 0;
}

FaceDetector::FaceDetector()
	: face_cascade_name ("../Recources/haarcascade_frontalface_alt.xml")
{
	bool s = face_cascade.load(face_cascade_name);
	int a = 2;
}

void FaceDetector::DetectAndDisplay(const cv::Mat& frame)
{
	std::vector<cv::Rect> faces;
	cv::Mat frame_gray;

	cvtColor(frame, frame_gray, cv::COLOR_BGR2GRAY);

 	// Detect faces
 	face_cascade.detectMultiScale(frame_gray, faces, scale_factor, min_neighbors, flags, cv::Size(30, 30));
 	
 	for (size_t ic = 0; ic < faces.size(); ic++) // Iterate through all current elements (detected faces)
 	{
 		cv::Point pt1(faces[ic].x, faces[ic].y); // Display detected faces on main window - live stream from camera
 		cv::Point pt2((faces[ic].x + faces[ic].width), (faces[ic].y + faces[ic].height));
 			rectangle(frame, pt1, pt2, color, thickness, line_type, shift);
 		
 	}

	imshow("Debug window", frame);
	cv::waitKey(1000);
}