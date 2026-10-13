/*
 * function: func_021BB508
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

int func_021BB508(int *p)
{
    return APP_TASKMENU_GetCursorPos((const u8 *)p[0x99]) == 0;
}
