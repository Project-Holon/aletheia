/*
 * file:     unit_021D8684.c
 * unit:     yes
 * function: func_021D8684, func_021D869C, func_021D86A8, func_021D86F0
 * address:  0x021D8684
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
 *   func_021D76BC   0x021D76BC  thumb
 *   func_021D775C   0x021D775C  thumb
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F07B0     0x021F07B0  data   ov093  a4
 *   d_021F05B8     0x021F05B8  data   ov093  a4
 */
#include "../../matched/include/Obj05216.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

int func_021D775C(int a);
void *func_021C88A4(char *p, int a, int b);
void func_021C88C8(void *a, void *b);
void func_021D8684(int a, int b, int c);
int *func_021D869C(int *p);
void func_021D86A8(void *a, int b, int c);
int *func_021D86F0(int *p);
extern int d_021F07B0[];
extern int d_021F05B8[];


/* 021D8684  shape F1: gate on func_021D775C(4) */
void func_021D8684(int a, int b, int c)
{
    if (c == func_021D775C(4))
        func_021D76BC(0x41, 1);
}


int *func_021D869C(int *p)
{
    *p = 1;
    return d_021F07B0;
}


void func_021D86A8(void *a, int b, int c)
{
    u8 *p;

    if (func_021D775C(0x22) == 6) {
        if (c == func_021D775C(2)) {
            p = func_021C88A4((char *)b, 0xe, c);
            ((struct Obj05216 *)p)->f0 |= 2 << 22;
            ((struct Obj05216 *)p)->f4 = 5;
            p[0xc] = 1;
            p[0xe] = 0;
            p[0xf] = 1;
            p[0x10] = c;
            func_021C88C8((void *)b, p);
        }
    }
}


int *func_021D86F0(int *p)
{
    *p = 1;
    return d_021F05B8;
}
