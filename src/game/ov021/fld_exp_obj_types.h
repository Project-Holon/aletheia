#ifndef ALETHEIA_OV021_FLD_EXP_OBJ_TYPES_H
#define ALETHEIA_OV021_FLD_EXP_OBJ_TYPES_H

#include "../types.h"

#include "../sdk_fx.h"

#include "../sdk_nnsfnd.h"

#include "../arm9/nns_g3d_anm_calc_types.h"

#include "../arm9/g3d_system_types.h"

struct FieldMap;
struct GameSystem;
struct GameData;
struct GameEvent;
struct GimmickWork;
#include "../arm9/g3d_util_types.h"

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
