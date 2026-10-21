#ifndef ALETHEIA_OV021_FIELD_EFFECT_TYPES_H
#define ALETHEIA_OV021_FIELD_EFFECT_TYPES_H

#include "../arm9/billboard_types.h"

/*
 * Field effect system (field_effect.c). One FieldEffectSys exists per field
 * map; the FLDEFF_* files (shadow, kemuri, grass, ...) keep their shared
 * resources in it and run their effect objects through it.
 */

struct FieldMap;
struct FieldEffectSys;
struct FieldEffectObj;
struct FieldEffectObjMgr;
struct ArcHandle;
struct TcbSystem;

/* One loaded resource of the system; id 0x18 marks a free slot. */
typedef struct FieldEffectResource {
    int id;
    void *handle;
} FieldEffectResource;

/* Table entry that loads and unloads the resource of one id. */
typedef struct FieldEffectResourceDef {
    int id;
    void *(*load)(struct FieldEffectSys *sys, u16 heapId);
    void (*unload)(struct FieldEffectSys *sys, void *handle);
} FieldEffectResourceDef;

typedef struct FieldEffectSys {
    int resourceCount;                    /* 0x00 */
    u16 heapId;                           /* 0x04 */
    u8 pad06[2];
    struct FieldMap *fieldmap;            /* 0x08 */
    struct ArcHandle *arcHandle;          /* 0x0C */
    FieldEffectResource *resources;       /* 0x10 */
    u16 objectCount;                      /* 0x14 */
    u8 modelBaseOffset;                   /* 0x16 */
    u8 modelBaseOffsetAlt;                /* 0x17 */
    void *taskBuffer;                     /* 0x18 */
    struct TcbSystem *taskSys;            /* 0x1C */
    struct FieldEffectObjMgr *objMgr;     /* 0x20 */
    const u8 *paletteTable;               /* 0x24 */
} FieldEffectSys;

typedef void (*FieldEffectObjFunc)(struct FieldEffectObj *obj, void *work);

/* Callbacks of one effect object; slot 0 is never called. */
typedef struct FieldEffectObjFuncs {
    FieldEffectObjFunc unused;
    FieldEffectObjFunc init;
    FieldEffectObjFunc exit;
    FieldEffectObjFunc update;
    FieldEffectObjFunc draw;
} FieldEffectObjFuncs;

typedef struct FieldEffectObj {
    u32 active;                           /* 0x00 */
    u32 mode;                             /* 0x04 */
    void *param;                          /* 0x08 start parameter pointer */
    VecFx32 pos;                          /* 0x0C */
    u8 work[0xA0];                        /* 0x18 */
    FieldEffectObjFuncs funcs;            /* 0xB8 */
    struct FieldEffectObjMgr *mgr;        /* 0xCC */
    void *task;                           /* 0xD0 */
} FieldEffectObj;

typedef struct FieldEffectObjMgr {
    u32 count;                            /* 0x00 */
    u16 heapId;                           /* 0x04 */
    u8 pad06[2];
    FieldEffectObj *objs;                 /* 0x08 */
    struct TcbSystem *taskSys;            /* 0x0C */
} FieldEffectObjMgr;

#endif
