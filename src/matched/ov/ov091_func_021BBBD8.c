/*
 * function: PLIST_MENU_Update
 * address:  0x021BBBD8
 * packet:   pkt_021BBBD8
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   APP_TASKMENU_UpdateMenu  0x02027974  thumb
 */

void APP_TASKMENU_UpdateMenu(int);

void PLIST_MENU_Update(int unused, int *p)
{
    (void)unused;
    APP_TASKMENU_UpdateMenu(p[29]);
}
