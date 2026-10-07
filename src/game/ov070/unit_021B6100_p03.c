/*
 * file:     unit_021B6100_p03.c
 * unit:     yes
 * function: func_021B6374, func_021B63F8, func_021B64A0, func_021B6554, func_021B65E8
 * address:  0x021B6374
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B61C8  0x021B61C8  thumb  ov070
 *   func_02035CB8  0x02035CB8  arm
 *   func_02035C60  0x02035C60  arm
 *   func_021B80C4  0x021B80C4  thumb  ov070
 *   func_0202EDE4  0x0202EDE4  thumb
 *   func_021BA654  0x021BA654  thumb  ov070
 *   func_020061E4  0x020061E4  thumb
 *   func_021B61B8  0x021B61B8  thumb  ov070
 *   func_0203633C  0x0203633C  arm
 *   func_021B6300  0x021B6300  thumb  ov070
 *   func_021B624C  0x021B624C  thumb  ov070
 *   _u32_div_f     0x0209C2B0  arm
 */
#include "../../matched/include/Obj00002.h"

struct Obj;
typedef struct Obj {
    unsigned char pad000[0x810];
    int a;
    int b;
} Obj;

typedef unsigned char u8;

typedef unsigned int u32;

extern int func_021B61C8(u8 *p);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern int func_02035C60(void);
extern void func_021B80C4(struct Obj *o, int flag);
extern u32 func_0202EDE4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern void func_021BA654(char *p);
extern void func_020061E4(u32 se);
extern int func_021B61B8(u8 *p);
extern unsigned int func_0203633C(void);
extern int func_021B6300(struct Obj *o, int n, int k);
extern void func_021B624C(void *o, int a, int b);
int func_021B6374(Obj *o, int n, int k);
u32 func_021B63F8(u8 *p);
int func_021B64A0(void *o);
int func_021B6554(void *o);
int func_021B65E8(u8 *p);


int func_021B6374(Obj *o, int n, int k)
{
    int a, b, v;

    if (n == 0)
        return 0;
    a = o->a;
    b = o->b;
    if (a == 0 && b != -1) {
        o->b = o->b - 1;
    } else if (a != 0) {
        o->a = o->a - 1;
    } else if (k == 1) {
        v = n - 7;
        o->b = v;
        if (v < -1)
            o->b = -1;
        if ((o->a = 5) >= n)
            o->a = n - 1;
    }
    return a != o->a || b != o->b;
}


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


int func_021B64A0(void *o)
{
    int res = 0;
    int a, k;
    u32 cnt;

    a = func_021B61B8(o);
    k = func_021B61C8(o);
    if (func_0203633C() & 0x80) {
        res = func_021B6300(o, k, 1);
    } else if (func_0203633C() & 0x40) {
        res = func_021B6374(o, k, 1);
    } else if (func_0203633C() & 0x100) {
        cnt = res;
        do {
            if (func_021B6300(o, k, 0) == 0)
                break;
            cnt++;
        } while (cnt < 6);
        if (cnt != 0)
            res = 1;
    } else if (func_0203633C() & 0x200) {
        cnt = res;
        do {
            if (func_021B6374(o, k, 0) == 0)
                break;
            cnt++;
        } while (cnt < 6);
        if (cnt != 0)
            res = 1;
    }
    if (res) {
        k = func_021B61B8(o);
        func_020061E4(0x548);
        func_021B624C(o, a, k);
    }
    return res;
}


int func_021B6554(void *o)
{
    int res = 0;
    int k;
    u32 cnt;

    k = func_021B61C8(o);
    if (func_0203633C() & 0x80) {
        res = func_021B6300(o, k, 1);
    } else if (func_0203633C() & 0x40) {
        res = func_021B6374(o, k, 1);
    } else if (func_0203633C() & 0x100) {
        cnt = res;
        do {
            if (func_021B6300(o, k, 0) == 0)
                break;
            cnt++;
        } while (cnt < 6);
        if (cnt != 0)
            res = 1;
    } else if (func_0203633C() & 0x200) {
        cnt = res;
        do {
            if (func_021B6374(o, k, 0) == 0)
                break;
            cnt++;
        } while (cnt < 6);
        if (cnt != 0)
            res = 1;
    }
    return res;
}


int func_021B65E8(u8 *p)
{
    u32 x, y;
    int k, a;
    u32 target;
    int n;
    u32 i;

    if (func_02035CB8(&x, &y) == 1) {
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
