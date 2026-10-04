/*
 * function: func_021BE938
 * address:  0x021BE938
 * packet:   pkt_021BE938
 * region:   ov203
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE7A8 0x021BE7A8 thumb
 */

typedef unsigned int   u32;
extern u32 func_021BE7A8(u32 id);

int func_021BE938(void *a)
{
    unsigned int v = *(unsigned short *)(func_021BE7A8((u32)a) + 6);
    return (v << 30) >> 31;
}
