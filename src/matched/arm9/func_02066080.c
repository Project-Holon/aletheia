/*
 * unit:     no
 * function: NNSi_G2dRendererDrawMultiCellTransformed
 * address:  0x02066080
 * packet:   pkt_02064B68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Applies one object's transform command, the twin of
 * src/matched/NNSi_G2dRendererDrawCellEntryTransformed.c one layer up: the command record lives inline
 * at +0x34 of the object (scale at +0x4c/+0x50, translate at +0x54/+0x56,
 * angle at +0x58, flags at +0x5a) and the draw call is NNS_G2dDrawMultiCell on
 * that inline record.  With no flags the record is drawn untransformed;
 * otherwise a matrix slot is pushed (NNS_G2dPushMtx gets the flag word, as
 * NNSi_G2dRendererDrawCellEntryTransformed hands it its guard word), translate / rotate / scale are
 * applied per flag bit 8 / 4 / 2, the record is drawn and the slot popped.
 * EXACT on the first compile under dsi/1.1p1 (and equally under ../2.0/sp2;
 * no pin taken, the default is kept).  The two levers NNSi_G2dRendererDrawCellEntryTransformed needed
 * carry over unchanged: y and x are assigned in separate statements, y
 * first, and the translate values are int, not s16.
 *
 * symbols:
 *   NNS_G2dDrawMultiCell  0x02065DB4  arm
 *   NNS_G2dPushMtx  0x0206615C  arm
 *   NNSi_G2dIsRndCoreFlipH  0x02067B50  arm
 *   NNSi_G2dIsRndCoreFlipV  0x02067B64  arm
 *   NNS_G2dTranslate  0x020663D0  arm
 *   NNS_G2dRotZ  0x02066620  arm
 *   NNS_G2dScale  0x020664CC  arm
 *   NNS_G2dPopMtx  0x02066380  arm
 *   g_02147B88     0x02147B88  data
 *   FX_SinCosTable_     0x020A1B38  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed   short s16;
typedef unsigned int   u32;
typedef int            fx32;

struct Obj02066080 {
    u8   pad_00[0x34];
    u8   unk_34[0x18];
    fx32 unk_4c;
    fx32 unk_50;
    s16  unk_54;
    s16  unk_56;
    u16  unk_58;
    u16  unk_5a;
};

struct B8802066080 {
    u8  pad_00[8];
    int unk_08;
};

struct NNSG2dMultiCellInstance;
extern void NNS_G2dDrawMultiCell(const struct NNSG2dMultiCellInstance *pMC);
extern void NNS_G2dPushMtx(void);
struct G2dOamState;
extern u32 NNSi_G2dIsRndCoreFlipH(const struct G2dOamState *p);
extern u32 NNSi_G2dIsRndCoreFlipV(const struct G2dOamState *p);
extern void  NNS_G2dTranslate(fx32 x, fx32 y, fx32 z);
extern void  NNS_G2dRotZ(fx32 sn, fx32 cs);
extern void  NNS_G2dScale(fx32 sx, fx32 sy, fx32 sz);
extern void  NNS_G2dPopMtx(int a);
extern struct B8802066080 g_02147B88;
extern s16 FX_SinCosTable_[];

void NNSi_G2dRendererDrawMultiCellTransformed(struct Obj02066080 *c)
{
    if (c->unk_5a == 0) {
        NNS_G2dDrawMultiCell((const struct NNSG2dMultiCellInstance *)c->unk_34);
        return;
    }

    NNS_G2dPushMtx();

    if ((c->unk_5a & 8) != 0) {
        int x, y;

        y = c->unk_56;
        x = c->unk_54;

        if (NNSi_G2dIsRndCoreFlipH((const struct G2dOamState *)g_02147B88.unk_08) != 0)
            x = -x;
        if (NNSi_G2dIsRndCoreFlipV((const struct G2dOamState *)g_02147B88.unk_08) != 0)
            y = -y;

        NNS_G2dTranslate(x << 12, y << 12, 0);
    }

    if ((c->unk_5a & 4) != 0) {
        int i = c->unk_58 >> 4;

        NNS_G2dRotZ(FX_SinCosTable_[i * 2], FX_SinCosTable_[i * 2 + 1]);
    }

    if ((c->unk_5a & 2) != 0)
        NNS_G2dScale(c->unk_4c, c->unk_50, 0x1000);

    NNS_G2dDrawMultiCell((const struct NNSG2dMultiCellInstance *)c->unk_34);
    NNS_G2dPopMtx(1);
}
