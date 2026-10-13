#ifndef BTLV_CORE_TYPES_H
#define BTLV_CORE_TYPES_H

#include "btlv_scu_types.h"

/* Opaque types owned by other files of the battle code. */
struct BtlClient;
struct MyItemSave;
struct BtlvAuxView;

struct BtlvCore;

/* One state step of a core procedure: returns nonzero when done. */
typedef int (*BtlvCoreProc)(int *state, struct BtlvCore *core);

/*
 * Step function of the menu runner: returns nonzero when the step is finished.
 * The state pointer is &core->stepState, the work pointer is core->task.work.
 */
typedef int (*BtlvCoreStepFn)(struct BtlvCore *core, int *state, void *work);

/*
 * Message record the battle code builds for the view: a message id, a text
 * speed parameter, a kind that selects the formatter, and up to 8 arguments.
 * btlv_scu.c keeps a copy of this layout.
 */
enum BtlvMessageKind {
    BTLV_MSG_KIND_SIDE = 1,
    BTLV_MSG_KIND_TAGGED = 2,
    BTLV_MSG_KIND_UI = 3,
    BTLV_MSG_KIND_ITEM_USE = 4,
    BTLV_MSG_KIND_UI_ARGS = 5,
    BTLV_MSG_KIND_TRAINER = 6,
    BTLV_MSG_KIND_PLAIN = 7
};

struct BtlvMessage {
    u16 msgId;
    u8 param;
    u8 kind : 4;
    u8 argCount : 4;
    u32 args[8];
};

/* Work area of a damage effect request (12 bytes). */
struct BtlvCoreDamageWork {
    u16 animId;
    u16 reserved02;
    int effectiveness;
    u16 step;
    u8 slot;
};

/* Work area of a multi-target damage effect request (20 bytes). */
struct BtlvCoreMultiDamageWork {
    u8 slots[6];
    u8 count;
    u8 reserved07;
    u16 step;
    u8 reserved0A[2];
    int effectiveness;
    u16 animId;
};

/* Work area of a mon swap request (4 bytes). */
struct BtlvCoreSwapWork {
    u8 slot;
    u8 clientId;
    u8 pokeIdx;
    u8 pokeId;
};

/* Work area of a rotation request (7 bytes). */
struct BtlvCoreRotationWork {
    u8 clientId;
    u8 rotateA;
    u8 rotateB;
    u8 posA;
    u8 posB;
    u8 monSlotA;
    u8 monSlotB;
};

/* Request block for the counter display of the aux view (0x10 bytes at 0x160). */
typedef struct BtlvCounterCmd {
    u32 current;                /* 0x00 */
    u32 target;                 /* 0x04 */
    u32 commandWord;            /* 0x08 queued command word of a remote client */
    u32 mode;                   /* 0x0C */
} BtlvCounterCmd;

/* Scratch block of BTLV_CORE_StartClearSidePosition (8 bytes in the task work area). */
typedef struct BtlvClearSideWork {
    u8 clientId;
    u8 kind;
    u8 viewPos[3];
    u8 monSlot[3];
} BtlvClearSideWork;

/* Scratch block of BTLV_CORE_StartYesNoMenu (12 bytes in the task work area). */
typedef struct BtlvYesNoWork {
    void *yesText;
    void *noText;
    u32 mode;
} BtlvYesNoWork;

/* Bag screen work (ov197), embedded at 0xC8 of BtlvCore. */
typedef struct BtlvBagWork {
    void *myItem;               /* 0x00 player bag */
    void *fontMain;             /* 0x04 */
    int isComm;                 /* 0x08 */
    u16 heapId;                 /* 0x0C */
    u8 reserved0E[2];
    void *regulationRules;      /* 0x10 */
    u8 pointCounter;            /* 0x14 */
    u8 lastItem;                /* 0x15 */
    u16 selectedItem;           /* 0x16 */
    u8 selectedItemPocket;      /* 0x18 */
    u8 done;                    /* 0x19 nonzero once an item was picked or the screen closed */
    u8 reserved1A[2];
    struct MyItemSave *myItemSave; /* 0x1C receives the pocket cursors and the last used item */
    int skipPartyPrompt;        /* 0x20 */
    int cursorPos;              /* 0x24 */
    u8 buttonMode;              /* 0x28 */
    u8 isWildBattle;            /* 0x29 */
    u8 selectedItemPage;        /* 0x2A */
    u8 reserved2B;
    int auxViewHandle;          /* 0x2C */
    s16 pocketCursorPos[4];     /* 0x30 */
    s16 pocketScrollPos[4];     /* 0x38 */
    int allowBag;               /* 0x40 */
} BtlvBagWork;

/* Party / move-list screen work (ov198), embedded at 0x10C of BtlvCore. */
typedef struct BtlvPlistWork {
    void *gameData;             /* 0x00 */
    void *party;                /* 0x04 */
    void *partnerParty;         /* 0x08 */
    void *fontMain;             /* 0x0C */
    u16 heapId;                 /* 0x10 */
    u8 reserved12[2];
    u32 rule;                   /* 0x14 */
    int isCommMulti;            /* 0x18 */
    u8 isSecondTeam;            /* 0x1C */
    u8 chosenSlots[2];          /* 0x1D */
    u8 mode;                    /* 0x1F */
    u8 modeSlot;                /* 0x20 */
    u8 slot;                    /* 0x21 */
    u8 positionsPerClient;      /* 0x22 */
    u8 reserved23;
    u16 itemId;                 /* 0x24 */
    u16 modeParam;              /* 0x26 can-cancel flag of party picks, move id of the move-learn mode */
    void *effectSys;            /* 0x28 */
    void *effectSysAux;         /* 0x2C */
    int choiceLocked;           /* 0x30 nonzero: picks are not copied to choiceFlags */
    int exitFlag;               /* 0x34 */
    u8 sickFlags[6];            /* 0x38 */
    u8 reserved3E[2];
    int allowBag;               /* 0x40 */
    int auxViewHandle;          /* 0x44 */
    u8 pickedSlots[3];          /* 0x48 */
    u8 result;                  /* 0x4B */
    u8 done;                    /* 0x4C */
    u8 reserved4D[3];
} BtlvPlistWork;

/*
 * Request slot of the core: a pre procedure that runs first and clears itself,
 * then a main procedure, both stepped with the same state counter. The work
 * area holds the request data (and the work of the menu step functions).
 */
typedef struct BtlvCoreTask {
    BtlvCoreProc preProc;           /* 0x1C */
    BtlvCoreProc mainProc;          /* 0x20 */
    struct BtlvCore *procCore;      /* 0x24 */
    int procState;                  /* 0x28 */
    u8 work[0x80];                  /* 0x2C */
} BtlvCoreTask;

/* Battle view core (0x188 bytes, allocated by BTLV_CORE_Create in btlv_core.c). */
struct BtlvCore {
    struct BtlContext *context;     /* 0x000 */
    struct BtlClient *client;       /* 0x004 */
    struct BtlMonTable *monTable;   /* 0x008 */
    u8 clientIndex;                 /* 0x00C */
    u8 reserved0D[3];
    int state;                      /* 0x010 */
    BtlvCoreStepFn stepFn;          /* 0x014 current menu step, zero when idle */
    int stepState;                  /* 0x018 */
    BtlvCoreTask task;              /* 0x01C */
    struct MsgBuf *msgBuffer;       /* 0x0AC */
    void *fontMain;                 /* 0x0B0 */
    void *fontSub;                  /* 0x0B4 */
    u8 *actionCursor;               /* 0x0B8 */
    struct BtlPokeParam *pokeParam; /* 0x0BC */
    u32 pokeId;                     /* 0x0C0 */
    int actionResult;               /* 0x0C4 */
    BtlvBagWork bag;                /* 0x0C8 */
    BtlvPlistWork plist;            /* 0x10C */
    u8 *choiceFlags;                /* 0x15C */
    BtlvCounterCmd counterCmd;      /* 0x160 */
    u32 *entry;                     /* 0x170 */
    u8 subStep;                     /* 0x174 step of whichever menu sub-screen runs */
    u8 canBack;                     /* 0x175 */
    u8 reserved176[2];
    void *taskList;                 /* 0x178 */
    struct BtlvScu *sceneUnit;      /* 0x17C */
    struct BtlvAuxView *auxView;    /* 0x180 */
    u16 heapId;                     /* 0x184 */
    u8 reserved186[2];
};

typedef char BtlvBagWork_SizeCheck[(sizeof(BtlvBagWork) == 0x44) ? 1 : -1];
typedef char BtlvPlistWork_SizeCheck[(sizeof(BtlvPlistWork) == 0x50) ? 1 : -1];
typedef char BtlvCoreTask_SizeCheck[(sizeof(BtlvCoreTask) == 0x90) ? 1 : -1];
typedef char BtlvCore_SizeCheck[(sizeof(struct BtlvCore) == 0x188) ? 1 : -1];

#endif
