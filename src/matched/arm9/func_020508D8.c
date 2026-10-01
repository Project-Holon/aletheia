/*
 * function: func_020508D8
 * address:  0x020508D8
 * packet:   pkt_020508D8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_020508D8(u8 *o, u32 i)
{
    return *(u16 *)(*(u8 **)(o + 0x18) + i * 0x28 + 4);
}
