#ifndef SCRCMD_MUSICAL_SHARED_TYPES_H
#define SCRCMD_MUSICAL_SHARED_TYPES_H

#include "../arm9/script_vm_types.h"

struct GameSystem;

struct GameData;

struct GameEvent;

struct FieldMap;

struct MyStatus;

struct SaveControl;

struct PokeParty;

struct Pokemon;

struct MapObject;

struct FieldSkillInfo;

typedef signed int s32;

/* Event task callback: (task, state, work). */
typedef int (*EventTaskFn)(struct GameEvent *task, u32 *state, void *work);

/* Field skill (hidden move) context filled by MOVE_POKEMON_InitSkillInfo (0x14 bytes). */
typedef struct FieldSkillInfo {
    u16 zoneId;                           /* 0x00 */
    u16 usableMask;                       /* 0x02: bit per skill */
    u32 playerState;                      /* 0x04 */
    struct GameSystem *gameSys;           /* 0x08 */
    struct MapObject *playerObj;          /* 0x0C */
    struct FieldMap *fieldMap;            /* 0x10 */
} FieldSkillInfo;

typedef struct SkillTarget {
    u16 id;                               /* 0x00 */
    u16 variant;                          /* 0x02 */
    u32 targetObj;                        /* 0x04 */
} SkillTarget;

typedef struct GameEvent *(*SkillEventFn)(SkillTarget *target, FieldSkillInfo *info);

#endif
