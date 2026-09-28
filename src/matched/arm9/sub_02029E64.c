/*
 * function: func_02029E64
 * address:  0x02029E64
 * packet:   pkt_02029E64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02013BDC  0x02013BDC  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02013BDC(u32 id, u32 which);

u32 func_02029E64(void *unused, u32 id, u32 which)
{
    return func_02013BDC((u16)id, which);
}
