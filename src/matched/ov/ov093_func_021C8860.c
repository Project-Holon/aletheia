/*
 * function: BTL_SERVER_FLOW_AppendMsgRecordArg
 * address:  0x021C8860
 * packet:   pkt_ov093_021C8860
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Named by the parked ov093 files (HAND_ITEM_DestinyKnot_Infatuate / HAND_ITEM_RockyHelmetDamageReaction /
 * HAND_WAZA_SimpleBeamSetAbility).  Appends `val` to the record at p: the count in bits 8..14
 * of the +2 halfword (max 7 entries) is incremented and `val` stored at
 * p + 4 + idx*4.  The 7-bit unsigned bitfield is what makes the count
 * unsigned (`bhs`, not `bge`) and produces the lsl/lsr extraction pair.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u16 x;
    u16 y : 8;
    u16 n : 7;
    u16 z : 1;
    u32 arr[8];
};

void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 val)
{
    unsigned int idx = p->n;

    if (idx >= 8)
        return;
    p->n = idx + 1;
    p->arr[idx] = val;
}
