/*
 * function: func_021E0214
 * address: 0x021E0214
 * packet: pkt_ov183_021E0214
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FB494 0x021FB494 thumb ov186
 *   func_021FCC80 0x021FCC80 thumb ov186
 *   func_0201F868 0x0201F868 thumb
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_020409B4 0x020409B4 arm
 */
#include "../include/Obj04574.h"
#include "../include/Obj24622.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_021FB494(char *p);
extern void func_021FCC80(char *p);
extern void func_0201F868(void *);
extern void func_021FBDA4(int a, unsigned mode);
extern void func_020409B4(u32 index);
int func_021E0214(char *p, char *q)
{
    if (((struct Obj04574 *)p)->fC) {
        func_021FB494(((struct Obj04574 *)p)->fC);
        ((struct Obj04574 *)p)->fC = 0;
    }
    func_021FCC80(((struct Obj04574 *)p)->f18);
    ((struct Obj04574 *)p)->f18 = 0;
    func_0201F868(((struct Obj04574 *)p)->f14);
    ((struct Obj04574 *)p)->f14 = 0;
    func_021FBDA4(((struct Obj24622 *)q)->f8, 28);
    func_020409B4(4);
    return 1;
}
