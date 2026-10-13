/*
 * function: NNSi_G2dRendererDrawCellEntryTransformed
 * address:  0x020659D4
 * packet:   pkt_02065020
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_G2dPushMtx  0x0206615C  arm
 *   NNSi_G2dIsRndCoreFlipH  0x02067B50  arm
 *   NNSi_G2dIsRndCoreFlipV  0x02067B64  arm
 *   NNS_G2dTranslate  0x020663D0  arm
 *   NNS_G2dRotZ  0x02066620  arm
 *   NNS_G2dScale  0x020664CC  arm
 *   NNSi_G2dRendererDrawCellTransformed  0x02065878  arm
 *   NNS_G2dPopMtx  0x02066380  arm
 *   g_02147B88     0x02147B88  data
 *   FX_SinCosTable_     0x020A1B38  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed   short s16;
typedef unsigned int   u32;
typedef int            fx32;

struct Cmd020659D4 {
    int  unk_00;
    u8   pad_04[4];
    int  unk_08;
    u8   pad_0c[4];
    fx32 unk_10;
    fx32 unk_14;
    s16  unk_18;
    s16  unk_1a;
    u16  unk_1c;
    u16  unk_1e;
};

struct B88020659D4 {
    u8  pad_00[8];
    int unk_08;
};

extern void NNS_G2dPushMtx(void);
struct G2dOamState;
struct Obj02065878;
extern u32 NNSi_G2dIsRndCoreFlipH(const struct G2dOamState *p);
extern u32 NNSi_G2dIsRndCoreFlipV(const struct G2dOamState *p);
extern void  NNS_G2dTranslate(fx32 x, fx32 y, fx32 z);
extern void  NNS_G2dRotZ(fx32 sn, fx32 cs);
extern void  NNS_G2dScale(fx32 sx, fx32 sy, fx32 sz);
extern void NNSi_G2dRendererDrawCellTransformed(struct Obj02065878 *c);
extern void  NNS_G2dPopMtx(int a);
extern struct B88020659D4 g_02147B88;
extern s16 FX_SinCosTable_[];

void NNSi_G2dRendererDrawCellEntryTransformed(struct Cmd020659D4 *c)
{
    int a;

    if (c->unk_08 == 0)
        return;

    a = c->unk_00;
    NNS_G2dPushMtx();

    if ((c->unk_1e & 8) != 0) {
        int x, y;

        y = c->unk_1a;
        x = c->unk_18;

        if (NNSi_G2dIsRndCoreFlipH((const struct G2dOamState *)g_02147B88.unk_08) != 0)
            x = -x;
        if (NNSi_G2dIsRndCoreFlipV((const struct G2dOamState *)g_02147B88.unk_08) != 0)
            y = -y;

        NNS_G2dTranslate(x << 12, y << 12, 0);
    }

    if ((c->unk_1e & 4) != 0) {
        int i = c->unk_1c >> 4;

        NNS_G2dRotZ(FX_SinCosTable_[i * 2], FX_SinCosTable_[i * 2 + 1]);
    }

    if ((c->unk_1e & 2) != 0)
        NNS_G2dScale(c->unk_10, c->unk_14, 0x1000);

    NNSi_G2dRendererDrawCellTransformed((struct Obj02065878 *)a);
    NNS_G2dPopMtx(1);
}
