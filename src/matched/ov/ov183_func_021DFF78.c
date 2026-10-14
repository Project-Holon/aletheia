/*
 * function: func_021DFF78
 * address: 0x021DFF78
 * packet: pkt_ov183_021DFF78
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FB494 0x021FB494 thumb ov186
 *   func_021FCC80 0x021FCC80 thumb ov186
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   BR_RES_ApplyBgSet 0x021FBDA4 thumb ov186
 *   func_020409B4 0x020409B4 arm
 */
#include "../include/Obj04572.h"
#include "../include/Obj24621.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_021FB494(char *p);
extern void func_021FCC80(char *p);
extern u32 BMP_MENUWORK_Delete(void *p);
extern void BR_RES_ApplyBgSet(int a, unsigned mode);
extern void func_020409B4(u32 index);
int func_021DFF78(char *p, char *q)
{
    if (((struct Obj04572 *)p)->fC) {
        func_021FB494(((struct Obj04572 *)p)->fC);
        ((struct Obj04572 *)p)->fC = 0;
    }
    func_021FCC80(((struct Obj04572 *)p)->f18);
    ((struct Obj04572 *)p)->f18 = 0;
    BMP_MENUWORK_Delete(((struct Obj04572 *)p)->f14);
    ((struct Obj04572 *)p)->f14 = 0;
    BR_RES_ApplyBgSet(((struct Obj24621 *)q)->f8, 27);
    func_020409B4(4);
    return 1;
}
