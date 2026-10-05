/*
 * function: ov208_func_021BDBA0
 * address:  0x021BDBA0
 * packet:   pkt_ov208_021BDBA0
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ov208_func_021BD360  0x021BD360  thumb
 */

typedef unsigned int u32;

struct Ov208Scene {
    u32 pad0[12];
    void *mgr;
};

extern void ov208_func_021BD360(void *mgr);

void ov208_func_021BDBA0(struct Ov208Scene *p)
{
    ov208_func_021BD360(p->mgr);
}
