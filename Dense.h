//
// Created by mikemerzl on 19/12/2019.
//

#ifndef Ex1_DENSE_H
#define Ex1_DENSE_H

#include "Activation.h"
/**
 * Dense object
 */
class Dense
{
public:
    /**
     * Con for Dense class
     * @param w :wieghts
     * @param bias :bias
     * @param type :ActiovationType
     */
    Dense(Matrix & w , Matrix & bias , ActivationType type) : weights(w) , bias(bias) ,
                                                              activation(type)
    {};

    /**
 * Get the cur weights.
 * @return Matrix of weights.
 */
    Matrix getWeights() const;

    /**
 * Get Bias Matrix
 * @return Bias Matrix
 */
    Matrix getBias() const;

    /**
 * Returns the activation function of this layer
 * @return activation function of this layer
 */
    Activation getActivation();

    /**
 * Applies the layer on input and returns output matrix
 * @param input : Matrix
 * @return Matrix after layer
 */
    const Matrix operator()(const Matrix & input);

private:
    Matrix & weights;
    Matrix & bias;
    ActivationType activation;

};

#endif //Ex1_DENSE_H
