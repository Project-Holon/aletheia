/*
 * function: func_021DEA4C
 * address:  0x021DEA4C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DE8B4  0x021DE8B4  thumb  ov170
 *
 * lane O46
 */
#include "../include/Obj10648.h"


extern void func_021DE8B4(unsigned char *p, int slot, unsigned idx, int mode, int flag);
void func_021DEA4C(char *p, int a, int b)
{
    func_021DE8B4((unsigned char *)p, *(unsigned char *)(*(int *)&((struct Obj10648 *)p)->f2C + 0xA17E), a, b, 0);
}
