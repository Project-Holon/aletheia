/*
 * function: func_02200EB0
 * address:  0x02200EB0
 * packet:   pkt_02200EB0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 * Claim the 0xb4/0x48 resource and park it at +0xb88.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern u32 func_020457B0(u32 a, u32 b);

void func_02200EB0(u8 *p)
{
    *(u32 *)(p + 0xb88) = func_020457B0(0xb4, 0x48);
}
