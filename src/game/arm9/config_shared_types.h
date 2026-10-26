#ifndef CONFIG_SHARED_TYPES_H
#define CONFIG_SHARED_TYPES_H

#include "../types.h"

/* Player options: one u16 of packed settings plus two reserved bytes. */
struct Config {
    u16 text_speed   : 4;
    u16 sound_mode   : 2;
    u16 battle_style      : 1;
    u16 battle_scene      : 1;
    u16 textLanguage     : 1;
    u16 button_mode      : 1;
    u16 battle_flag     : 1;
    u16 window_frame : 5;
    u16 reserved;
};

/* The 0x20-byte player record.  The name is eight u16 characters; the other
 * fields are only read and written as scalars. */
#include "../arm9/mystatus_types.h"

#endif
