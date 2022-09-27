/**
 * @file Byte.cpp
 * @brief Operators for bit level
 * @note To be implemented by students 
 * @author MP-DGIM, MP-IADE, MP-II (grupo B)
 */
#include <iostream>
#include <string>
#include "MPTools.h"
#include "Byte.h"

using namespace std;

const Byte Byte::MAX_BYTE_VALUE(255);
const Byte Byte::MIN_BYTE_VALUE(0);

void Byte::onBit(int pos) {

    unsigned char mask = 0x01;
    mask = mask << pos;
    _data = _data | mask;
}

void Byte::offBit(int pos) {

    unsigned char mask = 0x01;
    mask = mask << pos;
    mask = ~mask;
    _data = _data & mask;

}

Byte::Byte() {
    _data = 0;
}

Byte::Byte(int value) {
    _data = (unsigned char) value;
}

bool Byte::getBit(int pos) const {

    bool status;
    unsigned char mask;
    mask = 0x01 << pos;
    status = (mask & _data) > 0;

    return status;
}

string Byte::to_string() const {

    string s = "00000000";


    for (int i = 0; i < 8; i++)
        if (getBit(i) == true)
            s [7 - i] = '1';

    return s;
}

void Byte::onByte() {

    _data = 0xff;
}

void Byte::offByte() {

    _data = 0x00;
}

void Byte::encodeByte(bool v[]) {

    for (int i = 0; i < 8; i++) {
        if (v[7 - i] == true)
            onBit(i);
    }
}

void Byte::decodeByte(bool v[]) {

    for (int i = 0; i < 8; i++) {

        if (getBit(7 - i) == true)
            v[i] = 1;

        else
            v[i] = 0;
    }
}

void Byte::decomposeByte(int posits[], int n) {

    n = 0;
    for (int i = 0; i < 8; i++) {
        if (getBit(i) == true) {
            posits[n] = i;
            n++;
        }
    }
}

void Byte::shiftRByte(int n) {

    _data = _data >> n;
}

void Byte::shiftLByte(int n) {

    _data = _data << n;
}

void Byte::mergeByte(const Byte merge, int percentage) {

    _data = (_data * (100 - percentage) + merge._data * percentage) / 100;
} 