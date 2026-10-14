/*
 * function: ZUKAN_DETAIL_TOUCHBAR_SetButtonVisible
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
 *   ZKND_TBAR_SetButtonVisible  0x021BD378  thumb
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

extern void ZKND_TBAR_SetButtonVisible(int a, int b, int c);

void ZUKAN_DETAIL_TOUCHBAR_SetButtonVisible(struct Ov208Scene *p, int v)
{
    if (p->f10 == 2) {
        ZKND_TBAR_SetButtonVisible(p->mgr, *p->keyA, v);
        ZKND_TBAR_SetButtonVisible(p->mgr, *p->keyB, v);
    }
}
