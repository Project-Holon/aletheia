/*
 * function: func_021D7E58
 * address: 0x021D7E58
 * packet: pkt_ov123_021D7E58
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: bind the record word before the call and use shared goto guards.
 * symbols:
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D6FF0 0x021D6FF0 thumb ov123
 *   func_020093D0 0x020093D0 thumb
 *   func_021D6A70 0x021D6A70 thumb ov123
 *   func_021D7CEC 0x021D7CEC thumb ov123
 *   func_021D7E20 0x021D7E20 thumb ov123
 *   func_021D6AB8 0x021D6AB8 thumb ov123
 *   func_021D7BDC 0x021D7BDC thumb ov123
 */
#include "../include/Obj00063.h"
#include "../include/Obj03794.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int     s32;
typedef unsigned int   u32;
struct Sub02009210Obj;
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D6FF0(char *p);
extern s32 func_020093D0(const struct Sub02009210Obj *obj);
extern void func_021D6A70(u8 *p, int i, int a, int b, int c);
extern int func_021D7CEC(int a, u8 *p);
extern void func_021D7E20(u8 *, u8 *);
extern void func_021D6AB8(u8 *p);
extern void func_021D7BDC(u8 *);
void func_021D7E58(u8 *p, void *h, u8 *q, int *r)
{
    int i;
    int v;
    if (*r != 0) {
        ((struct Obj00063 *)p)->f80 = *r;
        func_021D6EE0(p, (int)func_021D6FF0, 0x500);
        return;
    }
    if (q[0x5b] != 0) goto unchanged;
    v = *(int *)q;
    if (v == func_020093D0(h)) goto unchanged;
    {
        ((struct Obj00063 *)p)->f7C = v;
        p[0xa4] = q[0x57];
        p[0xa5] = q[0x58];
        p[0xa6] = q[0x59];
        ((struct Obj00063 *)p)->f6C = ((struct Obj03794 *)q)->f54;
        if (p[0xa5]) p[0xa8] |= 1;
        if (p[0xa4]) p[0xa8] |= 2;
        if (p[0xa6]) p[0xa8] |= 4;
        for (i = 0; i < 10; i++) {
            if (*(u16 *)(q+i*8+4) == 0) break;
            func_021D6A70(((struct Obj00063 *)p)->f14, i+20, *(u16 *)(q+i*8+4), q[i*8+8], q[i*8+9]);
        }
        p[0xa9] = func_021D7CEC((int)h,q);
        func_021D7E20(p,q);
        func_021D6AB8(((struct Obj00063 *)p)->f14);
    }
    goto done;
unchanged:
    p[0xa9] = 0;
done:
    func_021D7BDC(p);
}
