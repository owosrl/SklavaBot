#include <iostream>
#include <tgbot/tgbot.h>

#include "utils.hpp"

void register_handlers(TgBot::Bot *bot) {
    
    /* WRITE HERE YOUR COMMAND HANDLERS */

    // start command
    bot->getEvents().onCommand("start", [bot](TgBot::Message::Ptr message) {
        log_cmd("start", message->from->username, message->date);
        bot->getApi().sendMessage(message->chat->id, "Hi!");
    });

}
