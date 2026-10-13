/*
 * function: WIFICLUB_OpenYesNoMenu
 * address: 0x021BA828
 * packet: pkt_ov099_021BA828
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   BMP_MENU_CreateYesNo 0x0201FDA0 thumb
 *   gWifiClubYesNoWindowTemplate 0x021C371A data a2
 */
#include "../include/Obj00008.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WinDat;
struct BmpMenu;
extern const struct WinDat gWifiClubYesNoWindowTemplate;
extern void GF_FONT_SetDefaultTextColor(void);
extern struct BmpMenu *BMP_MENU_CreateYesNo(const struct WinDat *, u16, u8, u8, u16);
void WIFICLUB_OpenYesNoMenu(char *p)
{
    GF_FONT_SetDefaultTextColor();
    *(struct BmpMenu * *)&((struct Obj00008 *)p)->f108 = BMP_MENU_CreateYesNo(&gWifiClubYesNoWindowTemplate, ((struct Obj00008 *)p)->f1334, 14, 0, 0x21);
}
