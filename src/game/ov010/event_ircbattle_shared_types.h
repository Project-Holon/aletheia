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
#include "../types.h"

struct GameEvent;

struct NetHandle;

/* Argument block of the battle recorder save event (ov008). */
typedef struct BattleRecSaveArgs {
    struct BattleSetupParam *setup;
    void *slotData;
    u32 flag;
} BattleRecSaveArgs;

/* ---- IR battle entry sequence ---- */

/* Argument block of the overlay that picks the party and result (work+0x08). */
typedef struct IrcBattlePickArgs {
    u32 reserved[2];        /* 0x00 */
    u32 repeatFlag;         /* 0x08: in/out, 1 = come back from the detail screen */
    u32 selection;          /* 0x0C: out */
    u32 subSelection;       /* 0x10: out */
    void *gameData;         /* 0x14 */
    u32 unused;             /* 0x18 */
    void *partyList;        /* 0x1C */
} IrcBattlePickArgs;

/* Argument block of the detail overlay (0x14 bytes, heap). */
typedef struct IrcBattleDetailArgs {
    void *gameData;         /* 0x00 */
    void *partyList;        /* 0x04 */
    u16 selection;          /* 0x08 */
    u8 reserved0A;          /* 0x0A */
    u8 subSelection;        /* 0x0B */
    u32 enabled;            /* 0x0C */
    u32 reserved10;         /* 0x10 */
} IrcBattleDetailArgs;

/* Argument block of the battle menu overlay (work+0x60). */
typedef struct IrcBattleMenuArgs {
    void *gameData;         /* 0x00 */
    void *ownParty;         /* 0x04 */
    void *linkParties[4];   /* 0x08 */
    u8 teamByNetId[4];      /* 0x18 */
    u32 mode;               /* 0x1C: in/out */
} IrcBattleMenuArgs;

/* Work of the IR battle entry event task (0xE8 bytes). */
typedef struct IrcBattleEntryWork {
    void *gameSys;                      /* 0x00 */
    void *gameData;                     /* 0x04 */
    IrcBattlePickArgs pickArgs;         /* 0x08 */
    IrcBattleDetailArgs *detailArgs;    /* 0x28 */
    u8 pad2C[0xC];
    void *ownParty;                     /* 0x38 */
    void *linkParties[4];               /* 0x3C */
    void *saveControl;                  /* 0x4C */
    u32 mode;                           /* 0x50: 1..5 battle kind, 6/7/8/12/13 menu results */
    u32 savedBgm;                       /* 0x54 */
    int partyMode;                      /* 0x58 */
    void *recorderArg;                  /* 0x5C */
    IrcBattleMenuArgs menuArgs;         /* 0x60 */
    u8 pad80[8];
    struct BattleSetupParam *setup;     /* 0x88 */
    u8 recorderSlots[0x40];             /* 0x8C */
    u32 reservedCC;                     /* 0xCC */
    u32 ruleCategory;                   /* 0xD0 */
    u32 ruleBase;                       /* 0xD4 */
    u32 ruleOffset;                     /* 0xD8 */
    u32 reservedDC;                     /* 0xDC */
    void *trainerRecord;                /* 0xE0 */
    u32 waitFrames;                     /* 0xE4 */
} IrcBattleEntryWork;

#endif
