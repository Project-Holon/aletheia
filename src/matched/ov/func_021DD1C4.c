/*
 * function: func_021DD1C4
 * address:  0x021DD1C4
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DEB14  0x021DEB14  thumb  ov170
 *   func_021EDECC  0x021EDECC  thumb  ov170
 *   func_021EE008  0x021EE008  thumb  ov170
 *
 * Fold the signed delta into p[0x19] through the wrap helper,
 *   then refresh and re-key the queue.
 */
#include "../include/Obj00000.h"


extern unsigned char func_021DEB14(unsigned char *p, int a);
extern void func_021EDECC(unsigned char *p, int d);
extern void func_021EE008(char *, int, int);
void func_021DD1C4(char *p, int a)
{
    ((struct Obj00000 *)p)->f19 = func_021DEB14((unsigned char *)p, (signed char)a);
    func_021EDECC((unsigned char *)p, a);
    func_021EE008(p, 0, 0);
}
