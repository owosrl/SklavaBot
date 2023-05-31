#include <iostream>
#include <cstdlib>
#include <string>
#include <tgbot/tgbot.h>

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
    
    register_handlers(&bot);

    try {
        std::cout << "Bot username: " << bot.getApi().getMe()->username.c_str() << "\n";
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        std::cerr << "error: " << e.what() << "\n";
    }

    flush();

    return EXIT_SUCCESS;
}
