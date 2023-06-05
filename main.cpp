#include <iostream>
#include <cstdlib>
#include <chrono>
#include <string>
#include <tgbot/tgbot.h>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/posix_time/conversion.hpp>

#include "utils.hpp"
#include "commands.hpp"
#include "error_codes.hpp"


#define BOT_TOKEN std::getenv("BOT_TOKEN")

int main(int argc, char *argv[]) {
    std::cout << "Starting Bot...\n";

    if(BOT_TOKEN == NULL) {
        std::cerr << "BOT_TOKEN variable isn't sourced\n";
        return EXIT_FAILURE;
    }

    TgBot::Bot bot(std::string(BOT_TOKEN));
    bot.getApi().deleteWebhook(true);
    

    register_handlers(&bot);

    while(true){
        try {
            std::cout << "Bot username: " << bot.getApi().getMe()->username.c_str() << "\n";
            TgBot::TgLongPoll longPoll(bot);
            while (true) {
                longPoll.start();
            }
        } catch (TgBot::TgException& e) {
            log_cmd(e.what(), "TG_BOT", boost::posix_time::to_time_t(boost::posix_time::second_clock::universal_time()), LOG::Error);
            bot.getApi().deleteWebhook(true);
        }
    }

    flush();

    return EXIT_SUCCESS;
}
