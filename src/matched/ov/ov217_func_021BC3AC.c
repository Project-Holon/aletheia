/*
 * function: func_021BC3AC
 * address:  0x021BC3AC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) 2 to func_02040804.
 *
 * symbols:
 *   func_02040804  0x02040804  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u32 func_02040804(u32 layer);

void func_021BC3AC(u32 a0)
{
    func_02040804(2);
}

