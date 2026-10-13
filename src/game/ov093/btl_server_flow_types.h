#ifndef BTL_SERVER_FLOW_TYPES_H
#define BTL_SERVER_FLOW_TYPES_H
/*
 * ov093 battle server flow: the work area of btl_server_flow.c.
 *
 * The constructor (BTL_SERVER_FLOW_Create) allocates 0x212C bytes and stores the five
 * arguments it receives: the owning server, the main module, the poke
 * container, the command queue, the bag mode and the heap id.  The flow runs
 * the actions of one turn; it keeps a stack of up to seven frames (one per
 * nested action) and a set of pointers into the frame on top of the stack.
 *
 * The includer must include btl_server_types.h first (Entry, u8, u16, u32).
 */

/* One frame of the action stack: the sets, parameter blocks and queues that one action works on. */
typedef struct BtlServerFlowFrame {
    u8 targetSet[0x48];             /* 0x000: poke set the action aims at */
    u8 targetSetWork[0x48];         /* 0x048: working copy of the target set */
    u8 hitSetA[0x48];               /* 0x090 */
    u8 hitSetB[0x48];               /* 0x0D8 */
    u8 damageSet[0x48];             /* 0x120: poke ids with the damage each took */
    u8 effectSet[0x48];             /* 0x168 */
    u8 queuedSet[0x48];             /* 0x1B0 */
    u8 turnState[8];                /* 0x1F8: struct Unk021BD1E0 view */
    u8 moveParam[0x14];             /* 0x200 */
    u8 moveParamBackup[0x14];       /* 0x214 */
    u8 hitFlags[6];                 /* 0x228 */
    u8 interruptQueue[0x13];        /* 0x22E: count, six poke ids, six selections, six params */
    u8 deferredQueue[0x13];         /* 0x241: same layout as interruptQueue */
    u8 hitRecordA[0x1C];            /* 0x254 */
    u8 hitRecordB[0x1C];            /* 0x270 */
    u8 reserveSlot;                 /* 0x28C: 6 when none */
    u8 flagsA;                      /* 0x28D: first bit field of stateFlags */
    u8 flagsB;                      /* 0x28E: second bit field of stateFlags */
    u8 padFrameEnd;                 /* 0x28F */
} BtlServerFlowFrame;
typedef char BtlServerFlowFrameSizeCheck[(sizeof(BtlServerFlowFrame) == 0x290) ? 1 : -1];

#define BTL_SERVER_FLOW_FRAME_MAX 7

typedef struct BtlServerFlow {
    u8 *server;                         /* 0x000: BtlServer that owns the flow */
    void *mainModule;                   /* 0x004 */
    void *pokeCon;                      /* 0x008: poke container */
    void *cmdQueue;                     /* 0x00C: command queue the flow writes to */
    u32 turnCount;                      /* 0x010 */
    u32 flowResult;                     /* 0x014 */
    int bagMode;                        /* 0x018 */
    u8 turnRecord[0x3C4];               /* 0x01C */
    u8 historyList[0xC4];               /* 0x3E0 */
    void *evolutionHandle;              /* 0x4A4: SHINKA_CHECK handle */
    u8 *curTurnState;                   /* 0x4A8: into the top frame */
    u8 *curInterruptQueue;              /* 0x4AC: into the top frame */
    u8 *curDeferredQueue;               /* 0x4B0: into the top frame */
    u8 *curHitFlags;                    /* 0x4B4: into the top frame */
    u8 slotTable[8];                    /* 0x4B8 */
    u8 expResult[0xE];                  /* 0x4C0 */
    u8 pokeIdBuf[6];                    /* 0x4CE */
    u8 actOrderScratch[0x2A0];          /* 0x4D4 */
    u32 actionCounter;                  /* 0x774 */
    u32 serialNumber;                   /* 0x778: never 0 */
    u8 initDone;                        /* 0x77C */
    u8 unusedFlag;                      /* 0x77D */
    u8 onceFlag;                        /* 0x77E */
    u8 reserveSlot;                     /* 0x77F: copy of the top frame's reserveSlot */
    u16 heapId;                         /* 0x780 */
    u8 numActOrder;                     /* 0x782 */
    u8 actOrderIndex;                   /* 0x783 */
    u8 chosenSlot;                      /* 0x784: 6 when none */
    u8 seenCount;                       /* 0x785: entries used in seenValues */
    u8 chainCount;                      /* 0x786: capped at 0x1E */
    u8 unusedByte;                      /* 0x787 */
    u8 lastFlag;                        /* 0x788 */
    u8 lastPokeId;                      /* 0x789: 0x1F when none */
    union {
        u8 raw;
        struct { u8 b0:1, b1:1, b2:1, rest:5; } bits;
    } stateFlags;                       /* 0x78A */
    u8 frontOrder[6];                   /* 0x78B */
    u8 seenValues[0x18];                /* 0x791 */
    u8 pokeFlagsA[0x18];                /* 0x7A9 */
    u8 pokeFlagsB[0x18];                /* 0x7C1 */
    u8 slotFlags[7];                    /* 0x7D9 */
    Entry actOrder[6];                  /* 0x7E0 */
    Entry actOrderTemp;                 /* 0x840 */
    void *curTargetSet;                 /* 0x850: into the top frame */
    void *curTargetSetWork;             /* 0x854 */
    void *curHitSetA;                   /* 0x858 */
    void *curHitSetB;                   /* 0x85C */
    void *curDamageSet;                 /* 0x860 */
    void *curEffectSet;                 /* 0x864 */
    void *curQueuedSet;                 /* 0x868 */
    void *curHitRecordA;                /* 0x86C */
    void *curHitRecordB;                /* 0x870 */
    BtlServerFlowFrame frames[BTL_SERVER_FLOW_FRAME_MAX]; /* 0x874 */
    u32 frameDepth;                     /* 0x1A64 */
    u8 pad1A68[0x48];                   /* 0x1A68 */
    void *curMoveParam;                 /* 0x1AB0: into the top frame */
    void *curMoveParamBackup;           /* 0x1AB4 */
    u8 posPoke[0x2C];                   /* 0x1AB8 */
    u8 msgParam[0x24];                  /* 0x1AE4: struct Msg view */
    u8 moveEffectParam[0x48];           /* 0x1B08 */
    u8 eventParamBuf[0x224];            /* 0x1B50 */
    u32 lock;                           /* 0x1D74 */
    u8 pad1D78[0x1FC];                  /* 0x1D78 */
    u16 lastActionId;                   /* 0x1F74 */
    u8 pad1F76[2];                      /* 0x1F76 */
    int pendingResult;                  /* 0x1F78 */
    u8 turnDeadRecord[0xC];             /* 0x1F7C */
    u8 targetParam[0x60];               /* 0x1F88 */
    u8 onceFlags[8];                    /* 0x1FE8 */
    u8 pad1FF0[0x13C];                  /* 0x1FF0 */
} BtlServerFlow;
typedef char BtlServerFlowSizeCheck[(sizeof(BtlServerFlow) == 0x212C) ? 1 : -1];

#endif
