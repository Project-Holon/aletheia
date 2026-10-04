/*
 * function: func_021EE454
 * address:  0x021EE454
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EE408  0x021EE408  thumb  ov170
 *
 * Twin of func_021EEC1C.
 */
#include "../include/Obj18527.h"


typedef unsigned char  u8;
struct Sound;
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021EE408(char *, int);
void func_021EE454(char *p, unsigned int a)
{
    func_020260E4((struct Sound *)(*(int *)(((struct Obj18527 *)p)->f2C + 0x70)), (unsigned char)a);
    func_021EE408(p, a);
}
