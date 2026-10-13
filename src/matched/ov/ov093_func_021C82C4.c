/*
 * function: BTL_SERVER_FLOW_CheckSideEffectActive
 * address:  0x021C82C4
 * packet:   pkt_021C82C4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   HAND_SIDE_IsActive  0x06898CF4  thumb  ov095
 *
 * Resolved: HAND_SIDE_IsActive was matched (ov095), so the +0x08 ABS32 now attests
 * through the `matched` class and the thunk is byte-exact.
 */

int HAND_SIDE_IsActive(int a, int b);

int BTL_SERVER_FLOW_CheckSideEffectActive(int a, int b, int c)
{
    (void)a;
    return HAND_SIDE_IsActive(b, c);
}
