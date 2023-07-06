#include <math.h>

void delta_inverse_kinematic(double x, double y, double z, double *theta1, double *theta2, double *theta3) {
    
    double R = 100;
    double r = 20;
    double L = 270;
    double l = 500;
    z = -z;
    double m = x * x + y * y + z * z + pow(R - r, 2) + pow(L, 2) - pow(l, 2);
    double A[3] = {
        (m - 2 * x * (R - r)) / (2 * L) - (R - r - x),
        (m + (R - r) * (x - sqrt(3) * y)) / L - 2 * (R - r) - (x - sqrt(3) * y),
        (m + (R - r) * (x + sqrt(3) * y)) / L - 2 * (R - r) - (x + sqrt(3) * y)
    };
    double B[3] = {
        2 * z,
        4 * z,
        4 * z
    };
    double C[3] = {
        (m - 2 * x * (R - r)) / (2 * L) + (R - r - x),
        (m + (R - r) * (x - sqrt(3) * y)) / L + 2 * (R - r) + (x - sqrt(3) * y),
        (m + (R - r) * (x + sqrt(3) * y)) / L + 2 * (R - r) + (x + sqrt(3) * y)
    };
    *theta1 = 2 * atan((-B[0] - sqrt(pow(B[0], 2) - 4 * A[0] * C[0])) / (2 * A[0]));
    *theta2 = 2 * atan((-B[1] - sqrt(pow(B[1], 2) - 4 * A[1] * C[1])) / (2 * A[1]));
    *theta3 = 2 * atan((-B[2] - sqrt(pow(B[2], 2) - 4 * A[2] * C[2])) / (2 * A[2]));
}