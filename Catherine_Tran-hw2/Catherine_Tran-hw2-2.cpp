#include "hw2_structs.h"
#include "hw2_problem2.h"

bool scale(Rectangle *rectangle, double xScale, double yScale) {
    if (xScale<=0 || yScale<=0) {
        return false;
    }
    
    Point ldown = rectangle->lowerLeft;
    int ldownx = ldown.x, ldowny = ldown.y;
    Point rup = rectangle->upperRight;
    int rupx = rup.x, rupy = rup.y;

    if (rupx<=ldownx || rupy<=ldowny) { // check if rectangle is illegal
        return false;
    }

    float lenx = rupx-ldownx, leny = rupy-ldowny;
    lenx*=xScale;
    leny*=yScale;
    Point newrup = createPoint(ldownx+lenx, ldowny+leny);

    if (newrup.x<=ldownx || newrup.y<=ldowny) {
        return false;
    }
    rectangle->upperRight = newrup;
    return true;
}