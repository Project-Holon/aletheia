/*
 * function: func_021E4888
 * address: 0x021E4888
 * packet: pkt_ov119_021E4888
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E69A4 0x021E69A4 thumb ov119
 *   func_021E4810 0x021E4810 thumb ov119
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj00001.h"
extern void func_021E69A4(char *);
extern void func_021E4810(char *, int);
typedef unsigned int   u32;
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_020307B0(void *);
void func_021E4888(char *p)
{
    int i;
    func_021E69A4(p);
    for (i = 0; i < 12; i++) func_021E4810(p, i);
    if (((struct Obj00001 *)p)->f87C) {
        func_0204ADA4(((struct Obj00001 *)p)->f87C);
        ((struct Obj00001 *)p)->f87C = 0;
    }
    if (((struct Obj00001 *)p)->f8AC) {
        func_0204AFD8(((struct Obj00001 *)p)->f8AC);
        ((struct Obj00001 *)p)->f8AC = 0;
    }
    if (((struct Obj00001 *)p)->f1184) func_020307B0(((struct Obj00001 *)p)->f1184);
    ((struct Obj00001 *)p)->f1184 = 0;
}
