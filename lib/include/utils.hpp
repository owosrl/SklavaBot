#ifndef HPP_UTILS
#define HPP_UTILS

#include <iostream>
#include <string>
#include <cstdint>

void flush();

void log_cmd(std::string command, std::string user, std::int32_t timestamp, const std::string log_type);

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
