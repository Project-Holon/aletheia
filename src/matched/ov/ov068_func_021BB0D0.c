/*
 * unit:     yes
 * function: func_021BB0D0, func_021BB0D8
 * address:  0x021BB0D0
 * packet:   pkt_ov068_021BB0D0
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * ARM9 tail call then a byte read-modify-write.
 *
 * symbols:
 *   func_02012FFC  0x02012FFC  thumb
 */
#include "../include/Obj13144.h"

void func_021BB0D0(void)
{
    signed char func_02012FFC(void);
    func_02012FFC();
}

int func_021BB0D8(void *p)
{
    unsigned char old = ((struct Obj13144 *)p)->f5;
    ((struct Obj13144 *)p)->f5 = 0xb;
    return old;
}
