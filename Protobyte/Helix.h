
/*! \Generates a customizable Helix structure
 * File:   Helix.h
 * Author: Ira Greenberg
 *
 * Created on April 30, 2013, 8:46 AM
 */

#ifndef HELIX_H
#define	HELIX_H

#include "GraphicsCore.h"
#include "GeomBase.h"
#include "Spline3.h"
#include "Tube.h"
#include "Math.h"

namespace proto {

    class Helix : public GraphicsCore {
    public:
        friend std::ostream& operator<<(std::ostream out, const Helix& helix);

        Helix();

        /*!
         * Default+ Constructor */
        Helix(int strandCount, float helixRadius = .2, int strandControlPtCount = 12, int strandInterpolatedPtDetail = 3, int strandPeriods = 1,
                int strandCrossSectionPointCount = 8, float strandRadius = .2);
        /*!
         * Constructor */
        Helix(const Vector3& pos, const Vector3& rot, const Dimension3f size,
                const Color4f col4, int strandCount = 2, float helixRadius = .2, int strandControlPtCount = 12, int strandInterpolatedPtDetail = 3, 
                int strandPeriods = 1, int strandCrossSectionPointCount = 8, float strandRadius = .2);


        void display(GeomBase::displayMode mode = GeomBase::VERTEX_ARRAY,
                GeomBase::renderMode render = GeomBase::SURFACE, float pointSize = 3.5f);

        /* Begin setters/getters, inlined below class */
        void setTubes(std::vector<Tube> tubes);
        std::vector<Tube> getTubes() const;
        void setSplines(std::vector<Spline3> splines);
        std::vector<Spline3> getSplines() const;
        void setTubeJitter(float TubeJitter);
        float getTubeJitter() const;
        void setNodeJitter(Vector3 nodeJitter);
        Vector3 getNodeJitter() const;
        void setPeriodJitter(float periodJitter);
        float getPeriodJitter() const;
        void setStrandRadius(float strandRadius);
        float getStrandRadius() const;
        void setHelixRadius(float helixRadius);
        float getHelixRadius() const;
        void setStrandCrossSectionPointCount(int strandCrossSectionPointCount);
        int getStrandCrossSectionPointCount() const;
        void setStrandPeriods(int strandPeriods);
        int getStrandPeriods() const;
        void setStrandInterpolatedPtDetail(int strandInterpolatedPtDetail);
        int getStrandInterpolatedPtDetail() const;
        void setStrandCount(int strandCount);
        int getStrandCount() const;
        void setStrandControlPtCount(int strandControlPtCount);
        int getStrandControlPtCount() const;

    private:
        // number of Helix strandCount
        int strandCount;

        // number of control points in strand (based on Catmull-Rom spline)
        int strandControlPtCount;

        // number of interpolated points between control points in strand
        int strandInterpolatedPtDetail;

        // number of sine waves through strand
        int strandPeriods;

        // Number of points in strand cross-section
        int strandCrossSectionPointCount;

        // Radius of Helix strand cross-section
        float strandRadius;

        // Radius of Helix
        float helixRadius;

        // factor to randomly perturb underlying spline curve
        float periodJitter;

        // factor to randomly perturb spline points
        Vector3 nodeJitter;

        // factor to randomly perturb Tube radii, implemented through smooth curves (e.g. cos/sine)
        float TubeJitter;

        // Helix containers
        std::vector<Spline3> splines;
        std::vector<Tube> tubes;

        void init();

    };

    inline void Helix::setTubes(std::vector<Tube> tubes) {
        this->tubes = tubes;
    }

    inline std::vector<Tube> Helix::getTubes() const {
        return tubes;
    }

    inline void Helix::setSplines(std::vector<Spline3> splines) {
        this->splines = splines;
    }

    inline std::vector<Spline3> Helix::getSplines() const {
        return splines;
    }

    inline void Helix::setTubeJitter(float TubeJitter) {
        this->TubeJitter = TubeJitter;
    }

    inline float Helix::getTubeJitter() const {
        return TubeJitter;
    }

    inline void Helix::setNodeJitter(Vector3 nodeJitter) {
        this->nodeJitter = nodeJitter;
    }

    inline Vector3 Helix::getNodeJitter() const {
        return nodeJitter;
    }

    inline void Helix::setPeriodJitter(float periodJitter) {
        this->periodJitter = periodJitter;
    }

    inline float Helix::getPeriodJitter() const {
        return periodJitter;
    }

    inline void Helix::setStrandRadius(float strandRadius) {
        this->strandRadius = strandRadius;
    }

    inline float Helix::getStrandRadius() const {
        return strandRadius;
    }

    inline void Helix::setHelixRadius(float helixRadius) {
        this->helixRadius = helixRadius;
    }

    inline float Helix::getHelixRadius() const {
        return helixRadius;
    }

    inline void Helix::setStrandCrossSectionPointCount(int strandCrossSectionPointCount) {
        this->strandCrossSectionPointCount = strandCrossSectionPointCount;
    }

    inline int Helix::getStrandCrossSectionPointCount() const {
        return strandCrossSectionPointCount;
    }

    inline void Helix::setStrandPeriods(int strandPeriods) {
        this->strandPeriods = strandPeriods;
    }

    inline int Helix::getStrandPeriods() const {
        return strandPeriods;
    }

    inline void Helix::setStrandControlPtCount(int strandControlPtCount) {
        this->strandControlPtCount = strandControlPtCount;
    }

    inline int Helix::getStrandControlPtCount() const {
        return strandControlPtCount;
    }

    inline void Helix::setStrandInterpolatedPtDetail(int strandInterpolatedPtDetail) {
        this->strandInterpolatedPtDetail = strandInterpolatedPtDetail;
    }

    inline int Helix::getStrandInterpolatedPtDetail() const {
        return strandInterpolatedPtDetail;
    }

    inline void Helix::setStrandCount(int strandCount) {
        this->strandCount = strandCount;
    }

    inline int Helix::getStrandCount() const {
        return strandCount;
    }





}

#endif	/* HELIX_H */

