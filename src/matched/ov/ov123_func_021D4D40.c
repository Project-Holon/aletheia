/*
 * function: func_021D4D40
 * address: 0x021D4D40
 * packet: pkt_ov123_021D4D40
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082D44 0x02082D44 arm
 *   func_0207E5D0 0x0207E5D0 arm
 *   func_0207E468 0x0207E468 arm
 *   func_021D4CBC 0x021D4CBC thumb ov123
 */
#include "../include/Obj00273.h"
extern void func_02082D44(void *, void *, int);
extern void func_0207E5D0(void *, int, int);
extern void func_0207E468(void *, int, int);
extern void func_021D4CBC(char *, int, int);
void func_021D4D40(char *p, int flag)
{
    if (flag) {
        func_02082D44((void *)0x05000600, ((struct Obj00273 *)p)->f280, 0x200);
        func_02082D44((void *)0x05000400, ((struct Obj00273 *)p)->f284, 0x200);
        func_021D4CBC(p, 3, 14);
        func_021D4CBC(p, 1, 9);
    } else {
        func_0207E5D0(((struct Obj00273 *)p)->f280, 0, 0x1c0);
        func_0207E468(((struct Obj00273 *)p)->f284, 0, 0x120);
    }
}
