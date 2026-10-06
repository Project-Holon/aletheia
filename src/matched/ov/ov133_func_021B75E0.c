/*
 * function: func_021B75E0
 * address: 0x021B75E0
 * packet: pkt_ov133_021B75E0
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B8A30 0x021B8A30 thumb ov133
 *   func_021B7A70 0x021B7A70 thumb ov133
 *   func_021B8AC8 0x021B8AC8 thumb ov133
 *   func_021B8FA8 0x021B8FA8 thumb ov133
 *   func_021B765C 0x021B765C thumb ov133
 */
#include "../include/Obj00004.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021B8A30(u8 *);
extern void func_021B7A70(u8 *);
extern void func_021B8AC8(u8 *);
extern void func_021B8FA8(u8 *);
typedef signed short   s16;
extern void *func_021B765C(u8 *p, u16 base, s16 speed, u16 rx, u16 ry);
void func_021B75E0(u8 *p)
{
    if (((struct Obj00004 *)p)->f98 == 1) func_021B8A30(p);
    else { func_021B7A70(p); func_021B8AC8(p); }
    func_021B8FA8(p);
    ++((struct Obj00004 *)p)->f94;
    if (((struct Obj00004 *)p)->f94 >= 90) {
        ((struct Obj00004 *)p)->f94 = 0;
        func_021B765C(p, ((struct Obj00004 *)p)->f182C, 0, 72, 48);
    }
    if (((struct Obj00004 *)p)->f94 == 45)
        func_021B765C(p, ((struct Obj00004 *)p)->f182C, 0, 72, 48);
}
