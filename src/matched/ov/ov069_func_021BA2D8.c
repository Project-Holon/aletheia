/*
 * function: func_021BA2D8
 * address:  0x021BA2D8
 * packet:   pkt_ov069_021BA2D8
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA400  0x021BA400  thumb  ov069
 *   func_021BA438  0x021BA438  thumb  ov069
 *   func_020061E4  0x020061E4  thumb
 *   func_0204B878  0x0204B878  arm
 */
#include "../include/Obj00432.h"

typedef unsigned int   u32;
extern int func_021BA400(char *p, int k);
extern void func_021BA438(char *p, int i);
extern void func_020061E4(u32 a);
typedef unsigned short u16;
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);

void func_021BA2D8(char *o, int k)
{
    switch (k) {
    case 0:
        if (func_021BA400(o, k) != 0) {
            func_020061E4(0x548);
            func_0204B878((struct Obj *)(((struct Obj00432 *)o)->f12C), 12);
            func_021BA438(o, ((struct Obj00432 *)o)->f160);
        }
        break;
    case 1:
        if (func_021BA400(o, k) != 0) {
            func_020061E4(0x548);
            func_0204B878((struct Obj *)(((struct Obj00432 *)o)->f130), 13);
            func_021BA438(o, ((struct Obj00432 *)o)->f160);
        }
        break;
    case 2:
        ((struct Obj00432 *)o)->f158 = 2;
        func_0204B878((struct Obj *)(((struct Obj00432 *)o)->f128), 9);
        break;
    }
}
