/*
 * function: MONOLITH_TOOL_STATS_UpdateCursor
 * address:  0x021B8EDC
 * packet:   pkt_ov071_021B8EDC
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to MONOLITH_TOOL_UpdateBlink((char *)p + 0x48).
 *
 * symbols:
 *   MONOLITH_TOOL_UpdateBlink  0x021B70C4  thumb  ov071
 */

void MONOLITH_TOOL_STATS_UpdateCursor(void *p)
{
    void MONOLITH_TOOL_UpdateBlink(void *);
    MONOLITH_TOOL_UpdateBlink((char *)p + 0x48);
}
