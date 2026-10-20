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
 * This header includes btl_server_types.h (BtlServerEntry, u8, u16, u32).
 */
#include "../ov093/btl_server_types.h"
#include "../ov093/btl_records_types.h"
#include "../ov093/btl_main_types.h"
#include "../ov093/hand_common_types.h"
#include "../ov095/btl_pokeset_types.h"


/*
 * Work area that the flow hands to the event system. The flow itself only clears
 * the pending counter word at its end (BTL_SERVER_FLOW_ClearPendingCounter); the
 * 0x220-byte body is never read by btl_server_flow.c.
 */
typedef struct EventParamBuf {
    u8 work[0x220];                     /* 0x000: event work area, not read by the flow */
    u32 pendingCounter;                 /* 0x220: cleared before the side table is initialized */
} EventParamBuf;
typedef char EventParamBufSizeCheck[(sizeof(EventParamBuf) == 0x224) ? 1 : -1];


/* One frame of the action stack: the sets, parameter blocks and queues that one action works on. */
typedef struct BtlServerFlowFrame {
    BtlPokeSet targetSet;             /* 0x000: poke set the action aims at */
    BtlPokeSet targetSetWork;         /* 0x048: working copy of the target set */
    BtlPokeSet hitSetA;               /* 0x090 */
    BtlPokeSet hitSetB;               /* 0x0D8 */
    BtlPokeSet damageSet;             /* 0x120: poke ids with the damage each took */
    BtlPokeSet effectSet;             /* 0x168 */
    BtlPokeSet queuedSet;             /* 0x1B0 */
    u8 moveTurnState[8];                /* 0x1F8: struct Unk021BD1E0 view */
    struct BtlMoveParam moveParam;  /* 0x200 */
    struct BtlMoveParam moveParamBackup; /* 0x214 */
    u8 hitInfo[6];                 /* 0x228 */
    u8 interruptQueue[0x13];        /* 0x22E: count, six poke ids, six selections, six params */
    u8 deferredQueue[0x13];         /* 0x241: same layout as interruptQueue */
    u8 hitRecordA[0x1C];            /* 0x254 */
    u8 hitRecordB[0x1C];            /* 0x270 */
    u8 retargetSlot;                 /* 0x28C: 6 when none */
    u8 frameFlagA;                      /* 0x28D: first bit field of stateFlags */
    u8 failMessageShown;                      /* 0x28E: second bit field of stateFlags */
    u8 padFrameEnd;                 /* 0x28F */
} BtlServerFlowFrame;
typedef char BtlServerFlowFrameSizeCheck[(sizeof(BtlServerFlowFrame) == 0x290) ? 1 : -1];

/* Cursor of the walk over the living pokes of the field. */
typedef struct BtlFieldPokeIter {
    u8 client;      /* client index of the next poke */
    u8 slot;        /* slot index of the next poke */
    u8 done;        /* 1 when the walk is over */
    u8 triple;      /* 1 in a triple battle: only the first three slots count */
} BtlFieldPokeIter;

#define BTL_SERVER_FLOW_FRAME_MAX 7

typedef struct BtlServerFlow {
    struct BtlServer *server;           /* 0x000: BtlServer that owns the flow */
    struct BtlMain *mainModule;                   /* 0x004 */
    struct BtlSide *pokeCon;            /* 0x008: poke container */
    void *cmdQueue;                     /* 0x00C: command queue the flow writes to */
    u32 turnCount;                      /* 0x010 */
    u32 flowResult;                     /* 0x014 */
    int bagMode;                        /* 0x018 */
    BtlWazaRec wazaRec;                 /* 0x01C: moves used so far */
    BtlDeadRec deadRec;                 /* 0x3E0: faint history */
    void *evolutionHandle;              /* 0x4A4: SHINKA_CHECK handle */
    u8 *curMoveTurnState;                   /* 0x4A8: into the top frame */
    u8 *curInterruptQueue;              /* 0x4AC: into the top frame */
    u8 *curDeferredQueue;               /* 0x4B0: into the top frame */
    u8 *curHitInfo;                    /* 0x4B4: into the top frame */
    struct BtlClientSet escapedClientSet;    /* 0x4B8: clients that escaped */
    struct BtlLevelUpResult levelUpResult;  /* 0x4C0 */
    u8 changeClientList[6];                    /* 0x4CE */
    u8 actOrderScratch[0x2A0];          /* 0x4D4 */
    u32 actionCounter;                  /* 0x774 */
    u32 serialNumber;                   /* 0x778: never 0 */
    u8 initDone;                        /* 0x77C */
    u8 unusedFlag;                      /* 0x77D */
    u8 turnCheckStep;                        /* 0x77E */
    u8 retargetSlot;                     /* 0x77F: copy of the top frame's retargetSlot */
    u16 heapId;                         /* 0x780 */
    u8 numActOrder;                     /* 0x782 */
    u8 actOrderIndex;                   /* 0x783 */
    u8 capturedTargetSlot;                      /* 0x784: 6 when none */
    u8 seenCount;                       /* 0x785: entries used in seenValues */
    u8 escapeAttemptCount;                      /* 0x786: capped at 0x1E */
    u8 unusedByte;                      /* 0x787 */
    u8 frontOrderCount;                        /* 0x788 */
    u8 currentTargetPokeId;                      /* 0x789: 0x1F when none */
    union {
        u8 raw;
        struct {
            u8 pursuitRunning:1;        /* bit 0: set while the pursuit moves before a switch-out run */
            u8 winBgmStarted:1;         /* bit 1 */
            u8 memberInMessageShown:1;  /* bit 2: member-in message already pushed */
            u8 frameFlagA:1;            /* bit 3: copy of the top frame's frameFlagA */
            u8 failMessageShown:1;      /* bit 4: copy of the top frame's failMessageShown */
            u8 healBlockShown:1;        /* bit 5 */
            u8 reservedFlag6:1;         /* bit 6: cleared at init, never read */
            u8 reservedFlag7:1;         /* bit 7 */
        } bits;
    } stateFlags;                       /* 0x78A */
    u8 frontOrder[6];                   /* 0x78B */
    u8 seenValues[0x18];                /* 0x791 */
    u8 faintHandled[0x18];                /* 0x7A9 */
    u8 memberInPending[0x18];                /* 0x7C1 */
    u8 memberChangeCount[7];                    /* 0x7D9 */
    BtlServerEntry actOrder[6];                  /* 0x7E0 */
    BtlServerEntry actOrderTemp;                 /* 0x840 */
    BtlPokeSet *curTargetSet;                 /* 0x850: into the top frame */
    BtlPokeSet *curTargetSetWork;             /* 0x854 */
    BtlPokeSet *curHitSetA;                   /* 0x858 */
    BtlPokeSet *curHitSetB;                   /* 0x85C */
    BtlPokeSet *curDamageSet;                 /* 0x860 */
    BtlPokeSet *curEffectSet;                 /* 0x864 */
    BtlPokeSet *curQueuedSet;                 /* 0x868 */
    void *curHitRecordA;                /* 0x86C */
    void *curHitRecordB;                /* 0x870 */
    BtlServerFlowFrame frames[BTL_SERVER_FLOW_FRAME_MAX]; /* 0x874 */
    u32 frameDepth;                     /* 0x1A64 */
    BtlPokeSet memberInSet;             /* 0x1A68: pokes that entered and wait for their entry events */
    struct BtlMoveParam *curMoveParam;  /* 0x1AB0: into the top frame */
    struct BtlMoveParam *curMoveParamBackup; /* 0x1AB4 */
    BtlPosPoke posPoke;                 /* 0x1AB8: who stands where */
    u8 padPosPokeEnd[0x14];             /* 0x1AD0 */
    BtlStrParam msgRecord;              /* 0x1AE4: the message being built */
    u8 expShareTable[0x48];           /* 0x1B08 */
    EventParamBuf eventParamBuf;        /* 0x1B50 */
    u32 cmdLock;                           /* 0x1D74 */
    u8 pad1D78[0x1FC];                  /* 0x1D78 */
    u16 lastMoveId;                   /* 0x1F74 */
    u8 pad1F76[2];                      /* 0x1F76 */
    int disobeyResult;                  /* 0x1F78 */
    u16 effectivenessRecord[6];              /* 0x1F7C: per-side type affinity counts, read as u16 words */
    u32 hitTable[24];                   /* 0x1F88: per poke id, the hit result of the move */
    u8 turnOnceFlags[4];                    /* 0x1FE8: [0] guards ProcPreTurnMoveCheck once per turn, [1] cleared at ProcMoveHitTargets */
    u8 scratchBuffer[0x140];                /* 0x1FEC: handler work area, see GetScratchBuffer */
} BtlServerFlow;
typedef char BtlServerFlowSizeCheck[(sizeof(BtlServerFlow) == 0x212C) ? 1 : -1];

#endif
