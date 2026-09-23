/*
 * docs/families/g3d_util.h -- shared declarations for the g3d_util.c family
 * (the 3D resource/object utility built on the g3d_system.c layer),
 * 0x02047CFC..0x02048A24 in the ARM9 image.  __FILE__ word 0x020A7EB8
 * ("g3d_util.c", layout/file_anchors.txt rows at 0x02047E4C, 0x02048738,
 * 0x02048914).
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and match.py never sees it.  Every offset below is fixed by
 * a load or store in a matched source named beside it.
 *
 * Addresses are Black-image addresses throughout (docs/AGENT-BRIEF.md s8).
 *
 * THE LEVER FOR THIS FAMILY: write it in its own library shape.  Every
 * function closed on the first or second compile once the utility object,
 * the setup records and the u16 prototypes below were used (wave 14), after
 * two waves of register-level spelling sweeps on generic `u8 *` + offset
 * readings had stalled at 7 to 50 bytes.  In particular:
 *   - unit index and heap id are u16 PARAMETERS of the callees; the per-call
 *     lsl/lsr pairs in the adders are implicit argument conversions, not
 *     casts (func_02047E88);
 *   - the constructor's counts and heap id are u16 parameters
 *     (func_02047CFC; with s32 the second half's constants CSE away);
 *   - the resource loader is an inline switch that writes through an out
 *     pointer (func_02048330).
 */

#ifndef G3D_UTIL_H
#define G3D_UTIL_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

/* One unit: a run of resources and a run of objects in the two tables.
 * 0xffff in resIdx marks a free record (func_02047CFC fills all four). */
typedef struct {
    u16 resIdx;         /* +0x0  func_02047E88, func_02048744 */
    u16 resCount;       /* +0x2  func_02047E88, func_02048120 */
    u16 objIdx;         /* +0x4  func_02048918, sub_020489F4 */
    u16 objCount;       /* +0x6  func_02048918, sub_02048A00 */
} Unit;

/* The utility object, 0x218 bytes (func_02047CFC allocates sizeof). */
typedef struct {
    void **res;         /* +0x000  resource handles; func_02048330, sub_02048A0C */
    u8    *resStat;     /* +0x004  per resource status byte; func_02048744 */
    u16    resCount;    /* +0x008  func_02047CFC */
    void **obj;         /* +0x00C  object handles; func_02048918, sub_02048A18 */
    u8    *objStat;     /* +0x010  per object status bits 1|2; func_02048330 */
    u16    objCount;    /* +0x014  func_02047CFC */
    Unit   unit[0x40];  /* +0x016  func_02047E88 (64-record scan) */
    u16    heapID;      /* +0x216  func_02048120, func_02048330 */
} Util;

/* Setup records passed to the adders. */
typedef struct {
    u32 arc;            /* +0x0  archive id, or a path for type 3 */
    u16 dat;            /* +0x4  member */
    u16 pad_06;
    u32 type;           /* +0x8  0..3, see createRes in func_02048330 */
} ResSetup;             /* 0xc bytes; func_02048120, func_02048330 (mla #0xc) */

typedef struct {
    u16 anmResIdx;      /* +0x0  0xff = no animation */
    u16 anmDatIdx;      /* +0x2 */
} AnmSetup;

typedef struct {
    u16       mdlResIdx;    /* +0x0 */
    u16       mdlDatIdx;    /* +0x2  func_02047400's second argument */
    u16       texResIdx;    /* +0x4  compared against mdlResIdx */
    u16       pad_06;
    AnmSetup *anmTbl;       /* +0x8 */
    u16       anmCount;     /* +0xC */
} ObjSetup;                 /* 0x10 bytes; func_02048330, func_02048744 */

typedef struct {
    ResSetup *resTbl;   /* +0x0 */
    u16       resCount; /* +0x4 */
    ObjSetup *objTbl;   /* +0x8 */
    u16       objCount; /* +0xC */
} Setup;

/* ---- the family's functions ------------------------------------------ */
Util *func_02047CFC(u16 resCount, u16 objCount, u16 heapID);   /* create */
void  func_02047E54(Util *util);                                /* delete, 5 frees */
u16   func_02047E88(Util *util, const Setup *setup);            /* add unit: 0x02048120 + 0x02048330 */
u16   func_02047F4C(Util *util, const Setup *setup);            /* add unit: 0x02048120 + 0x02048744 */
u16   func_02048010(Util *util, const Setup *setup, u32 extra); /* add unit: 0x02048258 + 0x02048744 */
void  func_020480E4(Util *util, u16 unitIdx);                   /* remove unit: 0x02048918 + 0x020482B4, record = 0xffff */
void  func_02048120(Util *util, u16 unitIdx, const Setup *setup, u16 heapID); /* load resources (inline createRes loop) */
void  func_02048258(Util *util, u16 unitIdx, const Setup *setup, u16 heapID, u32 extra);
void  func_020482B4(Util *util, u16 unitIdx);                   /* release resources */
void  func_02048330(Util *util, u16 unitIdx, const Setup *setup, u16 heapID); /* create objects, loading on demand */
void  func_02048744(Util *util, u16 unitIdx, const Setup *setup, u16 heapID); /* create objects, resources already loaded */
void  func_02048918(Util *util, u16 unitIdx);                   /* delete objects */
/* sub_020489F4 / 02048A00 / 02048A0C / 02048A18: unit objIdx, objCount,
 * res[i], obj[i] getters (src/matched/unit_020489F4.c). */

/* ---- callees (g3d_system.c layer and the heap) ----------------------- */
extern void *func_02030734(u16 heapID, u32 size, int clear, const char *file, int line); /* alloc; low heap = (id & 0x7fff) | 0x8000 */
extern void  func_020307B0(void *p);                     /* free */
extern void *func_02046DB8(u32 arc, u16 dat);            /* resource, type 0 */
extern void *func_02046E90(u32 arc, u16 dat);            /* resource, type 1 */
extern u32   func_02046C94(void);                        /* resource header size */
extern void  func_02046CE0(void *res, void *data);       /* wrap loaded data */
extern void *func_02048F60(u32 arc, u16 dat, u16 heapID);/* load by archive id */
extern void *func_02048F9C(u32 path, u16 dat, u16 heapID);/* load by path */
extern int   func_02046F50(void *res, int type);         /* type check, 1 = texture */
extern void  func_02046FF8(void *res);                   /* texture VRAM transfer */
extern int   func_02047348(void *res);                   /* texture already resident */
extern void *func_02047400(void *mdl, u16 mdlIdx, void *tex);   /* render object create */
extern void *func_02047564(void *rnd, void *res, u16 datIdx);   /* animation create */
extern void *func_0204767C(void *rnd, void **anm, u16 anmCount);/* object create */
extern void *func_02047788(void *obj);                   /* object -> render object */
extern u16   func_0204779C(void *obj);                   /* object animation count */
extern void *func_02047790(void *obj, u16 idx);          /* object animation */
extern void  func_0204762C(void *anm);                   /* animation delete */
extern void *func_02047554(void *rnd);                   /* render -> texture resource */
extern void *func_0204754C(void *rnd);                   /* render -> second resource */
extern void  func_020470D0(void *res);
extern void  func_02046EFC(void *res);
extern void  func_02047504(void *rnd);                   /* render object delete */
extern void  func_02047738(void *obj);                   /* object delete */

#endif /* G3D_UTIL_H */
