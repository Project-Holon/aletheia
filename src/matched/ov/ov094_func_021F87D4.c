/*
 * function: BTLV_EFFECT_SetLowHpBgmSuppressed
 * address:  0x021F87D4
 * packet:   pkt_ov094_021F87D4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Witness leaf for ov093 BTLV_SCU_HideMonPair: tail call (obj, v) to BTLV_GAUGE_SetLowHpBgmSuppressed.
 *
 * symbols:
 *   gBtlvEff     0x0220AF20  data   ov094
 *   BTLV_GAUGE_SetLowHpBgmSuppressed  0x0220893C  thumb  ov094
 */
typedef unsigned int u32;

typedef struct {
    char pad[0x1A4];
    void *obj;          /* 0x1A4 */
} Work;

extern Work *gBtlvEff;

extern void BTLV_GAUGE_SetLowHpBgmSuppressed(void *o, u32 v);

void BTLV_EFFECT_SetLowHpBgmSuppressed(u32 v)
{
    BTLV_GAUGE_SetLowHpBgmSuppressed(gBtlvEff->obj, v);
}
