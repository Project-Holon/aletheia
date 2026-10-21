#ifndef PLIST_DEMO_TYPES_H
#define PLIST_DEMO_TYPES_H

#include "../types.h"

/* Types of plist_demo.c. The including file defines u8, u16, u32, s16 first and
   includes plist_battle_types.h before this header. */

/* Plate position as two halfwords (the stack slot must stay two halfwords). */
typedef struct PlistPos {
    s16 x;
    s16 y;
} PlistPos;

enum {
    PLIST_SPECIES_SHEDINJA = 292,
    PLIST_SPECIES_GIRATINA = 487,
    PLIST_SPECIES_SHAYMIN = 492
};

enum {
    PLIST_ITEM_GRISEOUS_ORB = 112
};

/* Item record parameter ids (second argument of the item record getter). */
enum {
    PLIST_ITEM_USABLE_ON_PARTY = 14,
    PLIST_ITEM_CURES_SLEEP = 18,      /* the five status cures are in item data order (guess) */
    PLIST_ITEM_CURES_POISON = 19,
    PLIST_ITEM_CURES_BURN = 20,
    PLIST_ITEM_CURES_FREEZE = 21,
    PLIST_ITEM_CURES_PARALYSIS = 22,
    PLIST_ITEM_REVIVES = 26,
    PLIST_ITEM_REVIVES_FULL = 27,
    PLIST_ITEM_RAISES_LEVEL = 28,
    PLIST_ITEM_EVOLVES = 29,
    PLIST_ITEM_RAISES_PP_UPS = 37,
    PLIST_ITEM_MAXES_PP_UPS = 38,
    PLIST_ITEM_RESTORES_PP_ONE = 39,
    PLIST_ITEM_RESTORES_PP_ALL = 40,
    PLIST_ITEM_RESTORES_HP = 41,
    PLIST_ITEM_CHANGES_EV_HP = 42,
    PLIST_ITEM_CHANGES_EV_ATK = 43,
    PLIST_ITEM_CHANGES_EV_DEF = 44,
    PLIST_ITEM_CHANGES_EV_SPEED = 45,
    PLIST_ITEM_CHANGES_EV_SPATK = 46,
    PLIST_ITEM_CHANGES_EV_SPDEF = 47,
    PLIST_ITEM_EV_IGNORES_CAP = 48,
    PLIST_ITEM_FRIENDSHIP_LOW = 49,   /* friendship below 100 */
    PLIST_ITEM_FRIENDSHIP_MID = 50,   /* 100 to 199 */
    PLIST_ITEM_FRIENDSHIP_HIGH = 51,  /* 200 and above */
    PLIST_ITEM_EV_HP_AMOUNT = 52,
    PLIST_ITEM_EV_ATK_AMOUNT = 53,
    PLIST_ITEM_EV_DEF_AMOUNT = 54,
    PLIST_ITEM_EV_SPEED_AMOUNT = 55,
    PLIST_ITEM_EV_SPATK_AMOUNT = 56,
    PLIST_ITEM_EV_SPDEF_AMOUNT = 57,
    PLIST_ITEM_HP_AMOUNT = 58,
    PLIST_ITEM_PP_AMOUNT = 59,
    PLIST_ITEM_FRIENDSHIP_LOW_AMOUNT = 60,
    PLIST_ITEM_FRIENDSHIP_MID_AMOUNT = 61,
    PLIST_ITEM_FRIENDSHIP_HIGH_AMOUNT = 62
};

#endif
