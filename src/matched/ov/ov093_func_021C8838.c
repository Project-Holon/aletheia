/*
 * function: BTL_SERVER_FLOW_InitMsgRecord
 * address:  0x021C8838
 * packet:   pkt_ov093_021C8838
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Named by the parked ov093 files (HAND_ITEM_DestinyKnot_Infatuate / HAND_ITEM_RockyHelmetDamageReaction /
 * func_021E7388).  Low byte of the +2 halfword <- (u8)a; +0 halfword <- b;
 * then bits 8..14 of the +2 halfword are cleared.  `(u8)(u16)a` and the
 * `(int)` cast before `~0x7F00` are both load-bearing: the first gives the
 * double narrowing, the second keeps the mask sign-extended (0xFFFF80FF) so
 * the pooled word matches.
 */
#include "../include/Obj21124.h"

typedef unsigned char u8;
typedef unsigned short u16;

void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b)
{
    u16 *h = (u16 *)((u8 *)p + 2);
    u8 av = (u8)(u16)a;

    *h = (*h & ~0xff) | av;
    ((struct Obj21124 *)p)->f0 = (u16)b;
    *h = (u16)((int)*h & ~0x7F00);
}
