#include "cv.h"
#include "highgui.h"

using namespace std;
using namespace cv;

//fungsi deteksi wajah
int main()
{
	IplImage *img = cvLoadImage("foto1.jpg");

//inisialisasi
	CvHaarClassifierCascade *cascade=0;
	CvMemStorage *storage=0;
	IplImage* gray=img;

//baca file xml u/ image detection
	if(!cascade)
	{
		//char * file="C:/opencv249/sources/data/haarcascades/haarcascade_frontalface_alt.xml";
		char * file="C:/opencv249/sources/data/haarcascades/haarcascade_smile.xml";
		cascade=(CvHaarClassifierCascade*) cvLoad(file, 0, 0, 0);
		storage=cvCreateMemStorage(0);
	}

//deteksi wajah
CvSeq* faces=cvHaarDetectObjects(gray,cascade,storage,1.1,100,CV_HAAR_DO_CANNY_PRUNING,cvSize(10, 10));

int i;

//menggambar kotak merah pd bagian wajah yg ditemukan
for(i=0; i<(faces ? faces->total : 0) ; i++)
	{
		CvRect* r=(CvRect*) cvGetSeqElem(faces, i);
		cvRectangle(img,cvPoint(r->x, r->y),cvPoint(r->x + r->width, r->y + r->height),CV_RGB(255, 0, 0), 1, 8, 0);
	}

//menampilkan gambar hasil deteksi
	cvNamedWindow("hasil",1);
	cvShowImage("hasil", img);
	cvWaitKey(0);
	cvDestroyWindow("hasil");
	cvReleaseImage(&img);
	return 0;
}
