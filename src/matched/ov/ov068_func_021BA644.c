/*
 * function: OPTION_MENU_UpdateButtonWindows
 * address:  0x021BA644
 * packet:   pkt_ov068_021BA644
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   APP_TASKMENU_WIN_Update  0x02028178  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void APP_TASKMENU_WIN_Update(u8 *p);

void OPTION_MENU_UpdateButtonWindows(u8 *p)
{
    int i;

    for (i = 0; i < 2; i++) {
        APP_TASKMENU_WIN_Update((u8 *)(*(u32 *)(p + i * 4 + 0x34)));
    }
}
