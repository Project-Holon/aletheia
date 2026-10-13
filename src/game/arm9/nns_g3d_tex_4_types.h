/*
 * nns_g3d_tex_4_types.h: NitroSystem g3d global state (NNS_G3dGlb at 0x02148B4C)
 * for the NNS_G3dGlb setter files nns_g3d_glb_3.c, nns_g3d_glb_4.c and
 * nns_g3d_glb_5.c.
 *
 * The block is a mirror of the geometry commands the renderer sends: each
 * cmdN word holds packed command ids and the words that follow it are the
 * parameters of those commands.
 */
#ifndef NNS_G3D_TEX_4_TYPES_H
#define NNS_G3D_TEX_4_TYPES_H

typedef unsigned int u32;
typedef int          fx32;

typedef struct { fx32 x, y, z; } VecFx32;
typedef struct { fx32 m[3][3]; } MtxFx33;
typedef struct { fx32 m[4][3]; } MtxFx43;
typedef struct { fx32 m[4][4]; } MtxFx44;

/* NNS_G3dGlb.flag bits cleared by the base-transform setters: the cached
 * inverse matrices that depend on the base matrix. */
#define NNS_G3D_GLB_FLAG_BASE_DEPENDENT 0xa4u

typedef struct {
    u32     cmd0;
    u32     mtxmodeProj;
    MtxFx44 projMtx;
    u32     mtxmodePosVec;
    MtxFx43 cameraMtx;
    u32     cmd1;
    u32     lightVec[4];
    u32     cmd2;
    u32     prmMatColor0;
    u32     prmMatColor1;
    u32     prmPolygonAttr;
    u32     prmViewPort;
    u32     cmd3;
    u32     lightColor[4];
    u32     cmd4;
    MtxFx33 prmBaseRot;
    VecFx32 prmBaseTrans;
    VecFx32 prmBaseScale;
    u32     prmTexImageParam;
    u32     flag;
} NNSG3dGlb;

extern NNSG3dGlb NNS_G3dGlb;

#endif
