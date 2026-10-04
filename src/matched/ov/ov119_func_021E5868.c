/*
 * function: func_021E5868
 * address:  0x021E5868
 * packet:   pkt_ov119_021E5868
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 */
#include "../include/Obj04483.h"
typedef unsigned int   u32;
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
void func_021E5868(char *p)
{
    if (((struct Obj04483 *)p)->f898 != 0) {
        func_0204A8D4(((struct Obj04483 *)p)->f898);
        func_0204ADA4(((struct Obj04483 *)p)->f884);
        func_0204AFD8(((struct Obj04483 *)p)->f8B4);
        ((struct Obj04483 *)p)->f898 = 0;
        ((struct Obj04483 *)p)->f884 = 0;
        ((struct Obj04483 *)p)->f8B4 = 0;
    }
}
