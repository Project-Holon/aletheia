/*
 * file:     unit_021DBAF0_p02.c
 * unit:     yes
 * function: func_021DBBD8, func_021DBCEC, func_021DBD9C
 * address:  0x021DBBD8
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
 *   func_021D5B40 0x021D5B40 thumb ov093
 *   func_021C7D00 0x021C7D00 thumb ov093
 *   func_021C8120 0x021C8120 thumb ov093
 *   func_021C7F68 0x021C7F68 thumb ov093
 *   func_021D5BB0 0x021D5BB0 thumb ov093
 *   func_021D6740 0x021D6740 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   d_021F06C0 0x021F06C0 data a4
 *   func_021E85F8  0x021E85F8  thumb  ov093
 *   func_021E86E8  0x021E86E8  thumb  ov093
 *   func_0201BEB8  0x0201BEB8  thumb
 *   func_021C83D4  0x021C83D4  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021DBE50  0x021DBE50  thumb  ov093
 *   func_021D85C0  0x021D85C0  thumb  ov093
 *   func_021E896C  0x021E896C  thumb  ov093
 */
#include "../../matched/include/Obj06258.h"
#include "../../matched/include/Obj13481.h"
#include "../../matched/include/Obj10064.h"

struct QI;
struct QK;
struct UtilWork;
struct S;
struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef enum { N_4 = 4, N_5 = 5 } N;

typedef struct Word { u32 v; } Word;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D5B40(struct QI *p);
extern int func_021C7D00(u8 *p, int b);
extern u8 *func_021C8120(u8 *p, int b);
extern u8 func_021C7F68(int *p, int b, u8 *out);
extern int func_021D5BB0(struct UtilWork *p, u32 n);
extern u16 func_021D6740(struct QK *p);
extern u8 func_021D5440(u8 *p);
extern u32 func_021D78AC(u32 k);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);
extern int func_021E85F8(int id);
extern int func_021E86E8(void *a, int b, int c);
extern u32 func_0201BEB8(u16 id, u32 bit);
extern int func_021C83D4(u8 *p);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_021DBE50(u32 k);
extern int func_021D85C0(int a, u32 b);
extern Word func_021E896C(int a, int b);
void func_021DBBD8(int a, void *b, u8 c);
void *func_021DBCE0(int *p);
void func_021DBCEC(int u, void *a, int b);
void func_021DBD9C(int u, void *a, int b);
extern u8 d_021F06C0[];

void func_021DBBD8(int a, void *b, u8 c)
{
    u8 *buf;
    void *m;
    u32 flag;
    u8 i;
    u8 n;
    u8 selected;
    u16 value;
    u8 *r;
    if (c == func_021D775C(2) && !func_021D5B40(func_021C7CF4(b, c))) {
        flag = func_021C7D00(b, c);
        buf = func_021C8120(b, 14);
        buf[12] = (u8)func_021C7F68(b, (u16)(flag | 0x200), buf);
        n = 0;
        buf[13] = 0;
        for (i = 0; i < (u32)buf[12]; i++) {
            m = func_021C7CF4(b, buf[i]);
            if (func_021D5BB0(m, 8) && func_021D6740(m)) {
                buf[6 + n++] = func_021D5440(m);
            }
        }
        if (n) {
            selected = (buf + (u8)func_021D78AC(n))[6];
            value = func_021D6740(func_021C7CF4(b, selected));
            if (value) {
                r = (u8 *)func_021C88A4(b, 0x20, c);
                ((struct Obj06258 *)r)->f0 |= 0x800000;
                r[6] = c;
                ((struct Obj06258 *)r)->f4 = value;
                r[8] = 1;
                r[9] = selected;
                func_021C8838(r + 12, 2, 0x1ea);
                func_021C8860((struct S *)(r + 12), c);
                func_021C8860((struct S *)(r + 12), value);
                func_021C88C8(b, r);
            }
        }
    }
}

void *func_021DBCE0(int *p) { *p = 1; return d_021F06C0; }


void func_021DBCEC(int u, void *a, int b)
{
    u8 t;
    void *x;
    void *y;
    u8 *e;
    if (func_021E85F8(b) != 0) {
        t = func_021D775C(3);
        if (func_021E86E8(a, b, t) == 0
            && func_0201BEB8(func_021D775C(0x12), 0) != 0) {
            x = func_021C7CF4(a, b);
            y = func_021C7CF4(a, t);
            if (func_021D5B40(x) == 0 && func_021D5B40(y) != 0) {
                e = func_021C88A4(a, 0x24, b);
                ((struct Obj13481 *)e)->f0 |= 2 << 22;
                e[4] = t;
                func_021C8838(e + 8, 2, 0x1cc);
                func_021C8860((struct S *)(e + 8), t);
                func_021C8860((struct S *)(e + 8), func_021D5B40(y));
                func_021C88C8(a, e);
            }
        }
    }
}


/*
 * note:     func_021E896C returns a one-word struct (Word): its return temporary is
 *           the unreferenced third frame word and moves n/k to r6/r7
 *           (an-unused-frame-word-is-a-callee-returning-a-one-word-struct.md);
 *           the enum N keeps n + 1 out of constant folding.
 */
void func_021DBD9C(int u, void *a, int b)
{
    u8 t;
    u16 k;
    N n;
    void *m;
    u8 *e;
    n = N_4;
    if (b == func_021D775C(4)
        && func_021D775C(0x46) == 0
        && func_021C83D4(a) == 0) {
        t = func_021D775C(3);
        m = func_021C7CF4(a, t);
        if (func_021D62C4(m, 0xd) == 0) {
            k = func_021D775C(0x14);
            if (k != 0 && k != 0xa5 && func_021DBE50(k) == 0
                && func_021D85C0((int)a, 0x1e) != 0) {
                if (func_021D5BB0(m, 1) != 0) {
                    n = (N)(u8)(n + 1);
                }
                e = func_021C88A4(a, 0xc, b);
                ((struct Obj10064 *)e)->f4 = 0xd;
                *(Word *)(e + 8) = func_021E896C(n, k);
                e[0xf] = t;
                ((struct Obj10064 *)e)->f0 |= 2 << 22;
                func_021C88C8(a, e);
            }
        }
    }
}
