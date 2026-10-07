/*
 * file:     unit_021EE740_p02.c
 * unit:     yes
 * function: func_021EE810, func_021EE888
 * address:  0x021EE810
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021EEA34  0x021EEA34  thumb  ov025
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A21F8  0x021A21F8  thumb  ov021
 *   func_021A22E0  0x021A22E0  thumb  ov021
 *   func_021A2254  0x021A2254  thumb  ov021
 *   func_021A2114  0x021A2114  thumb  ov021
 *   func_02014A10  0x02014A10  thumb
 *   func_021A2248 0x021A2248 thumb ov021
 *   func_021A244C 0x021A244C thumb ov021
 *   func_021A2564 0x021A2564 thumb ov021
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct { char pad[0x774]; int *list; } Obj;

extern int *func_021A21B8(int *p);
extern void func_021A21F8(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
extern void func_021A22E0(unsigned int *p, int a, int b, int c);
extern void func_021A2254(int, void *, int, int, int, int);
extern int func_021A2114(unsigned int a, int b, unsigned int c);
extern u16 func_02014A10(u32 i);
extern void func_021EEA34(int a, int n, int idx);
extern int func_021A2248(u8 *, int);
extern void func_021A244C(u8 *, int *, int *);
extern void func_021A2564(Obj *, int, int);
int func_021EE810(unsigned int *a, int b, int c);
int func_021EE888(u8 *p, int unused, int arg);


int func_021EE810(unsigned int *a, int b, int c)
{
    int *p = func_021A21B8((int *)a);

    func_021A21F8((u8 *)a, 1, 0x10, 1, 0x10, -3, 1, 0, (int)((void *)func_021EEA34));
    p[1] = 1;
    p[2] = 0;
    func_021A22E0(a, 8, 0x7F5F, b);
    func_021A2254((int)a, (void *)func_021EEA34, 0x14, 1, 0x12, c);
    func_021A2114((unsigned int)a, 0x3E, func_02014A10(1));
    return 1;
}

int func_021EE888(u8 *p, int unused, int arg)
{
    int x;
    int y;
    func_021A2248(p, arg);
    func_021A244C(p, &x, &y);
    func_021A2564((Obj *)p, x, y);
    return 0;
}
