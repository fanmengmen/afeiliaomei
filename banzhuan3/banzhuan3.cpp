#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<opencv2/highgui/highgui_c.h>

using namespace cv;
using namespace std;

int main()
{
    Mat srcImage = imread("./color.png",1);
    if (!srcImage.data)  
   {  
    cout << "Could not open or find the image" << std::endl;  
    getchar();  
    return -1;  
   }   
   //imshow("srcImage", srcImage);
   Mat hsvimg; 
   cvtColor(srcImage, hsvimg, COLOR_BGR2HSV); 
   enum colorType{Red = 0, Green, Blue, ColorButt};  
       
   const Scalar hsvRedLo( 0,  40,  40);  
   const Scalar hsvRedHi(40, 255, 255);  
      
   const Scalar hsvGreenLo(41,  40,  40);  
   const Scalar hsvGreenHi(90, 255, 255);  
      
   const Scalar hsvBlueLo(100,  40,  40);  
   const Scalar hsvBlueHi(140, 255, 255);  
      
   vector<Scalar> hsvLo{hsvRedLo, hsvGreenLo, hsvBlueLo};  
   vector<Scalar> hsvHi{hsvRedHi, hsvGreenHi, hsvBlueHi};  
      
   vector<String> textColor{"1", "2", "3"};  
   // 查找指定范围内的颜色  
   Mat imgThresholded,imag_1;
	
	//初始化一个二位数组
	int output[1000][1000] ={0};
   for(int colorIdx=0;colorIdx<3;colorIdx++){
       inRange(hsvimg, hsvLo[colorIdx], hsvHi[colorIdx], imgThresholded);  
   // 转换成二值图  
   threshold(imgThresholded, imgThresholded, 1, 255, THRESH_BINARY);  
   copyMakeBorder(imgThresholded, imag_1, 1, 1, 1, 1, BORDER_CONSTANT, 0);  
    vector<vector<Point> > contours0;  
    vector<Vec4i> hierarchy;  
    findContours(imag_1, contours0, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);  
	Rect bound;
	Rect bound2;
	cout << "size of contours: " << contours0.size() <<endl;
        for (int idx = 0; idx < contours0.size(); idx++ )  
    {  
		//
        bound = boundingRect(Mat(contours0[idx]));
		/*if(idx == 0)
		bound2 = boundingRect(Mat(contours0[idx])); 
		else
		bound2 = boundingRect(Mat(contours0[idx-1])); */
		
        Point ab = Point(bound.x ,  
                         bound.y + bound.height / 2);
 		Point bc = Point(bound.x, bound.y);
		 
      	uchar x = imgThresholded.at<uchar>(ab); 
        if (x > 0)  
        {  
			//if(abs(bound.y - bound2.y) < 5 )
				//bc = Point(bound2.x, bound2.y);
				output[bc.y][bc.x] = colorIdx +1; 
				
            Point org = ab;  
            putText(srcImage, textColor[colorIdx], org, FONT_HERSHEY_COMPLEX, 0.5, Scalar(0,0,1),1, 8, false);
			 
        }  
    }  
   }
	int a[20][20] = {0};
	int m =0;
	int n =0;
	for(int i =0; i < 1000; i++)
	{
		for(int j = 0; j< 1000; j++)
		{
			if(output[i][j]!=0)
			{
				a[m][n] = output[i][j];
				cout << a[m][n] <<", ";
				n++;
			}	
		}
		if(n!= 0)
		{
			m++;
			n = 0;
			cout << endl;
		}
			
	}
   imshow("srcImage", srcImage);
   waitKey(0);
}
