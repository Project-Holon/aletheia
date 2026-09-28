/*
 * function: func_021B7D0C
 * address:  0x021B7D0C
 * packet:   pkt_ov104_021B7D0C
 * region:   ov104
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Thumb long-branch veneer in a .word run:
 *   ldr r3,[pc,#0]; bx r3; .word 0x0204A600
 * Declared as an ordinary tail-call extern at the veneer address.
 *
 * symbols:
 *   func_0204A600  0x0204A600  arm
 */

extern void func_0204A600(int);

void func_021B7D0C(int x)
{
    func_0204A600(x);
}
