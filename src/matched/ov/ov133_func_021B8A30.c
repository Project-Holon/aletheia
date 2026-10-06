/*
 * function: func_021B8A30
 * address: 0x021B8A30
 * packet: pkt_ov133_021B8A30
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021B8AC8 0x021B8AC8 thumb ov133
 *   func_021B765C 0x021B765C thumb ov133
 */
#include "../include/Obj00004.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_021B8AC8(u8 *);
extern void *func_021B765C(u8 *p, u16 base, s16 speed, u16 rx, u16 ry);
void func_021B8A30(u8 *p)
{
    u32 delta = ((struct Obj00004 *)p)->fA0 - ((struct Obj00004 *)p)->f9C;
    u32 step = delta / 10u;
    if (step < 256) {
        if (delta < 256) {
            step = delta;
            ((struct Obj00004 *)p)->f98 = 0;
        } else step = 256;
    }
    if (delta > 4096) {
        ((struct Obj00004 *)p)->f1838 -= 512;
        if (((struct Obj00004 *)p)->f1838 < -12288) ((struct Obj00004 *)p)->f1838 = -12288;
    } else func_021B8AC8(p);
    ((struct Obj00004 *)p)->f9C += step;
    ((struct Obj00004 *)p)->f182C -= (u16)step;
    func_021B765C(p, ((struct Obj00004 *)p)->f182C, step, 72, 48);
}
