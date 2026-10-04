/*
 * function: func_02019CF8
 * address:  0x02019CF8
 * packet:   pkt_02019CF8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02019BBC  0x02019BBC  thumb
 *
 * Plain forwarder to func_02019BBC (ldr r3, =target; bx r3).  Callee of
 * ov170 func_021DD718.
 */

extern unsigned int func_02019BBC(unsigned int item);

unsigned int func_02019CF8(unsigned int item)
{
    return func_02019BBC(item);
}
