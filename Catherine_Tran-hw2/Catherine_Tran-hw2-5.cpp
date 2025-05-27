#include "hw2_structs.h"
#include "hw2_problem5.h"
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <string>

std::string describeOverlap(Rectangle rectangleOne, Rectangle rectangleTwo) {
    int ax1 = rectangleOne.lowerLeft.x, ay1 = rectangleOne.lowerLeft.y;
    int ax2 = rectangleOne.upperRight.x, ay2 = rectangleOne.upperRight.y;

    int bx1 = rectangleTwo.lowerLeft.x, by1 = rectangleTwo.lowerLeft.y;
    int bx2 = rectangleTwo.upperRight.x, by2 = rectangleTwo.upperRight.y;

    Point upperLeft = createPoint(bx1,by2);
    Point lowerRight = createPoint(bx2,by1);
    Point bpoints[4] = {rectangleTwo.lowerLeft,upperLeft,lowerRight,rectangleTwo.upperRight};
    for (int i=0; i<4; i++) {
        //std::cout << describePoint(bpoints[i]) << std::endl;
        int xpt = bpoints[i].x;
        int ypt = bpoints[i].y;
        if ((ax1<=xpt && xpt<=ax2) && (ay1<=ypt && ypt<=ay2)) {
            //std::cout << ax1 << " " << xpt << " " << ax2 << "      " << ay1 << " " << ypt << " " << ay2 << std::endl;
            return "Rectangles overlap.";
        }
    }

    Point upperLeftA = createPoint(ax1,ay2);
    Point lowerRightA = createPoint(ax2,ay1);
    Point apoints[4] = {rectangleOne.lowerLeft,upperLeftA,lowerRightA,rectangleOne.upperRight};
    for (int i=0; i<4; i++) {
        int xpt = apoints[i].x;
        int ypt = apoints[i].y;
        if ((bx1<=xpt && xpt<=bx2) && (by1<=ypt && ypt<=by2)) {
            return "Rectangles overlap.";
        }
    }

    float xdiff = bx1-ax1, ydiff = by1-ay1;
    float distance = sqrt(xdiff*xdiff + ydiff*ydiff);
    distance = floor(distance * 100.0+0.5) / 100.0;
    std::string dist = std::to_string(distance);
    dist = dist.substr(0, dist.find('.') + 3);

    std::string result = "Rectangles do not overlap.  Distance between lower corners is: " + dist + ".";
    return result;
}