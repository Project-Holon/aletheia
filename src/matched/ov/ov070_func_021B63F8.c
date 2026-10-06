/*
 * function: func_021B63F8
 * address:  0x021B63F8
 * packet:   pkt_ov070_021B63F8
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B61C8  0x021B61C8  thumb  ov070
 *   func_02035CB8  0x02035CB8  arm
 *   func_02035C60  0x02035C60  arm
 *   func_021B80C4  0x021B80C4  thumb  ov070
 *   func_0202EDE4  0x0202EDE4  thumb
 *   func_021BA654  0x021BA654  thumb  ov070
 *   func_020061E4  0x020061E4  thumb
 */
#include "../include/Obj00002.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern int func_021B61C8(u8 *p);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern int func_02035C60(void);
struct Obj;
extern void func_021B80C4(struct Obj *o, int flag);
extern u32 func_0202EDE4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern void func_021BA654(char *p);
extern void func_020061E4(u32 se);

u32 func_021B63F8(u8 *p)
{
    u32 x, y, old;
    int k;

    k = func_021B61C8(p);
    if (k >= 7 && func_02035CB8(&x, &y) == 1) {
        if (x >= 0x100 || x < 0xE0)
            return 0;
        if (((struct Obj00002 *)p)->f85C == 0) {
            if (func_02035C60() == 1) {
                if (y < 0x10 || y >= 0x98)
                    return 0;
                ((struct Obj00002 *)p)->f85C = 1;
            } else
                return 0;
        }
        func_021B80C4((struct Obj *)p, 0);
        old = *(u32 *)&((struct Obj00002 *)p)->f814;
        *(u32 *)&((struct Obj00002 *)p)->f814 = func_0202EDE4(k - 6, y, 0x1A, 0x8E, 0) - 1;
        func_021BA654((char *)p);
        if (*(u32 *)&((struct Obj00002 *)p)->f814 != old) {
            func_020061E4(0x548);
            return 1;
        }
    }
    return 0;
}
