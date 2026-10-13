/*
 * function: func_021EA824
 * address:  0x021EA824
 * packet:   pkt_ov093_021EA824
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F8A78  0x021F8A78  thumb  ov094
 *   BTLV_SCU_NoOp  0x021EE224  thumb  ov093
 */
#include "../include/Obj21567.h"
extern void func_021F8A78(void);
extern void BTLV_SCU_NoOp(char *p);

void func_021EA824(char *p)
{
    func_021F8A78();
    BTLV_SCU_NoOp(*(char * *)&((struct Obj21567 *)p)->f17C);
}
