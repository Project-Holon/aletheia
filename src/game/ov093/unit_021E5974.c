/*
 * file:     unit_021E5974.c
 * unit:     yes
 * function: func_021E5968, func_021E5974, func_021E5A34
 * address:  0x021E5968
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
 *   func_06898CF4  0x06898CF4  thumb
 *   d_021F2584     0x021F2584  data   ov093  a4
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7F24  0x021C7F24  thumb  ov093
 *   func_021C7F4C  0x021C7F4C  thumb  ov093
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   func_021C8010  0x021C8010  thumb  ov093
 *   d_021F258C     0x021F258C  data   ov093  a4
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   func_021B9A40 0x021B9A40 thumb ov093
 */
#include "../../matched/include/Obj06274.h"

struct Flag;
struct QQ;
struct S;
struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int func_021C7F24(u8 *p, int i);
extern int func_021C7F4C(struct Flag *p);
extern u8 func_021B8DDC(u32 x);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern int func_021C8010(u8 *p, unsigned int v);
extern void *func_021C7CF4(int *p, int i);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern unsigned char func_021B9A40(unsigned int x);
extern int func_06898CF4(int, int);
extern int d_021F2584[];
int *func_021E5968(int *p);

int *func_021E5968(int *p)
{
    *p = 1;
    return d_021F2584;
}


void func_021E5974(void *a, void *b, int c);
int *func_021E5A28(int *p);
void func_021E5A34(void *x, void *a, int c);
extern int d_021F258C[];


void func_021E5974(void *a, void *b, int c)
{
    u8 *m;
    int v;

    if (c == BTL_EVENT_GetVar(3) && func_021C7F24(b, c) != 0 && func_021C7F4C(b) != 0) {
        v = func_021B8DDC(c);
        m = (u8 *)func_021C88A4(b, 0x29, c);
        m[0x4c] = c;
        func_021C8838(m + 4, 2, 0x302);
        func_021C8860((struct S *)(m + 4), c);
        func_021C8860((struct S *)(m + 4), v);
        func_021C88C8(b, m);
        m = (u8 *)func_021C88A4(b, 0x37, c);
        ((struct Obj06274 *)m)->f4 = (BTL_EVENT_GetFactorKey(a) == 0x171) ? 0x283 : 0x284;
        m[6] = func_021C8010(b, c);
        m[7] = 6;
        ((struct Obj06274 *)m)->f0 |= 1 << 24;
        func_021C88C8(b, m);
    }
}


int *func_021E5A28(int *p)
{
    *p = 1;
    return d_021F258C;
}

void func_021E5A34(void *x, void *a, int c)
{
    void *m;
    u8 *p;
    int v;
    u8 b, d, e;
    u32 i;
    if (c == BTL_EVENT_GetVar(3)) {
        m = func_021C7CF4(a, c);
        if (BTL_POKEPARAM_HasSick(m, 18) != 0) {
            p = func_021C88A4(a, 11, c);
            p[20] = 1;
            p[8] = c;
            *(int *)(p + 4) = 18;
            func_021C88C8(a, p);
        }
        if (BTL_POKEPARAM_HasSick(m, 8) != 0) {
            p = func_021C88A4(a, 11, c);
            p[20] = 1;
            p[8] = c;
            *(int *)(p + 4) = 8;
            func_021C88C8(a, p);
        }
        v = func_021B9A40(c);
        b = func_06898CF4(v, 6);
        d = func_06898CF4(v, 7);
        e = func_06898CF4(v, 8);
        if (b || d || e) {
            p = func_021C88A4(a, 26, c);
            p[7] = v;
            p[4] = 3;
            for (i = 1; i < 3; i++)
                p[4 + i] = 0;
            if (b && p[4] > 1)
                p[5] |= 0x40;
            if (d && p[4] > 1)
                p[5] |= 0x80;
            if (e && p[4] > 2)
                p[6] |= 1;
            func_021C88C8(a, p);
        }
    }
}
