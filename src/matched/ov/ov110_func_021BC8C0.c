/*
 * function: func_021BC8C0
 * address: 0x021BC8C0
 * packet: pkt_ov110_021BC8C0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0207D63C 0x0207D63C arm
 */
#include "../include/Obj03754.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_0207D63C(void *, int, int, int, int);
void func_021BC8C0(void *task, u8 *p)
{
    int level;
    if (((struct Obj03754 *)p)->f14 != 0) {
        ((struct Obj03754 *)p)->f8 += ((struct Obj03754 *)p)->f10;
        level = ((struct Obj03754 *)p)->f8 >> 3;
        ((struct Obj03754 *)p)->f14 -= 1;
    } else {
        level = ((struct Obj03754 *)p)->fC >> 3;
    }
    if (level > 16) level = 16;
    func_0207D63C((void *)0x04000050, ((struct Obj03754 *)p)->f0, ((struct Obj03754 *)p)->f4, level, 16 - level);
}
