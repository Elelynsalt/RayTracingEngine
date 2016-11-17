//#include "stdafx.h"
#include "GzCamera.h"
#include <cmath>
//#include <iostream>

GzVector3 schimidt(const GzVector3 &general, const GzVector3 &unit)
{
    return (general - general.dotMultiply(unit) * unit).normalize();
}

GzCamera::GzCamera() :
    position(0.0f, 0.0f, 0.0f), front(0.0f, 0.0f, -1.0f), up(0.0f, 1.0f, 0.0f), right(1.0f, 0.0f, 0.0f), fovScale(1.0f)
{
//    std::cout << "Default camera called" << std::endl;
}

GzCamera::GzCamera(const GzVector3 &p, const GzVector3 &lookat, const GzVector3 &worldup, float fov) :
    position(p), front((lookat - p).normalize()), up(schimidt(worldup, this->front)),
    right((this->up).crossMultiply(this->front)), fovScale(static_cast<float>(std::tan(fov * PI / 360)))
{
    // Default copy constructor called. It's fine now.
    //this->position = p;
    //std::cout << "position" << std::endl;
    //this->front = (lookat - p).normalize();
    //this->up = schimidt(worldup, this->front);
    //this->right = (this->up).crossMultiply(this->front);
//    this->fovScale = static_cast<float>(std::tan(fov * PI / 360));
}
