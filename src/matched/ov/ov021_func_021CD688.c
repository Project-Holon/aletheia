/*
 * function: COMM_ENTRY_MENU_Main
 * address:  0x021CD688
 * packet:   pkt_ov021_021CD688
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   COMM_ENTRY_MENU_MainRecruit  0x021CD6D0  thumb  ov021
 *   COMM_ENTRY_MENU_MainMode1  0x021CDAB8  thumb  ov021
 *   COMM_ENTRY_MENU_MainMode2  0x021CDD5C  thumb  ov021
 *   COMM_ENTRY_MENU_MainMode3  0x021CDF18  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00011.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern int COMM_ENTRY_MENU_MainRecruit(u8 *p);
extern int COMM_ENTRY_MENU_MainMode1(u8 *p);
extern int COMM_ENTRY_MENU_MainMode2(u8 *p);
extern int COMM_ENTRY_MENU_MainMode3(u8 *p);

u32 COMM_ENTRY_MENU_Main(u8 *p)
{
    int r;

    switch (p[0x51f]) {
    case 0:
        r = COMM_ENTRY_MENU_MainRecruit(p);
        break;
    case 1:
        r = COMM_ENTRY_MENU_MainMode1(p);
        break;
    case 2:
        r = COMM_ENTRY_MENU_MainMode2(p);
        break;
    case 3:
        r = COMM_ENTRY_MENU_MainMode3(p);
        break;
    }
    if (r == 1) {
        return ((struct Obj00011 *)p)->f2C;
    }
    return 0;
}
