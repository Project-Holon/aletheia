/*
 * function: func_021C88B4
 * address:  0x021C88B4
 * packet:   pkt_ov093_021C88B4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Named by the parked ov093 files (BTL_CALC_IntimidateOnEnter / BTL_HANDLER_ITEM_DestinyKnot_Infatuate /
 * BTL_HANDLER_ITEM_RockyHelmetDamageReaction / func_021E4A70 / func_021E7388).  EXACT*: both calls resolve
 * (func_021C88A4 by `label`, func_021C88C8 by `label`), the extent runs two
 * bytes long into the unlabelled follower.
 *
 * symbols:
 *   func_021C88A4   0x021C88A4  thumb  ov093
 *   func_021C88C8   0x021C88C8  thumb  ov093
 */

extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);

void func_021C88B4(void *a, int k, int b)
{
    func_021C88C8(a, func_021C88A4(a, k, b));
}
