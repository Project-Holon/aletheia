/*
 * function: func_021C11F4
 * address:  0x021C11F4
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: branch to func_021C1D28.
 *
 * symbols:
 *   func_021C1D28  0x021C1D28  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int func_021C1D28(u8 *p);

int func_021C11F4(u8 *p)
{
    return func_021C1D28(p);
}
