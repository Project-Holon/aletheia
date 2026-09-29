/*
 * function: func_021CE934
 * address:  0x021CE934
 * packet:   pkt_ov021_021CE934
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201F02C  0x0201F02C  thumb
 *   func_02008534  0x02008534  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02190758  0x02190758  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 f0, f4, f8, fc, f10, f14, f18, f1c, f20;
} S;

extern void func_0201F02C(int a, int b, int c);
extern u32 func_02008534(u32 a);
extern void func_0201EFA4(u32, u32, u32, u32, u32, u32);
extern void func_0201F250(u32, u32, u32);
extern void func_02190758(u32, u32, u32, u32);

void func_021CE934(S *p, u32 b, u32 c)
{
    u32 n;

    if (p->fc != 0) {
        func_0201F02C(p->f4, 0, b);
        n = func_02008534(b);
        func_0201EFA4(p->f4, 1, n, 5, 2, 1);
        func_0201F250(p->f4, p->f20, p->f1c);
        func_02190758(p->fc, 0, (c & 0xfff) << 4, p->f20);
    }
}
