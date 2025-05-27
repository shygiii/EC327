#include "hw2_problem1.h"
#include "hw2_structs.h"

Rectangle translate(Rectangle rectangle, int xTranslation, int yTranslation) {
    Point ldown = rectangle.lowerLeft;
    int ldownx = ldown.x, ldowny = ldown.y;
    Point newldown = createPoint(ldownx+xTranslation, ldowny+yTranslation);

    Point rup = rectangle.upperRight;
    int rupx = rup.x, rupy = rup.y;
    Point newrup = createPoint(rupx+xTranslation, rupy+yTranslation);

    if (rupx<=ldownx || rupy<=ldowny) { // check if rectangle is illegal
        return rectangle;
    }

    Rectangle result = createRectangle(newldown, newrup); // create translated rectangle
    return result;
}