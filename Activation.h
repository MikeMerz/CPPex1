//Activation.h
#ifndef ACTIVATION_H
#define ACTIVATION_H

#include "Matrix.h"

/**
 * @enum ActivationType
 * @brief Indicator of activation function.
 */
enum ActivationType
{
    Relu ,
    Softmax
};
/**
 * Activation object
 */
class Activation
{
public:
    /**
     * Con for Activation object
     * @param actType :ActivationType given
     */
    Activation(ActivationType actType) : active(actType)
    {};
/**
 * Retuns the activation type
 * @return get Activation type
 */
    ActivationType getActivationType();
    /**
 * overload () operator
 * @param input cur matrix
 * @return Matrix after given operation
 */
    Matrix operator()(const Matrix & input);

private:
    ActivationType active;
};

#endif //ACTIVATION_H
