/*
 * file:     unit_021DA624_p04.c
 * unit:     yes
 * function: func_021DA9E0, func_021DAA70, func_021DAA94, func_021DAAC0, func_021DAAEC
 * address:  0x021DA9E0
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
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   d_021F0B30 0x021F0B30 data a4
 *   func_021DA8A8 0x021DA8A8 thumb ov093
 *   func_021DA8DC 0x021DA8DC thumb ov093
 *   d_021F0730 0x021F0730 data a4
 *   d_021F0798 0x021F0798 data a4
 */
#include "../../matched/include/Obj06256.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D7B74(u8 *p, u32 k);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88B4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021D7704(int, int);
extern int func_021DA8A8(int, int, int);
extern void func_021DA8DC(int, int, int);
void func_021DA9E0(int unused, void *a, int id);
void func_021DAA70(int a, int b, int c);
void func_021DAA94(int a, int b, int c);
void *func_021DAAB4(int *p);
void func_021DAAC0(int a, int b, int c);
void *func_021DAAE0(int *p);
void func_021DAAEC(int a, int b, int c);
void *func_021DAB0C(int *p);
void *func_021DAB18(int *p);
extern unsigned char d_021F0B30[];
extern unsigned char d_021F0730[];
extern unsigned char d_021F0798[];


void func_021DA9E0(int unused, void *a, int id)
{
    u8 *r;
    void *m;
    u8 c;

    if (id == func_021D775C(2)) {
        m = func_021C7CF4(a, id);
        c = func_021D775C(0x39);
        if (c == 1) {
            func_021C88B4(a, 2, id);
            r = (u8 *)func_021C88A4(a, 7, id);
            r[6] = id;
            ((struct Obj06256 *)r)->f4 = func_021D7B74(m, 8);
            func_021C88C8(a, r);
            func_021C88B4(a, 3, id);
        } else if (c == 2) {
            r = (u8 *)func_021C88A4(a, 5, id);
            ((struct Obj06256 *)r)->f0 |= 0x800000;
            r[6] = id;
            ((struct Obj06256 *)r)->f4 = func_021D7B74(m, 8);
            func_021C88C8(a, r);
        }
    }
}


void func_021DAA70(int a, int b, int c)
{
    if (c == func_021D775C(4) && func_021D775C(0x16) == 9)
        func_021D7704(0x31, 5 << 10);
}


/*
 * extent: includes store-and-return followers 021DAAB4.
 */
void func_021DAA94(int a, int b, int c)
{
    if (func_021DA8A8(b, c, 10))
        func_021DA8DC(b, c, 4);
}


void *func_021DAAB4(int *p)
{
    *p = 3;
    return d_021F0B30;
}


/*
 * extent: includes store-and-return followers 021DAAE0.
 */
void func_021DAAC0(int a, int b, int c)
{
    if (func_021DA8A8(b, c, 10))
        func_021DA8DC(b, c, 4);
}


void *func_021DAAE0(int *p)
{
    *p = 1;
    return d_021F0730;
}


/*
 * extent: includes store-and-return followers 021DAB0C, 021DAB18.
 */
void func_021DAAEC(int a, int b, int c)
{
    if (func_021DA8A8(b, c, 12))
        func_021DA8DC(b, c, 4);
}


void *func_021DAB0C(int *p)
{
    *p = 1;
    return d_021F0798 + 8;
}


void *func_021DAB18(int *p)
{
    *p = 1;
    return d_021F0798;
}
