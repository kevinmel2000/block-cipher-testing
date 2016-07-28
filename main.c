#include <stdio.h>
#include <stdlib.h>
#include "num_utils.h"
#include "sbox_utils.h"

// PRESENT sbox (4 x 4)
unsigned int present_sbox[16] = {12, 5, 6, 11, 9, 0, 10, 13, 3, 14, 15, 8, 4, 7, 1, 2};

// sample sbox (3 x 3)
unsigned int sample_sbox[8] = {2, 7, 0, 6, 3, 1, 5, 4};

int main() {

    unsigned int m = 3, n = 3;
    unsigned int **ddt = sbox_differential_table(sample_sbox, m, n);

    printf("DDT:\n");
    print_uint_matrix(ddt, two_power(m), two_power(n));

    unsigned int **lat = sbox_linear_approx_table(sample_sbox, m, n);

    printf("LAT:\n");
    print_uint_matrix(lat, two_power(m), two_power(n));

    free(lat);
    free(ddt);

    return 0;
}