#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>


/** @function main */
 int main( int argc, char** argv )
 {


   // Get command line arguments
  if ( argc < 2 )
  {
   std::cerr << "Usage: " << argv[ 0 ] << " image_file" << std::endl;
    return( -1 );

  } // fi

  // Review given command line arguments
  std::cout << "-------------------------" << std::endl;
  for( int a = 0; a < argc; a++ )
    std::cout << argv[ a ] << std::endl;
  std::cout << "-------------------------" << std::endl;

  // Get basename
  std::stringstream ss( argv[ 1 ] );
  std::string basename;
  getline( ss, basename, '.' );

  // Read an image
  cv::Mat src;
  src = cv::imread( argv[1], 1 );

  if ( !src.data )
  {
    std::cerr << "Error: No image data" << std::endl;
    return( -1);
  }

   cv::Mat trMat = (cv::Mat_<double>(2,3) <<  0.65532163 ,  -44.5013712 ,  0 ,
                                          0.45886114  , 4.97473224 ,  0 );

   cv::Mat trImg;
   trImg = cv::Mat::zeros( src.rows, src.cols, src.type() );


   cv::warpAffine( src, trImg, trMat, trImg.size() );


   imwrite("Composite_Transformation.jpg",trImg);

    return 0;

}
