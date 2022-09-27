/**
 * @file Image.cpp
 * @note To be implemented by students 
 * @author MP-DGIM, MP-IADE, MP-II (grupo B)
 */
#include<iostream>
#include <fstream>
#include<cstring>
#include "MPTools.h"
#include "Byte.h"
#include "Image.h"
using namespace std;

Image::Image() {

    _width = 0;
    _height = 0;
}

Image::Image(int width, int height) {

    _width = width;
    _height = height;

}

int Image::height() const {

    return _height;
}

int Image::width() const {

    return _width;

}

void Image::setPixel(int x, int y, Byte v) {

    int i = y * _width + x;

    if (i <= IMAGE_MAX_SIZE && i >= 0)
        _data[i] = v;
}

int Image::getPixel(int x, int y) const {

    int i = y * _width + x;
    int valor_pixel = -1;

    if (x >= 0 && y >= 0 && i >= 0 && i <= IMAGE_MAX_SIZE)
        valor_pixel = _data[i].getValue();

    return valor_pixel;
}

void Image::setPos(int i, Byte v) {

    if (i > 0 && i < IMAGE_MAX_SIZE)
        _data [i] = v;
}

int Image::getPos(int i) const {

    int valor_pixel = -1;

    if (i >= 0 && i <= IMAGE_MAX_SIZE)
        valor_pixel = _data[i].getValue();

    return valor_pixel;

}

void Image::flatten(Byte b) {

    for (int i = 0; i < IMAGE_MAX_SIZE; i++) {
        _data [i] = b;
    }

}
// ...

void Image::showInWindow(string title) const {
    string tempname = "data" + SLASH + ".hidden_" + title + ".pgm";

    mpSavePGMImage(tempname, (const unsigned char *) _data, _width, _height);
    mpDisplayImage(tempname, title);

}

string Image::inspect() const {
    string result = "";
    result = std::to_string(_width) + "x" + std::to_string(_height) + " " + std::to_string(mphash((const unsigned char*) _data, _height * _width));
    return result;
}

void Image::getHistogram(int values[]) const {

    for (int i = 0; i < Byte::MAX_BYTE; i++) {
        values [i] = 0;
    } // Inicializo el vector a 0.

    for (int i = 0; i < (_height * _width); i++) {
        values [_data[i].getValue()]++;
    }



}



