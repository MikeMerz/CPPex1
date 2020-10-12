//
// Created by mikemerzl on 19/12/2019.
//

#include "Dense.h"

/**
 * Get the cur weights.
 * @return Matrix of weights.
 */
Matrix Dense::getWeights() const
{
    return weights;
}

/**
 * Get Bias Matrix
 * @return Bias Matrix
 */
Matrix Dense::getBias() const
{
    return bias;
}

/**
 * Returns the activation function of this layer
 * @return activation function of this layer
 */
Activation Dense::getActivation()
{
    return Activation(activation);
}

/**
 * Applies the layer on input and returns output matrix
 * @param input : Matrix
 * @return Matrix after layer
 */
const Matrix Dense::operator()(const Matrix & input)
{
    Matrix m(input);
    m = getWeights() * input;
    m += getBias();
    m = getActivation()(m);
    return m;
}
