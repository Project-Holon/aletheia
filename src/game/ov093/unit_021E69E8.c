/*
 * file:     unit_021E69E8.c
 * unit:     yes
 * function: func_021E69E8, func_021E6A78, func_021E6A84
 * address:  0x021E69E8
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
 *   func_0689CA8C  0x0689CA8C  thumb
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5C30  0x021D5C30  thumb  ov093
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D7E44  0x021D7E44  thumb  ov093
 *   func_021C8030  0x021C8030  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   d_021F28F8     0x021F28F8  data    a4
 */
#include "../../matched/include/Obj07834.h"
#include "../../matched/include/Obj13538.h"

struct UtilWork;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5C30(struct UtilWork *p);
extern int func_021C8010(u8 *p, unsigned int v);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern int func_0689CA8C(u32 *out);
extern u16 func_021D7E44(int a, int b);
extern int func_021C8030(int a, int b, int c);
extern int func_021D76BC(int key, u32 val);
void func_021E69E8(int x, void *a, int c);
int *func_021E6A78(int *p);
void func_021E6A84(int x, int a, int c);
extern int d_021F28F8[];


void func_021E69E8(int x, void *a, int c)
{
    u8 *p;
    u8 *q;

    if (c == func_021D775C(2)) {
        p = func_021C88A4(a, 0x15, c);
        p[8] = c;
        ((struct Obj13538 *)p)->f4 = 5;
        func_021C88C8(a, p);
        if (func_021D5C30(func_021C7CF4(a, c)) == 0) {
            q = func_021C88A4(a, 0x37, c);
            ((struct Obj07834 *)q)->f4 = 0x272;
            q[6] = func_021C8010(a, c);
            q[7] = 6;
            q[0xb] = 1;
            func_021C88C8(a, q);
        }
        p = func_021C88A4(a, 4, c);
        func_021C8838(p + 4, 2, 0x268);
        func_021C8860((struct S *)(p + 4), c);
        func_021C88C8(a, p);
    }
}


int *func_021E6A78(int *p)
{
    *p = 2;
    return d_021F28F8;
}


void func_021E6A84(int x, int a, int c)
{
    u32 v;
    int id;
    int r;

    if (c == func_021D775C(2)) {
        id = func_021D7E44(func_0689CA8C(&v), (u16)v);
        r = func_021C8030(a, c, id);
        func_021D76BC(0x12, id);
        func_021D76BC(0xd, r);
    }
}
