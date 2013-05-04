/*! File:   GraphicsCore.cpp
 * Author: Ira Greenberg
 *
 * Created on May 1, 2013, 10:44 PM
 * Copyright (c) 2013 Ira Greenberg. All rights reserved.
 */




#include "GraphicsCore.h"

using namespace proto;

/*!
 * Default Constructor */
GraphicsCore::GraphicsCore(){
}

/*!
 * Constructor */
GraphicsCore::GraphicsCore(const Vector3& pos, const Vector3& rot, const Dimension3f& size,
        const Color4f& col4) : pos(pos), rot(rot), size(size), col4(col4){

}

/*!
 * Constructor */
GraphicsCore::GraphicsCore(const Vector3& pos, const Vector3& rot, const Dimension3f& size,
        const std::vector< Color4f >& col4s) : pos(pos), rot(rot), size(size), col4s(col4s){

}

GraphicsCore::~GraphicsCore() {

}

