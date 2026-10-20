#ifndef GAME_OV021_FIELD_G3DOBJ_TYPES_H
#define GAME_OV021_FIELD_G3DOBJ_TYPES_H

#include "../types.h"
#include "../sdk_fx.h"
#include "../arm9/g3d_system_types.h"

/* Field 3D object control (field_g3dobj.c, 021C63AC..021C6AFC)        */
#define FIELD_G3DOBJ_ANIME_MAX 8

/* FieldG3dObjRes.state */
#define FIELD_G3DOBJ_RES_FREE    0   /* being rebuilt or released */

#define FIELD_G3DOBJ_RES_READY   1   /* textures are in VRAM */

#define FIELD_G3DOBJ_RES_PENDING 2   /* textures are sent to VRAM on the next update */

/* FieldG3dObj.kind */
#define FIELD_G3DOBJ_FREE    0

#define FIELD_G3DOBJ_ACTIVE  1   /* g3dObject and anime are created */

#define FIELD_G3DOBJ_PENDING 2   /* waits for the resource textures; created by the next update */

/* Files of one resource: a model, a texture file and up to eight animations (0x24 bytes). */
typedef struct FieldG3dObjResDesc {
    u32 modelArc;                          /* archive handle of the model file */
    u32 texArc;                            /* archive handle of the texture file, 0 = none */
    u32 anmArc;                            /* archive handle of the animation files */
    u16 modelFile;
    u16 texFile;
    u16 anmFile[FIELD_G3DOBJ_ANIME_MAX];
    u8  anmCount;
} FieldG3dObjResDesc;

/* One loaded model with its texture and animations (0x2C bytes). */
typedef struct FieldG3dObjRes {
    G3dResource *model;
    G3dResource *texture;
    G3dResource *anime[FIELD_G3DOBJ_ANIME_MAX];
    u8 animeCount;
    u8 state;                              /* FIELD_G3DOBJ_RES_* */
} FieldG3dObjRes;

/* One placed object (0x68 bytes). */
typedef struct FieldG3dObj {
    u32 kind : 2;                          /* FIELD_G3DOBJ_* */
    u32 culling : 1;                       /* draw with the view box test */
    u32 hidden : 1;
    u32 manualDraw : 1;                    /* skipped by the batch draw */
    u32 redrawFlag : 1;                    /* cleared by the batch draw */
    u32 reserved : 26;
    u16 resIdx;                            /* index in FieldG3dObjCtrl.resTbl */
    u16 modelIdx;                          /* model inside the resource */
    VecFx32 trans;
    VecFx32 scale;
    MtxFx33 rotate;
    G3dObject *object;
    G3dAnime *anime[FIELD_G3DOBJ_ANIME_MAX];
} FieldG3dObj;

/* The control: a table of resources and a table of objects (0x14 bytes). */
typedef struct FieldG3dObjCtrl {
    u16 heapId;
    u16 ready;                             /* 0 while a table is being changed */
    u16 resCount;
    u16 objCount;
    FieldG3dObjRes *resTbl;
    FieldG3dObj *objTbl;
    const u8 *palTable;                    /* palette conversion table, 0 = none */
} FieldG3dObjCtrl;

#endif
