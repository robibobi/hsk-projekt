#include "Camera.h"


Camera::Camera()
{
	mCamPlacement.AddCamera(&mVektoriaCamera);


	mCamPlacement.TranslateY(0.75);
	mCamPlacement.TranslateZDelta(2.0);

}


Camera::~Camera()
{
}


void Camera::initViewPort(float camAngle, Vektoria::CViewport* viewport){
	mVektoriaCamera.Init(camAngle);
	viewport->InitFull(&mVektoriaCamera);
}



void Camera::setPlayerPlacement(Vektoria::CPlacement* p){
	// Player placement wird in der Player klasse ge�ndert um
	// die Kugel und die Kamera zu bewegen. -> Kamera als child
	// des Player placements anh�ngen
	p->AddPlacement(&mCamPlacement);
}