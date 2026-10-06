/*
 * function: func_0219DAD0
 * address:  0x0219DAD0
 * packet:   pkt_ov021_0219DAD0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_0219DC08  0x0219DC08  thumb  ov021
 *   func_021BBDD4  0x021BBDD4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern u16 func_021AB0F8(u32 attr);
extern int func_0219DC08(u32 a);
extern void func_021BBDD4(int a, int b, int c);

void func_0219DAD0(u32 a, u32 x, u32 b, u8 *p)
{
    u32 h;
    int f;
    if (b != 0xFFFFFFFF && (func_021AB0F8(b) & 8)) {
        h = func_0219DC08(a);
        f = 0;
        if (p[5] == 2)
            f = 1;
        func_021BBDD4(a, h, f);
    }
}
