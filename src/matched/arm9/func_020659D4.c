/*
 * function: func_020659D4
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
 *   func_0206615C  0x0206615C  arm
 *   func_02067B50  0x02067B50  arm
 *   func_02067B64  0x02067B64  arm
 *   func_020663D0  0x020663D0  arm
 *   func_02066620  0x02066620  arm
 *   func_020664CC  0x020664CC  arm
 *   func_02065878  0x02065878  arm
 *   func_02066380  0x02066380  arm
 *   g_02147B88     0x02147B88  data
 *   g_020A1B38     0x020A1B38  data
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

extern void  func_0206615C(int a);
struct G2dOamState;
struct Obj02065878;
extern u32 func_02067B50(const struct G2dOamState *p);
extern u32 func_02067B64(const struct G2dOamState *p);
extern void  func_020663D0(fx32 x, fx32 y, fx32 z);
extern void  func_02066620(fx32 sn, fx32 cs);
extern void  func_020664CC(fx32 sx, fx32 sy, fx32 sz);
extern void func_02065878(struct Obj02065878 *c);
extern void  func_02066380(int a);
extern struct B88020659D4 g_02147B88;
extern s16 g_020A1B38[];

void func_020659D4(struct Cmd020659D4 *c)
{
    int a;

    if (c->unk_08 == 0)
        return;

    a = c->unk_00;
    func_0206615C(c->unk_08);

    if ((c->unk_1e & 8) != 0) {
        int x, y;

        y = c->unk_1a;
        x = c->unk_18;

        if (func_02067B50((const struct G2dOamState *)g_02147B88.unk_08) != 0)
            x = -x;
        if (func_02067B64((const struct G2dOamState *)g_02147B88.unk_08) != 0)
            y = -y;

        func_020663D0(x << 12, y << 12, 0);
    }

    if ((c->unk_1e & 4) != 0) {
        int i = c->unk_1c >> 4;

        func_02066620(g_020A1B38[i * 2], g_020A1B38[i * 2 + 1]);
    }

    if ((c->unk_1e & 2) != 0)
        func_020664CC(c->unk_10, c->unk_14, 0x1000);

    func_02065878((struct Obj02065878 *)a);
    func_02066380(1);
}
