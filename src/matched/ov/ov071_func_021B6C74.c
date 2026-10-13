/*
 * function: func_021B6C74
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
 * the 8-byte table at p + 0xC (field +2, see func_021B6C7C).
 */

typedef unsigned char u8;

u8 func_021B6C74(void *p, int i)
{
    return ((u8 *)p + i * 8)[0xe];
}
