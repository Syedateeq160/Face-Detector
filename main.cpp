#include<iostream>
#include<stdlib.h>
#include<opencv2\\objdetect\\objdetect.hpp>
#include<opencv2\\imgproc\\imgproc.hpp>
#include<opencv2\\highgui\\highgui.hpp>
#include<string>

using namespace cv;
int main()
{
CascadeClassifier faceDetection;
if (!faceDetection.load("C:\\Users\\Scientist\\Downloads\\Programs\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml"))
{
  std::cout << "\n File is not loaded Properly";
  exit(0); // stdlib.h
}

std :: string path;
std::cout << "\nEnter the path to the image for face detection: ";
cin.getline(path, 100);

Mat img = imread(path, CV_LOAD_IMAGE_UNCHANGED);

if (img.empty())
{
  std::cout << "Image is not loaded properly";
}
else
{
  std::cout << "\nGot the Image!\n";
  std::cout << "Image in Making !!!! \n";

vector<Rect> faces; //Creating a Vector

faceDetection.detectMultiScale(img, faces); //detecting Here

for (int i = 0; i < faces.size(); i++)
{
  Point pt1(faces[i].x, faces[i].y);
  Point pt2((faces[i].x + faces[i].height), (faces[i].y + faces[i].width));
  rectangle(img, pt1, pt2, Scalar(0, 0, 255), 2, 8, 0);

  imwrite("C:\\gs\\output.jpg", img);
  std::cout << "\nFace Detected Master!\n";

  system("pause");
}
  
} // Else closed


return 0;
}
