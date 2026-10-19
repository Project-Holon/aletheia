/*
 * nns_g3d_glb_types.h: NitroSystem g3d global state (NNS_G3dGlb at 0x02148B4C),
 * full layout as used by nns_g3d_glb.c.
 *
 * The first part is a mirror of the geometry commands the renderer sends: each
 * cmdN word holds packed command ids and the words that follow it are the
 * parameters of those commands.  The part from 0x100 holds the cached derived
 * matrices, each valid only while its NNS_G3D_GLB_FLAG_* bit is set.
 *
 * Do not include together with nns_g3d_tex_types.h (same type names).
 */
#ifndef NNS_G3D_GLB_TYPES_H
#define NNS_G3D_GLB_TYPES_H

#include "../types.h"

#include "../sdk_fx.h"

/* Matrices are addressable by row and column (m) or by cell name (_rc). */
/* NNS_G3dGlb.flag bits cleared by the base-transform setters: the cached
 * inverse matrices that depend on the base matrix. */
#define NNS_G3D_GLB_FLAG_BASE_DEPENDENT 0xa4u

/* NNS_G3dGlb.flag bits: cached matrix is valid. */
#define NNS_G3D_GLB_FLAG_INV_CAMERA_VALID 0x08u
#define NNS_G3D_GLB_FLAG_INV_PROJ_VALID   0x10u
#define NNS_G3D_GLB_FLAG_INV_VP_VALID     0x40u
#define NNS_G3D_GLB_FLAG_WV_VALID         0x80u

typedef struct {
    u32     cmd0;             /* 0x00 */
    u32     mtxmodeProj;      /* 0x04 */
    MtxFx44 projMtx;          /* 0x08 */
    u32     mtxmodePosVec;    /* 0x48 */
    MtxFx43 cameraMtx;        /* 0x4C */
    u32     cmd1;             /* 0x7C */
    u32     lightVec[4];      /* 0x80 */
    u32     cmd2;             /* 0x90 */
    u32     prmMatColor0;     /* 0x94 */
    u32     prmMatColor1;     /* 0x98 */
    u32     prmPolygonAttr;   /* 0x9C */
    u32     prmViewPort;      /* 0xA0 */
    u32     cmd3;             /* 0xA4 */
    u32     lightColor[4];    /* 0xA8 */
    u32     cmd4;             /* 0xB8 */
    MtxFx33 prmBaseRot;       /* 0xBC */
    VecFx32 prmBaseTrans;     /* 0xE0 */
    VecFx32 prmBaseScale;     /* 0xEC */
    u32     prmTexImageParam; /* 0xF8 */
    u32     flag;             /* 0xFC */
    MtxFx43 invCameraMtx;     /* 0x100 */
    MtxFx43 wvMtx;            /* 0x130 world-view: base * camera, then scaled */
    MtxFx43 invWvMtx;         /* 0x160 */
    u32     pad190[12];       /* 0x190 */
    MtxFx44 invProjMtx;       /* 0x1C0 */
    MtxFx44 invVpMtx;         /* 0x200 inverse projection * inverse camera */
    union {
        MtxFx33 viewFlipMtx;  /* 0x240 constant diag(0, 1.0, -1.0) set at init */
        struct {
            VecFx32 camPos;   /* 0x240, written by the look-at setter */
            VecFx32 camUp;    /* 0x24C */
            VecFx32 camTarget; /* 0x258 */
        };
    };
} NNSG3dGlb;

extern NNSG3dGlb NNS_G3dGlb;

#endif
