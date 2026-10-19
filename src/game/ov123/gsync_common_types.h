/* Basic types and forward declarations shared by the ov123 Game Sync and Dream World account files. */
#ifndef GSYNC_COMMON_TYPES_H
#define GSYNC_COMMON_TYPES_H

#include "../types.h"

/* Opaque handle of a CLACT sprite actor. */
struct ClActor;

/* Background layer template read by BG_SYS_SetBgTemplate (0x20 bytes). */
struct BgTemplate {
    u32 x;                  /* 0x00 */
    u32 y;                  /* 0x04 */
    u32 bufSize;            /* 0x08 */
    u32 baseTile;           /* 0x0C */
    u8 screenSize;          /* 0x10 */
    u8 colorMode;           /* 0x11 */
    u8 screenBase;          /* 0x12 */
    u8 charBase;            /* 0x13 */
    u32 extPaletteSlot;     /* 0x14 */
    u8 priority;            /* 0x18 */
    u8 areaOver;            /* 0x19 */
    u8 dummy;               /* 0x1A */
    u8 mosaic;              /* 0x1B */
    u32 bgType;             /* 0x1C */
};

typedef struct { u16 value; char *object; void (*callback)(char *); } NotifyCallback;

/* Position record passed to CLACT_CreateActor (8 bytes). */
struct ActorSpawnPos {
    s16 x;      /* 0x00 */
    s16 y;      /* 0x02 */
    u16 z;      /* 0x04, always 0 in ov123 */
    u8 mode;    /* 0x06, actor blend/anim mode */
    u8 space;   /* 0x07, 1 or 2 */
};

/* 2D point written by CLACT_GetActorSurfacePos and added by CLACT_AddActorSurfacePos. */
struct ActorPos {
    s16 x;      /* 0x00 */
    s16 y;      /* 0x02 */
};

/* 2D scale pair used by CLACT_SetActorScale and CLACT_GetActorScale. */
struct ActorScale {
    s32 x;      /* 0x00 */
    s32 y;      /* 0x04 */
};

/* Sprite image proxy filled by CLACT_GetActorImageProxy. */
struct ActorImageProxy {
    u32 unknown_00;         /* 0x00 */
    u32 characterBase;      /* 0x04, add 0x6400000 to get the VRAM address */
    u32 unknown_08[7];      /* 0x08 */
};

/* One slot of the background actor table (gGsyncSlotPositions). */
struct GsyncSlotPos {
    s32 x;      /* 0x00 */
    s32 y;      /* 0x04 */
    s32 mode;   /* 0x08, copied to the actor position mode byte */
};

/* Palette file record returned through ARC_UTIL_LoadPaletteBlockFromHandle and NNS_G2dGetUnpackedPaletteData. */
typedef struct GsyncPaletteData {
    u8 unknown_00[12];      /* 0x00 */
    void *rawData;          /* 0x0C */
} GsyncPaletteData;

/* Nitro sub-file record returned through NNS_G2dGetUnpackedCharacterDataEx. */
typedef struct GsyncGfxData {
    u8 unknown_00[20];      /* 0x00 */
    void *rawData;          /* 0x14 */
} GsyncGfxData;

/* Per-row icon buffers in the Game Sync display work (0x224 bytes). */
typedef struct GsyncDispIconRecord {
    u8 palette[0x20];       /* 0x000, OBJ palette uploaded to the hardware palette slot */
    u8 paletteData[0x200];  /* 0x020, icon palette copy written to VRAM */
    u32 paletteOffset;      /* 0x220, palette slot passed to CLACT_SetActorPaletteOffset */
} GsyncDispIconRecord;

/* One sprite particle of the Game Sync display (0x18 bytes). */
typedef struct GsyncDispParticle {
    struct ClActor *actor;  /* 0x00 */
    u16 x;                  /* 0x04 */
    u16 y;                  /* 0x06 */
    u16 angleA;             /* 0x08, index into FX_SinCosTable_ after >> 4 */
    u16 angleB;             /* 0x0A */
    u16 age;                /* 0x0C */
    u16 active;             /* 0x0E, set when the particle is spawned */
    u16 species;            /* 0x10, icon species of the row */
    u16 formArg;            /* 0x12, second argument of POKE_TOOL_NormalizeForm */
    u16 gender;             /* 0x14 */
    u16 finished;           /* 0x16, set when the actor is gone */
} GsyncDispParticle;

/* CLACT resource handles of the display work (20 pointers). */
typedef union GsyncDispResources {
    void *all[20];              /* 0x00 */
    struct {
        void *palettes[6];      /* 0x00 */
        void *characters[7];    /* 0x18 */
        void *cellAnims[7];     /* 0x34 */
    } byKind;
} GsyncDispResources;

/* Work area of the Game Sync display (gsync_disp.c), 0x4568 bytes. */
typedef struct GsyncDispWork {
    u32 charBase;                       /* 0x000, base slot of the character members */
    u32 paletteBase;                    /* 0x004, base slot of the palette members */
    u8 unknown_08[4];                   /* 0x008, never accessed */
    struct Bank *clactUnit;             /* 0x00C */
    void *vblankTcb;                    /* 0x010 */
    void *paletteWaveTcb;               /* 0x014 */
    GsyncPaletteData *paletteData;      /* 0x018, palette record returned by ARC_UTIL_LoadPaletteBlockFromHandle */
    void *paletteBlock;                 /* 0x01C, allocation freed on exit */
    GsyncDispResources resources;       /* 0x020 */
    u8 unknown_70[4];                   /* 0x070, never accessed */
    struct ClActor *actors[16];         /* 0x074 */
    struct ClActor *pokeIconActor;      /* 0x0B4 */
    struct ClActor *backdropActor;      /* 0x0B8 */
    GsyncDispIconRecord iconRecords[30];/* 0x0BC */
    GsyncDispParticle particles[30];    /* 0x40F4 */
    u16 heapId;                         /* 0x43C4 */
    s16 frame;                          /* 0x43C6, 0..191, drives the sine phase */
    s16 sineTable[192];                 /* 0x43C8 */
    u8 unknown_4548[12];                /* 0x4548, never accessed */
    s32 fadeProgress;                   /* 0x4554 */
    s32 fadeDelta;                      /* 0x4558, 0 stops the fade */
    s32 progressLine;                   /* 0x455C */
    u8 unknown_4560[4];                 /* 0x4560, never accessed */
    s32 vblankCounter;                  /* 0x4564 */
} GsyncDispWork;

#define GSYNC_DISP_ACTOR_MON 13         /* mon icon actor slot */
#define GSYNC_DISP_ACTOR_EFFECT 14      /* effect actor slot */

struct Ctx;
struct TaskMenu;
struct Actor;
struct MsgBank;
struct Cfg;
struct CharBuf;
struct GfFont;
struct U16Vec;
struct Cmd;
struct TaskMenuTmpl;
struct Rec3;
struct Big;
struct Proc;
struct Bank;
struct TaskMenuRes;
struct Tcbl;
struct DispConfig;
struct DispVram;
struct PrintSys;
struct Node;
struct S02031140;
struct Proc;
struct TaskMenuState;

/* Objects owned by arm9 helpers whose headers do not exist yet (folded from gsync_state_shared_types.h). */
struct Sub02009210Obj;
struct Sub02009448Obj;
struct Sub0200852CObj;
struct Ctrl020071D8;

#endif
