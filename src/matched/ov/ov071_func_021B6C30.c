/*
 * function: MONOLITH_TOOL_SetButtonPulse
 * address: 0x021B6C30
 * packet: pkt_ov071_021B6C30
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two-byte alignment padding at 0x021B6C46.
 * symbols:
 *   MONOLITH_TOOL_SetHighlightMode 0x021B6DB4 thumb ov071
 */
extern void MONOLITH_TOOL_SetHighlightMode(int *, int, int);
void MONOLITH_TOOL_SetButtonPulse(int *p, int flag, int index)
{
    if (flag == 1) {
        MONOLITH_TOOL_SetHighlightMode(p, 1, index);
    } else {
        MONOLITH_TOOL_SetHighlightMode(p, 0, index);
    }
}
