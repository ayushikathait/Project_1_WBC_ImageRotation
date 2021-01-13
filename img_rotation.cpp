#include <iostream>
#include <string>
#include "opencv/highgui.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"

using namespace std;
using namespace cv;

#define PIPI 3.14156

int main()
{
    Mat img = imread("C:/Users/Desktop/DSC00587.JPG",0);//loading gray scale image
    Mat imgC = imread("C:/Users/Desktop/DSC00587.JPG",1);//loading color image

    Mat rotC(imgC.cols, imgC.rows, imgC.type());
    rotC = Scalar(0,0,0);

    Mat rotG(img.cols, img.rows, img.type());
    rotG = Scalar(0,0,0);

    float angle = 90.0 * PIPI / 180.0;

    for(int r=0;r<imgC.rows;r++)
    {
        for(int c=0;c<imgC.cols;c++)
        {
            float new_px = c * cos(angle) - r * sin(angle);
            float new_py = c * sin(angle) + r * cos(angle);

            Point pt((int)-new_px, (int)new_py);

            //color image
            rotC.at<Vec3b>(pt) = imgC.at<Vec3b>(r,c);//assign color value at new location from original image

            //gray scale image
            rotG.at<uchar>(pt) = img.at<uchar>(r,c);//assign color value at new location from original image

        }
    }
    imshow("color",rotC);
    imshow("gray",rotG);
    waitKey(0);

    return 0;
}
