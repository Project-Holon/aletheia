/*
 * function: BTLV_EFFECT_GaugeInitSlotFromPartyPoke
 * address:  0x021F8090
 * packet:   pkt_ov094_021F8090
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   gBtlvEff 0x0220AF20 data ov094 a4
 *   BTLV_GAUGE_InitSlotFromPartyPoke 0x02207288 thumb ov094
 * extent: Already matched followers begin at 0x021F80E4.
 */
typedef unsigned int u32;
extern char *gBtlvEff;
struct W;
extern void BTLV_GAUGE_InitSlotFromPartyPoke(struct W *p, void *a, void *q, int mode, int i);

void BTLV_EFFECT_GaugeInitSlotFromPartyPoke(u32 a, u32 b, u32 c)
{
    switch (*(u32 *)(gBtlvEff + 0x1BC)) {
    case 2:
        BTLV_GAUGE_InitSlotFromPartyPoke((struct W *)(*(u32 *)(gBtlvEff + 0x1A4)), (void *)a, (void *)b, 2, c);
        break;
    case 3:
        BTLV_GAUGE_InitSlotFromPartyPoke((struct W *)(*(u32 *)(gBtlvEff + 0x1A4)), (void *)a, (void *)b, 3, c);
        break;
    default:
        BTLV_GAUGE_InitSlotFromPartyPoke((struct W *)(*(u32 *)(gBtlvEff + 0x1A4)), (void *)a, (void *)b, 0, c);
        break;
    }
}
