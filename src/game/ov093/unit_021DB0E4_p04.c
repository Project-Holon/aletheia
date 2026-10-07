/*
 * file:     unit_021DB0E4_p04.c
 * unit:     yes
 * function: func_021DB430, func_021DB460, func_021DB474, func_021DB4C4, func_021DB4E8
 * address:  0x021DB430
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
 *   func_021DA8A8 0x021DA8A8 thumb ov093
 *   func_021DA96C 0x021DA96C thumb ov093
 *   d_021F0A70 0x021F0A70 data a4
 *   func_021E85F8  0x021E85F8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C8290  0x021C8290  thumb  ov093
 *   func_021DB550  0x021DB550  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
#include "../../matched/include/Obj21327.h"

struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021DA8A8(int,int,int);
extern void func_021DA96C(void *,int,unsigned int,int);
extern int func_021E85F8(int id);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern int func_021D775C(int key);
extern int func_021C8290(u8 *p, int a, int b, void *item);
extern int func_021DB550(int t);
extern int func_021D76BC(int key, u32 val);
void func_021DB430(int a, void *b, int c);
const unsigned int *func_021DB454(int *p);
void func_021DB460(int a, int b, int c, int *d);
void func_021DB474(int unused, void *a, int id, int *f);
void func_021DB4C4(int a, void *b, int c);
int func_021DB4E8(int a, int b, int c, int d);
extern const unsigned int d_021F0A70[];


void func_021DB430(int a, void *b, int c)
{
    if (func_021DA8A8((int)b, c, 10) != 0) func_021DA96C(b, c, 3, 1);
}


const unsigned int *func_021DB454(int *p)
{
    *p = 3;
    return d_021F0A70;
}


void func_021DB460(int a, int b, int c, int *d)
{
    *d = func_021DB4E8(b, c, (int)d, 12);
}


void func_021DB474(int unused, void *a, int id, int *f)
{
    u8 *r;

    if (*f != 0) {
        if (func_021E85F8(id) != 0) {
            r = (u8 *)func_021C88A4(a, 4, id);
            ((struct Obj21327 *)r)->f0 |= 0x800000;
            func_021C8838(r + 4, 2, 0x1c0);
            func_021C8860((struct S *)(r + 4), id);
            func_021C88C8(a, r);
        }
        *f = 0;
    }
}


void func_021DB4C4(int a, void *b, int c)
{
    if (func_021DA8A8((int)b, c, 12) != 0) func_021DA96C(b, c, 3, 1);
}


int func_021DB4E8(int a, int b, int c, int d)
{
    u8 k;
    u16 t;
    u8 n;

    k = func_021D775C(3);
    if (k != b && d == func_021D775C(0x16)) {
        t = func_021D775C(0x12);
        if (func_021C8290((u8 *)a, k, b, (void *)t) == 0 && func_021DB550(t) == 0) {
            n = func_021D775C(4);
            if (func_021D76BC(4, b) != 0 && n != b)
                return 1;
        }
    }
    return 0;
}
