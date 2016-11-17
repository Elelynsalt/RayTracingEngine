#include "stdafx.h"
#include "GzColor.h"

GzColor::GzColor(float a_r, float a_g, float a_b) :
    r(a_r), g(a_g), b(a_b)
{
}

GzColor::GzColor() : GzColor(0.0f, 0.0f, 0.0f)
{
}

GzColor& GzColor::modulate(const GzColor &other) const
{
    return GzColor(this->r * other.r, this->g * other.g, this->b * other.b);
}

const GzColor GzColor::BLACK(0.0f, 0.0f, 0.0f);
const GzColor GzColor::RED(1.0f, 0.0f, 0.0f);
const GzColor GzColor::GREEN(0.0f, 1.0f, 0.0f);
const GzColor GzColor::BLUE(0.0f, 0.0f, 1.0f);
const GzColor GzColor::CYAN(0.0f, 1.0f, 1.0f);
const GzColor GzColor::MAGENTA(1.0f, 0.0f, 1.0f);
const GzColor GzColor::YELLOW(1.0f, 1.0f, 0.0f);



GzColor& operator+(const GzColor &c1, const GzColor &c2)
{
    return GzColor(c1.r + c2.r, c1.g + c2.g, c1.b + c2.b);
}

GzColor& operator*(const GzColor &c1, float s)
{
    return GzColor(c1.r * s, c1.g * s, c1.b * s);
}
