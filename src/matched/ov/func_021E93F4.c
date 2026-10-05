/*
 * function: func_021E93F4
 * address:  0x021E93F4
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021DE898  0x021DE898  thumb  ov170
 *   func_021E8F90  0x021E8F90  thumb  ov170
 *
 * candidate func_021E93F4: copy two bytes into a sub object
 */
#include "../include/Obj05869.h"


extern void func_021DE898(int *q);
extern int func_021E8F90(void *p, int a);
void func_021E93F4(char *p)
{
    func_021DE898((int *)((int)p));
    *(unsigned char *)(((struct Obj05869 *)p)->f0 + 0x2a) = ((struct Obj05869 *)p)->f14;
    *(unsigned char *)(((struct Obj05869 *)p)->f0 + 0x2b) = ((struct Obj05869 *)p)->f16;
    ((struct Obj05869 *)p)->f28 = 0x69;
    func_021E8F90((void *)((int)p), 1);
}

