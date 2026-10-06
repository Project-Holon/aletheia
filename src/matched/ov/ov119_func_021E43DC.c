/*
 * function: func_021E43DC
 * address: 0x021E43DC
 * packet: pkt_ov119_021E43DC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj00001.h"
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021E43DC(char *p)
{
    if (((struct Obj00001 *)p)->f1174) {
        func_020307B0(((struct Obj00001 *)p)->f1174);
        ((struct Obj00001 *)p)->f1174 = 0;
        func_020307B0(((struct Obj00001 *)p)->f1178);
        ((struct Obj00001 *)p)->f1178 = 0;
        func_020307B0(((struct Obj00001 *)p)->f117C);
        ((struct Obj00001 *)p)->f117C = 0;
        func_020307B0(((struct Obj00001 *)p)->f1180);
        ((struct Obj00001 *)p)->f1180 = 0;
    }
}
