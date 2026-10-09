/*
 * file:     weather_task_p14.c
 * unit:     yes
 * function: func_021A482C, func_021A4890, func_021A48A4, func_021A48C8, func_021A491C, func_021A4960, func_021A4994, func_021A4A74
 * address:  0x021A482C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021A5390  0x021A5390  thumb  ov021
 *   func_021A56F4  0x021A56F4  thumb  ov021
 *   func_0219F7CC  0x0219F7CC  thumb  ov021
 *   func_021A5708  0x021A5708  thumb  ov021
 *   func_021A53A4  0x021A53A4  thumb  ov021
 *   func_021A47B4  0x021A47B4  thumb  ov021
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A56C0  0x021A56C0  thumb  ov021
 *   func_021A54B4  0x021A54B4  thumb  ov021
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_021A491C  0x021A491C  thumb  ov021
 *   func_021A4AA8  0x021A4AA8  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_021AB140  0x021AB140  thumb  ov021
 *   func_021AB404  0x021AB404  thumb  ov021
 *   func_021AB410  0x021AB410  thumb  ov021
 *   func_021AB328  0x021AB328  thumb  ov021
 *   func_021A5264  0x021A5264  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_021AB158  0x021AB158  thumb  ov021
 *   func_021AB164  0x021AB164  thumb  ov021
 *   func_021AB170  0x021AB170  thumb  ov021
 *   func_021AB17C  0x021AB17C  thumb  ov021
 */
#include "../../matched/include/Obj02083.h"
#include "../../matched/include/Obj19788.h"
#include "../../matched/include/Obj12737.h"
#include "../../matched/include/Obj02084.h"
#include "../../matched/include/Obj02084.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern int func_021A5390(u32 a);
extern int func_021A56F4(u32 a);
extern int func_0219F7CC(u32, u32);
extern int func_021A5708(u32 a);
extern void func_021A53A4(u32 *p, int on);
extern int func_021A47B4(u8 *, u32, u8 *);
extern int func_0216D3CC(int a0);
extern void func_021A54B4(u8 *p);
extern u32 func_021A56C0(u32 *p, u32 a1, u32 a2, u32 a3);
extern void *func_021A3960(unsigned char *p);
extern int func_021A491C(u8 *, void *, u32);
extern int func_021A4AA8(u8 *, void *, u32);
extern u16 func_0216D5F8(void *p);
int func_021AB140(int a);
int func_021AB404(int a);
int func_021AB410(int a);
int func_021AB328(int a);
extern int func_021A5264(u8 *a, void *b, u32 c, int *d);
extern u16 func_021AB0F0(u32 attr);
extern u16 func_021AB0F8(u32 attr);
extern int func_021AB158(u16);
extern int func_021AB164(u16);
extern int func_021AB170(u16);
extern int func_021AB17C(u16);
int ov021_func_021A482C(u8 *a, u32 b, u8 *c);
int func_021A4890(u8 *a, u32 b, u32 c);
int func_021A48A4(u32 a, u32 b, u32 c, u32 d);
int ov021_func_021A48C8(u8 *a, u32 b);
int ov021_func_021A491C(u32 a, u32 b, u8 *c);
int func_021A4960(int a);
int func_021A4994(u8 *a, void *b, u8 *c);
int func_021A4A74(int a, int b, u8 *c);





int ov021_func_021A482C(u8 *a, u32 b, u8 *c)
{
    if (((struct Obj19788 *)c)->f8 == 9) {
        if (func_021A5390((u32)a) == 0) {
            func_021A56F4((u32)a);
        }
        if (((struct Obj02083 *)a)->f16 == 1) {
            if (func_0219F7CC(b, ((struct Obj02083 *)a)->f14) != 0) {
                ((struct Obj02083 *)a)->f16 = 0;
            }
        }
        ((struct Obj02083 *)a)->f14 = ((struct Obj02083 *)a)->f14 + 1;
        if (((struct Obj02083 *)a)->f14 == 60) {
            func_021A5708((u32)a);
            func_021A53A4((u32 *)a, 1);
            return 7;
        }
    } else {
        func_021A5708((u32)a);
        return func_021A47B4(a, b, c);
    }
    return 6;
}





/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A4890(u8 *a, u32 b, u32 c)
{
if (func_0216D3CC(b) == 1) {
    return 9;
}
return 8;
}





int func_021A48A4(u32 a, u32 b, u32 c, u32 d)
{
if (func_021A56C0((u32 *)a, b, c, d) == 1) {
    func_021A54B4((u8 *)a);
    func_021A53A4((u32 *)a, 0);
    return 1;
}
return 9;
}





int ov021_func_021A48C8(u8 *a, u32 b)
{
    void *r = func_021A3960(((struct Obj12737 *)a)->fC);
    int ret = 0;
    switch (((struct Obj12737 *)a)->f0) {
    case 0:
        ret = func_021A491C(a, r, b);
        break;
    case 1:
        ret = func_021A4994(a, r, (u8 *)b);
        break;
    case 2:
        ret = func_021A4A74((int)a, (int)r, (u8 *)b);
        break;
    case 3:
        ret = func_021A4AA8(a, r, b);
        break;
    }
    return ret;
}





int ov021_func_021A491C(u32 a, u32 b, u8 *c)
{
    if (func_0216D3CC(b) == 1) {
        if (((struct Obj02084 *)c)->f8 != 9) {
            u32 r = func_0216D5F8((void *)b);
            if (((struct Obj02084 *)c)->f8 != r && ((struct Obj02084 *)c)->f10 == 0) {
                return 3;
            }
            return func_021A4994((u8 *)a, (void *)b, (u8 *)((u32)c));
        }
        return 1;
    }
    return 0;
}




int func_021A4960(int a)
{
    if (func_021AB140(a) != 0 || func_021AB404(a) != 0 || func_021AB410(a) != 0 || func_021AB328(a) != 0)
        return 1;
    return 0;
}




/*
 * Twin of ov021_func_021A4598; the final attribute test also consults
 * func_021A4960 on the tile id.
 *
 * Addresses are Black-image addresses.
 */
int func_021A4994(u8 *a, void *b, u8 *c)
{
    int sp;
    u32 r;
    u16 k;
    u32 t;
    int cls;

    if (func_0216D3CC((int)b) == 0) {
        return 0;
    }
    if (((struct Obj02084 *)c)->f8 == 9) {
        return func_021A491C(a, b, (u32)c);
    }
    r = func_021A5264(a, b, ((struct Obj02084 *)c)->f8, &sp);
    if (((struct Obj02084 *)c)->f10 == 1 && r != 0 && !(r & 0x10)) {
        r = 0;
    }
    if (sp != -1) {
        k = func_021AB0F0(sp);
        t = func_021AB0F8(sp);
        if (r & 2) {
            cls = 9;
            if (func_021AB158(k)) {
                cls = 0;
            } else if (func_021AB164(k)) {
                cls = 1;
            } else if (func_021AB170(k)) {
                cls = 2;
            } else if (func_021AB17C(k)) {
                cls = 3;
            }
            if (cls != 9 && cls == ((struct Obj02084 *)c)->f8) {
                return 5;
            }
        }
        if (r == 0) {
            if (!(t & 2) && func_021A4960(k) == 0) {
                return 2;
            }
            if (((struct Obj02084 *)c)->f10 == 1) {
                return 2;
            }
        }
    }
    return 4;
}


int func_021A4A74(int a, int b, u8 *c)
{
    if (func_0216D3CC(b) == 0)
        return 0;
    if (((struct Obj02084 *)c)->f8 == 9)
        return func_021A491C((u8 *)a, (void *)b, (u32)c);
    return func_021A4994((u8 *)a, (void *)b, c);
}
