/*
 * function: BTLV_SCU_HideMonSlot
 * address:  0x021ED9EC
 * packet:   pkt_ov093_021ED9EC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_EFFECT_GaugeDeleteSlot  0x021F80E4  thumb  ov094
 */
typedef unsigned char u8;
struct E { int a0; u8 *owner; u8 k8; u8 v9; u8 fa; u8 fb; };
typedef unsigned int   u32;
extern void BTLV_EFFECT_GaugeDeleteSlot(u32 a);
void BTLV_SCU_HideMonSlot(struct E *e)
{
    if (e->fa != 0) {
        BTLV_EFFECT_GaugeDeleteSlot(e->v9);
        e->fa = 0;
    }
}
