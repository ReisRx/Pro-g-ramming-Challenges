#include <stdio.h>
#include <string.h>
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "libs/stb_image.h"
#include "libs/stb_image_resize.h"

#define WIDTH 80
#define HEIGHT 80
#define DENSITY "@#WN$9876543210?!abc;:+=-,._                         "
// #define DENSITY "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~i!lI;:,^`"
// #define DENSITY "@%#*+=-:. "

int main(void) {
    // Get image name
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

    // Load image
    int width, height, channels;
    unsigned char *img = stbi_load(filename, &width, &height, &channels, 0);
    if (img == NULL) {
        printf("Error loading image\n");
        return 1;
    }

    // Resize image
    int new_width = WIDTH;
    int new_height = HEIGHT;
    unsigned char *resized_img = malloc(new_width * new_height * channels);
    stbir_resize_uint8(img, width, height, 0, resized_img, new_width, new_height, 0, channels);

    // Convert image to ASCII
    int counter = 0;
    size_t img_size = new_width * new_height * channels;
    for(unsigned char *p = resized_img; p != resized_img + img_size; p += channels) {
        unsigned char gray = (p[0] + p[1] + p[2]) / 3;
        unsigned char index = gray * (strlen(DENSITY) - 1) / 255;
        printf("%c ", DENSITY[index]);
        if(++counter % new_width == 0) {
            printf("\n");
        }
    }

    // Free memory
    stbi_image_free(img);
    stbi_image_free(resized_img);
    return 0;
}