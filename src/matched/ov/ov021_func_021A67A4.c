/*
 * function: func_021A67A4
 * address:  0x021A67A4
 * packet:   pkt_ov021_021A67A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D7DC  0x0216D7DC  thumb  ov010
 *   func_021A66F8  0x021A66F8  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB348  0x021AB348  thumb  ov021
 *   func_021BB1AC  0x021BB1AC  thumb  ov021
 *   func_021BB1B8  0x021BB1B8  thumb  ov021
 *   func_021BB1C4  0x021BB1C4  thumb  ov021
 *   func_021BB1D0  0x021BB1D0  thumb  ov021
 *   func_021BB1DC  0x021BB1DC  thumb  ov021
 *   func_021BB1E8  0x021BB1E8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0216D7DC(void *p);
extern int func_021A66F8(u8 *p, u32 m);
extern u16 func_021AB0F0(u32 a);
extern int func_021AB348(u32 a);
extern int func_021BB1AC(int x);
extern int func_021BB1B8(int x);
extern int func_021BB1C4(int x);
extern int func_021BB1D0(int x);
extern int func_021BB1DC(int x);
extern int func_021BB1E8(int x);

u32 func_021A67A4(u8 *p)
{
    u32 r4 = func_0216D7DC((void *)(*(u32 *)(p + 0x1C)));

    if (!func_021A66F8(p, 2)) {
        r4 = func_021AB0F0(r4);
        if (func_021AB348(r4) == 1)
            return 1;
        if (func_021BB1AC(r4) == 1)
            return 2;
        if (func_021BB1B8(r4) == 1)
            return 3;
        if (func_021BB1C4(r4) == 1)
            return 4;
        if (func_021BB1D0(r4) == 1)
            return 5;
        if (func_021BB1DC(r4) == 1)
            return 6;
        if (func_021BB1E8(r4) == 1)
            return 7;
    }
    return 0;
}
