#ifndef PLIST_BATTLE_TYPES_H
#define PLIST_BATTLE_TYPES_H

#include "../types.h"

/* Types of plist_battle.c and plist_demo.c (party list screen): the team panel and
   mini-icon cell records, and the party member parameter ids the code passes to the
   parameter getters. The including file defines u8, u16, u32 and includes
   pokelist_types.h first. */

/* One team panel (PLIST_BATTLE_CreateTeamPanel): a name window and six mini cells. */
struct BmpWin;
typedef struct PlistMiniCell PlistMiniCell;
typedef struct PlistTeamPanel {
    u32 active;                       /* 0x00: windows are open */
    struct BmpWin *nameWindow;        /* 0x04 */
    PlistMiniCell *cells[6];          /* 0x08 */
} PlistTeamPanel;

/* Party and name of one panel, as passed to CreateTeamPanel. */
typedef struct PlistTeamSource {
    void *party;
    const u16 *name;
} PlistTeamSource;

/* One mini cell: party member icon, held item mark, sex and level windows. */
struct PlistMiniCell {
    u32 active;                       /* 0x00 */
    struct BmpWin *sexWindow;         /* 0x04: sex mark */
    struct BmpWin *levelWindow;       /* 0x08 */
    u32 iconRes;                      /* 0x0C */
    struct ClactActor *iconActor;                    /* 0x10 */
    struct ClactActor *itemMarkActor;                /* 0x14 */
};

typedef struct PlistActorParam {
    u16 x;
    u16 y;
    u16 animNo;
    u8 softPriority;
    u8 bgPriority;
} PlistActorParam;

/* Party member parameter ids (second argument of the parameter getter and setter). */
enum {
    PLIST_MON_SPECIES = 5,
    PLIST_MON_HELD_ITEM = 6,
    PLIST_MON_EXP = 8,
    PLIST_MON_FRIENDSHIP = 9,
    PLIST_MON_EV_HP = 13,
    PLIST_MON_EV_ATK = 14,
    PLIST_MON_EV_DEF = 15,
    PLIST_MON_EV_SPEED = 16,
    PLIST_MON_EV_SPATK = 17,
    PLIST_MON_EV_SPDEF = 18,
    PLIST_MON_MOVE_ID = 0x36,         /* + move slot */
    PLIST_MON_MOVE_PP = 0x3A,         /* + move slot */
    PLIST_MON_MOVE_PP_UPS = 0x3E,     /* + move slot */
    PLIST_MON_EGG_FLAG = 0x4C,
    PLIST_MON_SPECIAL_FLAG = 0x6D,    /* must be 1 for the Shaymin form change */
    PLIST_MON_SEX = 0x6E,
    PLIST_MON_FORM = 0x6F,
    PLIST_MON_STATUS = 0x9D,
    PLIST_MON_LEVEL = 0x9E,
    PLIST_MON_HP = 0xA0,
    PLIST_MON_MAX_HP = 0xA1
};

#endif
