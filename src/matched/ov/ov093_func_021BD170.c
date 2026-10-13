/*
 * function: BTL_SERVER_FLOW_PromoteActionsByMove
 * address:  0x021BD170
 * packet:   pkt_ov093_021BD170
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_FindPendingActionByMove  0x021BCAAC  thumb  ov093
 *   BTL_SERVER_FLOW_MoveActionForward  0x021BCB98  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 *BTL_SERVER_FLOW_FindPendingActionByMove(u8 *p, u8 *q, u8 i);
extern int BTL_SERVER_FLOW_MoveActionForward(u8 *p, u8 *x, int i);

int BTL_SERVER_FLOW_PromoteActionsByMove(u8 *p, u8 *q)
{
    int i = 0;
    int r;
    u8 *x = BTL_SERVER_FLOW_FindPendingActionByMove(p, q, 0);
    r = 0;
    while (x) {
        i = BTL_SERVER_FLOW_MoveActionForward(p, x, i);
        if (i < 0) break;
        i++;
        x = BTL_SERVER_FLOW_FindPendingActionByMove(p, q, i);
        r = 1;
    }
    return r;
}
