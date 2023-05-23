#ifndef EULER_CHARACTERISTIC_H
#define EULER_CHARACTERISTIC_H

#include <Eigen/Core>
#include <set>
#include "edges.h"
// Compute the Euler Characteristic of a given triangle mesh.
//
// Inputs:
//   F  #F by 3 list of triangle indices into some vertex list V
// Returns Euler Characteristic as an integer
int euler_characteristic( const Eigen::MatrixXi &F);
#endif
