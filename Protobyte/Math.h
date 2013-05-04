/* 
 * File:   Math.h
 * Author: 33993405
 *
 * Created on March 16, 2013, 2:17 PM
 */

#ifndef MATH_H
#define	MATH_H

#include <ctime>

namespace proto {


    class Math {
    private:
        // disallow instantiation/assignment

        Math() {
        }

    public:

        // all static functions

        // from http://stackoverflow.com/a/686373

        static float random(float max = 1.0) {
            return (float) rand() / ((float) RAND_MAX / max);
        }

        // from http://stackoverflow.com/a/686373

        static float random(float min, float max) {
            return min + (float) rand() / ((float) RAND_MAX / (max - min));

        }

        // static fields
        static const double PI = 3.14159265358979;
        static const double HALF_PI = 1.5707963267949;
        static const double H_PI = 1.5707963267949; // alt name to HALF_PI
        static const double QUARTER_PI = 0.785398163397448;
        static const double Q_PI = 0.785398163397448; // alt name to QUARTER_PI
        static const double TWO_PI = 6.28318530717958;
        static const double DOUBLE_PI = 6.28318530717958; // alt name to TWO_PI
    };
}

#endif	/* MATH_H */

