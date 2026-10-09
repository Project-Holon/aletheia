/*
 * file:     unit_021DEDF8.c
 * unit:     yes
 * function: func_021DEDF8, func_021DEE3C, func_021DEE48, func_021DEE7C, func_021DEEA4, func_021DEEF0, func_021DEEFC, func_021DEF48, func_021DEFB8
 * address:  0x021DEDF8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021DCFF8  0x021DCFF8  thumb  ov093
 *   func_021E8C50  0x021E8C50  thumb  ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_021DD044  0x021DD044  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   d_021F197C     0x021F197C  data   ov093  a4
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5B48  0x021D5B48  thumb  ov093
 *   func_021D70C8  0x021D70C8  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   d_021F16EC     0x021F16EC  data   ov093  a4
 *   d_021F14B4     0x021F14B4  data   ov093  a4
 */
#include "../../matched/include/Obj13496.h"

union U;
struct S;
struct QQ;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

extern int func_021D775C(int key);
extern int func_021D76BC(int key, u32 val);
extern int func_021DCFF8(int a, int b);
extern void func_021E8C50(union U *p, u32 v);
extern void func_021D7704(int,int);
extern void func_021DD044(void *, void *, int);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern u16 func_021D70A8(struct QQ *p);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5B48(u8 *p);
extern void func_021D70C8(int a);
extern int func_021D7B74(u8 *p, u32 k);
void func_021DEDF8(int a, int b, int c);
int *func_021DEE3C(int *p);
void func_021DEE48(int a,int b,int c,int *p);
void func_021DEE7C(void *a, void *b, int c, int *d);
void func_021DEEA4(int a, void *b, int c);
int *func_021DEEF0(int *p);
void func_021DEEFC(int a, void *b, int c);
void func_021DEF48(int a, void *b, int c);
int *func_021DEFB8(int *p);
extern int d_021F197C[];
extern int d_021F16EC[];
extern int d_021F14B4[];



void func_021DEDF8(int a, int b, int c)
{
    int t;
    u8 k;

    if (c == func_021D775C(2) && (u32)func_021D775C(0x53) <= 1) {
        t = func_021D775C(0x1e);
        k = func_021DCFF8(a, 2);
        func_021E8C50((union U *)(&t), k);
        func_021D76BC(0x1e, t);
    }
}



/*
 * sdk:      DWC_ScInitialize (libdwcsc.TWL.HYB.a dwc_sc.o)
 */
int *func_021DEE3C(int *p)
{
    *p = 3;
    return d_021F197C;
}



void func_021DEE48(int a,int b,int c,int *p) { if(c==func_021D775C(3)) { if(func_021D775C(18)!=507) { if(func_021D76BC(81,1)) *p=1; } } }




void func_021DEE7C(void *a, void *b, int c, int *d)
{
    if (c == func_021D775C(3) && *d != 0)
        func_021DD044(a, b, c);
}




void func_021DEEA4(int a, void *b, int c)
{
    u8 *r;

    if (c == func_021D775C(2)) {
        r = (u8 *)func_021C88A4(b, 4, c);
        func_021C8838(r + 4, 2, 0x3fe);
        func_021C8860((struct S *)(r + 4), c);
        func_021C8860((struct S *)(r + 4), func_021D70A8((void *)a));
        func_021C88C8(b, r);
    }
}


int *func_021DEEF0(int *p)
{
    *p = 2;
    return d_021F16EC;
}


void func_021DEEFC(int a, void *b, int c)
{
    u32 *r;

    if (c == func_021D775C(2)) {
        if (func_021D5B48(func_021C7CF4(b, c)) == 0) {
            r = (u32 *)func_021C88A4(b, 0, c);
            r[1] = (r[1] & ~1) | 1;
            func_021D70C8(a);
            func_021C88C8(b, r);
        }
    }
}



void func_021DEF48(int a, void *b, int c)
{
    void *m;
    u8 *r;

    if (c == func_021D775C(2)) {
        m = func_021C7CF4(b, c);
        if (func_021D5B48(m) == 0) {
            r = (u8 *)func_021C88A4(b, 5, c);
            r[6] = c;
            ((struct Obj13496 *)r)->f4 = func_021D7B74(m, 16);
            func_021C8838(r + 8, 2, 0x392);
            func_021C8860((struct S *)(r + 8), c);
            func_021C8860((struct S *)(r + 8), func_021D70A8((void *)a));
            func_021C88C8(b, r);
        }
    }
}


int *func_021DEFB8(int *p)
{
    *p = 1;
    return d_021F14B4;
}
