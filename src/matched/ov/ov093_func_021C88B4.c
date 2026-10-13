/*
 * function: BTL_SERVER_FLOW_PushCmdRecord
 * address:  0x021C88B4
 * packet:   pkt_ov093_021C88B4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Named by the parked ov093 files (BTL_CALC_IntimidateOnEnter / HAND_ITEM_DestinyKnot_Infatuate /
 * HAND_ITEM_RockyHelmetDamageReaction / HAND_WAZA_MementoOnUncategorizedMove / func_021E7388).  EXACT*: both calls resolve
 * (BTL_SERVER_FLOW_AllocCmdRecord by `label`, BTL_SERVER_FLOW_CommitCmdRecord by `label`), the extent runs two
 * bytes long into the unlabelled follower.
 *
 * symbols:
 *   BTL_SERVER_FLOW_AllocCmdRecord   0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord   0x021C88C8  thumb  ov093
 */

extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void BTL_SERVER_FLOW_PushCmdRecord(void *a, int k, int b)
{
    BTL_SERVER_FLOW_CommitCmdRecord(a, BTL_SERVER_FLOW_AllocCmdRecord(a, k, b));
}
