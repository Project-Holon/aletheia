/*
 * function: ov208_func_021BDBAC
 * address:  0x021BDBAC
 * packet:   pkt_ov208_021BDBAC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ov208_func_021BD330  0x021BD330  thumb
 */

typedef unsigned int u32;

struct Ov208Scene {
    u32 pad0[12];
    void *mgr;
};

extern void ov208_func_021BD330(void *mgr, int v);

void ov208_func_021BDBAC(struct Ov208Scene *p, int v)
{
    ov208_func_021BD330(p->mgr, v);
}
