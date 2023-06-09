#include <iostream>
#include <string>
#include <chrono>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/local_time_adjustor.hpp>
#include <boost/date_time/c_local_time_adjustor.hpp>

#include "utils.hpp"



/**
 * flush()
 * @brief Flush stdin
 */
void flush() {
    std::cout << "\n" << std::flush;
    return;
}



/**
 * log_cmd(command, user, timestamp, log_type)
 * @brief Function to print a better log 
 *
 * @param command Command string
 * @param user User or entity who sent log
 * @param timestamp Unix epoch of when log was generated
 * @param log_type Log type, see LOG namespace
 */
void log_cmd(std::string command, std::string user, std::int32_t timestamp, const std::string log_type) {
    typedef boost::date_time::c_local_adjustor<boost::posix_time::ptime> local_adj;


    std::string time = boost::posix_time::to_simple_string(
            local_adj::utc_to_local(boost::posix_time::from_time_t(timestamp)
        ));

    std::cout << log_type
              << " (" << command << ") " 
              << "sent by @" << user 
              << " -- at " << time;

    flush();
    return;
}
