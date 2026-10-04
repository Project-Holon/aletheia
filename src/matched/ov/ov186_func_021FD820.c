/*
 * function: func_021FD820
 * address:  0x021FD820
 * packet:   pkt_021FD820
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3B4   0x0204B3B4  arm
 *   func_021FC0C8   0x021FC0C8  thumb
 *   func_021FD714   0x021FD714  thumb
 *   func_020307B0   0x020307B0  arm
 *
 * Release the twelve handles at r5+0x1F8, then tear the object down.
 */
#include "../include/Obj10793.h"


struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_021FC0C8(char *p, unsigned i);
extern void func_021FD714(void *p);
extern void func_020307B0(void *p);

void func_021FD820(char *r5)
{
    int i;
    for (i = 0; i < 0xC; i++)
        func_0204B3B4((struct Obj *)(*(int *)(r5 + 0x1F8 + i * 4)));
    func_021FC0C8((char *)(((struct Obj10793 *)r5)->f14), ((struct Obj10793 *)r5)->fC + 9);
    func_021FD714((void *)(((struct Obj10793 *)r5)->f10));
    func_020307B0((int *)r5);
}
