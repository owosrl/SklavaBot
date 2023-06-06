#ifndef HPP_COMMANDS
#define HPP_COMMANDS

#include <tgbot/tgbot.h>


/**
 * register_handlers(*bot)
 * @brief Register all the handlers for bot commands
 *
 * @param *bot Pointer to TgBot::Bot object
 * @return void
 */
void register_handlers(TgBot::Bot *bot);

#endif
