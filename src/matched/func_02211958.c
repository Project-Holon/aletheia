/*
 * function: func_02211958
 * address:  0x02211958
 * packet:   pkt_02211958
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02211944  0x02211944  thumb  ov198
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_02211944(u8 **);

u32 func_02211958(u8 **p)
{
    if (*(u32 *)(*p + 0x30) == 1) {
        func_02211944(p);
        return 1;
    }
    return 0;
}

