/*
 * function: func_021B8E08
 * address:  0x021B8E08
 * packet:   pkt_ov070_021B8E08
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B7DD0  0x021B7DD0  thumb  ov070
 *   func_0204B92C  0x0204B92C  arm
 *   func_021BB3F4  0x021BB3F4  thumb  ov070
 *   func_020355C4  0x020355C4  arm
 *   func_021B80C4  0x021B80C4  thumb  ov070
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B7CD0  0x021B7CD0  thumb  ov070
 */
#include "../include/Obj00002.h"

extern void func_021B7DD0();
struct Obj;
extern void func_0204B92C(struct Obj *p, unsigned int v);
typedef unsigned char  u8;
extern void func_021BB3F4(int p, int mode);
extern u8 func_020355C4(void);
extern void func_021B80C4(struct Obj *o, int flag);
extern void func_021B6100(char *p, int k);
extern void func_021B7CD0(struct Obj *o);

void func_021B8E08(int p)
{
    int f;
    func_021B7DD0(p);
    func_0204B92C((struct Obj *)*(int *)&((struct Obj00002 *)p)->f6A8, 1);
    func_021BB3F4(p, 1);
    f = 1;
    if (func_020355C4()) {
        f = 0;
    }
    func_021B80C4((struct Obj *)p, f);
    func_021B6100((char *)p, (int)func_021B7CD0);
}
