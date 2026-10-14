/*
 * function: ZUKAN_DETAIL_TOUCHBAR_ClearButtonState
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
 *   ZKND_TBAR_ClearButtonState  0x021BD360  thumb
 */

typedef unsigned int u32;

struct Ov208Scene {
    u32 pad0[12];
    void *mgr;
};

extern void ZKND_TBAR_ClearButtonState(void *mgr);

void ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(struct Ov208Scene *p)
{
    ZKND_TBAR_ClearButtonState(p->mgr);
}
