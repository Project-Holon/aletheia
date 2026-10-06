/*
 * function: func_022110E0
 * address:  0x022110E0
 * packet:   pkt_022110E0
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_022110D4  0x022110D4  thumb  ov198
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int func_022110D4(u8 *p, int i);

void func_022110E0(u8 **p, u32 b, u32 c)
{
    u8 v = func_022110D4((u8 *)p, c);

    *(u8 *)(*p + b + 0x48) = v;
}

