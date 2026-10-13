/*
 * file:     unit_021E5620.c
 * unit:     yes
 * function: func_021E5620, func_021E5680
 * address:  0x021E5620
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
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7F24  0x021C7F24  thumb  ov093
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F2694     0x021F2694  data   ov093  a4
 *   d_021F254C     0x021F254C  data   ov093  a4
 */
#include "../../matched/include/Obj10094.h"
#include "../../matched/include/Obj10095.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int func_021C7F24(u8 *p, int i);
extern int func_021C8010(u8 *p, unsigned int v);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
void func_021E5620(int a, void *b, int c);
int *func_021E5674(int *p);
void func_021E5680(int a, void *b, int c);
int *func_021E56D4(int *p);
extern int d_021F2694[];
extern int d_021F254C[];


void func_021E5620(int a, void *b, int c)
{
    u8 *m;

    if (c == BTL_EVENT_GetVar(3) && func_021C7F24(b, c) != 0) {
        m = (u8 *)func_021C88A4(b, 0x1e, c);
        ((struct Obj10094 *)m)->f4 = 1;
        m[8] = func_021C8010(b, c);
        func_021C88C8(b, m);
        m = (u8 *)func_021C88A4(b, 0x13, c);
        m[4] = c;
        func_021C88C8(b, m);
    }
}


int *func_021E5674(int *p)
{
    *p = 1;
    return d_021F2694;
}


void func_021E5680(int a, void *b, int c)
{
    u8 *m;

    if (c == BTL_EVENT_GetVar(3) && func_021C7F24(b, c) != 0) {
        m = (u8 *)func_021C88A4(b, 0x1e, c);
        ((struct Obj10095 *)m)->f4 = 2;
        m[8] = func_021C8010(b, c);
        func_021C88C8(b, m);
        m = (u8 *)func_021C88A4(b, 0x13, c);
        m[4] = c;
        func_021C88C8(b, m);
    }
}


int *func_021E56D4(int *p)
{
    *p = 1;
    return d_021F254C;
}
