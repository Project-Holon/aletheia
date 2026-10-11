/*
 * file:     unit_021DE0DC.c
 * unit:     yes
 * function: func_021DE0DC, func_021DE0EC, func_021DE0F8, func_021DE108
 * address:  0x021DE0DC
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
 *   func_0689C8CC  0x0689C8CC  thumb
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D70C8  0x021D70C8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F162C     0x021F162C  data   ov093  a4
 */
#include "../../matched/include/Obj21383.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int key);
extern int func_0689C8CC(u16 a);
extern void func_021D70C8(void *a);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
void func_021DE0DC(void *a, void *b, int c, int *d);
int *func_021DE0EC(int *p);
void func_021DE0F8(void *a, void *b, int c, int *d);
void func_021DE108(void *a, void *b, int c, int *d, int e);
extern int d_021F162C[];

void func_021DE0DC(void *a, void *b, int c, int *d) { func_021DE108(a, b, c, d, 0x1); }


int *func_021DE0EC(int *p)
{
    *p = 2;
    return d_021F162C;
}


/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #2; str r4, [sp]; bl func_021DE108; add sp, #4; pop {r3, r4, pc}.
 */
void func_021DE0F8(void *a, void *b, int c, int *d) { func_021DE108(a, b, c, d, 0x2); }


void func_021DE108(void *a, void *b, int c, int *d, int e)
{
    u8 *m;

    if (c == func_021D775C(4) && func_021D775C(0x46) == 0
        && func_0689C8CC(func_021D775C(0x12)) == 0 && e == func_021D775C(0x1a)) {
        func_021D70C8(a);
        *d = func_021D775C(3) + 1;
        m = (u8 *)func_021C88A4(b, 0, c);
        ((struct Obj21383 *)m)->f4 |= 2;
        func_021C88C8(b, m);
    }
}
