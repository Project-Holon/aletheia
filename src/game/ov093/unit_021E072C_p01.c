/*
 * file:     unit_021E072C_p01.c
 * unit:     yes
 * function: func_021E072C, func_021E0818, func_021E0838, func_021E0850
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
 *   data_021F2B70 0x021F2B70 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D6D7C 0x021D6D7C thumb ov093
 *   func_021B9A40 0x021B9A40 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   func_021D7320  0x021D7320  thumb  ov093
 *   func_021E0900  0x021E0900  thumb  ov093
 *   func_021D7324   0x021D7324  thumb
 *   func_021E08E0  0x021E08E0  thumb  ov093
 *   func_021E08F0  0x021E08F0  thumb  ov093
 */
#include "../../matched/include/Obj06266.h"

struct QS;
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
extern int func_021E0900(int, int, int, int, unsigned short);
extern int func_021E08E0(int a, int b);
extern int func_021E08F0(int a, int b);
void func_021E072C(int unused, void *q, int id);
u32 *func_021E080C(u32 *p);
void func_021E0818(char *a, int b, int c);
/* 021E0838 shape F3: gate on func_021D775C(3) then func_021D7324 */ void func_021E0838(int a, int b, int c);
void func_021E0850(int a, void *b, int c);
extern u32 data_021F2B70[];

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
        if (func_021E08E0(t, 0) != 0 || func_021E08F0(t, 1) != 0) {
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
