/*
 * unit:     yes
 * function: MONOLITH_TOOL_ShowRowHighlight, MONOLITH_TOOL_ClearRowHighlight
 * address:  0x021B9FEC
 * packet:   pkt_ov071_021B9FEC
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two thunks passing a constant third argument.
 *
 * symbols:
 *   MONOLITH_TOOL_SetRowHighlight  0x021B9F74  thumb  ov071
 */

typedef unsigned char  u8;
void MONOLITH_TOOL_ShowRowHighlight(void *p, int a)
{
    void MONOLITH_TOOL_SetRowHighlight(u8 *p, int i, int v);
    MONOLITH_TOOL_SetRowHighlight(p, a, 3);
}

void MONOLITH_TOOL_ClearRowHighlight(void *p, int a)
{
    void MONOLITH_TOOL_SetRowHighlight(u8 *p, int i, int v);
    MONOLITH_TOOL_SetRowHighlight(p, a, 0);
}
