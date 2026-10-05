/*
 * function: func_021D96FC
 * address:  0x021D96FC
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D96FC   0x021D96FC  thumb ov093
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   func_021D62C4   0x021D62C4  thumb ov093
 *   func_021C88B4   0x021C88B4  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *
 * Build the record for (a, b) after a two-step gate, fill in c, publish it
 * through func_021C88C8, then emit the "3" event through func_021C88B4.
 */
#include "../include/Obj09218.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

struct Unk021D62A8;
void *func_021C7CF4(int *p, int i);
int func_021D62C4(struct Unk021D62A8 *p, int i);
void func_021C88B4(void *a, int k, int b);
void *func_021C88A4(void *a, int k, int b);
void func_021C88C8(void *a, void *p);

void func_021D96FC(void *a, int b, int c)
{
    if (func_021D62C4(func_021C7CF4(a, b), c) != 0) {
        u8 *p;
        func_021C88B4(a, 2, b);
        p = func_021C88A4(a, 0xb, b);
        ((struct Obj09218 *)p)->f4 = c;
        ((struct Obj09218 *)p)->f14 = 1;
        ((struct Obj09218 *)p)->f8 = b;
        func_021C88C8(a, p);
        func_021C88B4(a, 3, b);
    }
}
