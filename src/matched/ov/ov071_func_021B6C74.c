/*
 * function: MONOLITH_TOOL_GetHighlightMode
 * address:  0x021B6C74
 * packet:   pkt_ov071_021B6C74
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf called by MONOLITH_TOOL_MENU_Update: the state byte of entry i of
 * the 8-byte table at p + 0xC (field +2, see MONOLITH_TOOL_UpdateHighlight).
 */

typedef unsigned char u8;

u8 MONOLITH_TOOL_GetHighlightMode(void *p, int i)
{
    return ((u8 *)p + i * 8)[0xe];
}
