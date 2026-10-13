/*
 * file:     unit_021E508C.c
 * unit:     yes
 * function: func_021E508C, func_021E517C, func_021E5264, func_021E52C8, func_021E52D4, func_021E530C
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
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D58A8 0x021D58A8 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   d_021F2704 0x021F2704 data a4
 *   d_021F26DC 0x021F26DC data a4
 *   BTLV_CORE_MakeSlotKind4  0x021E8A28  thumb  ov093
 *   BTLV_CORE_MakeSlotKind2Index  0x021E8940  thumb  ov093
 *   func_021B9A40  0x021B9A40  thumb  ov093
 *   func_021E556C  0x021E556C  thumb  ov093
 *   d_021F25FC     0x021F25FC  data   ov093  a4
 *   d_021F259C     0x021F259C  data   ov093  a4
 */
#include "../../matched/include/Obj07831.h"
#include "../../matched/include/Obj07832.h"
#include "../../matched/include/Obj10093.h"

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

typedef struct Word { u32 v; } Word;

extern int BTL_EVENT_GetVar(int);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D58A8(u8 *p, int k);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *, void *);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(struct S *p, u32 val);
extern int BTLV_CORE_MakeSlotKind4(u32 a, u32 b);
extern Word BTLV_CORE_MakeSlotKind2Index(int k);
extern unsigned char func_021B9A40(unsigned int x);
extern void func_021E556C(int a, int b, int c, int d, int e, int f, Word g, int h);
void func_021E508C(void *x, void *a, int c);
void *func_021E5170(int *p);
void func_021E517C(void *x, void *a, int c);
void *func_021E5258(int *p);
void func_021E5264(int a, void *b, int c);
int *func_021E52C8(int *p);
void func_021E52D4(int a, int b, int c, int d);
int *func_021E530C(int *p);
extern u8 d_021F2704[];
extern u8 d_021F26DC[];
extern int d_021F25FC[];
extern int d_021F259C[];



void func_021E508C(void *x, void *a, int c)
{
    u8 k;
    void *m, *n;
    int first, second;
    Rec *p;
    if (c == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(6);
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
    if (c == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(6);
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



void func_021E5264(int a, void *b, int c)
{
    u8 *w;
    u8 k;

    if (c == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(6);
        w = func_021C88A4(b, 12, c);
        w[0xf] = c;
        ((struct Obj10093 *)w)->f4 = 0x1d;
        ((struct Obj10093 *)w)->f8 = BTLV_CORE_MakeSlotKind4(k, 2);
        func_021C8838(w + 0x14, 2, 0x28b);
        func_021C8860((struct S *)(w + 0x14), c);
        func_021C8860((struct S *)(w + 0x14), k);
        func_021C88C8(b, w);
    }
}


int *func_021E52C8(int *p)
{
    *p = 1;
    return d_021F25FC;
}


/*
 * The callee's word result is a one-word struct (see
 * docs/idioms/a-one-word-struct-result-passed-by-value-costs-a-second-frame-word.md).
 */
void func_021E52D4(int a, int b, int c, int d)
{
    Word t = BTLV_CORE_MakeSlotKind2Index(5);
    int e = func_021B9A40(c);
    func_021E556C(a, b, c, d, e, 0, t, 0x7c);
}


int *func_021E530C(int *p)
{
    *p = 1;
    return d_021F259C;
}
