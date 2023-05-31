#include <iostream>
#include <chrono>

#include "date.h"

void flush() {
    std::cout << "\n" << std::flush;
    return;
}

void log_cmd(std::string command, std::string user, std::int32_t timestamp) {
    date::sys_seconds tp{std::chrono::seconds{timestamp}};
    std::string time = date::format("%Y-%m-%d %I:%M:%S %p", tp);


    std::cout << "[" << command << "] " 
              << "sent by @" << user 
              << " -- at " << time;

    flush();
    return;
}
