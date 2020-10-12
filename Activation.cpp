//
// Created by mikemerzl on 19/12/2019.
//
#include <math.h>
#include "Activation.h"

/**
 * overload () operator
 * @param input cur matrix
 * @return Matrix after given operation
 */
Matrix Activation::operator()(const Matrix & input)
{
    Matrix returnOne(input);
    if (active == Relu)
    {
        for (int i = 0; i < input.getRows() * input.getCols(); ++ i)
        {
            if (returnOne[i] < 0)
            {
                returnOne[i] = 0;
            }
        }
        return returnOne;
    }
    else
    {
        float sum = 0;
        for (int i = 0; i < input.getRows(); ++ i)
        {
            returnOne[i] = std::exp(input[i]);
            sum += std::exp(input[i]);
        }
        return ((1 / sum) * returnOne);
    }
}

/**
 * Retuns the activation type
 * @return get Activation type
 */
ActivationType Activation::getActivationType()
{
    return active;
}