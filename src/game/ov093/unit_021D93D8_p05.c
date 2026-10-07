/*
 * file:     unit_021D93D8_p05.c
 * unit:     yes
 * function: func_021D9880, func_021D98DC, func_021D9934, func_021D9978
 * address:  0x021D9880
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
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C8288  0x021C8288  thumb  ov093
 *   func_0201C1E8  0x0201C1E8  thumb
 *   func_021D7704  0x021D7704  thumb  ov093
 *   d_021F0930     0x021F0930  data   ov093  a4
 */
#include "../../matched/include/Obj10057.h"
#include "../../matched/include/Obj13463.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

extern int func_021D775C(int);
extern int func_021D76BC(int key, u32 val);
extern void *func_021C7CF4(int *p, int i);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern int func_021D7B74(u8 *p, u32 k);
extern void func_021C88B4(void *a, int k, int b);
extern int func_021C8288(u8 *p);
extern int func_0201C1E8(int a);
extern void func_021D7704(int key, s32 m);
void func_021D9880(void *a, int b, int c);
void func_021D98DC(int a, void *b, int c);
void func_021D9934(int a, int b, int c);
int *func_021D996C(int *p);
void func_021D9978(int a,int b,int c);
extern int d_021F0930[];


void func_021D9880(void *a, int b, int c)
{
    void *q;
    u8 *p;

    if (c == func_021D775C(0x39) && b == func_021D775C(2)) {
        q = func_021C7CF4(a, b);
        p = func_021C88A4(a, 5, b);
        ((struct Obj10057 *)p)->f0 |= 0x800000;
        p[6] = b;
        ((struct Obj10057 *)p)->f4 = func_021D7B74(q, 0x10);
        func_021C88C8(a, p);
        func_021D76BC(0x41, 1);
    }
}


void func_021D98DC(int a, void *b, int c)
{
    int h;
    u8 *p;

    if (c == func_021D775C(2) && func_021D775C(0x39) == 1) {
        h = func_021D7B74(func_021C7CF4(b, c), 8);
        func_021C88B4(b, 2, c);
        p = func_021C88A4(b, 7, c);
        p[6] = c;
        ((struct Obj13463 *)p)->f4 = h;
        func_021C88C8(b, p);
        func_021C88B4(b, 3, c);
    }
}


void func_021D9934(int a, int b, int c)
{
    if (c == func_021D775C(3) && func_021C8288((u8 *)b) == 1) {
        if (func_0201C1E8((u16)func_021D775C(0x12)) == 2)
            func_021D7704(0x35, 0x1800);
    }
}


int *func_021D996C(int *p)
{
    *p = 2;
    return d_021F0930;
}

void func_021D9978(int a,int b,int c) { if(c==func_021D775C(4) && c!=func_021D775C(3) && func_021D775C(0x1d)!=8) func_021D76BC(0x41,1); }
