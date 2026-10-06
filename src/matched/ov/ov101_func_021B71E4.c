/*
 * function: func_021B71E4
 * address:  0x021B71E4
 * packet:   pkt_ov101_021B71E4
 * region:   ov101
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202824C  0x0202824C  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_0202822C  0x0202822C  thumb
 *   func_02028230  0x02028230  thumb
 *   func_020282A4  0x020282A4  thumb
 *   func_02028218  0x02028218  thumb
 *   func_02028178  0x02028178  thumb
 */
#include "../include/Obj02158.h"

extern unsigned int func_0202824C(void **p);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
typedef unsigned char  u8;
struct Obj;
extern void func_0202822C(char *p, int v);
extern u32 func_02028230(u8 *p);
extern void func_020282A4(struct Obj *obj);
extern void func_02028218(struct Obj *obj, u32 a);
extern void func_02028178(u8 *p);

void func_021B71E4(int a)
{
    if (((struct Obj02158 *)a)->f5C != 0) {
        switch (((struct Obj02158 *)a)->f50) {
        case 0:
            ((struct Obj02158 *)a)->f44 = -1;
            if (func_0202824C((void **)(((struct Obj02158 *)a)->f0))) {
                func_020061E4(0x551);
                func_0202822C((char *)(((struct Obj02158 *)a)->f0), 1);
                ((struct Obj02158 *)a)->f50 = 1;
            }
            break;
        case 1:
            if (func_02028230((u8 *)(((struct Obj02158 *)a)->f0))) {
                func_020282A4((struct Obj *)(((struct Obj02158 *)a)->f0));
                func_02028218((struct Obj *)(((struct Obj02158 *)a)->f0), 0);
                ((struct Obj02158 *)a)->f50 = 2;
            }
            break;
        case 2:
            ((struct Obj02158 *)a)->f44 = 1;
            break;
        }
        func_02028178((u8 *)(((struct Obj02158 *)a)->f0));
    }
}
