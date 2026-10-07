/*
 * file:     weather_task_p40.c
 * unit:     yes
 * function: func_021A3B78, func_021A3B94, func_021A3BB4, func_021A3C24, func_021A3C3C, func_021A3C54, func_021A3C6C
 * address:  0x021A3B78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_0216D608  0x0216D608  thumb  ov010
 *   data_021D89C4  0x021D89C4  data  a4
 */
#include "../../matched/include/Obj12730.h"
#include "../../matched/include/Obj12731.h"

typedef unsigned char u8;

typedef unsigned int  u32;

typedef unsigned short u16;

typedef struct {
    u8 pad[0x30];
    short step;
    u16 done;
} Obj021A3C6C;

typedef int (*Step021A3C6C)(Obj021A3C6C *p);

void *func_021A3960(u8 *p);
u16 func_0216D598(void *p);
int func_0216D7A8(void *p, unsigned int v);
extern u16 func_0216D608(void *p);
int func_021A3B78(u8 *p);
int func_021A3B94(u32 *p);
u16 func_021A3BB4(u8 *p, u32 keys);
void func_021A3C24(u8 *p, int a);
int func_021A3C3C(u32 keys);
int func_021A3C54(u32 keys);
u16 func_021A3C6C(Obj021A3C6C *p, int idx);
extern Step021A3C6C *const data_021D89C4[];


int func_021A3B78(u8 *p)
{
    int r = func_0216D598(func_021A3960(p));

    if (r == 1 || r == 4)
        return 1;
    return 0;
}


int func_021A3B94(u32 *p)
{
    int r = 0;

    if ((u16)func_0216D7A8((void *)p[7], 0) != 0xFFFF)
        r = 1;
    return r;
}


u16 func_021A3BB4(u8 *p, u32 keys)
{
    u32 a;
    u32 b;
    u32 c;
    u32 h1;
    u32 h2;

    a = func_021A3C3C(keys);
    b = func_021A3C54(keys);
    if (a == 9) {
        return b;
    }
    if (b == 9) {
        return a;
    }
    c = func_0216D608(func_021A3960(p));
    h1 = ((struct Obj12730 *)p)->f20;
    h2 = ((struct Obj12730 *)p)->f22;
    if (c != 9) {
        if (a == h1 && b == h2) {
            if (b == c) {
                return b;
            }
            if (a == c) {
                return a;
            }
        }
        if (b != h2) {
            return b;
        }
        return a;
    }
    return b;
}


void func_021A3C24(u8 *p, int a)
{
    ((struct Obj12731 *)p)->f20 = func_021A3C3C(a);
    ((struct Obj12731 *)p)->f22 = func_021A3C54(a);
}


/*
 * Unlabelled leaf (no lr save): maps a key mask to a direction, 9 for none.
 * Filed as a blocker of ov021 func_021A3BB4.
 */
int func_021A3C3C(u32 keys)
{
    if (keys & 0x20) {
        return 2;
    }
    if (keys & 0x10) {
        return 3;
    }
    return 9;
}


int func_021A3C54(u32 keys)
{
    if (keys & 0x40) {
        return 0;
    }
    if (keys & 0x80) {
        return 1;
    }
    return 9;
}


u16 func_021A3C6C(Obj021A3C6C *p, int idx)
{
    Step021A3C6C *tbl;

    if (p->done == 0) {
        tbl = data_021D89C4[idx];
        while (tbl[p->step](p) == 1)
            ;
    }
    return p->done;
}
