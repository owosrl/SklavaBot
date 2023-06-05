#include <iostream>
#include <string>
#include <chrono>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/posix_time/conversion.hpp>

#include "utils.hpp"

std::string getTextFromImage(Pix *image) {
    char *outText;
    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    // Initialize tesseract-ocr with English, without specifying tessdata path
    if (api->Init(NULL, "eng")) {
        log_cmd("Unable to initialize tesseract-ocr", "OCR", boost::posix_time::to_time_t(boost::posix_time::second_clock::universal_time()), LOG::Error);
        exit(1); 
    }

    api->SetImage(image);
    outText = api->GetUTF8Text();

    api->End();
    delete api;

    return std::string(outText);
}
