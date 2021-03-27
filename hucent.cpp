//
// Created by mbalantz on 2016-11-13.
//

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

double central_moment_integral(int p, int q, Mat matx_inp, double *integral) {

    Size s = matx_inp.size();
    double rows = s.height;
    double cols = s.width;

    double x_bar = floor( cols / 2.0 ) + 1.0 ;
    double y_bar = floor( rows / 2.0 ) + 1.0 ;

    int i;
    int j;
    Scalar intensity;


    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            intensity = matx_inp.at<uchar>(Point(j,i));
             *integral += pow((double)i - x_bar, p) * pow((double)j - y_bar, q) * intensity.val[0];
        }
    }

    return *integral;

}



int main(int argc, char **argv) {

    int one;
    int two;
    double out;

    Mat tempmatx;

    if (argc != 2) { cout << "usage: ./hucent <path/to/image/file> " << endl; return 0;}

    tempmatx = imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE);

    imshow("Image for calc", tempmatx);
    waitKey(0);

    cout << "Hu's Moment Calculator. Enter integer values for p, q, respectively." << endl;
    cin >> one;
    cin >> two;
    cout << "Moment m(" << one << "," << two << "): " << central_moment_integral(one,two,tempmatx,&out) << endl;

    return 0;
}
