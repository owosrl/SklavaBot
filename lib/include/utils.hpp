#ifndef HPP_UTILS
#define HPP_UTILS

#include <iostream>
#include <string>
#include <cstdint>


/**
 * flush()
 * @brief Flush stdin
 */
void flush();



/**
 * log_cmd(command, user, timestamp, log_type)
 * @brief Function to print a better log 
 *
 * @param command Command string
 * @param user User or entity who sent log
 * @param timestamp Unix epoch of when log was generated
 * @param log_type Log type, see LOG namespace
 */
void log_cmd(std::string command, std::string user, std::int32_t timestamp, const std::string log_type);



/**
 * LOG namespace
 * @brief Defined LOG types
 */
namespace LOG {

    #define FG_BRED     "\033[1;31m"
    #define FG_BYELLOW  "\033[1;33m"
    #define FG_BGREEN   "\033[1;32m"
    #define FG_BWHITE   "\033[1;37m"
    #define RESET       "\033[0m"

    const std::string Info  = FG_BWHITE  "[INFO]"  RESET;
    const std::string Warn  = FG_BYELLOW "[WARN]"  RESET;
    const std::string Error = FG_BRED    "[ERROR]" RESET;
    const std::string Debug = FG_BGREEN  "[DEBUG]" RESET;
}

#endif
