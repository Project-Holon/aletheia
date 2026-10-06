/*
 * function: func_021B8AC8
 * address: 0x021B8AC8
 * packet: pkt_ov133_021B8AC8
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B765C 0x021B765C thumb ov133
 */
#include "../include/Obj00004.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
extern void *func_021B765C(u8 *p, u16 base, s16 speed, u16 rx, u16 ry);
void func_021B8AC8(u8 *p)
{
    int n = ((struct Obj00004 *)p)->f182E;
    if (n < 0) n = -n;
    if (n < 48 && (((struct Obj00004 *)p)->f1838 != 0 || ((struct Obj00004 *)p)->f183A != 0)) {
        ((struct Obj00004 *)p)->f1838 += ((struct Obj00004 *)p)->f183A;
        if (((struct Obj00004 *)p)->f1838 > 0) {
            if (((struct Obj00004 *)p)->f183A > 0) ((struct Obj00004 *)p)->f183A -= 128;
            else ((struct Obj00004 *)p)->f183A -= 42;
        } else if (((struct Obj00004 *)p)->f1838 < 0) {
            if (((struct Obj00004 *)p)->f183A < 0) ((struct Obj00004 *)p)->f183A += 128;
            else ((struct Obj00004 *)p)->f183A += 42;
        }
        n = ((struct Obj00004 *)p)->f1838;
        if (n < 0) n = -n;
        if (n < 512) {
            n = ((struct Obj00004 *)p)->f183A;
            if (n < 0) n = -n;
            if (n < 512) {
                ((struct Obj00004 *)p)->f183A = 0;
                ((struct Obj00004 *)p)->f1838 = 0;
            }
        }
        func_021B765C(p, ((struct Obj00004 *)p)->f182C, 0, 72, 48);
    }
}
