#include <stdio.h>
#include <string.h>
#define STB_IMAGE_IMPLEMENTATION
#include "libs/stb_image.h"

#define DENSITY "@#WN$9876543210?!abc;:+=-,._                                       "

int main(void) {
    char filename[50];
    while(1) {
        printf("Enter the image file name: (png or jpg) ");
        gets(filename);
        if(strstr(filename, ".png") == NULL && strstr(filename, ".jpg") == NULL) {
            printf("Invalid file type. Please enter a png or jpg file.\n");
        }
        else {
            break;
        }
    }

    int width, height, channels;
    unsigned char *img = stbi_load(filename, &width, &height, &channels, 0);
    if (img == NULL) {
        printf("Error loading image\n");
        return 1;
    }

    int counter = 0;
    size_t img_size = width * height * channels;
    for(unsigned char *p = img; p != img + img_size; p += channels) {
        unsigned char gray = (p[0] + p[1] + p[2]) / 3;
        unsigned char index = gray * (strlen(DENSITY) - 1) / 255;
        printf("%c ", DENSITY[index]);
        if(++counter % width == 0) {
            printf("\n");
        }
    }


    stbi_image_free(img);



    return 0;
}