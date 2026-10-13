/*
 * function: BTL_MSG_BuildUiString
 * address:  0x021EF6A8
 * packet:   pkt_ov093_021EF6A8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MSG_BuildUiStringFlagged  0x021EF6B0  thumb  ov093
 *
 * Tail-call stub (ldr r3,[pc]; bx r3) to BTL_MSG_BuildUiStringFlagged; callee of func_021EA55C case 5.
 */

typedef unsigned int u32;

extern void BTL_MSG_BuildUiStringFlagged(u32 a, u32 b, u32 c);

void BTL_MSG_BuildUiString(u32 a, u32 b, u32 c)
{
    BTL_MSG_BuildUiStringFlagged(a, b, c);
}
