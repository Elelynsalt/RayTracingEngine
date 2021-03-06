#ifndef GZRENDER_H
#define GZRENDER_H

#include "GzConstants.h"
#include "GzCamera.h"
#include "GzAASetting.h"
#include "GzGeometry.h"
#include "GzLight.h"
#include "GzDisplay.h"

class GzRender
{
private:
    GzDisplay *p_display;
    GzCamera *p_camera;
    GzLight **p_light_arr; // Array of pointers
    int n_lights;
    GzGeometry *p_scene; // Union geometry object. Not an array
    GzAASetting *p_AA; // By default there will be one AA setting. Can be re-written.
    int options;

private:
    GzRender(); // Default constructor. Disabled by using private.
public:
    GzRender(GzDisplay *p_disp);
    ~GzRender();
    int putCamera(GzCamera *p_cam);
    int putLights(GzLight **p_li_arr, int num_lights);
    int putScene(GzGeometry *p_sce);
    int putAASetting(GzAASetting *p_aa);
    int putAttribute(int attribute);

    int renderToDisplay();

    GzColor shade(const IntersectResult &inter, const GzRay &incRay, float bar);
};

#endif

