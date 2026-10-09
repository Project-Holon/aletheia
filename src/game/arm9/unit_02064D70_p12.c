/*
 * file:     unit_02064D70_p12.c
 * unit:     no
 * function: func_02066080
 * address:  0x02066080
 * packet:   pkt_02064B68
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Applies one object's transform command, the twin of
 * src/matched/func_020659D4.c one layer up: the command record lives inline
 * at +0x34 of the object (scale at +0x4c/+0x50, translate at +0x54/+0x56,
 * angle at +0x58, flags at +0x5a) and the draw call is func_02065DB4 on
 * that inline record.  With no flags the record is drawn untransformed;
 * otherwise a matrix slot is pushed (func_0206615C gets the flag word, as
 * func_020659D4 hands it its guard word), translate / rotate / scale are
 * applied per flag bit 8 / 4 / 2, the record is drawn and the slot popped.
 * EXACT on the first compile under dsi/1.1p1 (and equally under ../2.0/sp2;
 * no pin taken, the default is kept).  The two levers func_020659D4 needed
 * carry over unchanged: y and x are assigned in separate statements, y
 * first, and the translate values are int, not s16.
 *
 * symbols:
 *   func_02065DB4  0x02065DB4  arm
 *   func_0206615C  0x0206615C  arm
 *   func_02067B50  0x02067B50  arm
 *   func_02067B64  0x02067B64  arm
 *   func_020663D0  0x020663D0  arm
 *   func_02066620  0x02066620  arm
 *   func_020664CC  0x020664CC  arm
 *   func_02066380  0x02066380  arm
 *   g_02147B88     0x02147B88  data
 *   g_020A1B38     0x020A1B38  data
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
extern void func_02065DB4(const struct NNSG2dMultiCellInstance *pMC);
extern void func_0206615C(void);
struct G2dOamState;
extern u32 func_02067B50(const struct G2dOamState *p);
extern u32 func_02067B64(const struct G2dOamState *p);
extern void  func_020663D0(fx32 x, fx32 y, fx32 z);
extern void  func_02066620(fx32 sn, fx32 cs);
extern void  func_020664CC(fx32 sx, fx32 sy, fx32 sz);
extern void  func_02066380(int a);
extern struct B8802066080 g_02147B88;
extern s16 g_020A1B38[];

void func_02066080(struct Obj02066080 *c)
{
    if (c->unk_5a == 0) {
        func_02065DB4((const struct NNSG2dMultiCellInstance *)c->unk_34);
        return;
    }

    func_0206615C();

    if ((c->unk_5a & 8) != 0) {
        int x, y;

        y = c->unk_56;
        x = c->unk_54;

        if (func_02067B50((const struct G2dOamState *)g_02147B88.unk_08) != 0)
            x = -x;
        if (func_02067B64((const struct G2dOamState *)g_02147B88.unk_08) != 0)
            y = -y;

        func_020663D0(x << 12, y << 12, 0);
    }

    if ((c->unk_5a & 4) != 0) {
        int i = c->unk_58 >> 4;

        func_02066620(g_020A1B38[i * 2], g_020A1B38[i * 2 + 1]);
    }

    if ((c->unk_5a & 2) != 0)
        func_020664CC(c->unk_4c, c->unk_50, 0x1000);

    func_02065DB4((const struct NNSG2dMultiCellInstance *)c->unk_34);
    func_02066380(1);
}
