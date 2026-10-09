/*
 * file:     unit_021DC13C.c
 * unit:     yes
 * function: func_021DC13C, func_021DC170, func_021DC20C, func_021DC218, func_021DC250, func_021DC25C, func_021DC294, func_021DC2A0, func_021DC320
 * address:  0x021DC13C
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
 *   d_021F0780 0x021F0780 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021B9A24 0x021B9A24 thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C7F68  0x021C7F68  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021D85C0  0x021D85C0  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   d_021F0778     0x021F0778  data   ov093  a4
 *   d_021F0768     0x021F0768  data   ov093  a4
 *   func_0201C314  0x0201C314  thumb
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   d_021F0620     0x021F0620  data   ov093  a4
 *   d_021F05E8     0x021F05E8  data   ov093  a4
 */
#include "../../matched/include/Obj06259.h"
#include "../../matched/include/Obj21343.h"

struct Unk021D62A8;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int);
extern int func_021B9A24(unsigned int,unsigned int);
extern void func_021D7704(int,int);
extern int func_021C8010(u8 *p, unsigned int v);
extern u8 func_021C7F68(int *p, int b, u8 *out);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern int func_021D85C0(int a, u32 b);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *, void *);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern u32 func_0201C314(u16 id);
extern int func_021D76BC(int key, u32 val);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
void func_021DC13C(int a,int b,unsigned int c);
int *func_021DC164(int *p);
void func_021DC170(int a, void *b, int c);
int *func_021DC20C(int *p);
void func_021DC218(int u, int a, int b);
int *func_021DC250(int *p);
void func_021DC25C(int u, int a, int b);
int *func_021DC294(int *p);
void func_021DC2A0(int u, void *a, u32 b);
int *func_021DC320(int *p);
extern int d_021F0780;
extern int d_021F0778[];
extern int d_021F0768[];
extern int d_021F0620[];
extern int d_021F05E8[];




void func_021DC13C(int a,int b,unsigned int c) { unsigned char k; k=func_021D775C(4); if(k!=c && func_021B9A24(c,k)) func_021D7704(0x35,3<<10); }




int *func_021DC164(int *p) { *p=1; return &d_021F0780; }




void func_021DC170(int a, void *b, int c)
{
    u8 buf[4];
    u8 n;
    u8 i;
    u8 *p;
    int two = 2;

    if (c == func_021D775C(2)) {
        n = func_021C7F68(b, (u16)((two << 9) | func_021C8010(b, c)), buf);
        for (i = 0; i < n; i++) {
            if (buf[i] != c) {
                if (func_021D62A8(func_021C7CF4(b, buf[i])) && func_021D85C0((int)b, 0x1e)) {
                    p = func_021C88A4(b, 0xb, c);
                    ((struct Obj06259 *)p)->f0 |= 2 << 22;
                    ((struct Obj06259 *)p)->f0 |= 2 << 24;
                    p[0x14] = 1;
                    p[8] = buf[i];
                    ((struct Obj06259 *)p)->f4 = 0x24;
                    func_021C88C8(b, p);
                }
            }
        }
    }
}




int *func_021DC20C(int *p)
{
    *p = 1;
    return d_021F0778;
}




void func_021DC218(int u, int a, int b)
{
    if (b == func_021D775C(3) && func_021D62C4(func_021C7CF4((int *)a, b), 5) != 0
        && func_021D775C(0x1a) == 1) {
        func_021D7704(0x31, 3 << 11);
    }
}



int *func_021DC250(int *p)
{
    *p = 1;
    return d_021F0768;
}



void func_021DC25C(int u, int a, int b)
{
    if (b == func_021D775C(3) && func_021D62C4(func_021C7CF4((int *)a, b), 4) != 0
        && func_021D775C(0x1a) == 2) {
        func_021D7704(0x31, 3 << 11);
    }
}


int *func_021DC294(int *p)
{
    *p = 1;
    return d_021F0620;
}


void func_021DC2A0(int u, void *a, u32 b)
{
    u8 *e;
    u8 c;
    if (b == func_021D775C(4)) {
        c = func_021D775C(3);
        if (func_021B9A24(b, c) != 0
            && b != c
            && func_0201C314(func_021D775C(0x12)) != 0
            && func_021D76BC(0x40, 1) != 0) {
            e = func_021C88A4(a, 4, b);
            ((struct Obj21343 *)e)->f0 |= 1 << 23;
            func_021C8838(e + 4, 2, 0x1d5);
            func_021C8860((struct S *)(e + 4), b);
            func_021C88C8(a, e);
        }
    }
}


int *func_021DC320(int *p)
{
    *p = 1;
    return d_021F05E8;
}
