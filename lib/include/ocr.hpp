#ifndef HPP_OCR
#define HPP_OCR

#include <string>
#include <leptonica/allheaders.h>



/**
 * getTextFromImage(*image)
 *
 * @param *image Pointer to a Pix object of leptonica
 *
 * @return outText OCR String
 */
std::string getTextFromImage(Pix *image);

#endif
