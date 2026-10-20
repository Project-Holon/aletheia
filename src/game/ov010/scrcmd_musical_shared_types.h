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

#include "../types.h"

/* Event task callback: (task, state, work). */
typedef int (*EventTaskFn)(struct GameEvent *task, u32 *state, void *work);

#include "../ov010/move_pokemon_types.h"

typedef struct SkillTarget {
    u16 id;                               /* 0x00 */
    u16 variant;                          /* 0x02 */
    u32 targetObj;                        /* 0x04 */
} SkillTarget;

typedef struct GameEvent *(*SkillEventFn)(SkillTarget *target, FieldSkillInfo *info);

#endif
