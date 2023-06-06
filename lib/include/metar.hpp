#ifndef HPP_METAR
#define HPP_METAR

#include <string>

/**
 * getMetar(ICAO)
 * @brief Get METAR information from stations
 *
 * @param ICAO The station's ICAO code
 * 
 * @return metarInfo Station response
 */
std::string getMetar(std::string ICAO);

#endif
