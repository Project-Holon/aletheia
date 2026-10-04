/*
 * function: func_021EAECC
 * address:  0x021EAECC
 * packet:   pkt_ov093_021EAECC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EAEF0  0x021EAEF0  thumb  ov093
 */
#include "../include/Obj07849.h"
typedef unsigned char u8;
extern void func_021EAEF0(void *, void *);
void func_021EAECC(u8 *p, int v, int w)
{
    ((struct Obj07849 *)p)->f160 = v;
    ((struct Obj07849 *)p)->f164 = v;
    ((struct Obj07849 *)p)->f16C = w;
    func_021EAEF0(((struct Obj07849 *)p)->f180, p + 0x160);
}
