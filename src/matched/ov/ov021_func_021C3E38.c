/*
 * function: func_021C3E38
 * address:  0x021C3E38
 * packet:   pkt_ov021_021C3E38
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reads personal-data field 0x15 for the species/form pair (EXACT*: pad).
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0201ADE4(u16 a, u16 b, u32 heap);
extern u32 func_0201AE1C(void *h, u32 id);
extern void func_0201AE14(void *h);

void func_021C3E38(u32 *p, u32 heap)
{
    void *h = func_0201ADE4(p[0], p[1], heap);
    u32 v = func_0201AE1C(h, 0x15);

    func_0201AE14(h);
    p[5] = v;
}
