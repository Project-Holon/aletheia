/*
 * function: func_021BB0E0
 * address: 0x021BB0E0
 * packet: pkt_ov093_021BB0E0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Lever: case 3 falls through to case 4; case 5 polls before dispatching
 * the result field through its nested switch.
 * symbols:
 *   func_021BB724 0x021BB724 thumb ov093
 *   func_021BB798 0x021BB798 thumb ov093
 *   func_021BB7D0 0x021BB7D0 thumb ov093
 *   func_021BA618 0x021BA618 thumb ov093
 *   func_021BABEC 0x021BABEC thumb ov093
 *   func_021BB280 0x021BB280 thumb ov093
 *   func_021BAEF8 0x021BAEF8 thumb ov093
 *   func_021BB6A8 0x021BB6A8 thumb ov093
 *   func_021BB628 0x021BB628 thumb ov093
 *   func_021BBD20 0x021BBD20 thumb ov093
 *   func_021BBD2C 0x021BBD2C thumb ov093
 *   func_021C84D8 0x021C84D8 thumb ov093
 *   func_021B916C 0x021B916C thumb ov093
 *   func_021BABF4 0x021BABF4 thumb ov093
 */
#include "../include/Obj02775.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern void func_021BB724(u8 *p, int a, int b, int c);
extern int func_021BB798(u8 *);
extern void func_021BB7D0(const u8 *p);
extern int func_021BA618(char *p);
extern void func_021BABEC(int *p, void *f);
extern int func_021BB280(u8 *);
extern int func_021BAEF8(u8 *, int *);
extern void func_021BB6A8(u8 *);
extern int func_021BB628(u8 *, int, int);
extern void func_021BBD20(u8 *p);
extern int func_021BBD2C(u8 *p, int a);
extern int func_021C84D8(u8 *p);
extern void func_021B916C(u8 *p, u32 x);
extern void func_021BABF4(void *);
int func_021BB0E0(u8 *p, int *s)
{
    switch (*s) {
    case 0:
        func_021BB724(p, 6, (int)(p + 0xcb4), p[0xcba]);
        (*s)++;
        break;
    case 1:
        if (func_021BB798(p)) {
            func_021BB7D0(p);
            if (func_021BA618(((struct Obj02775 *)p)->fC)) {
                func_021BABEC((int *)p, (void *)func_021BB280);
            } else {
                func_021BB6A8(p);
                if (func_021BB628(p, 3, 0)) (*s)++;
                else *s += 2;
            }
        }
        break;
    case 2:
        if (func_021BB798(p)) {
            func_021BB7D0(p);
            (*s)++;
        }
        break;
    case 3:
        func_021BB7D0(p);
        func_021BBD20(((struct Obj02775 *)p)->f44);
        (*s)++;
    case 4: {
        int *q;
        q = *(int * *)&((struct Obj02775 *)p)->fCB0;
        q[0] = 0;
        q[1] = 0;
        ((struct Obj02775 *)p)->f48 = func_021BBD2C(((struct Obj02775 *)p)->f44, (int)(p + 0xb4));
        q = *(int * *)&((struct Obj02775 *)p)->fCB0;
        func_021BB724(p, 8, (int)(q + 2), q[0]);
        (*s)++;
        break;
    }
    case 5:
        if (func_021BB798(p)) {
            func_021BB7D0(p);
            switch (((struct Obj02775 *)p)->f48) {
            case 1: *s = 0; break;
            case 3: *s = 4; break;
            case 2: func_021BABEC((int *)p, (void *)func_021BAEF8); break;
            case 4:
                func_021B916C((u8 *)(*(int *)&((struct Obj02775 *)p)->fC), func_021C84D8((u8 *)(*(int *)&((struct Obj02775 *)p)->f44)));
                func_021BABEC((int *)p, (void *)func_021BB280);
                break;
            case 5: return 1;
            case 0:
            default: func_021BABF4(p); break;
            }
        }
        break;
    }
    return 0;
}
