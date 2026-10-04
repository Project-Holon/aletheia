/*
 * function: func_021875B8
 * address: 0x021875B8
 * packet: pkt_ov020_021875B8
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: duplicate the zero store in both arms to retain the original branch stub.
 * regargs: high r2/r3 rows are conservative SDK-depth flags in owner callee 0219131C.
 * interface: 0219131C forwards them to 02045808 -> 020307B0 only; 0203046C
 * overwrites r2/r3, while 02030164's 0202FBAC overwrites r2 and no path reads incoming r3.
 * symbols:
 *   func_021912F8 0x021912F8 thumb ov021
 *   func_0219131C 0x0219131C thumb ov021
 *   func_021909BC 0x021909BC thumb ov021
 */
#include "../include/Obj00128.h"
typedef unsigned short u16;
extern int func_021912F8(void *p);
extern void func_0219131C(void *p);
typedef unsigned int   u32;
extern int func_021909BC(u32 a);
int func_021875B8(char *p)
{
    if (((struct Obj00128 *)p)->f10 != 0) {
        if (((struct Obj00128 *)p)->f52 == 5) {
            if (func_021912F8(((struct Obj00128 *)p)->f10) == 0) return 0;
            ((struct Obj00128 *)p)->f10 = 0;
        } else {
            func_0219131C(((struct Obj00128 *)p)->f10);
            ((struct Obj00128 *)p)->f10 = 0;
        }
    }
    if (((struct Obj00128 *)p)->f14 != 0) {
        func_021909BC((u32)(((struct Obj00128 *)p)->f14));
        ((struct Obj00128 *)p)->f14 = 0;
    }
    return 1;
}
