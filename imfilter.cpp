#include <stdio.h>
#include <cstring>
#include <map>
#include "simplecanvas/simplecanvas.h"


/**
 * @brief Return, by reference, the mean of the pixels in a neighborhood around a point
 * 
 * @param imagein 
 * @param x 
 * @param y 
 * @param kernelWidth 
 * @param pixelOut 
 */
void mean(SimpleCanvas& imagein, int x, int y, int kernelWidth, uint8_t* pixelOut) {
    double num = 0;
    double total[3];
    for (int k = 0; k < 3; k++) {
        total[k] = 0;
    }
    for (int dy = -kernelWidth; dy <= kernelWidth; dy++) {
        int y2 = y + dy;
        for (int dx = -kernelWidth; dx <= kernelWidth; dx++) {
            int x2 = x + dx;
            if (x2 >= 0 && x2 < imagein.width && y2 >= 0 && y2 < imagein.height) {
                num++;
                for (int k = 0; k < 3; k++) {
                    total[k] += imagein.data[y2][x2][k];
                }
            }
        }
    }
    for (int k = 0; k < 3; k++) {
        pixelOut[k] = (uint8_t)(total[k]/num);
    }
}

void motionBlur(SimpleCanvas& imagein, int x, int y, int kernelWidth, uint8_t* pixelOut) {
    // TODO: Fill this in
}

void sharpen(SimpleCanvas& imagein, int x, int y, int kernelWidth, uint8_t* pixelOut) {
    // TODO: Fill this in
}

void emboss(SimpleCanvas& imagein, int x, int y, int kernelWidth, uint8_t* pixelOut) {
    // TODO: Fill this in
}



struct Parameters {
    const char* inpath;
    const char* outpath;
    int kernelWidth=1;
    void(*filter)(SimpleCanvas&, int, int, int, uint8_t*);
};

/**
 * @brief Parse the command line arguments that specify parameters
 *        for image processing
 * 
 * @param argc Number of command line arguments
 * @param argv Array of command line arguments
 * @return Parameters
 */
Parameters parseArgs(int argc, char** argv) {
    Parameters params;
    argv++, argc--;
    while (argc > 0) {
        if ((*argv)[0] == '-') {
            if (strcmp(*argv, "--help") == 0) {
                printf("Usage: ./imfilter --in <path to input> --out <path to output> --kernelWidth <width of kernel> --filter(mean/motionBlur)\n");
                exit(0);
            }
            else if (!strcmp(*argv, "--in")) {
                argv++; argc--;
                params.inpath = (const char*)*argv;
            }
            else if (!strcmp(*argv, "--out")) {
                argv++; argc--;
                params.outpath = (const char*)*argv;
            }
            else if (!strcmp(*argv, "--kernelWidth")) {
                argv++; argc--;
                params.kernelWidth = atoi(*argv);
            }
            else if (!strcmp(*argv, "--mean")) {
                params.filter = &mean;
            }
            else if (!strcmp(*argv, "--motionBlur")) {
                params.filter = &motionBlur;
            }
            else if (!strcmp(*argv, "--sharpen")) {
                params.filter = &sharpen;
            }
            else { 
                fprintf(stderr, "Invalid option: %s\n", *argv);
            }
        }
        argv++, argc--; 
    }
    return params;
}


void filterImage(SimpleCanvas& imagein, SimpleCanvas& imageout, Parameters params) {
    // TODO: Fill this in
}

int main(int argc, char** argv) {
    Parameters params = parseArgs(argc, argv);
    SimpleCanvas imagein(params.inpath);
    SimpleCanvas imageout(params.inpath);
    filterImage(imagein, imageout, params);
    imageout.write(params.outpath);
    return 0;
}