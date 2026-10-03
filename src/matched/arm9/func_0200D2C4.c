/*
 * function: func_0200D2C4
 * address:  0x0200D2C4
 * packet:   pkt_0200D144
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned short u16;
typedef unsigned int   u32;
struct Blk37;
extern u16 func_0200D368(struct Blk37 *p, u32 heap);
int func_0200D2C4(void *p, unsigned int heap)
{
    return func_0200D368(p, heap) >= 0x96;
}
