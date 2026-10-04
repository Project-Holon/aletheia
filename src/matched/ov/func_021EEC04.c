/*
 * function: func_021EEC04
 * address:  0x021EEC04
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EEF74  0x021EEF74  thumb  ov170
 *   func_021DC9B4  0x021DC9B4  thumb  ov170
 *   func_021E066C  0x021E066C  thumb  ov170
 *
 * Release the child at +0x2c and reset its field +0x5c to the handler.
 */
#include "../include/Obj12184.h"

extern void func_021EEF74(char *q, int a, int b);
extern void func_021DC9B4(char *p, int v);
extern int func_021E066C(char *p);

void func_021EEC04(char *p, int a, int b)
{
    func_021EEF74(*(char * *)&((struct Obj12184 *)p)->f2C, a, b);
    func_021DC9B4(((struct Obj12184 *)p)->f2C, (int)((void *)&func_021E066C));
}

