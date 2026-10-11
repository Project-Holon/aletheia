/*
 * file:     unit_021DC57C.c
 * unit:     yes
 * function: func_021DC57C, func_021DC5EC, func_021DC5F8, func_021DC604, func_021DC614, func_021DC624, func_021DC630, func_021DC664, func_021DC6A0
 * address:  0x021DC57C
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
 *   func_0689C8CC  0x0689C8CC  thumb
 *   func_021D775C   0x021D775C  thumb ov093
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   func_021D5B68   0x021D5B68  thumb ov093
 *   func_021D5B48   0x021D5B48  thumb ov093
 *   func_021D7B74   0x021D7B74  thumb ov093
 *   func_021D59B4   0x021D59B4  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *   func_021D928C   0x021D928C  thumb
 *   func_021D92CC   0x021D92CC  thumb
 *   d_021F0700     0x021F0700  data   ov093  a4
 *   d_021F0940     0x021F0940  data   ov093  a4
 *   d_021F06D0 0x021F06D0 data a4
 *   func_021C8288 0x021C8288 thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   d_021F0628 0x021F0628 data a4
 *   func_021D76BC 0x021D76BC thumb ov093
 *   func_021E8624 0x021E8624 thumb ov093
 *   d_021F0950     0x021F0950  data   ov093  a4
 */
#include "../../matched/include/Obj07235.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

int func_021D775C(int a);
void *func_021C7CF4(int *p, int i);
int func_021D5B68(void *p);
extern int func_021D5B48(u8 *p);
extern int func_021D7B74(u8 *p, u32 k);
extern int func_021D59B4(u8 *p, int k);
void *func_021C88A4(char *p, int a, int b);
void func_021C88C8(void *a, void *b);
extern int func_021C8288(u8 *p);
extern void func_021D7704(int,int);
extern int func_021D76BC(int,unsigned int);
extern int func_0689C8CC(u16);
extern int func_021E8624(int a, int b);
void func_021DC57C(void *a, int b, int c);
int *func_021DC5EC(int *p);
int *func_021DC5F8(int *p);
void func_021DC604(int a, int b, int c, int d);
void func_021DC614(int a, int b, int c, int d);
int *func_021DC624(int *p);
void func_021DC630(int a, void *b, int c);
void *func_021DC658(int *p);
void func_021DC664(int a, int b, int c);
void *func_021DC694(int *p);
void func_021DC6A0(int a, void *b, int c);
/* 021DC604  shifted 4-arg wrapper -> func_021D928C(..., 0x2) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; adds r0, r1, #0; adds r1, r2, #0; adds r2, r3, #0; movs r3, #2; bl func_021D928C; pop {r3, pc}.
 */
extern int d_021F0700[];
extern int d_021F0940[];
extern unsigned char d_021F06D0[];
extern unsigned char d_021F0628[];
extern int d_021F0950[];


/*
 * Shape F1 gate on func_021D775C(2); reject the record if either predicate
 * holds; clamp func_021D7B74(r,3) down to the 0xe-minus-0xd gap reported by
 * func_021D59B4; then build and publish the record.  Two live calls with no
 * free saved register is what puts the first result on the stack.
 */
void func_021DC57C(void *a, int b, int c)
{
    void *r;
    u32 n, m;
    u8 *p;

    if (c != func_021D775C(2))
        return;
    r = func_021C7CF4((int *)b, c);
    if (func_021D5B68(r) != 0)
        return;
    if (func_021D5B48(r) != 0)
        return;
    n = func_021D7B74(r, 3);
    m = func_021D59B4(r, 0xe) - func_021D59B4(r, 0xd);
    if (n > m)
        n = m;
    p = func_021C88A4((char *)b, 8, c);
    ((struct Obj07235 *)p)->f7 = c;
    ((struct Obj07235 *)p)->f10 = n;
    ((struct Obj07235 *)p)->f4 = 1;
    ((struct Obj07235 *)p)->f5 = 1;
    func_021C88C8((void *)b, p);
}


int *func_021DC5EC(int *p)
{
    *p = 1;
    return d_021F0700;
}


int *func_021DC5F8(int *p)
{
    *p = 2;
    return d_021F0940;
}


void func_021DC604(int a, int b, int c, int d)
{
    func_021D928C(b, c, d, 0x2);
}


/* 021DC614  shifted 4-arg wrapper -> func_021D92CC(..., 0xcc) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; adds r0, r1, #0; adds r1, r2, #0; adds r2, r3, #0; movs r3, #0xcc; bl func_021D92CC; pop {r3, pc}.
 */
void func_021DC614(int a, int b, int c, int d)
{
    func_021D92CC(b, c, d, 0xcc);
}


int *func_021DC624(int *p)
{
    *p = 2;
    return d_021F0950;
}


void func_021DC630(int a, void *b, int c) { if (c == func_021D775C(2) && func_021C8288(b) == 4) func_021D7704(53,8192); }


void *func_021DC658(int *p) { *p = 1; return d_021F06D0; }


void func_021DC664(int a, int b, int c) { if (c == func_021D775C(4) && func_021D775C(26) == 0 && (unsigned int)func_021D775C(43) > 50) func_021D76BC(43,50); }


void *func_021DC694(int *p) { *p = 1; return d_021F0628; }


void func_021DC6A0(int a, void *b, int c) { if (c == func_021D775C(3) && func_0689C8CC(func_021D775C(18)) == 0 && func_021E8624((int)b,c) != 0) func_021D7704(49,0x14cd); }
