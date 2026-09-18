/*
 * function: func_020244F0
 * address:  0x020244F0
 * packet:   pkt_02024368
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned short u16;
typedef unsigned int   u32;

u16 func_020244F0(void *obj, u32 idx)
{
    return ((u16 *)((char *)obj + 4))[idx];
}
