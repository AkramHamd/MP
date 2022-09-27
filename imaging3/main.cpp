/**
 * @file main.cpp
 * @author MP
 */
#include <iostream>
#include <cstring>
#include "MPTools.h"
#include "Byte.h"
#include "Image.h"
#include "Histogram.h"

using namespace std;

static const int ERROR_ARGUMENTS=100;

/**
 * @brief It waits until the key [INTRO] [RETURN] is pressed
 */
void pressReturnToContinue();

/**
 * @brief it shows help about the syntax of the command line
 */
void showHelp();

/**
 * @brief It breaks the program due to some error and shows a message
 * @param errorcode The type of error as declared in Image.h
 * @param errordata A message trying to describe the error
 */
void errorBreak(int errorcode, const string & errordata);

int main(int nargs, char *args[]) {
    string input = "", copy = "", output = "", aux;
    Image im_input, im_output, im_copyfrom, im_bin, im_cut, im_histogram, im_collection[10], im_aux;
    int res, n, x, y, w, h;


        res = im_copyfrom.readFromFile(copy.c_str());
 

        im_copyfrom.showInWindow("copyfrom");
        cout << "[ " << .. << "]" << im_copyfrom.inspect();
        w = im_copyfrom.width() + 5;
        h = im_copyfrom.height() + 5;
        im_bin = im_copyfrom.threshold();
        im_bin.showInWindow("threshold");
        cout << "[ " << .. << "]" << im_bin.inspect();
        int x = 0;
        im_input.pasteArea(x, 0, im_copyfrom);
        im_copyfrom.extractObjects(im_collection, n, 3);
        im_cut = im_collection[0];
        im_collection[0].showInWindow("segmented");
        cout << "[ " << .. << "]" << im_collection[0].inspect();
        x = x + w;
        im_input.pasteArea(x, 0, im_cut);
        im_input.pasteArea(x, h, im_bin);
        x = x + w;
        im_input.pasteArea(x, 0, im_cut, 64);
        im_input.pasteArea(x, h, im_bin, 64);
        x = x + w;
        im_input.pasteArea(x, 0, im_cut, 64, 50);
        im_input.pasteArea(x, h, im_bin, 64, 50);
 
	im_output.showInWindow("output");
	cout << "[ " << .. << "]" << im_output.inspect();
	pressReturnToContinue();
	
    return 0;
}

void pressReturnToContinue() {
    char aux[10];
    cout << "Press [RETURN] to continue ...";
    cin.getline(aux, 1, '\n');
}

void showHelp() {
    cout << "Please use: -i <input> [-c <copyfrom> -o <output>]" << endl;
    cout << "\n-i <input>\n\tInput image from <input>";
    cout << "\n-c <copyfrom>\n\tCopy clip from <copyfrom>";
    cout << "\n-o <output>\n\tOutput image to <output>" << endl;
}

void errorBreak(int errorcode, const string & errordata) {
    switch (errorcode) {
        case ERROR_ARGUMENTS:
            cout  << endl << "Error in call: " << errordata << endl;
            showHelp();
            break;
        case Image::IMAGE_ERROR_OPEN:
            cout  << endl << "Error opening file " << errordata << endl;
            break;
        case Image::IMAGE_ERROR_DATA:
            cout  << endl << "Data error in file " << errordata << endl;
            break;
        case Image::IMAGE_ERROR_FORMAT:
            cout  << endl << "Unrecognized format in file " << errordata << endl;
            break;
        case Image::IMAGE_TOO_LARGE:
            cout  << endl << "The image is too large and does not fit into memory" << errordata << endl;
            break;
    }
    std::exit(1);
}
