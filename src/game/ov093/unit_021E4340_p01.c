/*
 * file:     unit_021E4340_p01.c
 * unit:     yes
 * function: func_021E4340, func_021E4408, func_021E448C
 * address:  0x021E4340
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
 *   func_021D5D14 0x021D5D14 thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   d_021F2D20 0x021F2D20 data a4
 *   d_021F2888 0x021F2888 data a4
 *   func_021D76BC   0x021D76BC  thumb ov093
 *   func_021D62C4   0x021D62C4  thumb ov093
 *   func_021D5B48   0x021D5B48  thumb ov093
 *   func_021D59B4   0x021D59B4  thumb ov093
 *   func_021D7D78 0x021D7D78 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   d_021F278C 0x021F278C data a4
 */
#include "../../matched/include/Obj06271.h"
#include "../../matched/include/Obj02433.h"

struct Unk021D62A8;
struct S;
typedef unsigned char u8;

typedef unsigned int u32;

typedef signed char    s8;

typedef unsigned short u16;

typedef signed short s16;

typedef signed int s32;

typedef struct Word { u32 v; } Word;

extern int func_021D775C(int);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5D14(s8 *p, int i, int sign);
extern u32 func_021D78AC(u32);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *, void *);
int func_021D76BC(int key, u32 val);
int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_021D5B48(u8 *p);
extern int func_021D59B4(u8 *p, int k);
extern Word func_021D7D78(int);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(struct S *p, u32 val);
void func_021E4340(int unused, void *s, int k);
int *func_021E43FC(int *p);
void func_021E4408(void *a, int b, int c);
void func_021E448C(int unused, void *s, int k);
int *func_021E4558(int *p);
extern const u32 d_021F2D20[];
extern int d_021F2888[];
extern int d_021F278C[];


/*
 * Lever: chained n = i = 0 initializes the index first; a fresh byte
 * pick for the random selection keeps the second loop's count in r4.
 * Reusing n for that selection swaps the second loop's r4/r5 allocation.
 */
void func_021E4340(int unused, void *s, int k)
{
    u8 v;
    void *q;
    u8 n;
    u8 i;
    u8 *p;
    u8 pick;
    if (k == func_021D775C(3)) {
        v = func_021D775C(6);
        q = func_021C7CF4(s, v);
        n = i = 0;
        for (; i < 7; i++) {
            if (func_021D5D14(q, d_021F2D20[i], 2) != 0)
                n++;
        }
        if (n != 0) {
            pick = func_021D78AC(n);
            for (i = 0; i < 7; i++) {
                if (func_021D5D14(q, d_021F2D20[i], 2) != 0) {
                    if (pick == 0) {
                        p = func_021C88A4(s, 14, k);
                        p[16] = v;
                        p[15] = 1;
                        ((struct Obj06271 *)p)->f4 = d_021F2D20[i];
                        p[12] = 2;
                        p[14] = 0;
                        func_021C88C8(s, p);
                        return;
                    }
                    pick--;
                }
            }
        }
    }
}


int *func_021E43FC(int *p)
{
    *p = 2;
    return d_021F2888;
}

/*
 * Two-key gate on func_021D775C(2) / func_021D775C(0x22), then classify the
 * func_021C7CF4(b, c) record: the first matching predicate decides which
 * func_021D76BC(0x22, code) event fires, and only the fall-through case
 * looks at the 16-bit func_021D59B4(u, 0x11) result.
 */
void func_021E4408(void *a, int b, int c)
{
    u16 v;
    void *u;

    if (c != func_021D775C(2))
        return;
    if (func_021D775C(0x22) != 0)
        return;
    u = func_021C7CF4((int *)b, c);
    if (func_021D62C4(u, 2) != 0) {
        func_021D76BC(0x22, 0x1a);
        return;
    }
    if (func_021D62C4(u, 0xf) != 0) {
        func_021D76BC(0x22, 0xd);
        return;
    }
    if (func_021D5B48(u) != 0) {
        func_021D76BC(0x22, 0xe);
        return;
    }
    v = func_021D59B4(u, 0x11);
    if (v == 0xf || v == 0x48)
        func_021D76BC(0x22, 0xf);
}


void func_021E448C(int unused, void *s, int k)
{
    void *q;
    u8 *p;
    u32 n;
    if (k == func_021D775C(3)) {
        q = func_021C7CF4(s, k);
        if (func_021D5B48(q) == 0) {
            p = func_021C88A4(s, 12, k);
            p[15] = k;
            ((struct Obj02433 *)p)->f4 = 2;
            *(Word *)(p + 8) = func_021D7D78(3);
            p[12] = 1;
            p[16] = 1;
            p[14] = 1;
            func_021C8838(p + 20, 2, 638);
            func_021C8860((struct S *)(p + 20), k);
            func_021C88C8(s, p);
            p = func_021C88A4(s, 5, k);
            p[6] = k;
            n = func_021D59B4(q, 14);
            *(u16 *)&((struct Obj02433 *)p)->f4 = n - func_021D59B4(q, 13);
            ((struct Obj02433 *)p)->f0 |= 0x1000000;
            func_021C88C8(s, p);
            p = func_021C88A4(s, 33, k);
            p[4] = k;
            ((struct Obj02433 *)p)->f8 = 3;
            ((struct Obj02433 *)p)->f0 |= 0x1000000;
            func_021C88C8(s, p);
            func_021D76BC(81, 0);
        }
    }
}


int *func_021E4558(int *p)
{
    *p = 1;
    return d_021F278C;
}
