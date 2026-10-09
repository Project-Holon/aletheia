/*
 * file:     unit_021D9118.c
 * unit:     yes
 * function: func_021D9118, func_021D9148, func_021D9154, func_021D9190, func_021D919C, func_021D91D8, func_021D91E4, func_021D91FC, func_021D9208, func_021D9214, func_021D9224, func_021D9234, func_021D9240, func_021D9250, func_021D9260, func_021D926C, func_021D927C, func_021D928C, func_021D92CC, func_021D9340, func_021D936C, func_021D93A8
 * address:  0x021D9118
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
 *   func_021D7704 0x021D7704 thumb ov093
 *   sub_0201BEB8 0x0201BEB8 thumb
 *   d_021F0758 0x021F0758 data a4
 *   func_0201BD28  0x0201BD28  thumb
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   d_021F06A8     0x021F06A8  data   ov093  a4
 *   func_021D76BC   0x021D76BC  thumb
 *   d_021F0720     0x021F0720  data   ov093  a4
 *   d_021F0618     0x021F0618  data   ov093  a4
 *   d_021F0880     0x021F0880  data   ov093  a4
 *   d_021F0890     0x021F0890  data   ov093  a4
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F06B8 0x021F06B8 data a4
 *   func_021C8288 0x021C8288 thumb ov093
 *   func_021D7D6C 0x021D7D6C thumb ov093
 *   d_021F0A40 0x021F0A40 data a4
 *   d_021F08A0     0x021F08A0  data   ov093  a4
 */
#include "../../matched/include/Obj21283.h"

struct Unk021D62A8;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int);
extern void func_021D7704(int, int);
extern unsigned int sub_0201BEB8(unsigned short, unsigned int);
extern u32 func_0201BD28(u16 id, u32 field);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern int func_021D76BC(int key, u32 val);
extern void func_021C88B4(void *a, int k, int b);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);
extern int func_021C8288(u8 *p);
extern int func_021D7D6C(int);
void func_021D9118(int a, int b, int c);
void *func_021D9148(int *p);
void func_021D9154(int u, int a, int b);
int *func_021D9190(int *p);
void func_021D919C(int a, void *b, int c);
int *func_021D91D8(int *p);
void func_021D91E4(int a, int b, int c);
int *func_021D91FC(int *p);
int *func_021D9208(int *p);
void func_021D9214(int a, int b, int c, int d);
void func_021D9224(int a, void *b, int c, int *d);
int *func_021D9234(int *p);
void func_021D9240(int a, int b, int c, int d);
void func_021D9250(int a, void *b, int c, int *d);
int *func_021D9260(int *p);
void func_021D926C(int a, int b, int c, int d);
void func_021D927C(int a, void *b, int c, int *d);
void func_021D928C(int a, int b, int c, int d);
void func_021D92CC(void *a, int b, int *c, int d);
void func_021D9340(int a, int b, int c);
void *func_021D9360(int *p);
void func_021D936C(int a, void *b, int c, int *d);
void func_021D93A8(int a, void *b, int c);
void *func_021D93CC(int *p);
extern unsigned int d_021F0758;
extern int d_021F06A8[];
extern int d_021F0720[];
/* 021D9214  shifted 4-arg wrapper -> func_021D928C(..., 0x1) */
extern int d_021F0618[];
extern int d_021F0880[];
/* 021D9240  shifted 4-arg wrapper -> func_021D928C(..., 0x6) */
extern int d_021F0890[];
extern unsigned int d_021F06B8;
extern unsigned int d_021F0A40;
/* 021D926C  shifted 4-arg wrapper -> func_021D928C(..., 0x8) */
extern int d_021F08A0[];





void func_021D9118(int a, int b, int c)
{
    if (c == func_021D775C(3) && sub_0201BEB8(func_021D775C(0x12), 7)) func_021D7704(0x31, 0x1333);
}





void *func_021D9148(int *p) { *p = 1; return &d_021F0758; }






void func_021D9154(int u, int a, int b)
{
    u16 t;

    if (b == func_021D775C(3)) {
        t = func_021D775C(0x12);
        if (func_0201BD28(t, 0x1e) != 0 || t == 0x1a || t == 0x88)
            func_021D7704(0x31, 0x1333);
    }
}





int *func_021D9190(int *p)
{
    *p = 1;
    return d_021F0720;
}





void func_021D919C(int a, void *b, int c)
{
    if (c == func_021D775C(4)) {
        if (func_021D62A8(func_021C7CF4(b, c))) {
            func_021D775C(0x12);
            if (func_021D775C(0x1a) == 1)
                func_021D7704(0x35, 0x1800);
        }
    }
}






int *func_021D91D8(int *p)
{
    *p = 1;
    return d_021F06A8;
}






/* 021D91E4  shape F1: gate on func_021D775C(3) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #3; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021D91FA; movs r0, #0x51; movs r1, #1; bl func_021D76BC; pop {r4, pc}.
 */
void func_021D91E4(int a, int b, int c)
{
    if (c == func_021D775C(3))
        func_021D76BC(0x51, 1);
}




int *func_021D91FC(int *p)
{
    *p = 1;
    return d_021F0618;
}




int *func_021D9208(int *p)
{
    *p = 2;
    return d_021F0880;
}




/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; adds r0, r1, #0; adds r1, r2, #0; adds r2, r3, #0; movs r3, #1; bl func_021D928C; pop {r3, pc}.
 */
void func_021D9214(int a, int b, int c, int d)
{
    func_021D928C(b, c, d, 0x1);
}





/* 021D9224  shifted 4-arg wrapper -> func_021D92CC(..., 0xc9) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; adds r0, r1, #0; adds r1, r2, #0; adds r2, r3, #0; movs r3, #0xc9; bl func_021D92CC; pop {r3, pc}.
 */
void func_021D9224(int a, void *b, int c, int *d)
{
    func_021D92CC(b, c, d, 0xc9);
}



int *func_021D9234(int *p)
{
    *p = 2;
    return d_021F0890;
}



/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; adds r0, r1, #0; adds r1, r2, #0; adds r2, r3, #0; movs r3, #6; bl func_021D928C; pop {r3, pc}.
 */
void func_021D9240(int a, int b, int c, int d)
{
    func_021D928C(b, c, d, 0x6);
}




/* 021D9250  shifted 4-arg wrapper -> func_021D92CC(..., 0xcf) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; adds r0, r1, #0; adds r1, r2, #0; adds r2, r3, #0; movs r3, #0xcf; bl func_021D92CC; pop {r3, pc}.
 */
void func_021D9250(int a, void *b, int c, int *d)
{
    func_021D92CC(b, c, d, 0xcf);
}


int *func_021D9260(int *p)
{
    *p = 2;
    return d_021F08A0;
}


/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; adds r0, r1, #0; adds r1, r2, #0; adds r2, r3, #0; movs r3, #8; bl func_021D928C; pop {r3, pc}.
 */
void func_021D926C(int a, int b, int c, int d)
{
    func_021D928C(b, c, d, 0x8);
}





/* 021D927C  shifted 4-arg wrapper -> func_021D92CC(..., 0xc6) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; adds r0, r1, #0; adds r1, r2, #0; adds r2, r3, #0; movs r3, #0xc6; bl func_021D92CC; pop {r3, pc}.
 */
void func_021D927C(int a, void *b, int c, int *d)
{
    func_021D92CC(b, c, d, 0xc6);
}





void func_021D928C(int a, int b, int c, int d)
{
    if (b == func_021D775C(2) && b != func_021D775C(3)) {
        if (d == 8 || d == func_021D775C(0x1f)) {
            if (func_021D775C(0x20) < 0)
                ((struct Obj21283 *)c)->f0 = func_021D76BC(0x41, 1);
        }
    }
}




void func_021D92CC(void *a, int b, int *c, int d)
{
    int t;
    u8 *p;

    if (b == func_021D775C(2) && c[0] != 0) {
        t = func_021D775C(0x19);
        if (t == 0 || c[1] != t) {
            func_021C88B4(a, 2, b);
            p = func_021C88A4(a, 4, b);
            func_021C8838(p + 4, 2, d);
            func_021C8860((struct S *)(p + 4), b);
            func_021C88C8(a, p);
            func_021C88B4(a, 3, b);
            c[1] = t;
        }
        c[0] = 0;
    }
}



void func_021D9340(int a, int b, int c)
{
    if (c == func_021D775C(2)) func_021D76BC(0x20, func_021D775C(0x20) << 1);
}



void *func_021D9360(int *p) { *p = 1; return &d_021F06B8; }



void func_021D936C(int a, void *b, int c, int *d)
{
    int v;
    if (c == func_021D775C(4) && func_021C8288(b) == 1) {
        v = func_021D775C(0x1d);
        if (func_021D7D6C(v) || v == 0xe) *d = func_021D76BC(0x41, 1);
    }
}



void func_021D93A8(int a, void *b, int c)
{
    if (c == func_021D775C(2) && func_021C8288(b) == 1) func_021D76BC(0x41, 1);
}



void *func_021D93CC(int *p) { *p = 3; return &d_021F0A40; }
