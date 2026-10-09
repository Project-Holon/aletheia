/*
 * file:     unit_021E65B0_p03.c
 * unit:     yes
 * function: func_021E6918, func_021E6924, func_021E6950, func_021E695C, func_021E6988
 * address:  0x021E6918
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
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F276C     0x021F276C  data   ov093  a4
 *   d_021F2754     0x021F2754  data   ov093  a4
 *   d_021F255C     0x021F255C  data   ov093  a4
 */
#include "../../matched/include/Obj13536.h"
#include "../../matched/include/Obj13537.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
int *func_021E6918(int *p);
void func_021E6924(int a, void *b, int c);
int *func_021E6950(int *p);
void func_021E695C(int a, void *b, int c);
int *func_021E6988(int *p);
extern int d_021F276C[];
extern int d_021F2754[];
extern int d_021F255C[];


int *func_021E6918(int *p)
{
    *p = 1;
    return d_021F276C;
}


void func_021E6924(int a, void *b, int c)
{
    u8 *m;

    if (c == func_021D775C(2)) {
        m = (u8 *)func_021C88A4(b, 0x17, c);
        m[8] = c;
        ((struct Obj13536 *)m)->f4 = 8;
        func_021C88C8(b, m);
    }
}


int *func_021E6950(int *p)
{
    *p = 1;
    return d_021F2754;
}


void func_021E695C(int a, void *b, int c)
{
    u8 *m;

    if (c == func_021D775C(2)) {
        m = (u8 *)func_021C88A4(b, 0x17, c);
        m[8] = c;
        ((struct Obj13537 *)m)->f4 = 7;
        func_021C88C8(b, m);
    }
}


int *func_021E6988(int *p)
{
    *p = 1;
    return d_021F255C;
}
