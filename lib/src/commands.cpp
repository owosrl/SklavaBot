#include <iostream>
#include <string>
#include <cstdint>
#include <tgbot/tgbot.h>
#include <leptonica/allheaders.h>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/posix_time/conversion.hpp>

#include "utils.hpp"
#include "config.hpp"
#include "ocr.hpp"

const std::string PARSE_MODE("Markdown");

const std::string HELP_MESSAGE =
            "Hello, I'm " BOT_NAME "!\n"
            "I'm a bot created by " BOT_AUTHOR "!\n"
            "My commands:\n"
            "/start - start the bot\n"
            "/help - show this message\n"
            "\n"
            "My source code is available at " BOT_GITHUB_REPO "\n"
            "Version: " BOT_VERSION "\n";


const std::string INFO_MESSAGE = 
            "System Informations\n\n"
            "*OS*: _"
    #if defined (__linux__)
            "Linux" 
    #elif defined (__APPLE__) 
            "MacOS"
    #elif defined (_WIN32)
        #if defined (_WIN64)
            "Windows x86-64"
        #else
            "Windows x86"
        #endif
    #endif 
            " with "
    #if defined (__amd64__) 
            "CPU x86-64"
    #elif defined (__i386__)
            "CPU x86"
    #elif defined (__arm__)
            "SoC ARMv7"
    #elif defined (__arm64__)
            "SoC ARMv8"
    #endif
            "_\n"
            "*Compiler*: _"
    #if defined (__clang__)
            "CLANG " __clang_version__
    #elif defined (__GNUC__)
            "GCC (GNU C Compiler) " __GNUC__ "." __GNUC_MINOR__
    #else
            "Unknown"
    #endif
            "_\n";

void register_handlers(TgBot::Bot *bot) {
    
    /* WRITE HERE YOUR COMMAND HANDLERS */

    // start command
    bot->getEvents().onCommand("start", [bot](TgBot::Message::Ptr message) {
        log_cmd("start", message->from->username, message->date, LOG::Info);
        bot->getApi().sendMessage(message->chat->id, "Hi!");
    });

    bot->getEvents().onCommand("help", [bot](TgBot::Message::Ptr message) {
        log_cmd("help", message->from->username, message->date, LOG::Info);
        bot->getApi().sendMessage(message->chat->id, HELP_MESSAGE);
    });

    bot->getEvents().onCommand("info", [bot](TgBot::Message::Ptr message) {
        log_cmd("info", message->from->username, message->date, LOG::Info);
        bot->getApi().sendMessage(message->chat->id, INFO_MESSAGE, false, 0, nullptr, PARSE_MODE);
    });

    bot->getEvents().onCommand("ocr", [bot](TgBot::Message::Ptr message) {
        log_cmd("ocr", message->from->username, message->date, LOG::Info);

        TgBot::Message::Ptr reply = message->replyToMessage;
        
        TgBot::File::Ptr file = bot->getApi().getFile(reply->photo[reply->photo.size()-1]->fileId);
#if defined(DEBUG)
        log_cmd("DOWNLOADED FILE", reply->from->username, reply->date, LOG::Debug);
#endif
        std::string fileContent = bot->getApi().downloadFile(file->filePath);
        
        Pix* pixImage = pixReadMem(reinterpret_cast<const l_uint8*>(fileContent.c_str()), fileContent.size());

        if (pixImage == nullptr) {
            log_cmd("Failed to read the image from memory", "PROGRAM", boost::posix_time::to_time_t(boost::posix_time::second_clock::universal_time()), LOG::Error);
            return;
        }

        bot->getApi().sendMessage(message->chat->id, getTextFromImage(pixImage));
    });

}
