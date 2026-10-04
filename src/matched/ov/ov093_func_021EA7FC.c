/*
 * function: func_021EA7FC
 * address:  0x021EA7FC
 * packet:   pkt_ov093_021EA7FC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F8A40  0x021F8A40  thumb  ov094
 *   func_021EE200  0x021EE200  thumb  ov093
 */
#include "../include/Obj21566.h"
extern void func_021F8A40(int a);
extern void func_021EE200(char *p);

void func_021EA7FC(char *p)
{
    func_021F8A40(3);
    func_021EE200(*(char * *)&((struct Obj21566 *)p)->f17C);
}
