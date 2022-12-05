#include "../include/camera.h"

Camera::Camera(int pX, int pY, int pW, int pH)
{
	CameraRect.x = pX;
	CameraRect.y = pY;
	CameraRect.w = pW;
	CameraRect.h = pH;
}

void Camera::FollowPoint(int pX, int pY)
{
	if (pX > CameraRect.w / 2 && pX < ROOM_WIDTH - (CameraRect.w / 2))
	{
		CameraRect.x = pX - (CameraRect.w / 2);
	}
	if (pY > CameraRect.h / 2 && pY < ROOM_HEIGHT - (CameraRect.h/2))
	{
		CameraRect.y = pY - (CameraRect.h / 2);
	}
}