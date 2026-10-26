#ifndef GAME_ARM9_G3D_UTIL_TYPES_H
#define GAME_ARM9_G3D_UTIL_TYPES_H

#include "../types.h"

/* One unit of a G3dUtil: the slice of resources and objects it owns (0xffff = free). */
typedef struct G3dUtilUnit {
    u16 resIdx;
    u16 resCount;
    u16 objIdx;
    u16 objCount;
} G3dUtilUnit;

typedef struct G3dUtil {
    void **res;
    u8    *resStat;
    u16    resCount;
    void **obj;
    u8    *objStat;
    u16    objCount;
    G3dUtilUnit unit[0x40];
    u16    heapID;
} G3dUtil;

typedef struct G3dUtilAnimeSetup {
    u16 anmResIdx;
    u16 anmDatIdx;
} G3dUtilAnimeSetup;

typedef struct G3dUtilObjSetup {
    u16       mdlResIdx;
    u16       mdlDatIdx;
    u16       texResIdx;
    u16       pad_06;
    G3dUtilAnimeSetup *anmTbl;
    u16       anmCount;
} G3dUtilObjSetup;

typedef struct G3dUtilResSetup {
    union {
        u32 id;              /* archive id (types 0 and 2) */
        const char *path;    /* file path (types 1 and 3) */
    } arc;
    u16 dat;
    u16 pad_06;
    u32 type;
} G3dUtilResSetup;

typedef struct G3dUtilSetup {
    G3dUtilResSetup *resTbl;
    u16       resCount;
    G3dUtilObjSetup *objTbl;
    u16       objCount;
} G3dUtilSetup;

#endif
