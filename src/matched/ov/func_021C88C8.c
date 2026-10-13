/*
 * function: func_021C88C8
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
 * (BTL_HANDLER_ITEM_RockyHelmetDamageReaction / func_021E4A70 / BTL_CALC_IntimidateOnEnter / func_021E7388 /
 * BTL_HANDLER_ITEM_DestinyKnot_Infatuate).  Runs the battle-command dispatcher on (`a`, `b`), then
 * dispatches the same command through the record `a + 0x1D74`.
 *
 * symbols:
 *   func_021C8918   0x021C8918  thumb  ov093
 *   func_021CCA74   0x021CCA74  thumb  ov093
 */

extern void func_021C8918(void *s, void *cmd);
extern void func_021CCA74(void *s, void *cmd);

void func_021C88C8(void *a, void *b)
{
    func_021C8918(a, b);
    func_021CCA74((char *)a + 0x1d74, b);
}
