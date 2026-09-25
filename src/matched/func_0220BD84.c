/*
 * function: func_0220BD84
 * address:  0x0220BD84
 * packet:   pkt_0220BD84
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_020452E8(u32);

void func_0220BD84(u8 *p)
{
    u32 t = *(u32 *)(p + 0x2170);

    if (t != 0) {
        func_020452E8(t);
        *(u32 *)(p + 0x2170) = 0;
    }
}

