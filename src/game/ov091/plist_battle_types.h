#ifndef PLIST_BATTLE_TYPES_H
#define PLIST_BATTLE_TYPES_H

/* Types of plist_battle.c and plist_demo.c (party list screen): the work area and
   argument block with the fields these two files use named at their offsets, the team
   panel and mini-icon cell records, and the party member and item parameter ids the
   code passes to the parameter getters. The including file defines u8, u16, u32 first.
   The work layout is the same 0x284 block as PokelistWork (pokelist_types.h); names
   for the shared offsets are the same there. */

typedef struct PlistArg {
    void *party;                      /* 0x00 */
    u8 pad04[4];
    void *bag;                        /* 0x08 */
    u8 pad0C[8];
    void *regulation;                 /* 0x14 */
    void *zukanSave;                  /* 0x18: pokedex save block (form registration) */
    u8 pad1C[0x14];
    u16 itemUseParam;                 /* 0x30 */
    u8 pad32[2];
    int mode;                         /* 0x34: list mode (0 normal) */
    u8 pad38[4];
    int selectedIndex;                /* 0x3C */
    int exitCode;                     /* 0x40 */
    u8 pad44[0x1B];
    u8 season;                        /* 0x5F: index for the daytime window table */
    u16 timeLeft;                     /* 0x60 */
    u8 pad62;
    u8 closeRequested;                /* 0x63 */
    int battleKind;                   /* 0x64 */
    u8 pad68[0x10];
    u16 *rivalName;                   /* 0x78: opponent name string (entries[1].name) */
    u8 rivalGender;                   /* 0x7C: entries[1].gender */
    u8 pad7D[3];
    u8 pad80[0xC];
    int timerShown;                   /* 0x8C */
    int timerRunning;                 /* 0x90 */
    u8 timerExpired;                  /* 0x94 */
    u8 pad95[3];
} PlistArg;
typedef char PlistArg_SizeCheck[(sizeof(PlistArg) == 0x98) ? 1 : -1];

typedef struct PlistWork {
    u16 heapId;                       /* 0x000 */
    u8 pad02[2];
    u8 pad04[8];
    u8 phase;                         /* 0x00C: Update switch state */
    u8 pad0D[0x1F];
    int selectedSlot;                 /* 0x02C */
    u8 pad30[8];
    u32 selectedMon;                  /* 0x038 */
    u8 pad3C[0xF8];
    void *msgBank;                    /* 0x134 */
    u32 fontMain;                     /* 0x138 */
    u8 pad13C[4];
    void *printSys;                   /* 0x140 */
    u8 pad144[0xC];
    u32 messageWindow;                /* 0x150 */
    u8 pad154[0xC];
    int plates[6];                    /* 0x160 */
    int charRes[8];                   /* 0x178 */
    int palRes[7];                    /* 0x198 */
    int cellRes[8];                   /* 0x1B4 */
    u8 pad1D4[0x18];
    void *actorSystem;                /* 0x1EC: owner of the party list actors */
    u8 pad1F0[0xC];
    void *timerLabelWindow;           /* 0x1FC: "time left" caption */
    void *timerValueWindow;           /* 0x200: minutes and seconds */
    int timerLabelPrinting;           /* 0x204: caption print still running */
    int timerValuePrinting;           /* 0x208: value print still running */
    u8 timerShown;                    /* 0x20C: copy of PlistArg.timerExpired */
    u8 shownSeconds;                  /* 0x20D: time left shown in the value window */
    u16 timerPalSrc[16];              /* 0x20E */
    u16 timerPalDst[16];              /* 0x22E */
    u16 timerPalPhase;                /* 0x24E: frame in the 60 frame pulse */
    u8 pad250[0xC];
    void *particleMemory;             /* 0x25C */
    void *particleSystem;             /* 0x260 */
    u32 evolveCheckKind;              /* 0x264 */
    u8 effectFrame;                   /* 0x268 */
    u8 effectLength;                  /* 0x269 */
    u8 pad26A[2];
    u32 effectStarted;                /* 0x26C */
    u32 cryStarted;                   /* 0x270 */
    u32 cryHandle;                    /* 0x274 */
    u8 pad278[8];
    PlistArg *arg;                    /* 0x280 */
} PlistWork;
typedef char PlistWork_SizeCheck[(sizeof(PlistWork) == 0x284) ? 1 : -1];

/* One team panel (PLIST_BATTLE_CreateTeamPanel): a name window and six mini cells. */
typedef struct PlistMiniCell PlistMiniCell;
typedef struct PlistTeamPanel {
    u32 active;                       /* 0x00: windows are open */
    u32 nameWindow;                   /* 0x04 */
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
    u32 sexWindow;                    /* 0x04: sex mark */
    u32 levelWindow;                  /* 0x08 */
    u32 iconRes;                      /* 0x0C */
    u32 iconActor;                    /* 0x10 */
    u32 itemMarkActor;                /* 0x14 */
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
