/*
 * file:     unit_021E508C_p01.c
 * unit:     yes
 * function: func_021E508C, func_021E517C
 * address:  0x021E508C
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
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D58A8 0x021D58A8 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   d_021F2704 0x021F2704 data a4
 *   d_021F26DC 0x021F26DC data a4
 */
#include "../../matched/include/Obj07831.h"
#include "../../matched/include/Obj07832.h"

struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Rec {
    u8 pad[14];
    u8 id;
    u8 f0:1;
    u8 f1:1;
    u8 f2:1;
    u8 f3:1;
    u8 rest:4;
} Rec;

extern int func_021D775C(int);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D58A8(u8 *p, int k);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *, void *);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(struct S *p, u32 val);
void func_021E508C(void *x, void *a, int c);
void *func_021E5170(int *p);
void func_021E517C(void *x, void *a, int c);
void *func_021E5258(int *p);
extern u8 d_021F2704[];
extern u8 d_021F26DC[];

void func_021E508C(void *x, void *a, int c)
{
    u8 k;
    void *m, *n;
    int first, second;
    Rec *p;
    if (c == func_021D775C(3)) {
        k = func_021D775C(6);
        m = func_021C7CF4(a, c);
        n = func_021C7CF4(a, k);
        first = (func_021D58A8(m, 8) + func_021D58A8(n, 8)) / 2;
        second = (func_021D58A8(m, 10) + func_021D58A8(n, 10)) / 2;
        p = func_021C88A4(a, 17, c);
        p->id = k;
        ((struct Obj07831 *)p)->f4 = first;
        ((struct Obj07831 *)p)->f8 = second;
        p->f0 = 1;
        p->f2 = 1;
        func_021C88C8(a, p);
        p = func_021C88A4(a, 17, c);
        p->id = c;
        ((struct Obj07831 *)p)->f4 = first;
        ((struct Obj07831 *)p)->f8 = second;
        p->f0 = 1;
        p->f2 = 1;
        func_021C8838((u8 *)p + 16, 2, 0x448);
        func_021C8860((struct S *)((u8 *)p + 16), c);
        func_021C88C8(a, p);
    }
}

void *func_021E5170(int *p)
{
    *p = 1;
    return d_021F2704;
}

void func_021E517C(void *x, void *a, int c)
{
    u8 k;
    void *m, *n;
    int first, second;
    Rec *p;
    if (c == func_021D775C(3)) {
        k = func_021D775C(6);
        m = func_021C7CF4(a, c);
        n = func_021C7CF4(a, k);
        first = (func_021D58A8(m, 9) + func_021D58A8(n, 9)) / 2;
        second = (func_021D58A8(m, 11) + func_021D58A8(n, 11)) / 2;
        p = func_021C88A4(a, 17, c);
        p->id = k;
        ((struct Obj07832 *)p)->f6 = first;
        ((struct Obj07832 *)p)->fA = second;
        p->f1 = 1;
        p->f3 = 1;
        func_021C88C8(a, p);
        p = func_021C88A4(a, 17, c);
        p->id = c;
        ((struct Obj07832 *)p)->f6 = first;
        ((struct Obj07832 *)p)->fA = second;
        p->f1 = 1;
        p->f3 = 1;
        func_021C8838((u8 *)p + 16, 2, 0x44b);
        func_021C8860((struct S *)((u8 *)p + 16), c);
        func_021C88C8(a, p);
    }
}

void *func_021E5258(int *p)
{
    *p = 1;
    return d_021F26DC;
}
