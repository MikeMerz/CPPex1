//MlpNetwork.h

#ifndef MLPNETWORK_H
#define MLPNETWORK_H

#include "Matrix.h"
#include "Digit.h"
#include "Dense.h"

#define MLP_SIZE 4

const MatrixDims imgDims = {28 , 28};
const MatrixDims weightsDims[] = {{128 , 784} ,
                                  {64 ,  128} ,
                                  {20 ,  64} ,
                                  {10 ,  20}};
const MatrixDims biasDims[] = {{128 , 1} ,
                               {64 ,  1} ,
                               {20 ,  1} ,
                               {10 ,  1}};
/**
 * MlpNetwork object
 */
class MlpNetwork
{
public:
    /**
 * Accepts 2 arrays, size 4 each
 * @param weights : Weights array
 * @param bias : bias array
 */
    MlpNetwork(Matrix *weights , Matrix *bias);
    /**
 * Applies the entire network on input
 * @param img :Matrix to activate the layers.
 * @return Matrix after layer activation.
 */
    Digit operator()(Matrix & img);

private:
    Dense first;
    Dense second;
    Dense third;
    Dense fourth;
};

#endif // MLPNETWORK_H
