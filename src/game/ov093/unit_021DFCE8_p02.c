/*
 * file:     unit_021DFCE8_p02.c
 * unit:     yes
 * function: func_021DFE28, func_021DFE88
 * address:  0x021DFE28
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
 *   func_021E85F8  0x021E85F8  thumb  ov093
 *   func_021C8374  0x021C8374  thumb  ov093
 *   func_021C83D4  0x021C83D4  thumb  ov093
 *   func_021C830C  0x021C830C  thumb  ov093
 *   func_021C7F24  0x021C7F24  thumb  ov093
 *   func_021C7F4C  0x021C7F4C  thumb  ov093
 *   func_021DD044  0x021DD044  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../../matched/include/Obj21422.h"

struct Flag;
struct S;
typedef unsigned char  u8;

extern int func_021D775C(int key);
extern int func_021E85F8(int id);
extern int func_021C8374(u8 *p, int i);
extern int func_021C83D4(u8 *p);
extern unsigned int func_021C830C(u8 *p);
extern int func_021C7F24(u8 *p, int i);
extern int func_021C7F4C(struct Flag *p);
extern void func_021DD044(void *a, void *b, int c);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, unsigned int v);
extern void func_021C88C8(void *a, void *b);
void func_021DFE28(int a, void *b, int c);
void func_021DFE88(int a, void *b, int c);


void func_021DFE28(int a, void *b, int c)
{
    if (func_021E85F8(c) != 0 && func_021D775C(0x4d) == 0 && func_021C8374(b, c) == 0
        && func_021C83D4(b) == 0 && func_021C830C(b) == 0 && func_021C7F24(b, c) != 0
        && func_021C7F4C(b) != 0) {
        func_021DD044((void *)a, (void *)((int)b), c);
    }
}


void func_021DFE88(int a, void *b, int c)
{
    char *p;
    char *q;

    if (c == func_021D775C(2) && func_021C7F24(b, c) != 0) {
        p = func_021C88A4(b, 4, c);
        func_021C8838(p + 4, 2, 0x19e);
        func_021C8860((struct S *)(p + 4), c);
        func_021C88C8(b, p);
        q = func_021C88A4(b, 0x29, c);
        ((struct Obj21422 *)q)->f4C = c;
        func_021C88C8(b, q);
    }
}
