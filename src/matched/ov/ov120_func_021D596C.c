/*
 * function: func_021D596C
 * address:  0x021D596C
 * packet:   pkt_021D596C
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D6AC0  0x021D6AC0  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int func_021D6AC0(u8 *p);

int func_021D596C(u8 *p, int x)
{
    if (func_021D6AC0(*(void **)(p + 0x3c)) == 0)
        x = 9;
    return x;
}
