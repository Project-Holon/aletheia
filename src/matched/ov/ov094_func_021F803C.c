/*
 * function: BTLV_EFFECT_GaugeInitSlotFromBattlePoke
 * address:  0x021F803C
 * packet:   pkt_ov094_021F803C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlvEff     0x0220AF20  data   ov094  a4
 *   BTLV_GAUGE_InitSlotFromBattlePoke  0x022070C0  thumb  ov094
 */
typedef unsigned int u32;

extern char *gBtlvEff;
struct W;
extern void BTLV_GAUGE_InitSlotFromBattlePoke(struct W *p, void *a, void *q, int mode, int i);

void BTLV_EFFECT_GaugeInitSlotFromBattlePoke(u32 a, void *m, u32 c)
{
    switch (*(u32 *)(gBtlvEff + 0x1BC)) {
    case 2:
        BTLV_GAUGE_InitSlotFromBattlePoke((struct W *)(*(u32 *)(gBtlvEff + 0x1A4)), (void *)a, m, 2, c);
        break;
    case 3:
        BTLV_GAUGE_InitSlotFromBattlePoke((struct W *)(*(u32 *)(gBtlvEff + 0x1A4)), (void *)a, m, 3, c);
        break;
    default:
        BTLV_GAUGE_InitSlotFromBattlePoke((struct W *)(*(u32 *)(gBtlvEff + 0x1A4)), (void *)a, m, 0, c);
        break;
    }
}
