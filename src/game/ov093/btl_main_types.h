#ifndef BTL_MAIN_TYPES_H
#define BTL_MAIN_TYPES_H
/*
 * ov093 battle main module (BTL_MAIN, file name a guess: no __FILE__ string
 * before btl_server.c): the work object of the battle proc.
 *
 * BtlMain is the 0x474-byte object that the proc init allocates. It owns the
 * battle setup, the view core, the server, the four clients and the two
 * sides. Offsets come from the init, exit, setup and sync tasks and from the
 * accessors of btl_main.c and from the readers in the server, client and
 * view files.
 */

#include "../arm9/btl_setup_types.h"

#ifndef OV093_BASIC_TYPES
#define OV093_BASIC_TYPES
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
#endif

struct BtlvCore;
struct BtlClient;
struct BtlServer;
struct BtlField;
struct PerapVoice;
struct BtlMain;

/* One step function of a task: runs once per frame until it returns nonzero. */
typedef int (*BtlStepFn)(u32 *step, void *arg);

/* The battle task slot: the running step, the step queued after it, and its state. */
struct BtlTask {
    BtlStepFn current;
    BtlStepFn queued;
    void *arg;
    u32 step;
};

/* Rule block that the parent sends to the child (32 bytes). */
struct BtlRuleExchange {
    u32 regulation[6];
    u16 resultCount;
    u16 limitTimeGame;
    u16 limitTimeCommand;
    u8 textSpeed;
    u8 sceneOff : 4;
    u8 reserved : 4;
};

/* Up to four client ids, 4 meaning an empty entry. */
struct BtlClientSet {
    u32 count;
    u8 ids[4];
};

/* Trainer slot of the main object (0x28 bytes). */
struct BtlTrainerSlot {
    void *handle;
    void *name;
    u16 hasData;
    u16 reserved0A;
    u8 info[0x1c];
};

/* One entry of a side (0x1c bytes). */
struct BtlSideSlot {
    u8 data[0x1c];
};

/* One side of the battle (0xE8 bytes), initialized by the server module. */
struct BtlSide {
    struct BtlMain *main;
    struct BtlSideSlot slots[4];
    u32 slotWork[4];
    void *entries[24];
    u32 sideIndex;
};

/*
 * The flag byte at the end of the main object. commLost is set when the
 * link drops (or the player quits a link battle), commLostHandled when the
 * main task has taken note of it and wants to leave.
 */
struct BtlMainFlagBits {
    u8 commLost : 1;
    u8 commLostHandled : 1;
    u8 noBattleAnim : 1;
    u8 unusedBit3 : 1;
    u8 unusedBit4 : 1;
    u8 keepBgm : 1;
    u8 unusedBit6 : 1;
    u8 sleepHooksSet : 1;
};

struct BtlMain {
    struct BattleSetupParam *setup;     /* 0x000 */
    struct BtlvCore *viewCore;          /* 0x004 */
    struct BtlServer *server;           /* 0x008 */
    struct BtlServer *subServer;        /* 0x00C */
    struct BtlClient *clients[4];       /* 0x010 */
    struct BtlTrainerSlot trainers[4];  /* 0x020 */
    void *playerStatus;                 /* 0x0C0 */
    u8 clientReady[4];                  /* 0x0C4 set when the client has built its state */
    struct BtlSide sides[2];            /* 0x0C8 */
    struct Party *battleParties[4];     /* 0x298 */
    struct Party *savedParties[4];      /* 0x2A8 */
    struct Party *tempParty;            /* 0x2B8 */
    struct BtlField *field;             /* 0x2BC */
    void *tempBuffer;                   /* 0x2C0 */
    void *netBuffer;                    /* 0x2C4 */
    u8 recordReader[0x118];             /* 0x2C8 */
    struct PerapVoice *voices[4];       /* 0x3E0 */
    struct BattleRngState rng;          /* 0x3F0 */
    struct BtlRuleExchange ruleExchange; /* 0x408 */
    u8 slotClientIds[6];                /* 0x428 */
    u8 pad42E[2];
    int prizeMoney;                     /* 0x430 */
    int bonusMoney;                     /* 0x434 */
    int penaltyMoney;                   /* 0x438 */
    u32 textSpeed;                      /* 0x43C */
    u16 limitTimeGame;                  /* 0x440 */
    u16 limitTimeCommand;               /* 0x442 */
    u32 outcome;                        /* 0x444 */
    struct BtlClientSet defeatedClients; /* 0x448 */
    struct BtlTask task;                /* 0x450 */
    union {
        u32 subStep;
        int fadeLevel;
    };                                  /* 0x460 */
    int (*tick)(struct BtlMain *main);  /* 0x464 */
    u16 heapId;                         /* 0x468 */
    u8 pad46A;
    u8 clientCount;                     /* 0x46B */
    u8 ownClientId;                     /* 0x46C */
    u8 ownFirstSlot;                    /* 0x46D */
    u8 hostsServer;                     /* 0x46E 1 when this machine runs the server (the parent) */
    u8 isSetStyle;                      /* 0x46F */
    u8 exchangeIndex;                   /* 0x470 round counter of the party exchange */
    u8 multiState;                      /* 0x471 */
    u8 exchangeSlot;                    /* 0x472 setup slot of the current round (1 or 3) */
    struct BtlMainFlagBits flags;       /* 0x473 */
};

/*
 * Target range kinds that BTL_MAIN expands into lists of battle positions
 * (double battles in func_021B8834, triple battles in func_021B88EC, both in btl_main.c).
 * The second kind of each pair (6/7/8/9 against 1/3/5/4) gives the same
 * list in a double battle; triple battles tell some of them apart.
 */
enum BtlRangeType {
    BTL_RANGE_DEFAULT = 0,
    BTL_RANGE_ENEMIES_IN_REACH = 1,
    BTL_RANGE_OTHERS_IN_REACH = 2,
    BTL_RANGE_SELF_AND_ALLIES_IN_REACH = 3,
    BTL_RANGE_ALLIES_IN_REACH = 4,
    BTL_RANGE_ALL_IN_REACH = 5,
    BTL_RANGE_ALL_ENEMIES = 6,
    BTL_RANGE_ALL_ALLIES = 7,
    BTL_RANGE_EVERY_POSITION = 8,
    BTL_RANGE_ALLIES_IN_REACH_ALT = 9
};

#endif
