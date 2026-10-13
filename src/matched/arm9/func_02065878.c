/*
 * unit:     no
 * function: NNSi_G2dRendererDrawCellTransformed
 * address:  0x02065878
 * packet:   pkt_02064B68
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The plain draw of one cell actor with its inline transform record, the
 * sibling of src/matched/NNSi_G2dRendererDrawMultiCellTransformed.c (record at +0x30 here, laid out
 * exactly as struct DrawCmd of docs/families/cluster_02064B68.h shifted by
 * 0x30: handle +0x30, alternate-surface id +0x38, scale +0x40/+0x44,
 * translate +0x48/+0x4a, angle +0x4c, flags +0x4e).  The draw itself is an
 * inline bracket: with a surface id other than -1 the id is published in
 * g_020A81F8+4 around NNSi_G2dRendererDrawCellToSurfaces and reset to -1 afterwards.  The
 * bracket is written out twice in the image (untransformed early exit and
 * the transformed tail), which is what an inline helper gives.
 *
 * Pinned to ../2.0/sp2: the image rematerialises the -1 (`mvn r0, #0` for
 * the compare, `mvn r1, #0` for the reset) and keeps a MATERIALISED boolean
 * (`movne r0, #1` / `moveq r0, #0` / `cmp r0, #0`) in front of each bracket.
 * THE LEVER is the spelling of that boolean: `r = !(c->unk_38 == -1);`.
 * Under the pin, `c->unk_38 != -1` (as an inline return, a named local, a
 * ternary, `!!(...)` or an if/else pair of assignments) folds the test into
 * a branch and is 324 bytes against 348; `r = 0; if (...) r = 1;` is size-
 * exact but 36 out; only the negated equality is EXACT.  Under dsi/1.1p1
 * every spelling is 308..340 bytes.
 *
 * symbols:
 *   NNSi_G2dRendererDrawCellToSurfaces  0x02065438  arm
 *   NNS_G2dPushMtx  0x0206615C  arm
 *   NNSi_G2dIsRndCoreFlipH  0x02067B50  arm
 *   NNSi_G2dIsRndCoreFlipV  0x02067B64  arm
 *   NNS_G2dTranslate  0x020663D0  arm
 *   NNS_G2dRotZ  0x02066620  arm
 *   NNS_G2dScale  0x020664CC  arm
 *   NNS_G2dPopMtx  0x02066380  arm
 *   g_02147B88     0x02147B88  data  a4
 *   g_020A81F8     0x020A81F8  data  a4
 *   FX_SinCosTable_     0x020A1B38  data  a2
 */

#include "../include/G_Scr.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed   short s16;
typedef unsigned int   u32;
typedef int            fx32;

struct Obj02065878 {
    u8   pad_00[0x30];
    void *unk_30;
    u8   pad_34[4];
    int  unk_38;
    u8   pad_3c[4];
    fx32 unk_40;
    fx32 unk_44;
    s16  unk_48;
    s16  unk_4a;
    u16  unk_4c;
    u16  unk_4e;
};

struct B8802065878 {
    u8  pad_00[8];
    int unk_08;
};

extern void  NNSi_G2dRendererDrawCellToSurfaces(void *a);
extern void NNS_G2dPushMtx(void);
struct G2dOamState;
extern u32 NNSi_G2dIsRndCoreFlipH(const struct G2dOamState *p);
extern u32 NNSi_G2dIsRndCoreFlipV(const struct G2dOamState *p);
extern void  NNS_G2dTranslate(fx32 x, fx32 y, fx32 z);
extern void  NNS_G2dRotZ(fx32 sn, fx32 cs);
extern void  NNS_G2dScale(fx32 sx, fx32 sy, fx32 sz);
extern void  NNS_G2dPopMtx(int a);
extern struct B8802065878 g_02147B88;
extern struct Scr g_020A81F8;
extern s16 FX_SinCosTable_[];

static inline void Draw(struct Obj02065878 *c, void *a)
{
    int r;
    r = !(c->unk_38 == -1);
    if (r != 0) {
        g_020A81F8.currenVramTransferHandle_ = c->unk_38;
        NNSi_G2dRendererDrawCellToSurfaces(a);
        g_020A81F8.currenVramTransferHandle_ = -1;
    } else {
        NNSi_G2dRendererDrawCellToSurfaces(a);
    }
}

void NNSi_G2dRendererDrawCellTransformed(struct Obj02065878 *c)
{
    void *a = c->unk_30;

    if (c->unk_4e == 0) {
        Draw(c, a);
        return;
    }

    NNS_G2dPushMtx();

    if ((c->unk_4e & 8) != 0) {
        int x, y;

        y = c->unk_4a;
        x = c->unk_48;

        if (NNSi_G2dIsRndCoreFlipH((const struct G2dOamState *)g_02147B88.unk_08) != 0)
            x = -x;
        if (NNSi_G2dIsRndCoreFlipV((const struct G2dOamState *)g_02147B88.unk_08) != 0)
            y = -y;

        NNS_G2dTranslate(x << 12, y << 12, 0);
    }

    if ((c->unk_4e & 4) != 0) {
        int i = c->unk_4c >> 4;

        NNS_G2dRotZ(FX_SinCosTable_[i * 2], FX_SinCosTable_[i * 2 + 1]);
    }

    if ((c->unk_4e & 2) != 0)
        NNS_G2dScale(c->unk_40, c->unk_44, 0x1000);

    Draw(c, a);
    NNS_G2dPopMtx(1);
}
