#include <iostream>
#include <string>
#include <curl/curl.h>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/posix_time/conversion.hpp>

#include "utils.hpp"

/**
 * writeFunction(*ptr, size, nmemb, *data)
 * @brief Write function for CURL
 *
 * @param *ptr Pointer to response data 
 * @param size Always 1
 * @param nmemb Response data size
 * @param *data Pointer to destination variable
 *
 * @return size*nmemb Size of data
 */
size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}



/**
 * getMetar(ICAO)
 * @brief Get METAR information from stations
 *
 * @param ICAO The station's ICAO code
 * 
 * @return metarInfo Station response
 */
std::string getMetar(std::string ICAO) {
    std::string metarInfo;
    const std::string url = "https://tgftp.nws.noaa.gov/data/observations/metar/stations/"+ICAO+".TXT";

    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if (!curl) {
        log_cmd("Unable to initalize CURL", "CURL", boost::posix_time::to_time_t(boost::posix_time::second_clock::universal_time()), LOG::Error);
        return "Failed";
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &metarInfo);

    res = curl_easy_perform(curl);
    if(res != CURLE_OK)
      log_cmd(curl_easy_strerror(res), "CURL", boost::posix_time::to_time_t(boost::posix_time::second_clock::universal_time()), LOG::Error);
    
    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return metarInfo;
}
