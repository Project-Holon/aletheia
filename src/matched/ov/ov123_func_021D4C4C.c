/*
 * function: GSYNC_MENU_UpdateCursorAnimFromKeys
 * address: 0x021D4C4C
 * packet: pkt_ov123_021D4C4C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_MENU_SetCursorAnimIfChanged 0x021D4C24 thumb ov123
 */
#include "../include/Obj05360.h"
typedef unsigned int u32;
typedef unsigned char  u8;
extern void GSYNC_MENU_SetCursorAnimIfChanged(u8 *p, int v);
void GSYNC_MENU_UpdateCursorAnimFromKeys(char *p)
{
    u32 keys = ((struct Obj05360 *)p)->f278;
    if (keys != ((struct Obj05360 *)p)->f27C) {
        if (keys & 0x40) GSYNC_MENU_SetCursorAnimIfChanged((u8 *)p, 0x18);
        else if (keys & 0x80) GSYNC_MENU_SetCursorAnimIfChanged((u8 *)p, 0x16);
        else if (keys & 0x100) GSYNC_MENU_SetCursorAnimIfChanged((u8 *)p, 0x15);
        else if (keys & 0x200) GSYNC_MENU_SetCursorAnimIfChanged((u8 *)p, 0x15);
        else GSYNC_MENU_SetCursorAnimIfChanged((u8 *)p, 0xe);
    }
}
