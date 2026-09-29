/*
 * function: func_021BC944
 * address:  0x021BC944
 * packet:   pkt_ov088_021BC944
 * region:   ov088
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   tbl_020A1B38   0x020A1B38  data
 *   func_02061CA4  0x02061CA4  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;

typedef struct W {
    u8 pad[0x18];
    u16 f18;
    u16 f1a;
} W;

extern s16 tbl_020A1B38[];
extern void func_02061CA4(int, int, void *, int);

void func_021BC944(W *w)
{
    s32 n = w->f18 + 0x400;
    s32 v;
    s16 s;
    u32 b, g, r;

    if (n >= 0x10000)
        w->f18 = w->f18 - 0xFC00;
    else
        w->f18 = n;
    v = tbl_020A1B38[(w->f18 >> 4) * 2 + 1] + 0x1000;
    s = v / 2;
    b = (u8)(0x1d + (-(s * 8) >> 12));
    r = (u8)(0x19 + (s * -0x14 >> 12));
    g = (u8)(0x1e + (s * -0xf >> 12));
    w->f1a = r | (g << 5) | (b << 10);
    func_02061CA4(0xf, 0x6c, &w->f1a, 2);
}
