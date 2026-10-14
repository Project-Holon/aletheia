/*
 * function: ZUKAN_DETAIL_TOUCHBAR_SetButtonDrawEnable
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
 *   ZKND_TBAR_SetButtonDrawEnable  0x021BD330  thumb
 */

typedef unsigned int u32;

struct Ov208Scene {
    u32 pad0[12];
    void *mgr;
};

extern void ZKND_TBAR_SetButtonDrawEnable(void *mgr, int v);

void ZUKAN_DETAIL_TOUCHBAR_SetButtonDrawEnable(struct Ov208Scene *p, int v)
{
    ZKND_TBAR_SetButtonDrawEnable(p->mgr, v);
}
