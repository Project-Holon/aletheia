/*
 * function: func_021DC57C
 * address:  0x021DC57C
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021DC57C   0x021DC57C  thumb ov093
 *   func_021D775C   0x021D775C  thumb ov093
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   func_021D5B68   0x021D5B68  thumb ov093
 *   func_021D5B48   0x021D5B48  thumb ov093
 *   func_021D7B74   0x021D7B74  thumb ov093
 *   func_021D59B4   0x021D59B4  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *
 * Shape F1 gate on func_021D775C(2); reject the record if either predicate
 * holds; clamp func_021D7B74(r,3) down to the 0xe-minus-0xd gap reported by
 * func_021D59B4; then build and publish the record.  Two live calls with no
 * free saved register is what puts the first result on the stack.
 */
#include "../include/Obj07235.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int func_021D775C(int a);
void *func_021C7CF4(int *p, int i);
int func_021D5B68(void *p);
extern int func_021D5B48(u8 *p);
extern int func_021D7B74(u8 *p, u32 k);
extern int func_021D59B4(u8 *p, int k);
void *func_021C88A4(int a, int k, int b);
void func_021C88C8(void *a, void *b);

void func_021DC57C(void *a, int b, int c)
{
    void *r;
    u32 n, m;
    u8 *p;

    if (c != func_021D775C(2))
        return;
    r = func_021C7CF4((int *)b, c);
    if (func_021D5B68(r) != 0)
        return;
    if (func_021D5B48(r) != 0)
        return;
    n = func_021D7B74(r, 3);
    m = func_021D59B4(r, 0xe) - func_021D59B4(r, 0xd);
    if (n > m)
        n = m;
    p = func_021C88A4(b, 8, c);
    ((struct Obj07235 *)p)->f7 = c;
    ((struct Obj07235 *)p)->f10 = n;
    ((struct Obj07235 *)p)->f4 = 1;
    ((struct Obj07235 *)p)->f5 = 1;
    func_021C88C8((void *)b, p);
}
