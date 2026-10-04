/*
 * function: func_021EE418
 * address:  0x021EE418
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EE408  0x021EE408  thumb  ov170
 *   func_021EC000  0x021EC000  thumb  ov170
 *
 * Run the frame update, then release slot 4 with force 1.
 */
#include "../include/Obj18526.h"


extern void func_021EE408(char *p, int v);
extern void func_021EC000(char *p, int i, int v);
void func_021EE418(char *p, int v)
{
    func_021EE408(p, v);
    func_021EC000((char *)(((struct Obj18526 *)p)->f2C), 4, 1);
}
