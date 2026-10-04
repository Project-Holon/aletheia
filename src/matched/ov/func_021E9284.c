/*
 * function: func_021E9284
 * address:  0x021E9284
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DE898  0x021DE898  thumb  ov170
 *   func_021E8F90  0x021E8F90  thumb  ov170
 *
 * Set the id, re-key the queue, store 0x69 as the frame, then
 *   arm the flag.
 */
#include "../include/Obj18472.h"


typedef unsigned int   u32;
extern void func_020061E4(u32 a);
extern void func_021DE898(char *);
extern int func_021E8F90(void *p, int a);
void func_021E9284(char *p)
{
    func_020061E4(0x55D);
    func_021DE898(p);
    ((struct Obj18472 *)p)->f28 = 0x69;
    func_021E8F90(p, 1);
}
