/*
 * function: func_021FFE5C
 * address:  0x021FFE5C
 * packet:   pkt_021FFE5C
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FFEA8  0x021FFEA8  thumb  ov186
 *   func_021FFF28  0x021FFF28  thumb  ov186
 */
#include "../include/Obj02237.h"

extern void func_021FFEA8(char *p);
struct Work;
extern void func_021FFF28(struct Work *p);

void func_021FFE5C(char *p)
{
    func_021FFEA8(p);
    func_021FFF28((struct Work *)p);
    ((struct Obj02237 *)p)->f6C = 1;
}
