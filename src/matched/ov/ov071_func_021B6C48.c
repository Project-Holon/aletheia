/*
 * function: MONOLITH_TOOL_SetButtonFlash
 * address:  0x021B6C48
 * packet:   pkt_ov071_021B6C48
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to MONOLITH_TOOL_SetHighlightMode(p, 2, a).  Address also resident in ov172;
 * region-qualified packet id.
 *
 * symbols:
 *   MONOLITH_TOOL_SetHighlightMode  0x021B6DB4  thumb  ov071
 */

void MONOLITH_TOOL_SetButtonFlash(void *p, int a)
{
    void MONOLITH_TOOL_SetHighlightMode(int *p, int a, int idx);
    MONOLITH_TOOL_SetHighlightMode(p, 2, a);
}
