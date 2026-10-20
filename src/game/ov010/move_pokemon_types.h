#ifndef GAME_OV010_MOVE_POKEMON_TYPES_H
#define GAME_OV010_MOVE_POKEMON_TYPES_H

#include "../types.h"

struct GameSystem;
struct Mmdl;
struct FieldMap;

/* Field skill (hidden move) context filled by MOVE_POKEMON_InitSkillInfo (0x14 bytes). */
typedef struct FieldSkillInfo {
    u16 zoneId;                           /* 0x00 */
    u16 usableMask;                       /* 0x02: bit per skill */
    u32 playerState;                      /* 0x04 */
    struct GameSystem *gameSys;           /* 0x08 */
    struct Mmdl *playerObj;               /* 0x0C */
    struct FieldMap *fieldMap;            /* 0x10 */
} FieldSkillInfo;

#endif
