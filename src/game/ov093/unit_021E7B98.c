/*
 * file:     unit_021E7B98.c
 * unit:     yes
 * function: func_021E7B98, func_021E7C6C, func_021E7C78, func_021E7CA0, func_021E7CAC, func_021E7CF4
 * address:  0x021E7B98
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
 *   func_0202136C 0x0202136C thumb
 *   func_021E869C 0x021E869C thumb ov093
 *   func_021D5444 0x021D5444 thumb ov093
 *   func_021E8638 0x021E8638 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   d_021F2AE8 0x021F2AE8 data a4
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   d_021F27EC     0x021F27EC  data   ov093  a4
 *   d_021F25B4     0x021F25B4  data   ov093  a4
 */
#include "../../matched/include/Obj07837.h"

struct QI;
struct QF;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int);
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D5B40(struct QI *p);
extern u32 func_0202136C(u16);
extern int func_021E869C(void *a, int b);
extern u16 func_021D5444(struct QF *p);
extern int func_021E8638(int, int);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(struct S *, u32);
extern void func_021C88C8(void *a, void *b);
extern int func_021D59B4(u8 *p, int k);
extern int func_021D76BC(int key, u32 val);
void func_021E7B98(int a, int b, int c);
int *func_021E7C6C(int *p);
void func_021E7C78(int a, void *b, int c);
int *func_021E7CA0(int *p);
void func_021E7CAC(int a, u8 *b, int c);
int *func_021E7CF4(int *p);
extern int d_021F2AE8[];
extern int d_021F27EC[];
extern int d_021F25B4[];



void func_021E7B98(int a, int b, int c)
{
    u8 k;
    void *x;
    u16 h;
    u8 *p;
    if (c == func_021D775C(3)) {
        k = func_021D775C(6);
        x = func_021C7CF4((int *)b, k);
        h = (int)func_021D5B40(func_021C7CF4((int *)b, c));
        if (h != 0 && func_0202136C(h) == 0 && (int)func_021D5B40(x) == 0
            && func_021E869C((void *)b, c) == 0 && func_021E869C((void *)b, k) == 0
            && func_021E8638(func_021D5444(x), h) == 0) {
            p = func_021C88A4((char *)b, 0x20, c);
            p[6] = c;
            ((struct Obj07837 *)p)->f4 = 0;
            func_021C88C8((void *)b, p);
            p = func_021C88A4((char *)b, 0x20, c);
            p[6] = k;
            ((struct Obj07837 *)p)->f4 = h;
            func_021C8838(p + 12, 2, 0x457);
            func_021C8860((struct S *)(p + 12), k);
            func_021C8860((struct S *)(p + 12), c);
            func_021C8860((struct S *)(p + 12), h);
            func_021C88C8((void *)b, p);
        }
    }
}



int *func_021E7C6C(int *p)
{
    *p = 2;
    return d_021F2AE8;
}



void func_021E7C78(int a, void *b, int c)
{
    if (c == func_021D775C(3))
        func_021D76BC(0x37, func_021D59B4(func_021C7CF4(b, c), 0xd));
}


int *func_021E7CA0(int *p)
{
    *p = 1;
    return d_021F27EC;
}


void func_021E7CAC(int a, u8 *b, int c)
{
    u8 *p;
    if (c == func_021D775C(3)) {
        p = func_021C88A4((char *)b, 0x2f, c);
        p[4] = func_021D775C(6);
        func_021C8838(p + 8, 2, 1134);
        func_021C8860((struct S *)(p + 8), p[4]);
        func_021C88C8(b, p);
    }
}


int *func_021E7CF4(int *p)
{
    *p = 1;
    return d_021F25B4;
}
