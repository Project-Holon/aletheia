/*
 * function: func_02037478
 * address:  0x02037478
 * packet:   pkt_02037478
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469D0     0x021469D0  data
 *   str_020A7A20   0x020A7A20  data
 *   func_0203D680  0x0203D680  arm
 *   func_02037258  0x02037258  arm
 *   func_0203D6BC  0x0203D6BC  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0203640C  0x0203640C  arm
 *   func_02037234  0x02037234  arm
 *   func_02037224  0x02037224  arm
 *   func_02036B4C  0x02036B4C  arm
 *
 * Second half of net_system init: wipe and re-seed every buffer
 * func_02037288 allocated (docs/families/net_system.h).  Closed from the
 * 520-byte / 135-out source of docs/notes/pkt_02037288_wave25.c.txt with two
 * changes:
 *   1. func_0203640C is a THREE-argument call at every site.  The first
 *      loop's "leftover" r2 is the slot stride f1E0 passed as the header's
 *      length (same finding as func_02037680); with it the file is 12 out.
 *   2. the loop index is declared FIRST, before the three counts.  With
 *      the counts first, n1 and i swap r7/r8 (the last 12 bytes).
 * The three product pairs stay spelled differently per site (n2 + n2 vs
 * n2 << 1, etc.) so the compiler rematerialises instead of CSEing them.
 */
typedef unsigned char  u8;
typedef unsigned int   u32;
typedef signed int     s32;

struct Net {
    u32  f00;
    u32 *f04;
    u8  *f08;
    u8  *f0C;
    u8  *f10;
    u8  *f14;
    u8   pad18[0x1b0 - 0x18];
    u32  f1B0;
    u32  f1B4[8];
    u8   pad1D4[0x1e0 - 0x1d4];
    u32  f1E0;
};

extern struct Net *g_021469D0;
extern u8 str_020A7A20[];
extern s32 func_0203D680(void);
extern s32 func_02037258(void);
extern s32 func_0203D6BC(void);
extern void func_02082BCC(u8 *p, u32 v, u32 n);
extern void func_0203640C(u8 *dst, u8 *src, u32 n);
extern void func_02037234(u8 *p);
extern void func_02037224(u32 a, u32 b);
extern void func_02036B4C(u8 *p);

void func_02037478(void)
{
    s32 i;
    s32 n1;
    s32 n2;
    s32 n3;

    n1 = func_0203D680();
    n2 = func_02037258();
    n3 = func_0203D6BC();

    func_02082BCC(g_021469D0->f10, 0, g_021469D0->f1E0 * n1);
    for (i = 0; i < n1; i++) {
        func_0203640C((u8 *)g_021469D0 + 0x4c + i * 16,
              g_021469D0->f10 + i * g_021469D0->f1E0, g_021469D0->f1E0);
        ((u8 *)g_021469D0)[0x1d7 + i] = 0;
    }

    func_02082BCC(g_021469D0->f0C, 0, n2 + n2);
    func_0203640C((u8 *)g_021469D0 + 0x3c, g_021469D0->f0C, (u32)n2 << 1);
    for (i = 0; i < n2; i++)
        g_021469D0->f08[i] = 0;

    func_02082BCC((u8 *)g_021469D0->f04, 0, n3 * 16 - n3);
    func_0203640C((u8 *)g_021469D0 + 0x1c, (u8 *)g_021469D0->f04, ((u32)n3 << 4) - n3);
    *(u8 *)g_021469D0->f00 = 0xff;
    for (i = 1; i < n3; i++)
        ((u8 *)g_021469D0->f00)[i] = 0;

    func_02082BCC(g_021469D0->f14, 0, g_021469D0->f1E0 + g_021469D0->f1E0 * 2);
    func_0203640C((u8 *)g_021469D0 + 0x2c, g_021469D0->f14,
                  g_021469D0->f1E0 * 3);
    for (i = 0; i < 8; i++) {
        func_02037234((u8 *)g_021469D0 + 0x11c + i * 16);
        g_021469D0->f1B4[i] = 0;
    }
    g_021469D0->f1B0 = 0;
    func_02037234((u8 *)g_021469D0 + 0x19c);
    func_02037224(4, 0x13a);
    str_020A7A20[1] = 4;
    func_02036B4C((u8 *)g_021469D0 + 0xcc);
    func_02036B4C((u8 *)g_021469D0 + 0xf4);
    ((u8 *)g_021469D0)[0x1e8] = 0;
    ((u8 *)g_021469D0)[0x1eb] = 1;
    ((u8 *)g_021469D0)[0x1ea] = 0;
    ((u8 *)g_021469D0)[0x1ed] = 0;
}

