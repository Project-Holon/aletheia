/*
 * function: FLDEFF_GYOE_DrawTask
 * address:  0x021BB68C
 * packet:   pkt_ov021_021BB68C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Twin of ov021_func_02189810 (save/modify/restore of the projection matrix
 * g_DefaultProjectionMtx).  Here the matrix is read through a pointer local initialised
 * at its declaration, which is what loads its address before the soft-float
 * conversion; `saved = g_DefaultProjectionMtx` loads it after (22 bytes off with the
 * pointer declared first, r4/r5 swapped with it declared last).
 *
 * symbols:
 *   gGyoeDrawTransformInit       0x021D9AA4  data  a4
 *   _fflt            0x0209BDBC  arm
 *   _fadd            0x0209C95C  arm
 *   _fsub            0x0209CB8C  arm
 *   _ffix            0x0209C494  arm
 *   _ll_mul          0x0209C054  arm
 *   MIi_CpuCopyFast  0x02082B0C  arm
 *   NNS_G3dGlbFlush    0x0206A854  arm
 *   NNS_G3dGeFlushBuffer    0x0206DB80  arm
 *   MTX_Identity33_    0x0207ADC4  arm
 *   FIELD_EFFECT_GetObjectPos    0x021AC1B8  thumb  ov021
 *   G3D_SYSTEM_DrawObjectCulling    0x02047AC8  arm
 *   g_DefaultProjectionMtx       0x02148B54  data
 *   SCREENTEX_CameraState       0x02148BCC  data
 * Addresses are Black-image addresses.
 */

#include "../include/G_Glb.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int fx32;
typedef long long fx64;

typedef struct { fx32 m[4][4]; } MtxFx44;
typedef struct { fx32 x, y, z; } V3;

typedef struct Node {
    V3 pos;
    V3 scale;
    u8 mtx[0x24];
} Node;

typedef struct {
    u8 pad[0x7C];
    u32 flag;
} Glb;

typedef struct {
    u8 pad0[0x24];
    u32 f24[4];
    u16 f34;
} Info;

typedef struct {
    u32 f0;
    u32 f4;
    Info *f8;
} Arg;

extern const Node gGyoeDrawTransformInit;
extern MtxFx44 g_DefaultProjectionMtx;
extern struct Glb SCREENTEX_CameraState;

extern void MIi_CpuCopyFast(const void *src, void *dst, u32 size);
extern void NNS_G3dGlbFlush(void);
extern void NNS_G3dGeFlushBuffer(void);
extern void MTX_Identity33_(void *mtx);
extern void FIELD_EFFECT_GetObjectPos(u32 a, Node *n);
struct Arg;
extern int G3D_SYSTEM_DrawObjectCulling(void *a0, struct Arg *a1);

#define FX_MUL(a, b) ((fx32)(((fx64)(a) * (b) + 0x800) >> 12))
#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? \
                                  ((x) * (1 << 12) + 0.5f) : \
                                  ((x) * (1 << 12) - 0.5f)))

void FLDEFF_GYOE_DrawTask(u32 a, Arg *b)
{
    Node n = gGyoeDrawTransformInit;
    MtxFx44 *g = &g_DefaultProjectionMtx;
    MtxFx44 saved;
    MtxFx44 m;
    fx32 z;

    z = FX_F32_TO_FX32(b->f8->f34);
    saved = *g;
    m = saved;
    m.m[3][2] += FX_MUL(m.m[2][2], z);
    MIi_CpuCopyFast(&m, &g_DefaultProjectionMtx, 0x40);
    SCREENTEX_CameraState.flag &= ~0x50;
    NNS_G3dGlbFlush();
    NNS_G3dGeFlushBuffer();
    MTX_Identity33_(n.mtx);
    FIELD_EFFECT_GetObjectPos(a, &n);
    G3D_SYSTEM_DrawObjectCulling((void *)b->f8->f24[b->f0], (struct Arg *)(&n));
    MIi_CpuCopyFast(&saved, &g_DefaultProjectionMtx, 0x40);
    SCREENTEX_CameraState.flag &= ~0x50;
    NNS_G3dGlbFlush();
    NNS_G3dGeFlushBuffer();
}
