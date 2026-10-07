/*
 * file:     unit_021DD87C_p01.c
 * unit:     yes
 * function: func_021DDA28, func_021DDA6C
 * address:  0x021DDA28
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
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021DD044  0x021DD044  thumb  ov093
 *   func_021DCFF8  0x021DCFF8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../../matched/include/Obj13487.h"

struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern void func_021DD044(void *a, void *b, int c);
extern int func_021DCFF8(int a, int b);
extern void *func_021C88A4(char *p, int a, int b);
extern int func_021D7B74(u8 *p, u32 k);
extern void func_021C88C8(void *a, void *b);
void func_021DDA28(u8 *a, u8 *b, int c);
void func_021DDA6C(int a, u8 *b, int c);


void func_021DDA28(u8 *a, u8 *b, int c)
{
    if (c == func_021D775C(4) && func_021D775C(0x46) == 0 && func_021D775C(0x38) > 3
        && func_021D62C4(func_021C7CF4((int *)b, c), 0xf) == 0)
        func_021DD044(a, b, c);
}


void func_021DDA6C(int a, u8 *b, int c)
{
    void *m;
    u8 *p;
    u8 k;
    if (c == func_021D775C(2)) {
        m = func_021C7CF4((int *)b, c);
        k = func_021DCFF8(a, 2);
        p = func_021C88A4((char *)b, 5, c);
        p[6] = c;
        ((struct Obj13487 *)p)->f4 = func_021D7B74(m, k);
        func_021C88C8(b, p);
    }
}
