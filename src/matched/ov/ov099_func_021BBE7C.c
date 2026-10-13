/*
 * function: WIFICLUB_CreateRuleChoiceMenu
 * address: 0x021BBE7C
 * packet: pkt_ov099_021BBE7C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gWifiClubMenuHeaderSlot 0x021C3B30 data a4
 *   gWifiClubRuleChoiceItems 0x021C39F0 data a4
 *   WIFICLUB_CreateMenuList 0x021BAC24 thumb ov099
 *   BMP_MENULIST_SetCancelDisabled 0x02020D10 thumb
 */
#include "../include/Obj00976.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Desc;
struct Pair { u32 a, b; };
extern char gWifiClubMenuHeaderSlot[];
extern struct Pair gWifiClubRuleChoiceItems[];
extern void WIFICLUB_CreateMenuList(char *, struct Desc *, struct Pair *, int, int, u32);
extern void BMP_MENULIST_SetCancelDisabled(u8 *p, u32 v);
void WIFICLUB_CreateRuleChoiceMenu(char *p)
{
    *(u16 *)(gWifiClubMenuHeaderSlot + 0x14) = 2;
    *(u16 *)(gWifiClubMenuHeaderSlot + 0x16) = 2;
    WIFICLUB_CreateMenuList(p, (struct Desc *)(gWifiClubMenuHeaderSlot + 4), gWifiClubRuleChoiceItems, 2, 5, 18);
    BMP_MENULIST_SetCancelDisabled(*(u8 * *)&((struct Obj00976 *)p)->fBC, 1);
}
