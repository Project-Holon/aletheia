/*
 * function: func_02211970
 * address:  0x02211970
 * packet:   pkt_02211970
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
extern void func_020061E4(u32);

void func_02211970(u8 **p, u32 b)
{
    if (*(u32 *)(*p + 0x40) == 1) {
        func_020061E4(b);
    }
}

