#ifndef BTLV_SCD_TYPES_H
#define BTLV_SCD_TYPES_H
/*
 * ov095 battle viewer: the command select view (BTLV_SCD). It owns the touch
 * screen menus of one turn: the action menu (Fight, Bag, Pokemon, Run), the move
 * menu, the target menu and the rotation menu. Each menu is a pair of step
 * functions on a four-entry task stack; the screen itself is drawn by the input
 * module of ov094 through one handle.
 */
#include "../ov093/btl_calc_types.h"

struct BtlMain;
struct BtlPokeCon;
struct BtlParty;
struct BtlPokeParam;
struct BtlvInput;
struct BtlNetCtx;
struct PrintQueue;
struct Strbuf;
struct BtlvCore;
struct BtlvAuxView;

/*
 * One step of a menu task. The state word is the task's own counter (the first
 * argument of the callbacks); the view is the second. Returns nonzero when the
 * step is finished.
 */
typedef int (*BtlvScdStepFn)(int *state, struct BtlvAuxView *view);

/* Task stack depth. */
#define BTLV_SCD_TASK_MAX 4

/*
 * One entry of the task stack (16 bytes). The open step runs first, until it
 * returns nonzero; then the wait step runs until it returns nonzero, which pops
 * the entry. A null step is skipped.
 */
typedef struct BtlvScdTask {
    BtlvScdStepFn openFn;           /* 0x00 */
    BtlvScdStepFn waitFn;           /* 0x04 */
    struct BtlvAuxView *view;       /* 0x08 */
    int state;                      /* 0x0c */
} BtlvScdTask;

/*
 * Positions the player can aim a move at, built by the target menu code:
 * count is the number of listed view positions, altCount and altKind describe
 * the fallback list (altKind 1 or 2) used when count is zero.
 */
typedef struct BtlvTargetSet {
    u8 count;                       /* 0x00 */
    u8 altCount;                    /* 0x01 */
    u8 altKind;                     /* 0x02 */
    u8 viewPos[6];                  /* 0x03 */
} BtlvTargetSet;

/* One Pokemon candidate of the rotation menu (8 bytes). */
typedef struct BtlvRotateCand {
    struct BtlPokeParam *pokeParam; /* 0x00 */
    u8 info[4];                     /* 0x04 */
} BtlvRotateCand;

/* Rotation battle choice: three candidates and the two actions they produce. */
typedef struct BtlvRotateSet {
    BtlvRotateCand cand[3];         /* 0x00 */
    union BtlAction rotateAction;   /* 0x18 */
    union BtlAction fightAction;    /* 0x1c */
} BtlvRotateSet;

/*
 * Auxiliary battle view (0xb4 bytes), created once by BTLV_CORE_Create. The
 * menu code of btlv_scd.c is the only user of the fields after 0x20.
 */
typedef struct BtlvAuxView {
    u8 pad00[8];
    void *fontMain;                 /* 0x08 */
    struct Strbuf *msgBuffer;       /* 0x0c, 0x80 characters */
    struct BtlNetCtx *netCtx;       /* 0x10 */
    struct PrintQueue *printQueue;  /* 0x14 */
    u8 pad18[8];
    BtlvScdTask taskStack[BTLV_SCD_TASK_MAX];  /* 0x20 */
    int taskDepth;                  /* 0x60 */
    u8 pad64[4];
    BtlvScdStepFn reselectFn;       /* 0x68, wait step pushed again after a cancel */
    struct BtlPokeParam *pokeParam; /* 0x6c, Pokemon that chooses */
    union BtlAction *action;        /* 0x70, action being filled in */
    int cursorIndex;                /* 0x74 */
    u8 pad78[4];
    BtlvRotateSet *rotateSet;       /* 0x7c */
    BtlvTargetSet targets;          /* 0x80 */
    u8 targetChosen;                /* 0x89 */
    u8 moveTargetKind;              /* 0x8a, target kind of the selected move */
    u8 canBack;                     /* 0x8b, the Back button is offered */
    s8 slideX;                      /* 0x8c */
    s8 slideY;                      /* 0x8d */
    s8 slideStep;                   /* 0x8e */
    u8 inputFlags;                  /* 0x8f */
    u8 viewParam;                   /* 0x90, "param" argument of BTLV_CORE_Create */
    u8 clientSlot;                  /* 0x91 */
    union {
        u8 raw;
        struct {
            u8 step : 7;
            u8 active : 1;
        } bits;
    } status;                       /* 0x92 */
    u8 choiceStep;                  /* 0x93 */
    int choiceIndex;                /* 0x94 */
    u32 result;                     /* 0x98, result of the last menu */
    struct BtlvCore *core;          /* 0x9c */
    struct BtlMain *mainModule;     /* 0xa0 */
    struct BtlPokeCon *pokeCon;     /* 0xa4 */
    struct BtlParty *ownParty;      /* 0xa8, party of the local client */
    u16 heapId;                     /* 0xac */
    u8 padAE[2];
    struct BtlvInput *input;        /* 0xb0 */
} BtlvAuxView;

/* Screens the input module (ov094) shows, the second argument of its command call. */
#define BTLV_INPUT_SCREEN_CLOSE 0
#define BTLV_INPUT_SCREEN_ACTION 1
#define BTLV_INPUT_SCREEN_MOVE 2
#define BTLV_INPUT_SCREEN_TARGET 3
#define BTLV_INPUT_SCREEN_CHOICE 4
#define BTLV_INPUT_SCREEN_ROTATE 5
#define BTLV_INPUT_SCREEN_COUNTER 6

/* Rows of the action menu payload: one entry per party slot, status in byte 1. */
typedef struct BtlvPartyBall {
    u8 pad00;
    u8 status;                      /* 0 unable, 1 healthy, 2 fainted, 3 afflicted */
    u8 pad02[10];
} BtlvPartyBall;

/* Payload of the action menu screen (200 bytes). */
typedef struct BtlvActionMenuInfo {
    BtlvPartyBall balls[2][6];      /* 0x00, own side then opponent side */
    u32 canBack;                    /* 0x90 */
    u32 hasOpponentParty;           /* 0x94 */
    u32 species[3];                 /* 0x98 */
    u32 monLabel[3];                /* 0xa4 */
    u32 monValue[3];                /* 0xb0 */
    u32 userViewPos;                /* 0xbc */
    u32 viewParam;                  /* 0xc0 */
    u8 clientSlot;                  /* 0xc4 */
    u8 countdown;                   /* 0xc5 */
    u8 padC6[2];
} BtlvActionMenuInfo;

/* Payload of the move menu screen. */
typedef struct BtlvMoveMenuInfo {
    u16 moveId[4];
    u8 pp[4];
    u8 ppMax[4];
    u32 userViewPos;
    u32 transformed;
} BtlvMoveMenuInfo;

/* One row of the target menu payload. */
typedef struct BtlvTargetRow {
    u8 flags;                       /* bits 0-1 gender, bit 2 present */
    u8 state;                       /* 1 healthy, 2 fainted, 3 afflicted */
    u16 pad02;
    s16 hp;
    s16 hpMax;
    u32 monWord;
} BtlvTargetRow;

/* Payload of the target menu screen. */
typedef struct BtlvTargetMenuInfo {
    BtlvTargetRow rows[6];
    u8 userViewPos;
    u8 targetKind;
    u16 pad;
} BtlvTargetMenuInfo;

/* Payload of the rotation menu screen. */
typedef struct BtlvRotateMenuInfo {
    u32 pokeParam[3];
    u32 info[3][4];
} BtlvRotateMenuInfo;

#endif
