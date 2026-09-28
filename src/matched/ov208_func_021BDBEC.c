/*
 * function: ov208_func_021BDBEC
 * address:  0x021BDBEC
 * packet:   pkt_ov208_021BDBEC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BD378  0x021BD378  thumb
 */

typedef unsigned int u32;

struct Ov208Scene {
    u32 pad0[4];
    u32 f10;
    u32 pad14[7];
    u32 mgr;
    u32 pad34[16];
    int *keyA;
    u32 pad78;
    int *keyB;
};

extern void func_021BD378(u32 mgr, int key, int v);

void ov208_func_021BDBEC(struct Ov208Scene *p, int v)
{
    if (p->f10 == 2) {
        func_021BD378(p->mgr, *p->keyA, v);
        func_021BD378(p->mgr, *p->keyB, v);
    }
}
