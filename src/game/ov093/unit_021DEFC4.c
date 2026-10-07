/*
 * file:     unit_021DEFC4.c
 * unit:     yes
 * function: func_021DEFC4, func_021DF0C4, func_021DF144, func_021DF150, func_021DF1B0, func_021DF288
 * address:  0x021DEFC4
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
 *   func_021C83D4 0x021C83D4 thumb ov093
 *   func_021D57FC 0x021D57FC thumb ov093
 *   func_021E8D24 0x021E8D24 thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021DCFF8 0x021DCFF8 thumb ov093
 *   func_021D7B74 0x021D7B74 thumb ov093
 *   func_021C8010 0x021C8010 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021D70A8 0x021D70A8 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   d_021F154C 0x021F154C data a4
 *   func_021E899C  0x021E899C  thumb  ov093
 *   d_021F16FC 0x021F16FC data
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_0201BEB8  0x0201BEB8  thumb
 *   d_021F138C 0x021F138C data a4
 *   d_021F1434 0x021F1434 data a4
 *   d_021F15A4 0x021F15A4 data a4
 *   d_021F1554 0x021F1554 data a4
 *   d_021F15B4 0x021F15B4 data a4
 *   d_021F15C4 0x021F15C4 data a4
 *   func_021D7704   0x021D7704  thumb ov093
 */
#include "../../matched/include/Obj03702.h"
#include "../../matched/include/Obj10069.h"
#include "../../matched/include/Obj05218.h"

struct QQ;
struct S;
struct QI;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct Word { u32 v; } Word;

extern int func_021D775C(int key);
extern int func_021C83D4(u8 *p);
extern u16 func_021D57FC(void *p);
extern int func_021E8D24(int x, int k);
extern void *func_021C7CF4(int *p, int i);
extern void *func_021C88A4(char *p, int a, int b);
extern int func_021DCFF8(int a, int b);
extern int func_021D7B74(u8 *p, u32 k);
extern int func_021C8010(u8 *p, unsigned int v);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern u16 func_021D70A8(struct QQ *p);
extern void func_021C88C8(void *a, void *b);
extern Word func_021E899C(int a);
extern u16 func_021D5B40(struct QI *p);
extern u32 func_0201BEB8(u16 id, u32 bit);
void func_021D7704(int a, int b);
void func_021DEFC4(int a, void *b, int c);
void *func_021DF0B8(int *p);
void func_021DF0C4(void *a, int b, int c);
void *func_021DF144(int *p);
void func_021DF150(int a, void *b, int c);
void func_021DF1B0(int a, void *b, int c);
void *func_021DF240(int *p);
void *func_021DF24C(int *p);
void *func_021DF258(int *p);
void *func_021DF264(int *p);
void *func_021DF270(int *p);
void *func_021DF27C(int *p);
void func_021DF288(void *a, void *b, int c);
extern u8 d_021F154C[];
extern unsigned char d_021F16FC[];
extern u8 d_021F138C[], d_021F1434[], d_021F15A4[], d_021F1554[], d_021F15B4[], d_021F15C4[];

void func_021DEFC4(int a, void *b, int c)
{
    void *m;
    u8 *r;
    if (c == func_021D775C(2) && func_021C83D4(b) == 0) {
        m = func_021C7CF4(b, c);
        if (func_021E8D24(func_021D57FC(m), 3)) {
            r = (u8 *)func_021C88A4(b, 5, c);
            r[6] = c;
            ((struct Obj03702 *)r)->f4 = func_021D7B74(m, func_021DCFF8(a, 2));
            func_021C8838(r + 8, 2, 0x392);
            func_021C8860((struct S *)(r + 8), c);
            func_021C8860((struct S *)(r + 8), func_021D70A8((void *)a));
            func_021C88C8(b, r);
        } else {
            r = (u8 *)func_021C88A4(b, 7, c);
            r[6] = c;
            ((struct Obj03702 *)r)->f4 = func_021D7B74(m, 8);
            r[7] |= 2;
            ((struct Obj03702 *)r)->f8 = 0x25f;
            r[10] = func_021C8010(b, c);
            r[11] = 6;
            func_021C8838(r + 12, 2, 0x40e);
            func_021C8860((struct S *)(r + 12), c);
            func_021C8860((struct S *)(r + 12), func_021D70A8((void *)a));
            func_021C88C8(b, r);
        }
    }
}

void *func_021DF0B8(int *p) { *p = 1; return d_021F154C; }


/*
 * 2026-10-03 (wave B3 lane 10): EXACT*. func_021E899C returns a one-word struct (Word), as in the other matched callers; its return temporary is the second frame word (see docs/idioms/an-unused-frame-word-is-a-callee-returning-a-one-word-struct.md).
 */
void func_021DF0C4(void *a, int b, int c)
{
    u8 k;
    u8 *p;

    if (c != func_021D775C(4))
        return;
    if (func_021D775C(0x1d) != 7)
        return;
    k = (u8)func_021D775C(3);
    if (k == 0x1f)
        return;
    p = func_021C88A4((char *)b, 0xc, c);
    ((struct Obj10069 *)p)->fF = k;
    ((struct Obj10069 *)p)->f4 = 7;
    *(Word *)(p + 8) = func_021E899C(c);
    ((struct Obj10069 *)p)->fD = 1;
    func_021C8838(p + 0x14, 2, 0x14a);
    func_021C8860((struct S *)(p + 0x14), k);
    func_021C8860((struct S *)(p + 0x14), func_021D70A8(a));
    func_021C88C8((void *)b, p);
}


void *func_021DF144(int *p)
{
    *p = 2;
    return d_021F16FC;
}


void func_021DF150(int a, void *b, int c)
{
    u8 t;
    u8 *r;

    if (c == func_021D775C(4) && func_021D775C(0x46) == 0) {
        if (func_0201BEB8(func_021D775C(0x12), 0) != 0) {
            t = func_021D775C(3);
            if (func_021D5B40(func_021C7CF4(b, t)) == 0) {
                r = (u8 *)func_021C88A4(b, 0x24, c);
                r[4] = t;
                func_021C88C8(b, r);
            }
        }
    }
}

void func_021DF1B0(int a, void *b, int c)
{
    void *m;
    u8 *r;
    if (c == func_021D775C(2)) {
        m = func_021C7CF4(b, c);
        r = (u8 *)func_021C88A4(b, 7, c);
        r[6] = c;
        ((struct Obj05218 *)r)->f4 = func_021D7B74(m, func_021DCFF8(a, 2));
        r[7] |= 2;
        ((struct Obj05218 *)r)->f8 = 0x25f;
        r[10] = func_021C8010(b, c);
        r[11] = 6;
        func_021C8838(r + 12, 2, 0x40e);
        func_021C8860((struct S *)(r + 12), c);
        func_021C8860((struct S *)(r + 12), func_021D70A8((void *)a));
        func_021C88C8(b, r);
    }
}

void *func_021DF240(int *p) { *p = 1; return d_021F138C; }

void *func_021DF24C(int *p) { *p = 1; return d_021F1434; }

void *func_021DF258(int *p) { *p = 1; return d_021F15A4; }

void *func_021DF264(int *p) { *p = 1; return d_021F1554; }

void *func_021DF270(int *p) { *p = 1; return d_021F15B4; }

void *func_021DF27C(int *p) { *p = 1; return d_021F15C4; }


void func_021DF288(void *a, void *b, int c)
{
    if (c == func_021D775C(2))
        func_021D7704(0x35, 2 << 10);
}
