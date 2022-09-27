/**
@file Image.h
@brief First class for management of black and white images in PGM format
@note To be implemented by students. Revise the prototype declaration in order 
 * to respect the condition for a correct communication among modules (input/output parameters as copy/ reference parameters...)
 * @note MP-DGIM, MP-IADE, MP-II (grupo B)
 * @author estudiante1: XXXX POR RELLENAR
 * @author estudiante2: XXXX POR RELLENAR 
 **/

#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <istream>
#include <fstream>
#include "Byte.h"
#include "Histogram.h"

/**
@brief A black and white image
 */
class Image {
public:
    static const int IMAGE_MAX_SIZE = 200000; ///< Max number of bytes allowd for
    static const int IMAGE_DISK_OK = 0; ///< Image read/write successful
    static const int IMAGE_ERROR_OPEN = 1; ///< Error opening the file
    static const int IMAGE_ERROR_DATA = 2; ///< Missing data in the file
    static const int IMAGE_ERROR_FORMAT = 3; ///< Unknown image format
    static const int IMAGE_TOO_LARGE = 4; ///< The image is too large and does not fit into memory 

    /**
     * @brief It builds an empty, image
     */
    Image();

    //....
    //INSTRUCCIONES PARA IMAGE, HAY QUE RETIRAR    
    //* Deprecated    void getHistogram(int values[]), the previous hide in comments 

    /**
     * @brief It builds an empty, image. Modifier method.
     */
//    Image();
    /**
     * @brief It builds a fully black image with @a width columns and @a height rows. Modifier method.
     * @param height number of rows
     * @param width number of columns
     */
    Image(int width, int height);
    /**
    @brief It gives the number of rows of the image. Query method.
    @return number of rows
     */
    int height() const;
    /**
    @brief It gives the number of columns of the image
    @return The number of rows
     */
    int width() const;
    /**
     * @brief It assigns the value @a v to the position(x,y) of the image.It must check that
     * the values x and y are valid, otherwise, it does not do anything. Modifier method.
     * @param x The column
     * @param y the row
     * @param v The new value
     */
    void setPixel(int x, int y, Byte v);
    /**
     * @brief It returns the value of the requested (x,y) position. It must check that
     * the values x and y are valid, otherwise, it returns a negative value. Please note that
     * the value returned is a int in order to allow negative values. Query method.
     * @param x The column
     * @param y the row
     * @return The value of the pixel in [0-256] or -1 if there is an access error
     */
    int getPixel(int x, int y) const;
    /**     
     * @brief It assigns the value @a v to the linear position i of the image. It must check that
     * the values i is valid, otherwise, it does not do anythig. Modifier method.
     * @param i The linear position
     * @param v The new value
     */
    void setPos(int i, Byte v);
    /**
     * @brief It returns the value of the requested linear position. It must check that
     * the value i is valid, otherwise, it returns a negative value. Please note that
     * the value returned is a int. Query method.
     * @param i The linear position
     * @return The value of the pixel in [0-256] or -1 if there is an access error
     */
    int getPos(int i) const;
    /**
     * @brief  It sets all pixels of the image to the value given
     * @param b The value
     */
    void flatten(Byte b);

    /**
     * @brief It shows an image in an external window, ready for inspection. It uses
     * the program display (ImageMagick) to display every image. For an easier identification 
     * every image is labeled with a title. Query method.
     * @param title The title on top of the window
     */
    void showInWindow(std::string title) const;
    /**
     * @brief It calculates the hash value of the image and returns it inside a string,
     * together with its dimension.
     * @return a string that contains the dimension and the hash value of the image
     */
    std::string inspect() const;
    /**
     * @brief It calculates the histogram of the image, and returns it into the array values such 
     * that values[i] = number of pixels whose tone is i. Query method.
     * @param values The array of pixel counts. The sum of all these values must be, exactly, output parameter.
     */

    /**************************************************
     *
     *    The new functionalities for the Images 
     *
     **************************************************/

    /**
     * @brief It opens a file that contains a PGM Image and reads the data to build
     * an image object. Modifier method. 
     * @param filename Name of the file. input parameter a c-string.
     * @return a code that means the following: 0 - Successful operation. 
     * 1 - Error opening the file
     * 2 - Error reading the data
     * 3 - The detected data does not follow the PGM technical description
     */
    int readFromFile(const char filename[]);

    /**
     * @brief It writes the Image on disk, in PGM ascii format. Query method.
     * @param filename The name of the disk file which will contain the image. filename input parameter a c-string.
     * @return The same code that readFromFile()
     */
    int saveToFile(const char filename[]) const;

    /**
     * @brief It calculates the histogram of the image, and returns it into an
     * instance of the class Histogram. Query method.
     * Deprecated    void getHistogram(int values[]), the previous can be removed
     
     */

    Histogram getHistogram() const;
    /**
     * @brief It takes the histogram of the image and depicts a new image with the
     * visualization of the histogram according to these rules 
     * ~~~~
     *   +-     +-----------------------------o 
     *   |      |                             | --- 1 pix white line
     *   |      |   *                         | -+
     *   |      |   **                        |  |
     *   |      |   **                        | 
     *   |      |   ***                   *   |   Normalized histogram
     *          |   ***                  **   |     150 pix
     *   h=160  |   ****    *            **   |  |
     *          |   *****  ***          ****  |  |
     *   |      |  ************************** | -+
     *   |      |-----------------------------|  1 pix  white line
     *   |      |-----------------------------| -+
     *   |      |                             |  8 pix Scale of gray levels
     *   +-     o-----------------------------+ -+
     *
     *          |                             |
     *          +--------- w  = 256 ----------+
     * ~~~~
     * Query method.
     * @return the built image
     */
    Image depictsHistogram() const;

    /**
     * @brief It segments the histogram by groups whose value is higher than the admitted tolerance and returns
     * an array of images, each of which corresponds to one of these objects. Query method
     * Given the following histogram, cut by the tolerance level. The method find 4 groups.
     * ~~~~
     *   +-     +-----------------------------o 
     *   |      |                             | --- 1 pix white line
     *   |      |   *                         | -+
     *   |      |   **                        |  |
     *   |      |   **                        | 
     *   |      |   ***                   *   |   Normalized histogram
     *          |   ***                  **   |     150 pix
     *   h=160  |   ****    *            **   |  |
     *          |   *****  ***          ****  |  |
     *   |      |  ******  ***   *     ****** | -+
     *   |      |-----------------------------|  tolerance level 
     *   |      |-----------------------------| -+
     *   |      |-----------------------------| -+                        
     *   +-     o-----------------------------+ -+
     *          |                             |
     *          +--------- w  = 256 ----------+
     * ~~~~
     * @param set The array of images. input/out param
     * @param nimages The number of images found. output param
     * @param maximages The max number of images to be found. input param
     * @param tolerance The tolerance admitted. input param
     */

    void extractObjects(Image imageSet [], int &nimages, int maximages, double tolerance) const;
    
   
private:
    Byte _data[IMAGE_MAX_SIZE]; ///< Bytes of the image
    int _height; ///< number of rows
    int _width; ///< number of columms

    
    
};
#endif
