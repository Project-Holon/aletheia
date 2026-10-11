/*
 * file:     unit_021E072C.c
 * unit:     yes
 * function: func_021E072C, func_021E0818, func_021E0838, func_021E0850, func_021E0900, func_021E0914, func_021E0920, func_021E0944, func_021E098C, func_021E0998
 * address:  0x021E072C
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
 *   func_0689CA7C  0x0689CA7C  thumb
 *   data_021F2B70 0x021F2B70 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D6D7C 0x021D6D7C thumb ov093
 *   func_021B9A40 0x021B9A40 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   func_021D7320  0x021D7320  thumb  ov093
 *   func_021D7324   0x021D7324  thumb
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   d_021F2504     0x021F2504  data    a4
 *   func_021D6D54 0x021D6D54 thumb ov093
 *   func_021D67A8 0x021D67A8 thumb ov093
 *   func_021D67B8 0x021D67B8 thumb ov093
 *   func_021D5778 0x021D5778 thumb ov093
 *   func_021D70A8 0x021D70A8 thumb ov093
 *   d_021F280C     0x021F280C  data   ov093  a4
 */
#include "../../matched/include/Obj06266.h"
#include "../../matched/include/Obj13505.h"
#include "../../matched/include/Obj06267.h"

struct QS;
struct S;
struct QL;
struct QQ;
struct R5;
typedef unsigned char u8;

typedef signed char s8;

typedef unsigned int u32;

struct Record { u32 f0; volatile u8 f4; u8 f5; u8 f6; u8 f7; };

typedef unsigned short u16;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int);
extern void *func_021C7CF4(int *p, int i);
extern u32 func_021D6D7C(u8 *p);
extern unsigned char func_021B9A40(unsigned int x);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *, void *);
extern void func_021D7320(struct QS *p, u32 v);
extern int func_06898CF4(int a, int b);
extern int func_021D7B74(u8 *p, u32 k);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern int func_021D6D54(struct R5 *p);
extern u16 func_021D67A8(struct QL *p);
extern u16 func_021D67B8(u8 *p);
extern int func_0689CA7C(int);
extern u8 func_021D5778(void *, int);
extern u16 func_021D70A8(struct QQ *p);
void func_021E072C(int unused, void *q, int id);
u32 *func_021E080C(u32 *p);
void func_021E0818(char *a, int b, int c);
void func_021E0838(int a, int b, int c);
void func_021E0850(int a, void *b, int c);
int func_021E0900(int a, int b, int c, int d, unsigned short e);
int *func_021E0914(int *p);
void func_021E0920(int a, void *b, int c, int d);
void func_021E0944(int unused, void *q, int id, int unused2);
int *func_021E098C(int *p);
void func_021E0998(void *a, void *q, int id);
extern u32 data_021F2B70[];
extern int d_021F2504[];
extern int d_021F280C[];


void func_021E072C(int unused, void *q, int id)
{
    u8 target;
    u8 *r;
    struct Record *e;
    u32 i;
    if (id == func_021D775C(3)) {
        target = func_021D775C(6);
        if (func_021D6D7C(func_021C7CF4(q, target)) == 0) {
            r = func_021C88A4(q, 14, id);
            ((struct Obj06266 *)r)->f4 = 7;
            ((struct Obj06266 *)r)->fC = -1;
            r[14] = 1;
            r[15] = 1;
            r[16] = target;
            func_021C88C8(q, r);
        }
        e = (struct Record *)func_021C88A4(q, 26, id);
        e->f7 = func_021B9A40(target);
        e->f4 = 3;
        for (i = 1; i < 3; i++) ((u8 *)e)[4 + i] = 0;
        if (e->f4 > 1) e->f5 |= 1;
        if (e->f4 > 1) e->f5 |= 2;
        if (e->f4 > 1) e->f5 |= 8;
        if (e->f4 > 1) e->f5 |= 4;
        if (e->f4 > 1) e->f5 |= 64;
        if (e->f4 > 1) e->f5 |= 128;
        if (e->f4 > 2) e->f6 |= 1;
        func_021C88C8(q, e);
    }
}


/*
 * follower: 021E080C store-return stub included.
 * volatile: 021E079E,021E07AC,021E07BA,021E07C8,021E07D6,021E07E4,021E07F2 reread byte +4
 */
u32 *func_021E080C(u32 *p)
{
    *p = 3;
    return data_021F2B70;
}


void func_021E0818(char *a, int b, int c)
{
    if (c == func_021D775C(3))
        func_021D7320((struct QS *)a, (u32)func_021E0900);
}


/* 021E0838  shape F3: gate on func_021D775C(3) then func_021D7324 */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r3, r4, r5, lr}; adds r5, r0, #0; movs r0, #3; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021E084E; adds r0, r5, #0; bl func_021D7324; pop {r3, r4, r5, pc}.
 */
void func_021E0838(int a, int b, int c)
{
    if (c == func_021D775C(3))
        func_021D7324(a);
}


void func_021E0850(int a, void *b, int c)
{
    int t;
    u8 *p;
    u8 *q;
    unsigned i;

    if (c == func_021D775C(3)) {
        t = (int)func_021B9A40((u8)func_021D775C(4));
        if (func_06898CF4(t, 0) != 0 || func_06898CF4(t, 1) != 0) {
            p = func_021C88A4(b, 0x1a, c);
            p[7] = t;
            p[4] = 3;
            for (i = 1; i < 3; i++) {
                p[4 + i] = 0;
            }
            if (p[4] > 1) {
                p[5] |= 1;
            }
            if (p[4] > 1) {
                p[5] |= 2;
            }
            func_021C88C8(b, p);
            q = func_021C88A4(b, 0x3a, c);
            q[4] = 1;
            func_021C88C8(b, q);
        }
    }
}


/*
 * Callback passed to func_021D7320 by func_021E0818 (pool word 0x021E0901).
 * Not a worklist entry; filed as the witness for that relocation.
 */
int func_021E0900(int a, int b, int c, int d, unsigned short e)
{
    if (c == 2 && e <= 1)
        return 1;
    return 0;
}


int *func_021E0914(int *p)
{
    *p = 1;
    return d_021F2504;
}


/*
 * The call passes r3 (d) through to func_021E0944, whose own C takes three
 * parameters; the prototype here carries the fourth.
 */
void func_021E0920(int a, void *b, int c, int d)
{
    if (c == func_021D775C(2))
        func_021E0944(a, b, c, d);
}


void func_021E0944(int unused, void *q, int id, int unused2)
{
    u8 *r;
    int n;

    n = func_021D7B74(func_021C7CF4(q, id), 2);
    r = (u8 *)func_021C88A4(q, 7, id);
    r[6] = id;
    ((struct Obj13505 *)r)->f4 = n;
    func_021C8838(r + 0xc, 2, 0x386);
    func_021C8860((struct S *)(r + 0xc), id);
    func_021C88C8(q, r);
}


int *func_021E098C(int *p)
{
    *p = 1;
    return d_021F280C;
}


/*
 * lever: move stays int; the caller passes the full value to func_021D5778 without narrowing.
 */
void func_021E0998(void *a, void *q, int id)
{
    void *m;
    void *t;
    int move;
    int other;
    int slot;
    u8 *r;
    if (id == func_021D775C(3)) {
        m = func_021C7CF4(q, id);
        if (func_021D6D54(m) != 0) return;
        t = func_021C7CF4(q, (u8)func_021D775C(6));
        move = func_021D67A8(t);
        other = func_021D67B8(t);
        if (other != move) move = other;
        if (move == 0 || func_0689CA7C(move) != 0 || func_021D5778(m, move) != 4) return;
        slot = func_021D5778(m, func_021D70A8(a));
        if (slot == 4) return;
        r = func_021C88A4(q, 37, id);
        r[4] = id;
        r[5] = slot;
        ((struct Obj06267 *)r)->f8 = move;
        r[6] = 0;
        r[7] = 0;
        func_021C88C8(q, r);
        r = func_021C88A4(q, 4, id);
        func_021C8838(r + 4, 2, 0x2b0);
        func_021C8860((struct S *)(r + 4), id);
        func_021C8860((struct S *)(r + 4), move);
        func_021C88C8(q, r);
    }
}
