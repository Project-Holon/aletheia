/*
 * file:     unit_021E3B64_p01.c
 * unit:     yes
 * function: func_021E3B64, func_021E3BBC, func_021E3BF4, func_021E3C5C, func_021E3CB0, func_021E3D38, func_021E3D98, func_021E3DCC
 * address:  0x021E3B64
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
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D69AC  0x021D69AC  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021E8624  0x021E8624  thumb  ov093
 *   d_021F2856     0x021F2856  data   a1
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D7040  0x021D7040  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   d_021F2FF8     0x021F2FF8  data   a4
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021E89D4  0x021E89D4  thumb  ov093
 *   func_021C83DC  0x021C83DC  thumb  ov093
 *   func_021E3F08  0x021E3F08  thumb  ov093
 *   func_021E3E84  0x021E3E84  thumb  ov093
 */
#include "../../matched/include/Obj13514.h"
#include "../../matched/include/Obj06270.h"
#include "../../matched/include/Obj13515.h"

struct Node;
struct S;
struct QQ;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct Word { unsigned int v; } Word;

extern int func_021D775C(int);
extern void *func_021C7CF4(int *p, int i);
extern unsigned char func_021D69AC(unsigned char *base, int idx);
extern u32 func_021D78AC(u32 range);
extern int func_021D76BC(int key, u32 val);
extern int func_021E8624(int a, int b);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021D7040(struct Node *n);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, unsigned int a);
extern u16 func_021D70A8(struct QQ *p);
extern Word func_021E89D4(unsigned int a);
extern void func_021C83DC(char *p, int x);
extern void func_021E3F08(void *a, int c, int *w);
extern int func_021E3E84(int u, void *a, int c, int *w);
void func_021E3B64(int u, void *a, int c);
void func_021E3BBC(void *u, int a, int b);
void func_021E3BF4(int u, void *a, int c);
void func_021E3C5C(void *a, int b, int c);
int *func_021E3CA4(int *p);
void func_021E3CB0(int u, void *a, int c, int *w);
void func_021E3D38(int u, int v, int c, int *w);
void func_021E3D98(int u, int a, int b, int *p);
void func_021E3DCC(int u, void *a, int b, int *p);
extern const u8 d_021F2856[];
extern int d_021F2FF8[];


void func_021E3B64(int u, void *a, int c)
{
    unsigned x;

    if (c == func_021D775C(2)) {
        x = func_021D69AC(func_021C7CF4(a, c), 3);
        if (x != 0) {
            if (x >= 10)
                x = 9;
            if (func_021D78AC(d_021F2856[x]) != 0) {
                func_021D76BC(0x22, 0x1a);
                return;
            }
        }
        if (func_021E8624((int)a, c) != 0)
            func_021D76BC(0x22, 0x1a);
    }
}


void func_021E3BBC(void *u, int a, int b)
{
    u8 *s;

    if (b == func_021D775C(2)) {
        s = func_021C88A4((char *)a, 0x26, b);
        s[4] = b;
        s[5] = 3;
        s[6] = 0;
        func_021C88C8((void *)a, s);
        func_021D7040(u);
    }
}


void func_021E3BF4(int u, void *a, int c)
{
    char *p;

    if (c == func_021D775C(3)) {
        func_021C7CF4(a, c);
        p = func_021C88A4(a, 0x15, c);
        p[8] = c;
        ((struct Obj13514 *)p)->f4 = 7;
        func_021C88C8(a, p);
        func_021E3C5C(a, c, 0);
        p = func_021C88A4(a, 4, c);
        func_021C8838(p + 4, 2, 0x205);
        func_021C8860((struct S *)(p + 4), c);
        func_021C88C8(a, p);
    }
}


void func_021E3C5C(void *a, int b, int c)
{
    void *q;
    u8 *p;

    q = func_021C7CF4(a, b);
    p = func_021C88A4(a, 0x26, b);
    p[6] = func_021D69AC(q, 3) + 1;
    p[4] = b;
    p[5] = 3;
    ((struct Obj06270 *)p)->f0 = (((struct Obj06270 *)p)->f0 & 0xfeffffff) | ((c & 1) << 24);
    func_021C88C8(a, p);
}


int *func_021E3CA4(int *p)
{
    *p = 7;
    return d_021F2FF8;
}


void func_021E3CB0(int u, void *a, int c, int *w)
{
    char *p;

    if (c == func_021D775C(2)) {
        switch (w[0]) {
        case 0:
            p = func_021C88A4(a, 0xc, c);
            ((struct Obj13515 *)p)->f4 = 0x19;
            *(Word *)(p + 8) = func_021E89D4(func_021D70A8((void *)u));
            p[0xf] = c;
            func_021C88C8(a, p);
            func_021D76BC(0x3e, 2);
            w[6] = 1;
            w[0] = 1;
            w[1] = 0;
            break;
        case 1:
            func_021D76BC(0x3e, 2);
            w[0] = 2;
            break;
        case 2:
        default:
            func_021C83DC(a, 1);
            func_021E3F08(a, c, w);
            break;
        }
    }
}


void func_021E3D38(int u, int v, int c, int *w)
{
    int p;

    if (c == func_021D775C(2)) {
        p = func_021D775C(0x3f);
        switch (w[0]) {
        case 1:
            func_021C8838((void *)p, 2, 0x2e9);
            func_021C8860((struct S *)p, c);
            func_021D76BC(0x51, 1);
            break;
        case 2:
            func_021C8838((void *)p, 2, 0x2ec);
            func_021C8860((struct S *)p, c);
            func_021D76BC(0x51, 1);
            break;
        }
    }
}


void func_021E3D98(int u, int a, int b, int *p)
{
    if (b == func_021D775C(2)) {
        if (*p >= 2) {
            if (p[1] == 0)
                func_021D76BC(0x22, 0x1a);
            else if (p[2] == 0x1f)
                func_021D76BC(0x22, 0x1a);
            *p = 3;
        }
    }
}


void func_021E3DCC(int u, void *a, int b, int *p)
{
    int t;

    if (b == func_021D775C(3)) {
        if (*p >= 2) {
            t = func_021E3E84(u, a, b, p);
            p[2] = t;
            func_021D76BC(4, t);
        }
    }
}
