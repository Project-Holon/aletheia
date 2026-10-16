#ifndef CONFIG_SHARED_TYPES_H
#define CONFIG_SHARED_TYPES_H

typedef unsigned char      u8;

typedef unsigned short     u16;

typedef unsigned int       u32;

/* Player options: one u16 of packed settings plus two reserved bytes. */
struct Config {
    u16 text_speed   : 4;
    u16 sound_mode   : 2;
    u16 battle_style      : 1;
    u16 battle_scene      : 1;
    u16 applied_flag      : 1;
    u16 button_mode      : 1;
    u16 battle_flag     : 1;
    u16 window_frame : 5;
    u16 reserved;
};

/* The 0x20-byte player record.  The name is eight u16 characters; the other
 * fields are only read and written as scalars. */
struct MyStatus {
    u16 name[8];
    u32 id;
    u32 profile_id;
    u8  language;
    u8  version;
    u8  gender;
    u8  avatar_id;
    u8  outfit;
    u8  outfit_variant;
};

#endif
