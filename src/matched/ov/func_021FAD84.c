/*
 * function: func_021FAD84
 * address:  0x021FAD84
 * packet:   pkt_021FAD84
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
 * Drain the queue then flush the shadowed value, always answering -1.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern int func_0202CE40(u32 v, int z);
extern void func_0202CC70(u32 v, int z);

int func_021FAD84(u8 *p)
{
    if (func_0202CE40(*(u32 *)(p + 0x18), 0) == 0) {
        func_0202CC70(*(u32 *)(p + 0x18), 0);
        *(u32 *)(p + 0x48) = *(u32 *)(p + 0x4c);
    }
    return -1;
}
