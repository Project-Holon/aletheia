/*
 * function: func_021C3DA8
 * address:  0x021C3DA8
 * packet:   pkt_ov021_021C3DA8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Sets the +0x4C flag by coin flip when a parent is species 0x84 (EXACT*: pad).
 */

typedef unsigned int u32;

extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern u32 func_02005728(u32 v);

void func_021C3DA8(void **p, u32 *out)
{
    u32 a = func_02017E1C(p[0], 5, 0);
    u32 b = func_02017E1C(p[1], 5, 0);

    if (a == 0x84 || b == 0x84) {
        if (func_02005728(2) == 0)
            out[19] = 0;
        else
            out[19] = 1;
    }
}
