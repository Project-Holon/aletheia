#ifndef GAME_ARM9_MYSTATUS_TYPES_H
#define GAME_ARM9_MYSTATUS_TYPES_H

#include "../types.h"

/*
 * The 0x20-byte player record (MyStatus). GAME_DATA returns the address of
 * PlayerWork.status as the player's status (GAME_DATA_GetMyStatus,
 * GAME_DATA_GetMyStatusPlayer); the player work constructor clears id,
 * language and sex.  The name is eight u16 characters.
 */
struct MyStatus {
    u16 name[8];
    u32 id;
    u32 profile_id;
    u8  nation;
    u8  area;
    u8  language;
    u8  rom_code;
    u8  trainer_view;
    u8  sex;
};

#endif
