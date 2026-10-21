#ifndef GAME_OV096_TR_AI_TYPES_H
#define GAME_OV096_TR_AI_TYPES_H
#include "../arm9/script_vm_types.h"
#include "../types.h"
struct BtlPokeParam;
/* Trainer AI work area, 0xD8 bytes; every AI script command gets it as its 2nd argument. */
typedef struct TrAiWork {
    u8 phase;            /* 0x00 */
    u8 moveIndex;        /* 0x01 */
    u16 moveId;          /* 0x02 */
    int moveScores[4];   /* 0x04 */
    int baseScores[4];   /* 0x14: 0 or 100 per slot */
    s16 targetScores[6]; /* 0x24 */
    s8 targetMove[6];    /* 0x30 */
    u8 pad36[2];
    int workValue;       /* 0x38 */
    u32 pendingMask;     /* 0x3C */
    u32 fullMask;        /* 0x40 */
    u8 flags;            /* 0x44: 1 move done, 2 no move, 8 stop, 16 timed out */
    u8 scriptId;         /* 0x45 */
    u8 chosenMove;       /* 0x46 */
    u8 chosenTarget;     /* 0x47 */
    u8 moveRoll[4];      /* 0x48 */
    u16 knownMoves[2][4]; /* 0x4C: 4 per opposing position */
    u8 pad5C[0x20];
    u8 abilityCache[6];  /* 0x7C */
    u8 pad82[0x12];
    u8 selfPos;          /* 0x94 */
    u8 targetPos;        /* 0x95 */
    u8 pad96[2];
    u32 rule;            /* 0x98 */
    u32 competitor;      /* 0x9C */
    u16 heapId;          /* 0xA0 */
    u8 padA2[2];
    void *scriptArchive; /* 0xA4 */
    void *itemArchive;   /* 0xA8 */
    u8 *script;          /* 0xAC */
    void *battleMain;    /* 0xB0 */
    void *serverFlow;    /* 0xB4 */
    void *sideTable;     /* 0xB8 */
    struct BtlPokeParam *selfPoke;      /* 0xBC */
    struct BtlPokeParam *targetPoke;      /* 0xC0 */
    int cmdReturn;       /* 0xC4: 1 */
    int moveCount;       /* 0xC8: 4 */
    u32 randomByte;      /* 0xCC */
    u64 startTick;       /* 0xD0 */
} TrAiWork;
#endif
