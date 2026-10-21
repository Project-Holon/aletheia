#ifndef PLIST_PLATE_TYPES_H
#define PLIST_PLATE_TYPES_H

/* Party list screen: the plate drawn for one party slot (allocated by
   PLIST_PLATE_Create, 0x44 bytes) and the small structs only plist_plate.c uses.
   The including file defines u8, u16, u32, s8, s16 and includes pokelist_types.h first. */

struct ClactActor;
struct Unit;
struct Descriptor;

/* Values the plate reads with POKE_TOOL_GetPartyValue; same ids as enum PokeToolParam in poke_tool.c. */
enum {
    POKE_TOOL_PARAM_SPECIES = 0x05,
    POKE_TOOL_PARAM_HELD_ITEM = 0x06,
    POKE_TOOL_PARAM_IS_EGG = 0x4C,
    POKE_TOOL_PARAM_GENDER = 0x6E,
    POKE_TOOL_PARAM_HP = 0xA0,
    POKE_TOOL_PARAM_MAX_HP = 0xA1,
    POKE_TOOL_PARAM_NICKNAME_NOT_DEFAULT_NIDORAN = 0xAD
};

/* Message ids of the plate bank (gSpeciesNameBank). */
enum {
    PLIST_PLATE_MSG_GENDER_MALE = 7,
    PLIST_PLATE_MSG_GENDER_FEMALE = 8,
    PLIST_PLATE_MSG_NOT_ELIGIBLE = 0x81,
    PLIST_PLATE_MSG_ELIGIBLE = 0x82,
    PLIST_PLATE_MSG_ORDER_FIRST = 0x83,   /* + order index 0..5 */
    PLIST_PLATE_MSG_TEACH_ABLE = 0x89,
    PLIST_PLATE_MSG_TEACH_KNOWN = 0x8A,
    PLIST_PLATE_MSG_TEACH_NOT_ABLE = 0x8B,
    PLIST_PLATE_MSG_EVOLVE_ABLE = 0x8C,
    PLIST_PLATE_MSG_EVOLVE_NOT_ABLE = 0x8D,
    PLIST_PLATE_MSG_EGG = 0x28A
};

/* PokelistArg.mode values the plate tests. */
enum {
    PLIST_PLATE_MODE_BATTLE_ORDER = 6,
    PLIST_PLATE_MODE_EVOLVE_ITEM = 0x10
};

/* PokelistWork.phase values that mark a slot being swapped or healed. */
enum {
    PLIST_PLATE_PHASE_SWAP = 3,
    PLIST_PLATE_PHASE_HEAL = 4
};

/* What the label area of a plate shows (PlistPlate.labelState). 0..5: order index. */
enum {
    PLIST_PLATE_LABEL_NOT_ELIGIBLE = 6,
    PLIST_PLATE_LABEL_ELIGIBLE = 7,
    PLIST_PLATE_LABEL_NONE = 8
};

/* Result of PLIST_PLATE_GetHpBarColor (hp gauge colour class). */
enum {
    PLIST_PLATE_HPBAR_RED = 0,
    PLIST_PLATE_HPBAR_YELLOW = 1,
    PLIST_PLATE_HPBAR_GREEN = 2,
    PLIST_PLATE_HPBAR_FULL = 3
};

typedef struct PlistPlate {
    void *mon;                       /* 0x00 */
    u8 slot;                         /* 0x04: party slot, also the screen position index */
    u8 pad05;
    u16 hp;                          /* 0x06: hp shown (counts toward targetHp) */
    u16 targetHp;                    /* 0x08 */
    u8 pad0A[2];
    int isEgg;                       /* 0x0C */
    int selected;                    /* 0x10 */
    int isEmpty;                     /* 0x14: empty slot plate, owns no actors */
    int textPending;                 /* 0x18: text printed, waiting for the print to finish */
    int labelState;                  /* 0x1C */
    struct Descriptor *window;       /* 0x20 */
    struct ClactActor *clactUnit;           /* 0x24 */
    struct Unit *clactBank;          /* 0x28 */
    s32 iconResource;                /* 0x2C */
    struct ClactActor *monIconActor;        /* 0x30 */
    struct ClactActor *frameActor;          /* 0x34 */
    struct ClactActor *hpBarActor;          /* 0x38 */
    struct ClactActor *itemIconActor;       /* 0x3C */
    struct ClactActor *statusIconActor;     /* 0x40 */
} PlistPlate;
typedef char PlistPlate_SizeCheck[(sizeof(PlistPlate) == 0x44) ? 1 : -1];

/* Screen rectangle in pixels. */
typedef struct PlistPlateRect {
    u8 top;
    u8 bottom;
    u8 left;
    u8 right;
} PlistPlateRect;

/* Position pair for a plate or an actor. */
typedef struct PlistPlatePos {
    s16 x;
    s16 y;
} PlistPlatePos;

/* Screen area the plate actor unit covers, with its offset. */
typedef struct PlistPlateSurface {
    s16 offsetX;                     /* 0x00 */
    s16 offsetY;                     /* 0x02 */
    u16 areaLeft;                    /* 0x04 */
    u16 areaTop;                     /* 0x06 */
    u16 areaWidth;                   /* 0x08 */
    u16 areaHeight;                  /* 0x0A */
    int priority;                    /* 0x0C */
    int bgPriority;                  /* 0x10 */
} PlistPlateSurface;

/* Actor creation parameters (CLACT_CreateActor). */
typedef struct PlistPlateActorSpec {
    u16 x;
    u16 y;
    u16 depth;
    u8 animation;
    u8 bgPriority;
} PlistPlateActorSpec;

#endif
