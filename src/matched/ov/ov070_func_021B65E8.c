/*
 * function: func_021B65E8
 * address:  0x021B65E8
 * packet:   pkt_ov070_021B65E8
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   func_021B61C8  0x021B61C8  thumb  ov070
 *   func_021B61B8  0x021B61B8  thumb  ov070
 *   func_021B6300  0x021B6300  thumb  ov070
 *   func_021B6374  0x021B6374  thumb  ov070
 *   func_021B624C  0x021B624C  thumb  ov070
 *   func_021B80C4  0x021B80C4  thumb  ov070
 */
#include "../include/Obj00002.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern int func_021B61C8(u8 *p);
extern int func_021B61B8(u8 *p);
struct Obj;
extern int func_021B6300(struct Obj *o, int n, int k);
extern int func_021B6374(struct Obj *o, int n, int k);
extern void func_021B624C(void *o, int a, int b);
extern void func_021B80C4(struct Obj *o, int flag);

int func_021B65E8(u8 *p)
{
    u32 x, y;
    int k, a;
    u32 target;
    int n;
    u32 i;

    if (TOUCHPANEL_GetPointCont(&x, &y) == 1) {
        if (x < 0x90 || x > 0xE7 || y < 0xC || y > 0x9B)
            return 0;
        target = (y - 0xC) / 0x18;
        if (*(u32 *)&((struct Obj00002 *)p)->f810 == target)
            return 0;
        k = func_021B61C8(p);
        a = func_021B61B8(p);
        n = *(u32 *)&((struct Obj00002 *)p)->f810 - target;
        if (n < 0)
            n = -n;
        if (*(u32 *)&((struct Obj00002 *)p)->f810 < target) {
            for (i = 0; i < n; i++) {
                if (func_021B6300((struct Obj *)p, k, 0) == 0)
                    break;
            }
        } else if (*(u32 *)&((struct Obj00002 *)p)->f810 > target) {
            for (i = 0; i < n; i++) {
                if (func_021B6374((struct Obj *)p, k, 0) == 0)
                    break;
            }
        }
        if (i == 0)
            return 0;
        func_021B624C(p, a, func_021B61B8(p));
        func_021B80C4((struct Obj *)p, 0);
        return 1;
    }
    return 0;
}
