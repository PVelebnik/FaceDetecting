#include "FaceDetector.h"

#include <iostream>
#include <string>


// Global variables

//int filenumber; // Number of file to be saved
//std::string filename;


int main(void)
{
	FaceDetector detector;
	cv::VideoCapture capture(0);

	if (!capture.isOpened())  // check if we succeeded
		return -1;

	cv::Mat frame;

	for (;;)
	{
		capture.read(frame);

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
