/*
 * function: func_0220163C
 * address:  0x0220163C
 * packet:   pkt_0220163C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 * State-setter: hand the object to func_021C8978, latch state 0xe at +0x28,
 * clear the word at +0xf8c and report 2.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021C8978(u8 *p);

int func_0220163C(u8 *p)
{
    func_021C8978(p);
    *(u32 *)(p + 0x28) = 0xe;
    *(u32 *)(p + 0xf8c) = 0;
    return 2;
}
