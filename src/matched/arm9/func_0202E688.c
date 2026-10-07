/*
 * function: func_0202E688
 * address:  0x0202E688
 * packet:   pkt_0202E688
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_020A02B8        0x020A02B8  data
 *   g_020A02C4        0x020A02C4  data
 *   g_020A0300        0x020A0300  data
 *   FX_SinCosTable_   0x020A1B38  data
 *   g_020A2B38        0x020A2B38  data
 *   g_02148B54        0x02148B54  data
 *   g_02148B98        0x02148B98  data
 *   g_02148BCC        0x02148BCC  data
 *   g_02148D8C        0x02148D8C  data
 *   g_02148D98        0x02148D98  data
 *   g_02148DA4        0x02148DA4  data
 *   func_02047A60     0x02047A60  arm
 *   MTX_PerspectiveW  0x0207C408  arm
 *   MTX_LookAt        0x0207BCA0  arm
 *   MTX_RotX33_       0x0207AF00  thumb
 *
 * One camera/billboard setup for the texture upload path: three VecFx32
 * globals are snapshotted into locals (0x020A02C4 -> cam, 0x020A02B8 -> tgt,
 * up zeroed between them), a 60-byte render block is copied up from
 * 0x020A0300, the perspective matrix is built with the SDK's
 * MTX_Perspective(FX_SinIdx(0xE38), FX_CosIdx(0xE38), ...) (a 20 degree
 * half-angle; FX_SinCosTable_ at 0x020A1B38), the three vectors are stored back
 * out to 0x02148D8C/0x02148D98/0x02148DA4 and MTX_LookAt writes the view
 * matrix to 0x02148B98.  The two `bics` on word 31 of 0x02148BCC are modes:
 * the first clears 0x50 before the vectors are committed, the second clears
 * 0xe8 after the look-at.  MTX_RotX33_ then writes the 3x3 at +0x18 of the
 * copied block (buf[6]) from the (sin, cos) pair at the head of 0x020A2B38.
 *
 * WAVE 16: the 10-byte residue of docs/notes/pkt_0202E560.c.txt (the cos
 * offset `movs r1, #0xe` issued one slot early) was the SDK inlines.  Written
 * as FX_SinIdx / FX_CosIdx inside the MTX_Perspective inline rather than
 * two constant table reads straight into MTX_PerspectiveW, the argument IR
 * comes out in the image's order.  The old `literal` cap on the four rodata
 * pool words is carried by sole-ref/self now.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202E688.c \
 *       --func func_0202E688 --addr 0x0202E688 --cc 1.1p1 --thumb
 */

#include "../include/G_Glb.h"

typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;

typedef struct {
    s32 x, y, z;
} VecFx32;

typedef struct {
    s32 m[9];
} MtxFx33;

typedef struct {
    u32      f[6];
    MtxFx33  m;
} Blk;

extern VecFx32 g_020A02C4;
extern VecFx32 g_020A02B8;
extern Blk      g_020A0300;
extern const s16 FX_SinCosTable_[];

static inline s16 FX_SinIdx(int idx)
{
    return FX_SinCosTable_[((idx >> 4) << 1)];
}

static inline s16 FX_CosIdx(int idx)
{
    return FX_SinCosTable_[((idx >> 4) << 1) + 1];
}

extern s16      g_020A2B38[];
extern u32      g_02148B54[];
extern u32      g_02148B98[];
extern struct Glb g_02148BCC;
extern VecFx32  g_02148D8C;
extern VecFx32  g_02148D98;
extern VecFx32  g_02148DA4;

struct Arg;
extern void func_02047A60(void *a0, struct Arg *a1);
extern void MTX_PerspectiveW(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, void *g);
static inline void MTX_Perspective(s32 fovySin, s32 fovyCos, s32 aspect,
                                   s32 n, s32 f, void *mtx)
{
    MTX_PerspectiveW(fovySin, fovyCos, aspect, n, f, 0x1000, mtx);
}

extern void MTX_LookAt(const VecFx32 *cam, const VecFx32 *tgt,
                       const VecFx32 *up, void *mtx);
extern void MTX_RotX33_(void *mtx, s32 sinv, s32 cosv);

void func_0202E688(u32 a0)
{
    VecFx32 cam = g_020A02C4;
    VecFx32 up = { 0, 0, 0 };
    VecFx32 tgt = g_020A02B8;
    Blk buf = g_020A0300;

    MTX_Perspective(FX_SinIdx(0xE38), FX_CosIdx(0xE38), 0x1555, 0x1000,
                    0x400000, g_02148B54);
    ((u32 *)&g_02148BCC)[31] &= ~0x50u;
    g_02148D8C = cam;
    g_02148D98 = tgt;
    g_02148DA4 = up;
    MTX_LookAt(&cam, &tgt, &up, g_02148B98);
    ((u32 *)&g_02148BCC)[31] &= ~0xe8u;
    MTX_RotX33_(&buf.m, g_020A2B38[0], g_020A2B38[1]);
    func_02047A60((void *)a0, (struct Arg *)buf.f);
}

