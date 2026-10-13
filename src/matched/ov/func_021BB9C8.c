/*
 * function: WIFICLUB_CreateKindMenu
 * address:  0x021BB9C8
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gWifiClubMenuHeaderSlot  0x021C3B30  data
 *   data_021C3B34  0x021C3B34  data
 *   gWifiClubKindMenuItems  0x021C3A78  data
 *   WIFICLUB_CreateMenuList  0x021BAC24  thumb  ov099
 *
 * Writes the two halfwords at 0x021C3B44 and runs the script pair with 5 / 1 / 0x11.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern u8 gWifiClubMenuHeaderSlot[];
extern u8 data_021C3B34[];
extern u8 gWifiClubKindMenuItems[];
extern void WIFICLUB_CreateMenuList(int a, void *b, void *c, int d, int e, int f);

void WIFICLUB_CreateKindMenu(int a)
{
    u16 *r = (u16 *)gWifiClubMenuHeaderSlot;

    r[0xA] = 5;
    r[0xB] = 5;
    WIFICLUB_CreateMenuList(a, data_021C3B34, gWifiClubKindMenuItems, 5, 1, 0x11);
}
