#include "FaceDetector.h"

#include <iostream>
#include <string>


// Global variables

//int filenumber; // Number of file to be saved
//std::string filename;

// Function main
int main(void)
{
	FaceDetector detector;
	cv::VideoCapture capture(0);

	if (!capture.isOpened())  // check if we succeeded
		return -1;

	// Load the cascade
	if (!detector.face_cascade.load(detector.face_cascade_name))
	{
		printf("--(!)Error loading\n");
		return (-1);
	};

	// Read the video stream
	cv::Mat frame;

	for (;;)
	{
		capture >> frame;

		// Apply the classifier to the frame
		if (!frame.empty())
		{
			detector.DetectAndDisplay(frame);
		}
		else
		{
			printf(" --(!) No captured frame -- Break!");
			break;
		}

		int c = cv::waitKey(10);

		if (27 == char(c))
		{
			break;
		}
	}

	return 0;
}
