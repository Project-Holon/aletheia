/*
 * function: BR_CODEIN_CodeDeleteMenu
 * address: 0x021DFF78
 * packet: pkt_ov183_021DFF78
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_BTN_DeleteObject 0x021FB494 thumb ov186
 *   BR_UTIL_DeleteListMenu 0x021FCC80 thumb ov186
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   BR_RES_ApplyBgSet 0x021FBDA4 thumb ov186
 *   BG_SYS_PushTile 0x020409B4 arm
 */
#include "../include/Obj04572.h"
#include "../include/Obj24621.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void BR_BTN_DeleteObject(char *p);
extern void BR_UTIL_DeleteListMenu(char *p);
extern u32 BMP_MENUWORK_Delete(void *p);
extern void BR_RES_ApplyBgSet(int a, unsigned mode);
extern void BG_SYS_PushTile(u32 index);
int BR_CODEIN_CodeDeleteMenu(char *p, char *q)
{
    if (((struct Obj04572 *)p)->fC) {
        BR_BTN_DeleteObject(((struct Obj04572 *)p)->fC);
        ((struct Obj04572 *)p)->fC = 0;
    }
    BR_UTIL_DeleteListMenu(((struct Obj04572 *)p)->f18);
    ((struct Obj04572 *)p)->f18 = 0;
    BMP_MENUWORK_Delete(((struct Obj04572 *)p)->f14);
    ((struct Obj04572 *)p)->f14 = 0;
    BR_RES_ApplyBgSet(((struct Obj24621 *)q)->f8, 27);
    BG_SYS_PushTile(4);
    return 1;
}
