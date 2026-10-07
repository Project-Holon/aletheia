/*
 * file:     unit_021D87C8_p03.c
 * unit:     yes
 * function: func_021D8964, func_021D8974
 * address:  0x021D8964
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
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../../matched/include/Obj21270.h"

struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

void *func_021C88A4(char *p, int a, int b);
void func_021C8838(void *p, int a, int b);
void func_021C8860(struct S *p, u32 a);
void func_021C88C8(void *a, void *b);
void func_021D8964(void *a, int b, int c, int *d);
void func_021D8974(void *a, int b, int c, int *d);


void func_021D8964(void *a, int b, int c, int *d)
{
    if (d[0] == 0) func_021D8974(a,b,c,d);
}


void func_021D8974(void *a, int b, int c, int *d)
{
    u8 *p;

    d[0] = 1;
    d[1] = 0;
    d[2] = 0;
    d[3] = 1;
    p = func_021C88A4((char *)b, 4, c);
    ((struct Obj21270 *)p)->f0 |= 4 << 21;
    func_021C8838(p + 4, 2, 0x1f0);
    func_021C8860((struct S *)(p + 4), c);
    func_021C88C8((void *)b, p);
}
