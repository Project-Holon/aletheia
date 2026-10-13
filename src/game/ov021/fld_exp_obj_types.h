#ifndef ALETHEIA_OV021_FLD_EXP_OBJ_TYPES_H
#define ALETHEIA_OV021_FLD_EXP_OBJ_TYPES_H

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef int fx32;

typedef struct { fx32 x, y, z; } VecFx32;
typedef struct { fx32 m[3][3]; } MtxFx33;
typedef struct NNSFndAllocator { u32 w[4]; } NNSFndAllocator;
typedef struct NNSG3dRenderObj NNSG3dRenderObj;
typedef struct NNSG3dAnmObj NNSG3dAnmObj;

#include "../arm9/g3d_system_types.h"

struct FieldMap;
struct GameSystem;
struct GameData;
struct GameEvent;
struct GimmickWork;
struct G3dUtil;

/* Partial NitroSystem animation layouts (same as g3d_system.c). */
typedef struct {
    u32 anmHeader;
    u16 numFrame;
} NNSG3dResAnmCommon;

struct NNSG3dAnmObj {
    fx32                      frame;
    fx32                      ratio;
    const NNSG3dResAnmCommon *resAnm;
};

/*
 * Setup tables of the 3D utility (g3d_util.c): the resources to load and
 * the objects built from them. A unit is one such setup.
 */
typedef struct G3dUtilAnimeSetup {
    u16 anmResIdx;
    u16 anmDatIdx;
} G3dUtilAnimeSetup;

typedef struct G3dUtilObjSetup {
    u16                mdlResIdx;
    u16                mdlDatIdx;
    u16                texResIdx;
    u16                pad06;
    G3dUtilAnimeSetup *anmTbl;
    u16                anmCount;
} G3dUtilObjSetup;

typedef struct G3dUtilResSetup {
    u32 arc;        /* archive id, read when the unit comes from an archive */
    u16 dat;
    u16 pad06;
    u32 type;
} G3dUtilResSetup;

typedef struct G3dUtilSetup {
    G3dUtilResSetup *resTbl;
    u16              resCount;
    G3dUtilObjSetup *objTbl;
    u16              objCount;
} G3dUtilSetup;

#define FLD_EXP_OBJ_UNIT_MAX 4

/*
 * One animation of a field expansion model (0x10 bytes). The flags are
 * written by the FLD_EXP_OBJ setters; FLD_EXP_OBJ_UpdateAnimes advances
 * every enabled, unpaused animation by speed each frame.
 */
typedef struct FldExpObjAnime {
    u8            paused;           /* 0x00: 1 stops the advance */
    u8            loop;             /* 0x01: 1 wraps at the ends, 0 stops there */
    u8            enabled;          /* 0x02: animation is attached to the model */
    u8            pad03;
    fx32          speed;            /* 0x04: frame step, 0x1000 = 1 frame */
    int           advanceResult;    /* 0x08: result of the last advance, 1 while playing */
    struct G3dAnime *anime;         /* 0x0C: G3D_SYSTEM_GetObjectAnime of the model */
} FldExpObjAnime;

/* The animations of one model (8 bytes). */
typedef struct FldExpObjAnimeSet {
    int             count;
    FldExpObjAnime *anime;          /* count entries, owned */
} FldExpObjAnimeSet;

/* One model of a unit (0x44 bytes). */
typedef struct FldExpObjModel {
    int             cullDraw;       /* 0x00: draw with the box culling test */
    int             hidden;         /* 0x04: not drawn while nonzero */
    G3dObjectStatus status;         /* 0x08: position, scale, rotation */
} FldExpObjModel;

/* One loaded setup (0x10 bytes): its models and their animations. */
typedef struct FldExpObjUnit {
    int                active;      /* 0x00 */
    FldExpObjModel    *models;      /* 0x04: modelCount entries, owned */
    FldExpObjAnimeSet *animeSets;   /* 0x08: modelCount entries, owned */
    u16                unitId;      /* 0x0C: G3D_UTIL unit id */
    u16                modelCount;  /* 0x0E */
} FldExpObjUnit;

/* The field expansion object controller (0x48 bytes, FieldMap.expObj). */
typedef struct FldExpObjCnt {
    int             heapId;
    struct G3dUtil *util;
    FldExpObjUnit   units[FLD_EXP_OBJ_UNIT_MAX];
} FldExpObjCnt;

#endif
