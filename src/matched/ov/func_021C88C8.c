/*
 * function: BTL_SERVER_FLOW_CommitCmdRecord
 * address:  0x021C88C8
 * packet:   pkt_021C88C8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled-record helper reached from the five ov093 packets that name it
 * (HAND_ITEM_RockyHelmetDamageReaction / HAND_WAZA_MementoOnUncategorizedMove / BTL_CALC_IntimidateOnEnter / func_021E7388 /
 * HAND_ITEM_DestinyKnot_Infatuate).  Runs the battle-command dispatcher on (`a`, `b`), then
 * dispatches the same command through the record `a + 0x1D74`.
 *
 * symbols:
 *   BTL_SERVER_FLOW_ExecCmd   0x021C8918  thumb  ov093
 *   BTL_SERVER_FLOW_FreeLastHandExRecord   0x021CCA74  thumb  ov093
 */

extern void BTL_SERVER_FLOW_ExecCmd(void *s, void *cmd);
extern void BTL_SERVER_FLOW_FreeLastHandExRecord(void *s, void *cmd);

void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b)
{
    BTL_SERVER_FLOW_ExecCmd(a, b);
    BTL_SERVER_FLOW_FreeLastHandExRecord((char *)a + 0x1d74, b);
}
