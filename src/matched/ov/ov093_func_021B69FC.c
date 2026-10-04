/*
 * function: func_021B69FC
 * address:  0x021B69FC
 * packet:   pkt_ov093_021B69FC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9E38  0x021B9E38  thumb  ov093
 *   func_021B9E7C  0x021B9E7C  thumb  ov093
 *   func_021B6954  0x021B6954  thumb  ov093
 */
#include "../include/Obj00661.h"
#include "../include/Obj06216.h"

struct A;
struct B;
extern void func_021B9E38(char *p, int a, int b);
extern void func_021B9E7C(struct A *p, struct B *src);
extern void func_021B6954(int, int);

void func_021B69FC(int a, char *b)
{
    if (((struct Obj00661 *)b)->f23 == 0) {
        func_021B9E38((char *)(a + 0x20), ((struct Obj06216 *)a)->f468, ((struct Obj06216 *)a)->fC0);
        func_021B9E7C((struct A *)(a + 0x48), (struct B *)(((struct Obj00661 *)b)->f4C));
    } else {
        func_021B6954(a, 0);
        func_021B6954(a, 1);
    }
}
