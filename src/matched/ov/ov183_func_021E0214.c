/*
 * function: BR_CODEIN_CodeDeletePokeList
 * address: 0x021E0214
 * packet: pkt_ov183_021E0214
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
 *   func_020409B4 0x020409B4 arm
 */
#include "../include/Obj04574.h"
#include "../include/Obj24622.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void BR_BTN_DeleteObject(char *p);
extern void BR_UTIL_DeleteListMenu(char *p);
extern u32 BMP_MENUWORK_Delete(void *p);
extern void BR_RES_ApplyBgSet(int a, unsigned mode);
extern void func_020409B4(u32 index);
int BR_CODEIN_CodeDeletePokeList(char *p, char *q)
{
    if (((struct Obj04574 *)p)->fC) {
        BR_BTN_DeleteObject(((struct Obj04574 *)p)->fC);
        ((struct Obj04574 *)p)->fC = 0;
    }
    BR_UTIL_DeleteListMenu(((struct Obj04574 *)p)->f18);
    ((struct Obj04574 *)p)->f18 = 0;
    BMP_MENUWORK_Delete(((struct Obj04574 *)p)->f14);
    ((struct Obj04574 *)p)->f14 = 0;
    BR_RES_ApplyBgSet(((struct Obj24622 *)q)->f8, 28);
    func_020409B4(4);
    return 1;
}
