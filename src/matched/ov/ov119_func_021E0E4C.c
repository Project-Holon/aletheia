/*
 * function: func_021E0E4C
 * address: 0x021E0E4C
 * packet: pkt_ov119_021E0E4C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_021B6284 0x021B6284 thumb ov067
 */
#include "../include/Obj08064.h"
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_021B6284(unsigned int *p);
void func_021E0E4C(char *p)
{
    if (((struct Obj08064 *)p)->f10) {
        func_0204B3B4(((struct Obj08064 *)p)->f10);
        *(int *)&((struct Obj08064 *)p)->f10 = 0;
        func_021B6284((unsigned int *)p);
    }
}
