/*
 * function: func_02202094
 * address:  0x02202094
 * packet:   pkt_02202094
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 * When the mode query answers 1, publish the u16 at +0xe0c.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern u32 func_020120F4(u32 v);
extern u32 func_02012DD0(u32 v);

int func_02202094(u8 *p)
{
    if (func_02012DD0(func_020120F4(*(u32 *)(*(u32 *)p + 0x40))) == 1) {
        *(u32 *)(p + 0x28) = *(u16 *)(p + 0xe0c);
    }
    return 2;
}
