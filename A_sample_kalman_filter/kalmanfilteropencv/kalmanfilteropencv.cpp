#include <iostream>
#include <vector>
//#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>
//#include <opencv2/highgui/highgui_c.h>
//#include <Eigen/Core>           // For Kalman filtering 
//#include <Eigen/LU>           // To use inverse of a matrix
//#include <Eigen/Dense>           // To use inverse of a matrix

#define drawCross( center, color, d )                              \
  line( img, Point( center.x - d, center.y - d ),                  \
        Point( center.x + d, center.y + d ), color, 2, CV_AA, 0);  \
  line( img, Point( center.x + d, center.y - d ),                  \
        Point( center.x - d, center.y + d ), color, 2, CV_AA, 0 )

using namespace cv;
using namespace std;
struct mouse_info_struct
{
  int x, y;
};
struct mouse_info_struct mouse_info = { -1, -1}, last_mouse;
vector<Point> mousev, kalmanv;
void on_mouse(int event, int x, int y, int flags, void* param)
{
  {
    last_mouse = mouse_info;
    mouse_info.x = x;
    mouse_info.y = y;
  }
}


//Kalman filter based on Eigen
/*
KF = cv::KalmanFilter(4, 2, 0);
KF.transitionMatrix = *(cv::Mat_<float>(4, 4) << 1,0,1,0, 0,1,0,1, 0,0,1,0, 0,0,0,1); 
measurement.setTo(cv::Scalar(0));
//Kalman filter based on Opencv

//Taken from Matlab 2010
Eigen::MatrixXd LocalizeFire::MyKalmanFilter(double z)
{
  double dt = 1;
  Eigen::Matrix2d A; 
  Eigen::RowVector2d H; 
  Eigen::RowVector2d B; 
  Eigen::Vector2d B_inv; 
  Eigen::MatrixXd S; 
  Eigen::MatrixXd S_inv;
  Eigen::RowVector2d klm_gain_before;
  Eigen::Vector2d klm_gain;
  Eigen::Matrix2d Q = Eigen::MatrixXd::Identity(2,2);
  Eigen::MatrixXd R = Eigen::MatrixXd::Identity(1,1); //Should be a vector with one item (or scalar)
  Eigen::MatrixXd y;
  Eigen::Vector2d x_prd;
  Eigen::Matrix2d p_prd;
  // Initial state conditions for Kalman filter
  // must exists AFTER the function is called (persist)
  // static keyword specifies that the variable retains its state between calls to that function.
  // x_est = [x,y,Vx,Vy,Ax,Ay]'
  static Eigen::Matrix2d p_est = []  //Statically init matrix 2x2
  {
    Eigen::Matrix2d tmp_m;
    tmp_m << 0, 0,
             0, 0;
    return tmp_m;
  }();
  // static Eigen::Vector2d x_est = Eigen::Vector2d::Zero(2); 
  static Eigen::Vector2d x_est = []  //Statically init vector 2x1
  {
    Eigen::Vector2d tmp_v;
    tmp_v << 0,
             0;
    return tmp_v;
  }();
  // Initialize state transition matrix (With array float dynamic dynamic)
  A <<  1, dt,  //[x] Position
        0, 1;   //[Vx]  
  // std::cout << "A: \n" << A << std::endl;
  // Initialize measurement matrix
  H <<  1, 0;
  R *= 1000;
  // std::cout << "H: \n" << H << std::endl; //yes
  // std::cout << "Q: \n" << Q << std::endl; //yes
  // std::cout << "R: \n" << R << std::endl; //yes

  // std::cout << "AFTER p_est is of size " << p_est.rows() << "x" << p_est.cols() << std::endl;
  // std::cout << "AFTER x_est is of size " << x_est.rows() << "x" << x_est.cols() << std::endl;
  // std::cout << "2 p_est  \n" << p_est << " x_est \n" << x_est << std::endl;
  x_prd = A * x_est; 
  // std::cout << "2 x_prd\n" << x_prd << std::endl;
  p_prd = A * p_est * A.transpose() + Q;
  // std::cout << "2 p_prd\n" << p_prd << std::endl;
  // // Estimation
  S = H * p_prd.transpose() * H.transpose() + R;
  B = H * p_prd.transpose();
  // std::cout << "3 B \n " << B << std::endl;
  // std::cout << "3 S \n " << S << std::endl;
  B_inv = B.inverse();
  // std::cout << "3 B_inv \n " << B_inv << std::endl;
  S_inv = S.inverse();
  // std::cout << "3 S_inv \n " << S_inv << std::endl;
  klm_gain_before = S_inv*B; //left_matrix divide A\B = inv(A)*B
  // std::cout << "3 klm_gain_before \n " << klm_gain_before << std::endl;
  klm_gain = klm_gain.transpose(); //left_matrix divide A\B = inv(A)*B
  // std::cout << "3 klm_gain \n " << klm_gain << std::endl;
  // Estimated state and covariance
  x_est = x_prd + klm_gain * (z - H * x_prd);
  p_est = p_prd - klm_gain * H * p_prd;
  // std::cout << "3 p_est \n " << p_est << std::endl;
  // std::cout << "3 x_est \n " << x_est << std::endl;
  // Compute the estimated measurements
  y = H * x_est;
  // std::cout << "4 final H \n " << H << std::endl;
  // std::cout << "4 final x_est \n " << x_est << std::endl;
  // std::cout << "4 final y \n " << y << std::endl;  
  return y;
}
*/




int main(int argc, char* const argv[])
{
  Mat img(500, 500, CV_8UC3);
  KalmanFilter KF(4, 2, 0);
  Mat_<float> state(4, 1); /* (x, y, Vx, Vy) */
  Mat processNoise(4, 1, CV_32F);
  Mat_<float> measurement(2, 1);
  measurement.setTo(Scalar(0));
  char code = (char) - 1;
  namedWindow("mouse kalman");
  setMouseCallback("mouse kalman", on_mouse, 0);

  for(;;)
  {
    if(mouse_info.x < 0 || mouse_info.y < 0)
    {
      imshow("mouse kalman", img);
      waitKey(30);
      continue;
    }
    std::cout << "outermost loop" << std::endl;
    KF.statePre.at<float>(0) = mouse_info.x;
    KF.statePre.at<float>(1) = mouse_info.y;
    KF.statePre.at<float>(2) = 0;
    KF.statePre.at<float>(3) = 0;
    KF.transitionMatrix = *(Mat_<float>(4, 4) << 1, 0, 0, 0,   0, 1, 0, 0,  0, 0, 1, 0,  0, 0, 0, 1);
    setIdentity(KF.measurementMatrix);
    setIdentity(KF.processNoiseCov, Scalar::all(1e-4));
    setIdentity(KF.measurementNoiseCov, Scalar::all(1e-1));
    setIdentity(KF.errorCovPost, Scalar::all(.1));
    mousev.clear();
    kalmanv.clear();

    for(;;)
    {
      Mat prediction = KF.predict();
      Point predictPt(prediction.at<float>(0), prediction.at<float>(1));
  std::cout << "  size of measurement" << measurement.size() << std::endl;
  std::cout << "  type of measurement" << measurement.type() << std::endl;
      measurement(0) = mouse_info.x;
      measurement(1) = mouse_info.y;
      Point measPt(measurement(0), measurement(1));
      mousev.push_back(measPt);
      std::cout << "innermost loop" << std::endl;
      // generate measurement
      Mat estimated = KF.correct(measurement);
      Point statePt(estimated.at<float>(0), estimated.at<float>(1));
      kalmanv.push_back(statePt);
      // plot points
      img = Scalar::all(0);
      drawCross(statePt, Scalar(255, 255, 255), 5);
      drawCross(measPt, Scalar(0, 0, 255), 5);
      for(int i = 0; i < mousev.size() - 1; i++)
      {
        line(img, mousev[i], mousev[i + 1], Scalar(255, 255, 0), 1);
      }

      for(int i = 0; i < kalmanv.size() - 1; i++)
      {
        line(img, kalmanv[i], kalmanv[i + 1], Scalar(0, 255, 0), 1);
      }
      imshow("mouse kalman", img);
      code = (char)waitKey(100);
      if(code > 0)
      {
        break;
      }
    }

    if(code == 27 || code == 'q' || code == 'Q')
    {
      break;
    }
  }

  return 0;
}
