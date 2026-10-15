/*
 * function: PSEL_GRAPHIC_GetMenuChoice
 * address:  0x021BB508
 * packet:   pkt_021BB508
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);

int PSEL_GRAPHIC_GetMenuChoice(int *p)
{
    return APP_TASKMENU_GetCursorPos((const u8 *)p[0x99]) == 0;
}
