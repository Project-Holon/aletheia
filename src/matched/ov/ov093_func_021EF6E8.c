/*
 * function: BTL_MSG_BuildTrainerString
 * address:  0x021EF6E8
 * packet:   pkt_ov093_021EF6E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MSG_BuildTrainerStringBody  0x021EF6F0  thumb  ov093
 *
 * Tail-call stub (ldr r3,[pc]; bx r3) to BTL_MSG_BuildTrainerStringBody; callee of func_021EA55C case 6.
 */

typedef unsigned int u32;

extern void BTL_MSG_BuildTrainerStringBody(u32 a, u32 b, u32 c);

void BTL_MSG_BuildTrainerString(u32 a, u32 b, u32 c)
{
    BTL_MSG_BuildTrainerStringBody(a, b, c);
}
