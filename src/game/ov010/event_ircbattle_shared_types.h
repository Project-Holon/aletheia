#ifndef EVENT_IRCBATTLE_SHARED_TYPES_H
#define EVENT_IRCBATTLE_SHARED_TYPES_H

#include "../arm9/btl_setup_types.h"

/*
 * Types of this file. Three original files share it:
 *  - an IR battle entry sequence (IrcBattleEntryWork, IRC_BATTLE_ENTRY_Main and the
 *    accessors after it, plus the IrcBattleTask at the end),
 *  - the musical show sequence (musical_event.c: MusicalEventWork),
 *  - the musical dress-up, stage and show-program objects.
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

struct GameEvent;

struct NetHandle;

/* Argument block of the battle recorder save event (ov008). */
typedef struct BattleRecSaveArgs {
    struct BattleSetupParam *setup;
    void *slotData;
    u32 flag;
} BattleRecSaveArgs;

#endif
