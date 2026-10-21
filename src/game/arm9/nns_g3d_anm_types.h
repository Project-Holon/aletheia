/*
 * nns_g3d_anm_types.h: NitroSystem g3d animation object and joint animation
 * result, shared by nns_g3d_anm.c and nns_g3d_anm_calc.c.
 */
#ifndef NNS_G3D_ANM_TYPES_H
#define NNS_G3D_ANM_TYPES_H

#include "../types.h"

#define NNS_G3D_ANMOBJ_MAPDATA_MASK  0x300
#define NNS_G3D_ANMOBJ_MAPDATA_EXIST 0x100
#define NNS_G3D_ANMOBJ_MAPDATA_ID    0xff

/* flag bits of NNSG3dJntAnmResult */
#define NNS_G3D_JNTANM_RESULTFLAG_SCALE_ONE    0x01
#define NNS_G3D_JNTANM_RESULTFLAG_ROT_ZERO     0x02
#define NNS_G3D_JNTANM_RESULTFLAG_TRANS_ZERO   0x04
#define NNS_G3D_JNTANM_RESULTFLAG_SCALEEX0_ONE 0x08
#define NNS_G3D_JNTANM_RESULTFLAG_SCALEEX1_ONE 0x10

/* Result of one joint animation sample (0x58 bytes). */
typedef struct NNSG3dJntAnmResult {
    u32  flag;
    fx32 scale[3];
    fx32 scaleEx0[3];
    fx32 scaleEx1[3];
    fx32 rot[3][3];
    fx32 trans[3];
} NNSG3dJntAnmResult;

struct NNSG3dAnmObj;

/* Per-node sampling callback: result type depends on the animation kind. */
typedef void (*NNSG3dAnmObjFunc)(void *result, const struct NNSG3dAnmObj *anmObj, u32 dataIdx);

/* Header of an animation resource: the two category codes select the init handler. */
typedef struct NNSG3dAnmFmtHeader {
    u8  category0;
    u8  dummy_;
    u16 category1;
} NNSG3dAnmFmtHeader;

/* One animation in a blend chain (0x1a bytes of header, then mapData). */
typedef struct NNSG3dAnmObj {
    fx32 frame;
    fx32 ratio;
    const void *resAnm;
    NNSG3dAnmObjFunc funcAnm;
    struct NNSG3dAnmObj *next;
    const void *resTex;
    u8 priority;
    u8 numMapData;
    u16 mapData[1];
} NNSG3dAnmObj;

#endif
