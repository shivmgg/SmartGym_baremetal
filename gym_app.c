#include "gym_app.h"


void fc_layer(float input[], float weights[], float bias[], float output[],  int in_dim, int out_dim){
    int i,j,k;
    for (j=0;j<in_dim; j++) {
        float sum = 0;
        for (k=0;k<out_dim; k++){
            sum += input[k]*weights[j*in_dim+k];
        }
        output[j] = sum + bias[j];
    }
}


void main() {
    //read test data 
    clock_t begin = clock();

    float input[1020];
    float inter_out1[32], inter_out2[16], final_out[4]; 

    //initialization
    for (int i=0; i<1020; i++) {
    	input[i] = 2.5;
    }
    
    for (int i=0; i<32; i++) {
    	inter_out1[i] = 0;
    }

    for (int i=0; i<16; i++) {
    	inter_out2[i] = 0;
    }

    for (int i=0; i<4; i++) {
    	final_out[i] = 0;
    }

    //layer1
    fc_layer(input, param1, param2, inter_out1, 32, 1020);

    //layer2
    fc_layer(inter_out1, param3, param4, inter_out2, 16, 32);

    //layer3
    fc_layer(inter_out2, param5, param6, final_out, 4, 16);

    for (int i=0; i<4; i++) {
    	printf("%f\n", final_out[i]);
    }


    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("%f\n", time_spent);

}