/*
 * file:     unit_021E0518.c
 * unit:     yes
 * function: func_021E0518, func_021E05A4, func_021E05B0, func_021E061C
 * address:  0x021E0518
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
 *   func_021C8174  0x021C8174  thumb  ov093
 *   func_021E8CF0  0x021E8CF0  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D57FC  0x021D57FC  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021EF948  0x021EF948  thumb  ov093
 *   func_021E8940  0x021E8940  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   d_021F26F4     0x021F26F4  data   ov093  a4
 *   d_021F2424     0x021F2424  data   ov093  a4
 */
#include "../../matched/include/Obj13504.h"

struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern int func_021D775C(int key);
extern int func_021C8174(int *p);
extern u16 func_021E8CF0(int c);
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D57FC(void *p);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern int func_021EF948(int k);
extern int func_021E8940(u32 a);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
void func_021E0518(int a, int *b, int c);
int *func_021E05A4(int *p);
void func_021E05B0(int a, void *b, int c);
int *func_021E061C(int *p);
extern int d_021F26F4[];
extern int d_021F2424[];


void func_021E0518(int a, int *b, int c)
{
    int t;
    u16 v;
    char *p;

    if (c == func_021D775C(3)) {
        switch (func_021C8174(b)) {
        case 1: case 2: case 3: case 8: case 9: case 15:
            t = 4;
            break;
        case 4: case 14:
        default:
            t = 0;
            break;
        case 10:
            t = 5;
            break;
        case 0: case 5:
            t = 0xb;
            break;
        case 6: case 11: case 12:
            t = 0xa;
            break;
        case 7: case 13:
            t = 0xe;
            break;
        }
        v = func_021E8CF0(t);
        if (v != func_021D57FC(func_021C7CF4(b, c))) {
            p = func_021C88A4((char *)b, 0x14, c);
            ((struct Obj13504 *)p)->f4 = v;
            ((struct Obj13504 *)p)->f6 = c;
            func_021C88C8(b, p);
        }
    }
}


int *func_021E05A4(int *p)
{
    *p = 1;
    return d_021F26F4;
}


void func_021E05B0(int a, void *b, int c)
{
    int *p;

    if (c == func_021D775C(3)) {
        if (func_021EF948(1) == 0) {
            p = func_021C88A4(b, 0x1b, c);
            p[1] = 1;
            p[2] = func_021E8940(5);
            func_021C8838(p + 4, 2, 0x359);
            func_021C8860((struct S *)(p + 4), c);
            func_021C88C8(b, p);
        } else {
            p = func_021C88A4(b, 0x1c, c);
            p[1] = 1;
            func_021C88C8(b, p);
        }
    }
}


int *func_021E061C(int *p)
{
    *p = 1;
    return d_021F2424;
}
