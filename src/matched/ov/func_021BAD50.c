/*
 * function: WIFICLUB_CreateMainMenu
 * address:  0x021BAD50
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gWifiClubMainMenuHeader  0x021C3B00  data
 *   WIFICLUB_CreateMenuList  0x021BAC24  thumb  ov099
 *   gWifiClubMainMenuItems  0x021C3A50  data
 *
 * Runs the second script pair with 5 / 4 / 0x11.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern u8 gWifiClubMainMenuHeader[];
extern void WIFICLUB_CreateMenuList(int a, void *b, void *c, int d, int e, int f);

void WIFICLUB_CreateMainMenu(int a)
{
    WIFICLUB_CreateMenuList(a, gWifiClubMainMenuHeader, (void *)0x021C3A50, 5, 4, 0x11);
}
