/*
 * function: func_021BEFCC
 * address:  0x021BEFCC
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021B9B58  0x021B9B58  arm  ov114
 *
 * unblocked: func_021B9B58 (the ARM veneer `ldr ip,[pc]; bx ip; .word
 *   0x02086028`, printed as a .word run in ov114) was matched as the same
 *   far-tail-call shape and filed as pkt_ov114_021B9B58; the ABS32 site then
 *   attests as `matched, overlay`.
 *
 * Tail-call thunk to the ARM stub at 0x021B9B58.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021B9B58(void);

void func_021BEFCC(void)
{
    func_021B9B58();
}
