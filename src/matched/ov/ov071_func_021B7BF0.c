/*
 * function: MONOLITH_TOOL_SLOT_SELECT_UpdateCursor
 * address:  0x021B7BF0
 * packet:   pkt_ov071_021B7BF0
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to MONOLITH_TOOL_UpdateBlink((char *)p + 0x24).
 *
 * symbols:
 *   MONOLITH_TOOL_UpdateBlink  0x021B70C4  thumb  ov071
 */

void MONOLITH_TOOL_SLOT_SELECT_UpdateCursor(void *p)
{
    void MONOLITH_TOOL_UpdateBlink(void *);
    MONOLITH_TOOL_UpdateBlink((char *)p + 0x24);
}
