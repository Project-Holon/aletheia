/*
 * function: func_022020E0
 * address:  0x022020E0
 * packet:   pkt_022020E0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 *
 * Run the sub-object init, stamp 0x27 and report 2.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern u32 func_020120F4(u32 v);
extern void func_02012DAC(u32 v);

int func_022020E0(u8 *p)
{
    func_02012DAC(func_020120F4(*(u32 *)(*(u32 *)p + 0x40)));
    *(u32 *)(p + 0x28) = 0x27;
    return 2;
}
