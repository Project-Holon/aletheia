#ifndef GAME_ARM9_NNS_G3D_TEX_MTX_H
#define GAME_ARM9_NNS_G3D_TEX_MTX_H

/* Public functions of nns_g3d_tex_mtx.c, prototypes copied from their definitions. */

struct DST;
struct SRC;
struct TexMtxObj;
typedef struct TexMtxObj TexMtxObj;

#include "../arm9/nns_g3d_anm_calc_types.h"

void NNSi_G3dSendTexMtx(NNSG3dMatAnmResult *pMatAnm);
void NNSi_G3dTexMtxScaleRot_Max(struct DST *d, struct SRC *s);
void NNSi_G3dTexMtxRot_Max(struct DST *d, struct SRC *s);
void NNSi_G3dTexMtxScale_Max(struct DST *d, struct SRC *s);
void NNSi_G3dTexMtxIdentity_Max(struct DST *d);
void NNSi_G3dSendTexMtx_Max(TexMtxObj *o);

#endif
