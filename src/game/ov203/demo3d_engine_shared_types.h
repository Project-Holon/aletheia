#ifndef DEMO3D_ENGINE_SHARED_TYPES_H
#define DEMO3D_ENGINE_SHARED_TYPES_H

#include "demo3d_graphic_shared_types.h"

struct Rec;

struct IcaAnime;

/*
 * Light-record view returned by DEMO3D_ENGINE_GetCameraRecord and stored at
 * struct Demo3dEngineCtx.cam.  The same object is viewed as struct Record in
 * demo3d_engine.c: its flag halfword at 0x06 carries bit 0 "doubled" (a
 * size or value doubling selector) and bit 1 "count".  The int fields at
 * 0x08.. are the camera clip parameters.  Only the two flag bits and the
 * clip fields are named here; the rest of the record is not touched through
 * this view.
 */
struct Cam {
    u8  pad0[6];
    u16 doubled : 1;   /* 0x06 bit 0: size or value doubled */
    u16 count   : 1;   /* 0x06 bit 1 */
    u16 rest    : 14;
    int f8, fc, f10, f14, f18, f1c;
    s16 clipOffset;    /* 0x20: near/far clip offset, first display mode */
    s16 clipOffsetAlt; /* 0x22: near/far clip offset, second display mode */
};

/* Processed demo config embedded in struct Demo3dEngineCtx at 0x78. */
typedef struct Demo3dCfg {
    u32 id;       /* 0x00 */
    u32 frame;    /* 0x04 */
    u8  color;    /* 0x08 */
    u8  timeZone; /* 0x09 */
    u8  flag;     /* 0x0A */
    u8  mode;     /* 0x0B */
    u8  extra;    /* 0x0C */
    u8  sec;      /* 0x0D */
} Demo3dCfg;

/*
 * Engine context of the demo3d demo (0x88 bytes; DEMO3D_ENGINE_Create allocates it
 * with GFL_HEAP_Alloc(heap, 0x88, 1, ...)).  DEMO3D_ENGINE_Update also views the 0x30
 * block as its G3D draw arguments.
 */
struct Demo3dEngineCtx {
    void *graphic;      /* 0x00 owner graphic context */
    u32 id;             /* 0x04 animation id */
    u32 cmdMode;        /* 0x08 command update mode */
    u32 pad0c;
    u32 animeOn;        /* 0x10 also selects clip-plane update */
    u32 step;           /* 0x14 frame step */
    struct IcaAnime *anime; /* 0x18 animation stream */
    struct G3dUtil *table;          /* 0x1C G3D_UTIL handle */
    void *light;        /* 0x20 G3D camera */
    u32 nearClip;       /* 0x24 */
    u32 farClip;        /* 0x28 */
    u32 count;          /* 0x2C object count */
    u32 scale[6];       /* 0x30 */
    u8 matrix[0x24];    /* 0x48 */
    struct Demo3dCmdContext *cmdSys; /* 0x6C DEMO3D_CMDSYS handle */
    u16 *indices;       /* 0x70 */
    struct Cam *cam;    /* 0x74 camera/light record */
    Demo3dCfg data;     /* 0x78 */
};

typedef char Ctx_SizeCheck[(sizeof(struct Demo3dEngineCtx) == 0x88) ? 1 : -1];

#endif
