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
#include "../ov093/btl_calc_types.h"
#include "../arm9/pms_types.h"
#include "../ov093/btl_field_types.h"
#include "../ov093/btl_rec_types.h"

#include "../types.h"

struct BtlvCore;
struct BtlClient;
struct BtlServer;
struct PerapVoice;
struct BtlMain;
struct BtlPokeParam;

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

/*
 * Trainer slot of the main object (0x28 bytes). Slot 0 holds the player
 * (handle is the status object, trainerType is a gender flag); the other
 * slots copy a BattleTrainerData and have no handle.
 */
struct BtlTrainerSlot {
    void *handle;
    void *name;
    u16 trainerType;
    u16 trainerId;
    int aiFlags;
    u16 itemIds[4];
    PmsData winWord;
    PmsData loseWord;
};

/* Trainer record that a link partner relays to the other machine (0x6C bytes). */
struct BtlTrainerPacket {
    u32 trainerId;
    u32 trainerType;
    u32 aiFlags;
    u16 itemIds[4];
    u32 namePtrUnused;
    PmsData winWord;
    PmsData loseWord;
    u16 nameChars[32];
    int nameLength;
};

/* One entry of a side (0x1c bytes). */
struct BtlSideSlot {
    struct BtlPokeParam *items[6];
    u8 count;
    u8 pad19[3];
};

/* One side of the battle (0xE8 bytes), initialized by the server module. */
struct BtlSide {
    struct BtlMain *main;
    struct BtlSideSlot slots[4];
    struct Party *parties[4];
    struct BtlPokeParam *pokeParams[24];
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
    u8 moneyLocked : 1;
    u8 penaltyDone : 1;
    u8 keepBgm : 1;
    u8 doubleMoney : 1;
    u8 sleepHooksSet : 1;
};

struct BtlMain {
    struct BattleSetupParam *setup;     /* 0x000 */
    struct BtlvCore *viewCore;          /* 0x004 */
    struct BtlServer *server;           /* 0x008 */
    struct BtlServer *subServer;        /* 0x00C */
    struct BtlClient *clients[4];       /* 0x010 */
    struct BtlTrainerSlot trainers[4];  /* 0x020 */
    struct MyStatus *playerStatus;      /* 0x0C0 */
    u8 clientReady[4];                  /* 0x0C4 set when the client has built its state */
    struct BtlSide sides[2];            /* 0x0C8 */
    struct Party *battleParties[4];     /* 0x298 */
    struct Party *savedParties[4];      /* 0x2A8 */
    struct Party *tempParty;            /* 0x2B8 */
    BtlFieldState *field;               /* 0x2BC */
    void *tempBuffer;                   /* 0x2C0 */
    void *netBuffer;                    /* 0x2C4 */
    BtlRecReader recordReader;          /* 0x2C8 */
    struct PerapVoice *voices[4];       /* 0x3E0 */
    BtlRngState rng;               /* 0x3F0 */
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

/* A list of battle positions in the position tables: how many positions the first and the
   second group hold, then the positions. secondCount is volatile: the loops that read it
   test it from memory on every pass. */
struct BtlPosTable {
    u16 firstCount;
    volatile u16 secondCount;
    u8 positions[6];
};

/*
 * Target range kinds that BTL_MAIN expands into lists of battle positions
 * (double battles in BTL_MAIN_ExpandPosDouble, triple battles in BTL_MAIN_ExpandPosTriple, both in btl_main.c).
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
