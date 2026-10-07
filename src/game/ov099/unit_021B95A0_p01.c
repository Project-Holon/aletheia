/*
 * file:     unit_021B95A0_p01.c
 * unit:     yes
 * function: func_021B95A0, func_021B9670, func_021B96CC, func_021B96D0
 * address:  0x021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_021B9DC0  0x021B9DC0  thumb  ov099
 *   func_021B9E04  0x021B9E04  thumb  ov099
 *   func_021BA810  0x021BA810  thumb  ov099
 *   func_021BA81C  0x021BA81C  thumb  ov099
 *   func_021C47A0  0x021C47A0  thumb  ov127
 *   func_021C4800  0x021C4800  thumb  ov127
 *   func_021C4880  0x021C4880  thumb  ov127
 *   func_021B9D30  0x021B9D30  thumb  ov099
 *   func_021C59D0  0x021C59D0  thumb  ov127
 *   func_021B9D6C  0x021B9D6C  thumb  ov099
 *   func_021B9E0C  0x021B9E0C  thumb  ov099
 *   func_021BA60C  0x021BA60C  thumb  ov099
 *   func_021C5EEC  0x021C5EEC  thumb  ov127
 *   func_021C5F30  0x021C5F30  thumb  ov127
 *   func_021B9DB0  0x021B9DB0  thumb  ov099
 *   func_021BA648  0x021BA648  thumb  ov099
 *   func_021B9B80  0x021B9B80  thumb  ov099
 *   func_021B9D5C  0x021B9D5C  thumb  ov099
 *   func_021C48C0  0x021C48C0  thumb  ov127
 *   func_021C47E4  0x021C47E4  thumb  ov127
 *   func_021B9DD4  0x021B9DD4  thumb  ov099
 *   func_021B9E08  0x021B9E08  thumb  ov099
 *   func_021C48E8  0x021C48E8  thumb  ov127
 *   func_021B9C9C  0x021B9C9C  thumb  ov099
 *   func_021B9C4C  0x021B9C4C  thumb  ov099
 *   func_021C5994  0x021C5994  thumb  ov127
 *   func_021C5A60  0x021C5A60  thumb  ov127
 *   func_021C571C  0x021C571C  thumb  ov127
 *   func_021B9CD0  0x021B9CD0  thumb  ov099
 *   func_021B9F84  0x021B9F84  thumb  ov099
 *   func_021B9BA8  0x021B9BA8  thumb  ov099
 *   func_021B97CC  0x021B97CC  thumb  ov099
 *   func_021B9FDC  0x021B9FDC  thumb  ov099
 *   func_021B9F48  0x021B9F48  thumb  ov099
 *   func_0203630C  0x0203630C  arm
 *   func_020362DC  0x020362DC  arm
 *   func_021B97F4  0x021B97F4  thumb  ov099
 *   func_021B9BC4  0x021B9BC4  thumb  ov099
 */
#include "../../matched/include/Obj07938.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u16 w, h; } WH;

extern void func_02082BCC(void *p, u32 v, u32 n);
extern void func_021B9DC0(void *a, u32 b, u32 c);
extern void func_021B9E04(void *a, int heap);
extern WH func_021BA810(int i);
extern u32 func_021BA81C(int i);
extern void *func_021C47A0(u32 w, u32 h, u32 heap);
extern void func_021C4800(u8 *p, void *out);
extern void *func_021C4880(u32 count, u32 heap);
extern void func_021B9D30(u8 *p, void *q, u32 heap);
extern void func_021C59D0(void *p);
extern int func_021B9D6C(char *p, u32 heap, u32 x, u32 n);
extern void func_021B9E0C(void *a, u32 b, u32 c, u32 d);
extern void func_021BA60C(char *a, char *p, u32 unused, u32 arc);
extern void *func_021C5EEC(int n, int heap);
extern void func_021C5F30(u8 *p);
extern void func_021B9DB0(char *p);
extern void func_021BA648(int unused, void *p);
extern void func_021B9B80(char *p);
extern void func_021B9D5C(char *p);
extern void func_021C48C0(u8 *p);
extern void func_021C47E4(u8 *p);
extern void func_021B9DD4(void *a);
extern void func_021B9E08(int);
extern void func_021C48E8(u8 *p);
extern void func_021B9C9C(u8 *p);
extern void func_021B9C4C(char *p);
extern void func_021C5994(void *p, void *q);
extern void func_021C5A60(char *p, void *q);
extern void func_021C571C(u8 *p);
extern void func_021B9CD0(char *p);
extern void func_021B9F84(char *p);
extern int func_021B9BA8(char *p);
extern void func_021B97CC(char *p);
extern int func_021B9FDC(char *p);
extern void func_021B9F48(u8 *p);
extern u32 func_0203630C(void);
extern u32 func_020362DC(void);
extern u8 func_021B97F4(char *p);
extern int func_021B9BC4(char *p);
void func_021B95A0(char *p, int heap, u32 x2, u32 x3, u32 a4, u32 a5, u32 a6, u32 a7);
void func_021B9670(char *p);
int func_021B96CC(int *p);
u32 func_021B96D0(char *p);


void func_021B95A0(char *p, int heap, u32 x2, u32 x3, u32 a4, u32 a5, u32 a6, u32 a7)
{
    WH t;
    u32 n = 0;
    func_02082BCC(p, 0, 0x5A0);
    if (a4 != 0) n = (a4 - 1) >> 3;
    *(u32 *)(p + 0x14) = a6;
    *(u32 *)(p + 4) = heap;
    *(u32 *)(p + 0x18) = a7;
    func_021B9DC0(p + 0x14, heap, x2);
    func_021B9E04(*(void **)(p + 0x10), heap);
    t = func_021BA810(n);
    *(void **)(p + 0x588) = func_021C47A0(t.w, t.h, heap);
    func_021C4800(*(void **)(p + 0x588), (void *)func_021BA81C(n));
    *(void **)(p + 0x58C) = func_021C4880(0x30, heap);
    func_021B9D30((u8 *)p, (void *)x3, heap);
    func_021C59D0(p + 0x594);
    func_021B9D6C(p, heap, x2, n);
    func_021B9E0C(*(void **)(p + 0x10), heap, x2, a5);
    func_021BA60C(p, p + 0x574, x2, a5);
    *(void **)(p + 0x59C) = func_021C5EEC(0x80, heap);
    *(u32 *)p = 1;
}


void func_021B9670(char *p)
{
    func_021C5F30((u8 *)(((struct Obj07938 *)p)->f59C));
    func_021B9DB0(p);
    func_021BA648((int)p, p + 0x574);
    func_021B9B80(p);
    func_021B9D5C(p);
    func_021C48C0((u8 *)(((struct Obj07938 *)p)->f58C));
    func_021C47E4((u8 *)(((struct Obj07938 *)p)->f588));
    func_021B9DD4(p + 0x14);
    func_021B9E08(((struct Obj07938 *)p)->f10);
    func_02082BCC(p, 0, 0x5a0);
}

int func_021B96CC(int *p)
{
    return *p;
}


u32 func_021B96D0(char *p)
{
    if (*(u32 *)0x02FFFC3C & 1) {
        func_021C48E8(*(void **)(p + 0x58C));
        func_021B9C9C((u8 *)p);
        func_021B9C4C(p);
        func_021C5994(p + 0x594, **(void ***)(p + 0x570));
        func_021C5A60(*(char **)(p + 0x598), p + 0x594);
        func_021C571C(*(void **)(p + 0x590));
        func_021B9CD0(p);
        func_021B9F84(p);
    }
    if (func_021B9BA8(p) == 1) {
        func_021B97CC(p);
        if (func_021B9FDC(p) == 1) {
            func_021B9F48((u8 *)p);
            if (func_0203630C() & 0x80)
                return 1;
        }
        if (func_020362DC() & 1) {
            if (func_021B97F4(p) != 0)
                return 2;
            if (func_021B9BC4(p) == 1)
                return 3;
        }
    }
    return 0;
}
