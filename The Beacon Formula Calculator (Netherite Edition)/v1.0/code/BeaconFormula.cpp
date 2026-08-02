#include "BeaconFormula.hpp"

int b_l(int h, int L, int W){
    return (2*h + L) * (2*h + W);
}

int b(int L, int W, int m, int beta){
    return ((2*m*(m+1)*(2*m+1)/3) + L*m*(m+1) + W*m*(m+1) + L*W*(m+1)) - beta;
}