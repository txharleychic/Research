/* 
 * File:   Helix.cpp
 * Author: ira
 * 
 * Created on April 30, 2013, 8:46 AM
 */

#include "Helix.h"


using namespace proto;

Helix::Helix(){ 
}
/*!
 * Constructor */
Helix::Helix(int strandCount, float helixRadius, int strandControlPtCount, int strandInterpolatedPtDetail, int strandPeriods,
        int strandCrossSectionPointCount, float strandRadius) : GraphicsCore(Vector3(0,0,0), Vector3(0,0,0), Dimension3f(1,1,1), Color4f(1, .6, .5, 1.0)),
strandCount(strandCount), helixRadius(helixRadius), strandControlPtCount(strandControlPtCount), strandInterpolatedPtDetail(strandInterpolatedPtDetail), strandPeriods(strandPeriods),
strandCrossSectionPointCount(strandCrossSectionPointCount), strandRadius(strandRadius) {
    init();
}

/*!
 * Constructor */
Helix::Helix(const Vector3& pos, const Vector3& rot, const Dimension3f size, const Color4f col4,
        int strandCount, float helixRadius, int strandControlPtCount, int strandInterpolatedPtDetail, int strandPeriods, int strandCrossSectionPointCount, float strandRadius) :
GraphicsCore(pos, rot, size, col4), strandCount(strandCount), helixRadius(helixRadius), strandControlPtCount(strandControlPtCount), strandInterpolatedPtDetail(strandInterpolatedPtDetail), strandPeriods(strandPeriods),
strandCrossSectionPointCount(strandCrossSectionPointCount), strandRadius(strandRadius) {
    init();
}

void Helix::init() {
   
    float helixHt = 1.0;
    float theta = 0.0, thetaSpd = 0.0;
    splines.resize(strandCount);
    tubes.resize(strandCount);
    float smoothness = .5;
    for (int i = 0; i <strandCount; ++i) {
        // start at random position around y-axis
        theta = Math::TWO_PI/strandCount*i;
        std::vector<Vector3> cps;
        float x = 0.0, y = -helixHt / 2.0, z = 0.0;
        cps.resize(strandControlPtCount);
        thetaSpd = (Math::TWO_PI*strandPeriods)/strandControlPtCount;
        for (int j = 0; j < strandControlPtCount; ++j) {
            //std::cout << "in helix" << std::endl;
            z = cos(theta) * helixRadius;// + Math::random(-.15, .15);
            x = sin(theta) * helixRadius;// + Math::random(-.15, .15);
            y += helixHt / strandControlPtCount; // + Math::random(-15, 15);
            cps.at(j) = Vector3(x, y, z);
            //std::cout << "cps.at(j)" << cps.at(j) << std::endl;
            theta += thetaSpd;
        }
        splines.at(i) = Spline3(cps, strandInterpolatedPtDetail, true, smoothness);
        tubes.at(i) = Tube(pos, rot, size, col4, splines.at(i), strandRadius, strandCrossSectionPointCount);

    }
    tubes.at(0).exportSTL();

}

void Helix::display(GeomBase::displayMode mode, GeomBase::renderMode render, float pointSize) {
    for (int i = 0; i < tubes.size(); ++i) {
        tubes.at(i).display(mode, render, pointSize);
    }
}


