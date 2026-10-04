/*
 * function: func_021EA990
 * address:  0x021EA990
 * packet:   pkt_ov093_021EA990
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E9100  0x021E9100  thumb  ov093
 *   func_021F84B4  0x021F84B4  thumb  ov094
 *   func_021EAF00  0x021EAF00  thumb  ov093
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   func_021ED4E4  0x021ED4E4  thumb  ov093
 *   func_021ED510  0x021ED510  thumb  ov093
 */
#include "../include/Obj13564.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 *func_021E9100(void *p, u32 k);
extern void func_021F84B4(u32 a, u32 b);
extern void func_021EAF00(u8 *p, int a);
extern int func_021F7EB4(void);
extern void func_021ED4E4(u8 *p, int a, int b);
extern int func_021ED510(u8 *p, int a, int b);

int func_021EA990(int *st, u8 *b)
{
    u8 *t = func_021E9100(b, 7);

    switch (*st) {
    case 0:
        func_021F84B4(t[1], t[2]);
        func_021EAF00(b, 0x57b);
        *st = *st + 1;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            func_021ED4E4((u8 *)(((struct Obj13564 *)b)->f17C), t[5], t[6]);
            *st = *st + 1;
        }
        break;
    case 2:
        if (func_021ED510((u8 *)(((struct Obj13564 *)b)->f17C), t[5], t[6]) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}
