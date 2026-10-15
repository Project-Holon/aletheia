/*
 * function: PARTICLE_DrawSystem
 * address:  0x02051414
 * packet:   pkt_02051414
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sDefaultViewVec      0x020A159C  data
 *   g_renderState      0x02148B4C  data
 *   g_renderStateDrawParams      0x02148B98  data
 *   g_renderStateIdentityMtx      0x02148C08  data
 *   G3D_SYSTEM_GetProjection   0x020467EC  arm
 *   G3D_SYSTEM_SetProjection   0x02046858  arm
 *   G3D_SYSTEM_GetLookAt   0x02046AFC  arm
 *   G3D_SYSTEM_SetLookAt   0x02046B40  arm
 *   G3D_SYSTEM_ApplyLookAt   0x020479D8  arm
 *   G3D_CAMERA_Reset   0x02048AD0  arm
 *   SPL_EMITTER_FreeNodeHeap   0x020526A8  arm
 *   NNS_G3dGlbBaseTrans   0x0206A9DC  arm
 *   NNS_G3dGlbBaseScale   0x0206AA0C  arm
 *   NNS_G3dGeFlushBuffer   0x0206DB80  arm
 *   MI_Copy36B      0x02082B60  arm
 *   MTX_Identity33_ 0x0207ADC4  arm
 *
 * particle.c, the 3D setup half of a two-phase emitter pass (wave 13).  When
 * the private block at +0x20 exists: bring up the two frame objects (0x20 and
 * 0x24 bytes), copy the model vector 0x020A159C into a local, build an
 * identity 3x3, zero a vector for NNS_G3dGlbBaseTrans, copy the 3x3 to the
 * 0x02148C08 scratch, clear bits 0xa4 of word 63 of 0x02148B4C and hand the
 * model vector to NNS_G3dGlbBaseScale; then the shared call SPL_EMITTER_FreeNodeHeap and, when
 * the block is still there, the teardown.
 *
 * WHAT CLOSED IT (docs/notes/pkt_02051414.c.txt had it at 152 bytes out,
 * 220 against 224): the three setup-only locals are declared in a NESTED
 * BLOCK with INITIALISERS -- `VecFx32 v = sDefaultViewVec; MtxFx33 m;
 * VecFx32 z = {0, 0, 0};`.  The aggregate initialiser `{0, 0, 0}` is what
 * keeps &z in a callee-saved register (r6) and stores the zero through it,
 * which costs the image's extra r7 (&v) and the push of r3/r7.  Assigning the
 * three fields, a pointer local, an inline VEC_Set, a compound literal and
 * the same locals in the if-block without initialisers all stay at 152 out.
 *
 * sDefaultViewVec resolves through sole-ref/self (its only pool word is inside
 * this function; the ROM word equals the relocation), SPL_EMITTER_FreeNodeHeap through
 * sole-ref/code.
 */
#include "../include/Obj06994.h"

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct {
    u32 x, y, z;
} VecFx32;

typedef struct {
    u32 m[9];
} MtxFx33;

typedef struct {
    u32 w[8];
} Blk32;

typedef struct {
    u32 w[9];
} Blk36;

extern VecFx32  sDefaultViewVec;
extern u32      g_renderState[];
extern u32      g_renderStateDrawParams[];
extern u32      g_renderStateIdentityMtx[];

extern void G3D_SYSTEM_GetProjection(int p0);
extern void G3D_SYSTEM_SetProjection(const u32 *src);
extern void G3D_SYSTEM_GetLookAt(u8 *dst);
extern void G3D_SYSTEM_SetLookAt(u8 *a0);
extern void G3D_SYSTEM_ApplyLookAt(void);
struct Head;
struct Light;
extern void G3D_CAMERA_Reset(struct Light *l);
extern void SPL_EMITTER_FreeNodeHeap(struct Head *h, u32 a);
extern void NNS_G3dGlbBaseTrans(void *p);
extern void NNS_G3dGlbBaseScale(VecFx32 *p);
extern void NNS_G3dGeFlushBuffer(void);
extern void MI_Copy36B(const void *src, void *dst);
extern void MTX_Identity33_(MtxFx33 *p);

void PARTICLE_DrawSystem(u8 *a0)
{
    Blk32    b;
    Blk36    g;

    if (((struct Obj06994 *)a0)->f20 != 0) {
        G3D_SYSTEM_GetProjection((int)(&b));
        G3D_SYSTEM_GetLookAt((u8 *)(&g));
        {
            VecFx32  v = sDefaultViewVec;
            MtxFx33  m;
            VecFx32  z = {0, 0, 0};
            MTX_Identity33_(&m);
            NNS_G3dGlbBaseTrans(&z);
            MI_Copy36B(&m, g_renderStateIdentityMtx);
            g_renderState[63] = g_renderState[63] & ~0xa4u;
            NNS_G3dGlbBaseScale(&v);
        }
        G3D_CAMERA_Reset((struct Light *)(((struct Obj06994 *)a0)->f20));
        G3D_SYSTEM_ApplyLookAt();
        NNS_G3dGeFlushBuffer();
    }
    SPL_EMITTER_FreeNodeHeap((struct Head *)(((struct Obj06994 *)a0)->f0), (u32)g_renderStateDrawParams);
    if (((struct Obj06994 *)a0)->f20 == 0)
        return;
    G3D_SYSTEM_SetProjection((const u32 *)(&b));
    G3D_SYSTEM_SetLookAt((u8 *)(&g));
    G3D_SYSTEM_ApplyLookAt();
    NNS_G3dGeFlushBuffer();
}
