/*
 * function: func_021C3C78
 * address:  0x021C3C78
 * packet:   pkt_ov021_021C3C78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Rolls the offspring nature (EXACT*: pad).
 */

typedef unsigned int u32;

extern u32 func_02005728(u32 v);

void func_021C3C78(void *a, u32 *out)
{
    out[3] = func_02005728(0x19);
}
