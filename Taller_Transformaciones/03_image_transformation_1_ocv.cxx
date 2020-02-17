#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;

int main(int argc, char** argv )
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
  Mat image;
  image = imread( argv[1], 1 );

  if ( !image.data )
  {
    std::cerr << "Error: No image data" << std::endl;
    return( -1);
  }

    Mat t(2,3,CV_64F, cvScalar(0.0));
    Mat dest,dest2,dest3;
    Size size(image.cols,image.rows);
    t.at<double>(0,0) = 0.8;    
    t.at<double>(1,1) = 0.8;
    
    Mat t2(2,3,CV_64F, cvScalar(0.0));
    t2.at<double>(0,0) = std::cos(0.610865);
    t2.at<double>(0,1) = -std::sin(0.610865);    
    t2.at<double>(1,1) = std::cos(0.610865);
    t2.at<double>(1,0) = std::sin(0.610865); 

  
    Mat t3(2,3,CV_64F, cvScalar(0.0));
    t3.at<double>(0,0) = 1;    
    t3.at<double>(1,1) = 1;
    t3.at<double>(0,2) = -42;    
    t3.at<double>(1,2) = 37;

    warpAffine(image, dest, t, size, INTER_LINEAR, BORDER_CONSTANT); 

    warpAffine(dest, dest2, t2, size, INTER_LINEAR, BORDER_CONSTANT); 

    warpAffine(dest2, dest3, t3, size, INTER_LINEAR, BORDER_CONSTANT);

    imwrite("outputImage.jpg", dest);

    imwrite("outputImage2.jpg", dest2);

    imwrite("outputImageFinal.jpg", dest3);



  return( 0 );
}

// eof - 02_rescale_intensity.cxx
