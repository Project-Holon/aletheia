/*
 * function: func_021F4D78
 * address:  0x021F4D78
 * packet:   pkt_021F4D78
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F4D34  0x021F4D34  thumb  ov194
 *   func_020307B0  0x020307B0  arm  ov194
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_021F4D34(u32);
extern void func_020307B0(u8 *);

void func_021F4D78(u8 *p)
{
    int i;

    for (i = 0; i < 5; i++) {
        func_021F4D34(*(u32 *)(p + i * 4));
    }
    func_020307B0(p);
}

