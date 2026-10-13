/*
 * unit:     no
 * function: NNSi_G2dRendererDrawCellToSurfaces
 * address:  0x02065438
 * packet:   pkt_02064B68
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The plain actor draw (NNSi_G2dRendererDrawCellTransformed / NNSi_G2dRendererDrawCellZOffset / NNSi_G2dRendererDrawCellTransformedZOffset call
 * it).  With the live object's +0x7c bit 1 set it draws the object itself:
 * an affine record (GetAff: cached per g_02148718.h00 in g_02148718.arr04
 * when +0x404 is set, else rebuilt through NNSi_G2dMCMLoadCurrentMtxToCache) and the selected
 * matrix go to NNS_G2dSetRndCoreCurrentMtx2D for a node whose +0x14 is set, otherwise the
 * slot's g_02147B98 word goes to NNS_G2dSetRndCore3DSoftSpriteZvalue and the matrix alone to
 * NNS_G2dSetRndCoreCurrentMtx3D; then NNS_G2dRndCoreDrawCellVramTransfer(a, g_020A81F8.f04) when that word is
 * not -1, else NNS_G2dRndCoreDrawCell(a).  Without the bit it walks the node list at
 * +0x70 (next at +0x30), drawing every node whose +0x10 is set the same way
 * with the node bound to the object's +0x74 and cleared again after.
 *
 * What closed it: the two loop arms are INLINE HELPERS (DrawA / DrawB), each
 * carrying its own "obj->f74 = 0; NNS_G2dRndCoreEndRendering()" tail.  Written as one if
 * with the shared tail after it (or with the tail duplicated in plain arms)
 * the compiler hoists the f74 store and merges the tails: 20 bytes short /
 * 225 out.  The matrix selection is the else-first GetMtx of
 * NNSi_G2dRendererAfterDrawCell / NNSi_G2dRendererCallSurfaceOamFunc.  ../2.0/sp2; 1.1p1 is 1028 bytes, 850 out.
 *
 * symbols:
 *   g_02147B88     0x02147B88  data  a4
 *   g_020A81F8     0x020A81F8  data  a4
 *   g_02148718     0x02148718  data  a4
 *   g_02147C18     0x02147C18  data  a4
 *   g_02148318     0x02148318  data  a4
 *   g_02147D18     0x02147D18  data  a4
 *   g_02147B98     0x02147B98  data  a4
 *   NNSi_G2dMCMLoadCurrentMtxToCache  0x02064EDC  arm
 *   NNS_G2dSetRndCoreCurrentMtx2D  0x02067B28  arm
 *   NNS_G2dSetRndCoreCurrentMtx3D  0x02067AC0  arm
 *   NNS_G2dRndCoreDrawCellVramTransfer  0x02067DC8  arm
 *   NNS_G2dRndCoreDrawCell  0x02067D14  arm
 *   NNS_G2dSetRndCore3DSoftSpriteZvalue  0x02067B40  arm
 *   NNS_G2dSetRndCoreSurface  0x02067B48  arm
 *   NNS_G2dSetRndCoreOamRegisterFunc  0x02067AAC  arm
 *   NNS_G2dRndCoreBeginRendering  0x02067BA4  arm
 *   NNS_G2dRndCoreEndRendering  0x02067CB0  arm
 */

#include "../include/G_Mtx.h"
#include "../include/G_SlotRec.h"
#include "../include/G_G18.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed   short s16;
typedef unsigned int   u32;
typedef int            fx32;

typedef struct { fx32 m00, m01, m10, m11, tx, ty; } Mtx;

struct Node {
    u8           pad_00[0x10];
    int          f10;
    int          f14;
    u8           pad_18[0x10];
    int          f28;
    int          f2c;
    struct Node *f30;
};

struct Obj {
    u8           pad_00[0x70];
    struct Node *f70;
    struct Node *f74;
    u8           pad_78[4];
    u32          f7c;
};

struct Manager {
    u16         slotCount;
    u16         slotLimit;
    u32         unk_04;
    struct Obj *obj;
    u32         slot;
};

struct Aff {
    fx32 m00, m01, m10, m11;
    u8   f10[0x10];
};

struct Scr {
    u16 h00;
    u8  pad_02[2];
    int f04;
    Mtx mtx;
};

extern struct Manager g_02147B88;
extern struct Scr     g_020A81F8;
extern struct G18 g_02148718;
extern struct SlotRec g_02147C18[];
extern struct Aff     g_02148318[];
extern struct Mtx g_02147D18[];
extern fx32           g_02147B98[];

extern void NNSi_G2dMCMLoadCurrentMtxToCache(void);
struct Ctx;
struct G2dOamState;
struct Src02067AC0;
extern void NNS_G2dSetRndCoreCurrentMtx2D(u32 a, u32 b);
extern void NNS_G2dSetRndCoreCurrentMtx3D(struct Src02067AC0 *src);
typedef signed int     s32;
extern void NNS_G2dRndCoreDrawCellVramTransfer(u32 a0, s32 a1);
extern void NNS_G2dRndCoreDrawCell(u32 arg0);
extern void NNS_G2dSetRndCore3DSoftSpriteZvalue(struct G2dOamState *p, u32 v);
extern void NNS_G2dSetRndCoreSurface(u32 *p, u32 v);
extern void NNS_G2dSetRndCoreOamRegisterFunc(int *p, int a, int b);
extern void NNS_G2dRndCoreBeginRendering(struct Ctx *c);
extern void NNS_G2dRndCoreEndRendering(void);

static inline Mtx *GetMtx(void)
{
    if (g_02147B88.unk_04 != 0) {
        g_020A81F8.mtx.tx = g_02147D18[g_02147B88.slot].tx;
        g_020A81F8.mtx.ty = g_02147D18[g_02147B88.slot].ty;
        return &g_020A81F8.mtx;
    }
    return &((Mtx *)g_02147D18)[g_02147B88.slot];
}

static inline struct Aff *GetAff(void)
{
    struct Aff *aff = 0;
    int r;

    if (g_02147B88.unk_04 == 0 && g_020A81F8.h00 != 0xFFFE)
        r = 1;
    else
        r = 0;
    if (r != 0) {
        if (g_02148718.bDrawMC != 0) {
            aff = g_02148718.arr04[g_02148718.currentCellAnimIdx];
            if (aff == 0) {
                NNSi_G2dMCMLoadCurrentMtxToCache();
                aff = &g_02148318[g_02147C18[(u16)g_02147B88.slot].mtxCacheIdx];
                g_02148718.arr04[g_02148718.currentCellAnimIdx] = aff;
            }
        } else {
            NNSi_G2dMCMLoadCurrentMtxToCache();
            aff = &g_02148318[g_02147C18[(u16)g_02147B88.slot].mtxCacheIdx];
        }
    }
    return aff;
}

static inline void Finish(void *a)
{
    int r = !(g_020A81F8.f04 == -1);

    if (r != 0)
        NNS_G2dRndCoreDrawCellVramTransfer((u32)a, g_020A81F8.f04);
    else
        NNS_G2dRndCoreDrawCell((u32)a);
}

static inline void DrawA(void *a, struct Node *p)
{
    struct Obj *q = g_02147B88.obj;
    struct Aff *aff;

    q->f74 = p;
    NNS_G2dSetRndCoreSurface((u32 *)q, (u32)p);
    NNS_G2dSetRndCoreOamRegisterFunc((int *)q, p->f28, p->f2c);
    NNS_G2dRndCoreBeginRendering((struct Ctx *)q);
    aff = GetAff();
    NNS_G2dSetRndCoreCurrentMtx2D((u32)GetMtx(), (u32)aff);
    Finish(a);
    g_02147B88.obj->f74 = 0;
    NNS_G2dRndCoreEndRendering();
}

static inline void DrawB(void *a, struct Obj *o, struct Node *p)
{
    struct Obj *q = g_02147B88.obj;

    q->f74 = p;
    NNS_G2dSetRndCoreSurface((u32 *)q, (u32)p);
    NNS_G2dRndCoreBeginRendering((struct Ctx *)q);
    NNS_G2dSetRndCore3DSoftSpriteZvalue((struct G2dOamState *)o, g_02147B98[g_02147B88.slot]);
    NNS_G2dSetRndCoreCurrentMtx3D((struct Src02067AC0 *)GetMtx());
    Finish(a);
    g_02147B88.obj->f74 = 0;
    NNS_G2dRndCoreEndRendering();
}

void NNSi_G2dRendererDrawCellToSurfaces(void *a)
{
    struct Obj *o = g_02147B88.obj;
    struct Node *p = o->f70;

    if ((o->f7c & 2) != 0) {
        if (p->f14 != 0) {
            struct Aff *aff = GetAff();
            NNS_G2dSetRndCoreCurrentMtx2D((u32)GetMtx(), (u32)aff);
            Finish(a);
        } else {
            NNS_G2dSetRndCore3DSoftSpriteZvalue((struct G2dOamState *)o, g_02147B98[g_02147B88.slot]);
            NNS_G2dSetRndCoreCurrentMtx3D((struct Src02067AC0 *)GetMtx());
            Finish(a);
        }
        return;
    }

    for (; p != 0; p = p->f30) {
        if (p->f10 != 0) {
            if (p->f14 != 0)
                DrawA(a, p);
            else
                DrawB(a, o, p);
        }
    }
}
