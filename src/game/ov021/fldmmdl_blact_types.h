#ifndef GAME_OV021_FLDMMDL_BLACT_TYPES_H
#define GAME_OV021_FLDMMDL_BLACT_TYPES_H

#include "../arm9/billboard_act_types.h"
#include "../ov010/fldmmdl_types.h"

/*
 * Billboard actors of the field models. The container (BlactSys, 0x24 bytes)
 * hangs off MmdlSys.blActCont. It keeps a table that maps each object code to
 * its billboard image slot, a reserve work for resources and actors that are
 * added a few frames later (BlactReserve), and four object code change
 * records.
 */

/* Resource flags of an object code (BlactResIndex.flags). */
#define FLDMMDL_BLACT_RESBIT_GUEST 0x1 /* added on demand: deleted when no model uses the code */
#define FLDMMDL_BLACT_RESBIT_TRANS 0x2 /* one slot per actor, image sent to VRAM per frame */

/* Number of object code change records. */
#define FLDMMDL_BLACT_CODE_CHANGE_MAX 4

/* Slot kind for FLDMMDL_BLACT_AddResourceSlot: the image stays in VRAM. */
#define FLDMMDL_BLACT_SLOT_VRAM (-1)

/* Called when a reserved actor is added. */
typedef void (*BlactAddActorHook)(u32 blactId, void *arg);

/* Object code to image slot (8 bytes). */
typedef struct BlactResIndex {
    u16 code;      /* 0x00: 0xFFFF free */
    u16 slotIndex; /* 0x02 */
    u16 flags;     /* 0x04: FLDMMDL_BLACT_RESBIT_ */
    u16 pad_06;
} BlactResIndex;

typedef struct BlactResTable {
    int count;              /* 0x00 */
    BlactResIndex *entries; /* 0x04 */
} BlactResTable;

/* Resource that waits to be loaded from the archive (0x0C bytes). */
typedef struct BlactResReserve {
    u16 code;     /* 0x00: 0xFFFF free */
    u16 resId;    /* 0x02: archive data id */
    u8 mdlSize;   /* 0x04 */
    u8 texSize;   /* 0x05 */
    u8 pad_06[2];
    u32 flags;    /* 0x08 */
} BlactResReserve;

/* Loaded resource that waits to be registered in a slot (0x14 bytes). */
typedef struct BlactAddRes {
    u8 isReady;      /* 0x00 */
    u8 pad_01[3];
    u32 flags;       /* 0x04 */
    u16 code;        /* 0x08 */
    u8 mdlSize;      /* 0x0A */
    u8 texSize;      /* 0x0B */
    u8 pad_0C[4];
    void *resHandle; /* 0x10 */
} BlactAddRes;

/* Actor that waits for its resource (0x28 bytes). */
typedef struct BlactEntry {
    u16 *outBlactId;        /* 0x00: receives the actor id; 0 when free */
    Mmdl *mmdl;             /* 0x04: 0 for an actor at a fixed position */
    u16 code;               /* 0x08 */
    u8 mdlSize;             /* 0x0A */
    u8 texSize;             /* 0x0B */
    u8 animId;              /* 0x0C */
    u8 isWaiting;           /* 0x0D */
    u8 pad_0E[2];
    void *resHandle;        /* 0x10: own image of the actor, or 0 */
    BlactAddActorHook hook; /* 0x14 */
    void *hookArg;          /* 0x18 */
    VecFx32 pos;            /* 0x1C */
} BlactEntry;

typedef struct BlactReserve {
    u32 isActive;                /* 0x00 */
    u16 resReserveMax;           /* 0x04 */
    u16 addResMax;               /* 0x06 */
    u16 actReserveMax;           /* 0x08 */
    u8 pad_0A[2];
    BlactResReserve *resReserve; /* 0x0C */
    BlactAddRes *addRes;         /* 0x10 */
    BlactEntry *actReserve;      /* 0x14 */
} BlactReserve;

/* Actor of a model whose object code changed (0x0C bytes). */
typedef struct BlactCodeChange {
    Mmdl *mmdl;     /* 0x00: 0 when free */
    u16 oldBlactId; /* 0x04 */
    u16 oldCode;    /* 0x06 */
    u16 newCode;    /* 0x08 */
    u16 pad_0A;
} BlactCodeChange;

typedef struct BlactSys {
    u8 entryHookFlag;              /* 0x00: set by the entry hook, cleared each update */
    u8 pad_01;
    u16 resMax;                    /* 0x02 */
    struct BbActSys *bbdActSys;    /* 0x04 */
    u16 slotBase;                  /* 0x08 */
    u8 pad_0A[6];
    MmdlSys *mmdlSys;              /* 0x10 */
    BlactResTable resTable;        /* 0x14 */
    BlactReserve *reserve;         /* 0x1C */
    BlactCodeChange *codeChanges;  /* 0x20: FLDMMDL_BLACT_CODE_CHANGE_MAX records */
} BlactSys;

/* Animation command lists of one animation id (8 bytes). */
typedef struct BlactAnimeTable {
    void *cmdLists;
    u32 listCount;
} BlactAnimeTable;

#endif
