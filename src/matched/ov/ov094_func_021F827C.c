/*
 * function: BTLV_EFFECT_IsPartyBallBarActive
 * address: 0x021F827C
 * packet: pkt_ov094_021F827C
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Leaf blocking ov093 BTLV_SCU_ProcEntrySingleTrainer.
 * symbols:
 *   gBtlvEff 0x0220AF20 data ov094 a4
 *   BTLV_B_GAUGE_IsPartyBallBarActive 0x022090A4 thumb ov094
 */
typedef unsigned int u32;
extern char *gBtlvEff;
extern int BTLV_B_GAUGE_IsPartyBallBarActive(int *);
int BTLV_EFFECT_IsPartyBallBarActive(u32 i)
{
    return BTLV_B_GAUGE_IsPartyBallBarActive(*(int **)(gBtlvEff + i * 4 + 0x1a8));
}
