/*
 * function: COLOSSEUM_ClearBattleInfo
 * address: 0x0217534C
 * packet: pkt_ov012_0217534C
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 * evidence: unlabelled Thumb tail-call leaf (ldr r3,=MI_CpuFill8; bx r3) after
 * COLOSSEUM_SetupBattleInfo; called by the bl at 0x02174A94 in UNION_MAIN_StepColosseumPartyEntry.
 */
extern void MI_CpuFill8(void *p, int v, int n);

void COLOSSEUM_ClearBattleInfo(void *p)
{
    MI_CpuFill8(p, 0, 0x58);
}
