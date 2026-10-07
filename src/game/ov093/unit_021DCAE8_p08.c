/*
 * file:     unit_021DCAE8_p08.c
 * unit:     yes
 * function: func_021DD338, func_021DD368, func_021DD39C, func_021DD480, func_021DD4B0, func_021DD4E0, func_021DD514
 * address:  0x021DD338
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
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D67B8 0x021D67B8 thumb ov093
 *   func_021D5778 0x021D5778 thumb ov093
 *   func_021D5584 0x021D5584 thumb ov093
 *   func_021D5448 0x021D5448 thumb ov093
 *   func_021D554C 0x021D554C thumb ov093
 *   func_021D54C0 0x021D54C0 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021D70A8 0x021D70A8 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   d_021F1BB4 0x021F1BB4 data a4
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021DDE30 0x021DDE30 thumb ov093
 *   func_021DDEA4 0x021DDEA4 thumb ov093
 *   func_021DD044 0x021DD044 thumb ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021DCFF8  0x021DCFF8  thumb  ov093
 */
#include "../../matched/include/Obj13484.h"

struct UtilWork;
struct QG;
struct QQ;
struct S;
struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D67B8(u8 *p);
extern u8 func_021D5778(struct UtilWork *p, u16 id);
extern u8 func_021D5584(struct UtilWork *p, u32 i);
extern u8 func_021D5448(struct QG *p);
extern u8 func_021D554C(u8 *p, u8 i);
extern u16 func_021D54C0(u8 *p, int i);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern u16 func_021D70A8(struct QQ *p);
extern void func_021C88C8(void *a, void *b);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern void func_021DDE30(int a, int b, int c, int d, int e);
extern int func_021DDEA4(void *, int, u32);
extern void func_021DD044(void *, void *, int);
extern int func_021D775C(int key);
extern int func_021DCFF8(int a, int b);
u8 func_021DD338(void *a, int b);
u8 func_021DD368(void *a, int b);
int func_021DD39C(int a, void *b, u8 c, int d, int e);
void *func_021DD474(int *p);
void func_021DD480(int a, void *b, int c);
void func_021DD4B0(int a, void *b, int c);
void func_021DD4E0(int a, void *b, int c);
void func_021DD514(int a, u8 *b, int c);
extern u8 d_021F1BB4[];

/*
 * extent: trailing two-byte alignment padding.
 * prototype: C7CF4 result used and r1 supplied; 5584 index is the u8 return of 5778.
 */
u8 func_021DD338(void *a, int b)
{
    void *m;
    u8 slot;
    m = func_021C7CF4(a, b);
    slot = func_021D5778(m, func_021D67B8(m));
    if (slot != 4 && func_021D5584(m, slot) == 0) return slot;
    return 4;
}

u8 func_021DD368(void *a, int b)
{
    void *m;
    u32 n, i;
    m = func_021C7CF4(a, b);
    n = func_021D5448(m);
    for (i = 0; i < n; i++) {
        if (func_021D5584(m, (u8)i) == 0) return (u8)i;
    }
    return 4;
}

int func_021DD39C(int a, void *b, u8 c, int d, int e)
{
    void *m;
    u32 i;
    u32 n;
    u8 slot;
    u8 *r;
    m = func_021C7CF4(b, c);
    slot = func_021DD338(b, c);
    if (slot == 4) {
        slot = func_021DD368(b, c);
        if (slot == 4 && e) {
            n = func_021D5448(m);
            for (i = 0; i < n; i++) {
                if (func_021D554C(m, i)) {
                    slot = i;
                    break;
                }
            }
        }
    }
    if (slot != 4) {
        r = (u8 *)func_021C88A4(b, 9, c);
        r[4] = 10;
        r[5] = c;
        r[6] = slot;
        r[7] = (r[7] & ~1) | 1;
        func_021C8838(r + 8, 2, 0x38f);
        func_021C8860((struct S *)(r + 8), c);
        func_021C8860((struct S *)(r + 8), func_021D70A8((void *)a));
        func_021C8860((struct S *)(r + 8), func_021D54C0(m, slot));
        func_021C88C8(b, r);
        return 1;
    }
    return 0;
}

void *func_021DD474(int *p) { *p = 5; return d_021F1BB4; }

void func_021DD480(int a, void *b, int c)
{
    if (func_021D62C4(func_021C7CF4(b, c), 15) == 0)
        func_021DDE30(a, (int)b, c, 2, 1);
}

void func_021DD4B0(int a, void *b, int c)
{
    if (func_021D62C4(func_021C7CF4(b, c), 15) == 0)
        func_021DDE30(a, (int)b, c, 2, 0);
}

void func_021DD4E0(int a, void *b, int c)
{
    if (func_021D62C4(func_021C7CF4(b, c), 15) == 0 && func_021DDEA4(b, c, 2) != 0)
        func_021DD044((void *)a, b, c);
}


void func_021DD514(int a, u8 *b, int c)
{
    u8 *p;
    if (c == func_021D775C(2)) {
        p = func_021C88A4((char *)b, 5, c);
        p[6] = c;
        ((struct Obj13484 *)p)->f4 = func_021DCFF8(a, 2);
        func_021C8838(p + 8, 2, 908);
        func_021C8860((struct S *)(p + 8), c);
        func_021C8860((struct S *)(p + 8), func_021D70A8((void *)a));
        func_021C88C8(b, p);
    }
}
