/*
 * function: BTL_SERVER_FLOW_AllocCmdRecord
 * address:  0x021C88A4
 * packet:   pkt_ov093_021C88A4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * BLOCKER: byte-identical (MATCH), one wildcarded ABS32: the tail-call pool
 * word at +0x0C names 0x021CC9AC.  That address is real Thumb code in ov093
 * (a 176-byte unlabelled bitfield packer, disasm prints it as a `.word` run)
 * but no listing labels it and no branch or pool word anywhere outside this
 * range names it, so `label`, `literal`, `sole-ref/code` and `matched` all
 * refuse.  It can only be witnessed by matching it bottom-up.  Passing the
 * full (char*, int, int) arity through to the callee is what makes the two
 * loads schedule as the original (add before the target load).
 *
 * Named by five parked pending files (BTL_CALC_IntimidateOnEnter / HAND_ITEM_DestinyKnot_Infatuate /
 * HAND_ITEM_RockyHelmetDamageReaction / HAND_WAZA_MementoOnUncategorizedMove / HAND_WAZA_SimpleBeamSetAbility).
 *
 * 2026-10-05 (D9 lane 02): unchanged. 0x021CC9AC is a 176-byte packer, not a tiny leaf, and ov093 below 0x021D4000 is pengy's, so no witness filed. Needs the integrator seed.
 * 2026-10-05 (D9r lane 14): callee 0x021CC9AC is now matched EXACT as
 * src/matched/ov/ov093_func_021CC9AC.c (user-approved). Re-verified MATCH: the
 * relocation still waits on that file's shard (integrator manifest), then this
 * should verify EXACT with no source change.
 * symbols:
 *   BTL_SERVER_FLOW_AllocHandExRecord   0x021CC9AC  thumb  ov093
  * note 2026-10-05 (D8 lane16): re-verified MATCH. Callee 0x021CC9AC is a real 176-byte Thumb bitfield packer (bitfield insert into a table with 0x3b-entry byte lookup), not a veneer and not tiny; not filed in this lane. Needs bottom-up match or integrator seed.
 */

struct Pack;
struct Rec;
extern struct Rec *BTL_SERVER_FLOW_AllocHandExRecord(struct Pack *p, int id, int b);

void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b)
{
    return BTL_SERVER_FLOW_AllocHandExRecord((struct Pack *)(p + 0x1D74), a, b);
}
