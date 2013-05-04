/*! \Class containing common and core fields
 *  for all primitive and composite Geometry
 * File:   GraphicsCore.h
 * Author: Ira Greenberg
 *
 * Created on May 1, 2013, 10:44 PM
 * Copyright (c) 2013 Ira Greenberg. All rights reserved.
 */

#ifndef GRAPHICSCORE_H
#define	GRAPHICSCORE_H

#include <iostream>
#include <vector>
#include "Vector3.h"
#include "Dimension3.h"
#include "Color4.h"

namespace proto {

    class GraphicsCore {
    public:
        /*!
         * Default Constructor */
        GraphicsCore();

        /*!
         * Constructor */
        GraphicsCore(const Vector3& pos, const Vector3& rot, const Dimension3f& size,
                const Color4f& col4);
        
        /*!
         * Constructor */
        GraphicsCore(const Vector3& pos, const Vector3& rot, const Dimension3f& size,
                const std::vector< Color4f >& col4s);

        virtual ~GraphicsCore();

        // setters
        virtual void setPosition(const Vector3& pos);
        virtual void setRotation(const Vector3& rot);
        virtual void setSize(const Dimension3f size);
        virtual void setColor(const Color4f col4);
        virtual void setRotSpd(const Vector3& rotSpd);
        virtual void setSpd(const Vector3& spd);

        // getters
        virtual Vector3& getPosition();
        virtual Vector3& getRotation();
        virtual Dimension3f& getSize();
        virtual Color4f& getColor();
        virtual Vector3 getRotSpd() const;
        virtual Vector3 getSpd() const;

    protected:
        Vector3 pos, rot;
        Dimension3f size;
        Color4f col4;
        std::vector< Color4f > col4s;
        Vector3 spd, rotSpd;


    private:
        // nothing  here yet

    };

    // setters

    inline void GraphicsCore::setPosition(const Vector3& pos) {
        this->pos = pos;
    }

    inline void GraphicsCore::setRotation(const Vector3& rot) {
        this->rot = rot;
    }

    inline void GraphicsCore::setSize(const Dimension3f size) {
        this->size = size;
    }

    inline void GraphicsCore::setColor(const Color4f col4) {
        this->col4 = col4;
    }

    inline void GraphicsCore::setRotSpd(const Vector3& rotSpd) {
        this->rotSpd = rotSpd;
    }

    inline void GraphicsCore::setSpd(const Vector3& spd) {
        this->spd = spd;
    }

    // getters

    inline Vector3& GraphicsCore::getPosition() {
        return pos;
    }

    inline Vector3& GraphicsCore::getRotation() {
        return rot;
    }

    inline Dimension3f& GraphicsCore::getSize() {
        return size;
    }

    inline Color4f& GraphicsCore::getColor() {
        return col4;
    }

    inline Vector3 GraphicsCore::getRotSpd() const {
        return rotSpd;
    }

    inline Vector3 GraphicsCore::getSpd() const {
        return spd;
    }

}

#endif	/* GRAPHICSCORE_H */

