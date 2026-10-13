#ifndef POKELIST_TYPES_H
#define POKELIST_TYPES_H

/* Party Pokemon list screen: the work area allocated in POKELIST_Init (0x284 bytes)
   and the argument block it points to. The including file defines u8, u16, u32 first.
   Handles are kept as int/u32 (the original code passed them to both int and pointer
   parameters). Layout from the census of pokelist.c; the plist_* files may name more. */

struct Obj;
struct Bank;
struct PlistPlate;
struct PokelistWork;
typedef void (*PokelistFn)(struct PokelistWork *work);
typedef void (*PokelistMenuFn)(struct PokelistWork *work, int choice);

typedef struct PokelistBlend {
    u16 v[3];
} PokelistBlend;

/* Partial view of the battle regulation record (see Regulation in poke_regulation.c). */
typedef struct PokelistRegulation {
    u8 cupNo;                         /* 0x00 */
    u8 ruleNo;                        /* 0x01 */
    u8 minPartySize;                  /* 0x02 */
    u8 maxPartySize;                  /* 0x03 */
    u8 level;                         /* 0x04 */
    u8 levelRange;                    /* 0x05 */
    u16 levelTotal;                   /* 0x06 */
    u8 allowSameSpecies;              /* 0x08 */
    u8 allowSameItem;                 /* 0x09 */
    u8 pad0A[0x9E];
    u16 mustPoke;                     /* 0xA8 */
} PokelistRegulation;

typedef struct PokelistRivalEntry {
    void *party;                      /* 0x00: party built for one opponent slot */
    u16 *name;                        /* 0x04: 6-entry name string */
    u8 gender;                        /* 0x08: random 0 or 1 */
} PokelistRivalEntry;

typedef struct PokelistArg {
    void *party;                      /* 0x00 */
    void *bag;                        /* 0x04: bag item pocket table */
    void *mailBox;                    /* 0x08: mail table (Sub02008F80Obj array) */
    u8 pad0C[8];
    PokelistRegulation *regulation;   /* 0x14: freed in Exit */
    void *zukanSave;                  /* 0x18: pokedex save block (form registration) */
    u8 fieldMoveParam[0x14];          /* 0x1C: passed with the move index to the field move check */
    u16 itemUseParam;                 /* 0x30 */
    u8 pad32[2];
    int mode;                         /* 0x34: list mode (0 normal, 1 item, 5, 0x16..0x1A ...) */
    u8 pad38[4];
    int selectedIndex;                /* 0x3C */
    int exitCode;                     /* 0x40 */
    u16 itemId;                       /* 0x44 */
    u16 moveId;                       /* 0x46 */
    u8 moveSlot;                      /* 0x48 */
    u8 slotOrder[6];                  /* 0x49: selection order per party slot */
    u8 pad4F[1];                      /* old plist_menu.c code indexes pad4F[1] for 0x50 */
    u32 levelUpCursor;                /* 0x50 */
    u8 pad54[8];
    u16 mailSlot;                      /* 0x5C: mail table slot */
    union {
        u8 pad5E[1];                  /* old code indexes pad5E[1] for 0x5F */
        u8 learnableFlags;            /* 0x5E: bit per party slot that can learn the move */
    };
    u8 season;                        /* 0x5F */
    u16 timeLeft;                     /* 0x60 */
    u8 pad62;
    u8 closeRequested;                /* 0x63 */
    int battleKind;                   /* 0x64 */
    PokelistRivalEntry entries[3];    /* 0x68, stride 12 */
    int timerShown;                   /* 0x8C */
    int timerRunning;                 /* 0x90 */
    u8 timerExpired;                  /* 0x94 */
    u8 pad95[3];
} PokelistArg;
typedef char PokelistArg_SizeCheck[(sizeof(PokelistArg) == 0x98) ? 1 : -1];

typedef struct PokelistWork {
    u16 heapId;                       /* 0x000 */
    u8 pad02[2];
    int updateTask;                   /* 0x004 */
    int touchMode;                    /* 0x008: input mode restored with func_020355D8 */
    u8 phase;                         /* 0x00C: Update switch state */
    u8 nextPhase;                     /* 0x00D */
    u8 inputStage;                    /* 0x00E */
    u8 command;                       /* 0x00F */
    int fadeMode;                     /* 0x010 */
    int switchButtonEnabled;          /* 0x014 */
    int restoreMode18;                /* 0x018 */
    int restoreMode19;                /* 0x01C */
    int restoreMode1A;                /* 0x020 */
    int healSoundPending;             /* 0x024 */
    int allowDisabledSelect;          /* 0x028 */
    int selectedSlot;                 /* 0x02C */
    int swapSourceSlot;               /* 0x030 */
    int healSourceSlot;               /* 0x034 */
    u32 selectedMon;                  /* 0x038 */
    int menuChoice;                   /* 0x03C: last context menu choice (0x17 = none yet) */
    u16 palSrc[3][16];                /* 0x040 */
    u16 palDst[3][16];                /* 0x0A0 */
    u8 fadeStep;                      /* 0x100 */
    u8 pad101;
    u16 fadePhase;                    /* 0x102 */
    u8 swapAnimStep;                  /* 0x104: plate slide step of the swap animation */
    u8 selectedCount;                 /* 0x105 */
    u8 pad106[2];
    int commandButtons[2];            /* 0x108 */
    u16 reservedCounter;              /* 0x110 */
    u8 pad112[2];
    u8 waitFrames;                    /* 0x114 */
    u8 pad115[3];
    int selectionConfirmed;           /* 0x118 */
    u16 cursorState;                  /* 0x11C */
    signed char hpStep;               /* 0x11E: hp count-up step */
    u8 pad11F;
    PokelistFn phaseCallback;         /* 0x120 */
    union {
        u8 pad124[0xC];
        u16 levelUpMoveStat[6];       /* 0x124 */
    };
    int descriptor;                   /* 0x130 */
    void *msgBank;                    /* 0x134 */
    void *fontMain;                   /* 0x138 */
    void *fontSub;                    /* 0x13C */
    void *printSys;                   /* 0x140 */
    int messageWaitKey;               /* 0x144: message waits for a key press */
    PokelistFn messageDoneCallback;   /* 0x148: called when the message ends */
    PokelistMenuFn menuChoiceCallback; /* 0x14C: called with the choice of the open menu */
    u32 messageWindow;                /* 0x150 */
    u32 contextMenu;                  /* 0x154 */
    void *paletteFile;                /* 0x158 */
    void *paletteData;                /* 0x15C */
    struct PlistPlate *plates[6];                    /* 0x160 */
    int charRes[8];                   /* 0x178 */
    int palRes[7];                    /* 0x198 */
    int cellRes[8];                   /* 0x1B4 */
    struct Bank *clactUnit;                    /* 0x1D4 */
    struct Obj *cursorActor;                  /* 0x1D8 */
    struct Obj *swapMarkerActor;              /* 0x1DC */
    struct Obj *backButtonActor;              /* 0x1E0 */
    struct Obj *switchButtonActor;            /* 0x1E4 */
    struct Obj *pressedButtonActor;           /* 0x1E8 */
    union {
        u8 pad1EC[0x64];
        struct {
            void *actorSystem;            /* 0x1EC: owner of the party list actors */
            int timerDigit[3];            /* 0x1F0 */
            void *timerLabelWindow;       /* 0x1FC: "time left" caption */
            void *timerValueWindow;       /* 0x200: minutes and seconds */
            int timerLabelPrinting;       /* 0x204: caption print still running */
            int timerValuePrinting;       /* 0x208: value print still running */
            u8 timerShown;                /* 0x20C: copy of PokelistArg.timerExpired */
            u8 shownSeconds;              /* 0x20D: time left shown in the value window */
            u16 timerPalSrc[16];          /* 0x20E */
            u16 timerPalDst[16];          /* 0x22E */
            u16 timerPalPhase;            /* 0x24E: frame in the 60 frame pulse */
        };
    };
    int touchDragState;               /* 0x250 */
    int taskMenu;                     /* 0x254 */
    int light;                        /* 0x258 */
    void *particleMemory;             /* 0x25C */
    void *particleSystem;             /* 0x260 */
    u32 evolveCheckKind;              /* 0x264 */
    u8 effectFrame;                   /* 0x268 */
    u8 effectLength;                  /* 0x269 */
    u8 pad26A[2];
    u32 effectStarted;                /* 0x26C */
    u32 cryStarted;                   /* 0x270 */
    u32 cryHandle;                    /* 0x274 */
    int reservedWord;                 /* 0x278 */
    u8 pad27C[4];
    PokelistArg *arg;                 /* 0x280 */
} PokelistWork;
typedef char PokelistWork_SizeCheck[(sizeof(PokelistWork) == 0x284) ? 1 : -1];

#endif
