/*
 * function: BTLV_EFFECT_DeletePartyBallBar
 * address: 0x021F8260
 * packet: pkt_ov094_021F8260
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Leaf blocking ov093 BTLV_SCU_ProcEntrySingleTrainer.
 * symbols:
 *   gBtlvEff 0x0220AF20 data ov094 a4
 *   BTLV_B_GAUGE_DeletePartyBallBar 0x02209068 thumb ov094
 */
typedef unsigned int u32;
extern char *gBtlvEff;
extern void BTLV_B_GAUGE_DeletePartyBallBar(void *);
void BTLV_EFFECT_DeletePartyBallBar(u32 i)
{
    BTLV_B_GAUGE_DeletePartyBallBar(*(void **)(gBtlvEff + i * 4 + 0x1a8));
}
