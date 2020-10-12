//
// Created by mikemerzl on 19/12/2019.
//

#include "MlpNetwork.h"
#include "Dense.h"

/**
 * Accepts 2 arrays, size 4 each
 * @param weights : Weights array
 * @param bias : bias array
 */
MlpNetwork::MlpNetwork(Matrix weights[4] , Matrix bias[4]) :
        first(weights[0] , bias[0] , ActivationType::Relu) ,
        second(weights[1] , bias[1] , ActivationType::Relu) ,
        third(weights[2] , bias[2] , ActivationType::Relu) ,
        fourth(weights[3] , bias[3] , ActivationType::Softmax)
{
}

/**
 * Applies the entire network on input
 * @param img :Matrix to activate the layers.
 * @return Matrix after layer activation.
 */
Digit MlpNetwork::operator()(Matrix & img)
{
    img = first(img);
    img = second(img);
    img = third(img);
    img = fourth(img);
    float max = 0;
    unsigned int maxIndex = 0;
    for (int j = 0; j < img.getRows(); ++ j)
    {
        if (img[j] > max)
        {
            max = img[j];
            maxIndex = (unsigned int) j;
        }
    }
    Digit final = {maxIndex, max};
    return final;
}

