/*
 * file:     unit_021E2188_p02.c
 * unit:     yes
 * function: func_021E237C, func_021E249C, func_021E24D4, func_021E2574
 * address:  0x021E237C
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
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021D70A8 0x021D70A8 thumb ov093
 *   func_021E896C 0x021E896C thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   func_021C7D00 0x021C7D00 thumb ov093
 *   func_021C8120 0x021C8120 thumb ov093
 *   func_021C7F68 0x021C7F68 thumb ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021E03D8  0x021E03D8  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
#include "../../matched/include/Obj05222.h"
#include "../../matched/include/Obj13508.h"
#include "../../matched/include/Obj10078.h"

struct QQ;
struct Unk021D62A8;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Word { u32 v; } Word;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern void *func_021C88A4(char *p, int a, int b);
extern u16 func_021D70A8(struct QQ *p);
extern Word func_021E896C(int, int);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(struct S *, u32);
extern void func_021C88C8(void *, void *);
extern int func_021C7D00(u8 *p, int b);
extern u8 *func_021C8120(u8 *p, int b);
extern u8 func_021C7F68(int *p, int b, u8 *out);
extern int func_021D5B68(void *m);
extern void func_021E03D8(u8 *a, int b);
extern int func_021D76BC(int key, unsigned v);
void func_021E237C(void *a, void *b, u8 c, u8 *d);
void func_021E249C(int u, int a, int b);
void func_021E24D4(void *a, void *b, int c, int *d);
void func_021E2574(int a, void *b, int c, int *d);

/*
 * lever: Word return from func_021E896C reserves the unused aggregate slot;
 * u8 c schedules its stack reload after the zero store at 021E23CE.
 */
void func_021E237C(void *a, void *b, u8 c, u8 *d)
{
    u8 *p;
    u8 *buf;
    u32 flags;
    unsigned i;
    u8 *entry;
    if (c != func_021D775C(3)) return;
    if (func_021D62C4(func_021C7CF4(b, c), 25) != 0) return;
    if (((struct Obj13508 *)d)->f18 != 0) return;
    p = func_021C88A4(b, 12, c);
    ((struct Obj05222 *)p)->f4 = 25;
    *(Word *)(p + 8) = func_021E896C(3, func_021D70A8(a));
    p[12] = 0;
    p[15] = c;
    func_021C88C8(b, p);
    p = func_021C88A4(b, 4, c);
    func_021C8838(p + 4, 2, 703);
    func_021C8860((struct S *)(p + 4), c);
    func_021C88C8(b, p);
    flags = func_021C7D00(b, c);
    buf = func_021C8120(b, 7);
    buf[0] = func_021C7F68(b, (u16)(flags | 0x800), buf + 1);
    for (i = 0; i < buf[0]; i++) {
        entry = buf + i;
        if (func_021D62C4(func_021C7CF4(b, entry[1]), 2) != 0) {
            p = func_021C88A4(b, 11, c);
            ((struct Obj05222 *)p)->f4 = 2;
            p[20] = 1;
            p[8] = entry[1];
            func_021C8838(p + 24, 2, 706);
            func_021C8860((struct S *)(p + 24), entry[1]);
            func_021C88C8(b, p);
        }
    }
    ((struct Obj13508 *)d)->f18 = 1;
}


void func_021E249C(int u, int a, int b)
{
    u8 *s;

    if (b == func_021D775C(2)) {
        if (func_021D775C(0x51) == 0) {
            s = func_021C88A4((char *)a, 0xb, b);
            ((struct Obj10078 *)s)->f4 = 0x19;
            s[0x14] = 1;
            s[8] = b;
            func_021C88C8((void *)a, s);
        }
    }
}


void func_021E24D4(void *a, void *b, int c, int *d)
{
    void *v;
    char *p;

    if (c == func_021D775C(2) && d[6] != 0) {
        v = func_021C7CF4(b, c);
        if (func_021D5B68(v) == 0) {
            if (func_021D62C4(v, 0x19) == 0) {
                p = func_021C88A4(b, 4, c);
                func_021C8838(p + 4, 2, 0x2CE);
                func_021C8860((struct S *)(p + 4), c);
                func_021C88C8(b, p);
                func_021E03D8(v, func_021D70A8(a));
            } else {
                p = func_021C88A4(b, 4, c);
                func_021C8838(p + 4, 2, 0x2CB);
                func_021C8860((struct S *)(p + 4), c);
                func_021C88C8(b, p);
            }
        }
    }
}


void func_021E2574(int a, void *b, int c, int *d)
{
    char *p;
    u8 u;

    if (d[6] != 0 && func_021D775C(0x1D) == 2 && func_021D76BC(0x41, 1) != 0) {
        p = func_021C88A4(b, 4, c);
        u = func_021D775C(4);
        func_021C8838(p + 4, 2, (u16)(u == c ? 0x2C8 : 0x2C5));
        func_021C8860((struct S *)(p + 4), u);
        func_021C88C8(b, p);
    }
}
