/*
 * function: func_021EE7C4
 * address:  0x021EE7C4
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EE754  0x021EE754  thumb  ov170
 *   func_021EEF74  0x021EEF74  thumb  ov170
 *   func_021DC9B4  0x021DC9B4  thumb  ov170
 *
 * Stage the pair, forward it, re-key the queue with the
 *   0x021E066D selector and record the first argument at 0xA168.
 */
#include "../include/Obj00000.h"


extern void func_021EE754(char *, int, int);
extern void func_021EEF74(char *q, int a, int b);
extern void func_021DC9B4(char *p, int v);
void func_021EE7C4(char *p, int a, int b)
{
    func_021EE754(p, a, b);
    func_021EEF74((char *)(*(int *)&((struct Obj00000 *)p)->f2C), a, b);
    func_021DC9B4((char *)(*(int *)&((struct Obj00000 *)p)->f2C), 0x021E066D);
    *(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0xA168) = a;
}
