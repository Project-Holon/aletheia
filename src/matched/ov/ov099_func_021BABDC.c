/*
 * function: WIFICLUB_SetMenuListColors
 * address:  0x021BABDC
 * packet:   pkt_ov099_021BABDC
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Lever: the k==4||k==5 test is a switch (case 4/5) so it stays two
 * compares and keeps obj in r5.
 *
 * symbols:
 *   BMP_MENULIST_GetUserData  0x02020D0C  thumb
 *   WIFICLUB_GetStatusSeatFlag  0x021C27E0  thumb  ov099
 *   BMP_MENULIST_SetColors  0x02020268  thumb
 */
#include "../include/Obj22019.h"

typedef unsigned char  u8;
typedef unsigned long  u32;

extern u32 BMP_MENULIST_GetUserData(u8 *p);
extern int WIFICLUB_GetStatusSeatFlag(void *a);
struct Obj;
extern void BMP_MENULIST_SetColors(struct Obj *obj, u8 a, u8 b, u8 c);

void WIFICLUB_SetMenuListColors(void *obj, int k)
{
    u8 *w = (u8 *)BMP_MENULIST_GetUserData(obj);

    if (WIFICLUB_GetStatusSeatFlag(((struct Obj22019 *)w)->f8) == 0) {
        switch (k) {
        case 4:
        case 5:
            BMP_MENULIST_SetColors(obj, 2, 15, 2);
            break;
        default:
            BMP_MENULIST_SetColors(obj, 1, 15, 2);
            break;
        }
    } else {
        BMP_MENULIST_SetColors(obj, 1, 15, 2);
    }
}
