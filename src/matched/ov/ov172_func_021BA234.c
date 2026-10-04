/*
 * function: func_021BA234
 * address: 0x021BA234
 * packet: pkt_ov172_021BA234
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02072BDC 0x02072BDC arm
 */
#include "../include/Obj04555.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Slot02072BDC Slot02072BDC;
extern void func_02072BDC(Slot02072BDC *s);
void func_021BA234(void *p)
{
    ((struct Obj04555 *)p)->fC = 0;
    func_02072BDC(*(Slot02072BDC * *)&((struct Obj04555 *)p)->f20);
}
