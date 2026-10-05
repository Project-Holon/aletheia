/*
 * function: ov208_func_021BD360
 * address:  0x021BD360
 * packet:   pkt_ov208_021BD360
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 */

typedef unsigned int u32;

struct Ov208Mgr {
    u32 pad0[4];
    u32 f10;
};

void ov208_func_021BD360(struct Ov208Mgr *p)
{
    p->f10 = 0;
}
