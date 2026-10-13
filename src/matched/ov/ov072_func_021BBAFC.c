/*
 * function: TOWNMAP_GRH_DrawClactSystem
 * address:  0x021BBAFC
 * packet:   pkt_ov072_021BBAFC
 * region:   ov072
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
 *   CLACT_DrawSystem  0x0204A600  arm
 */

extern void CLACT_DrawSystem(int);

void TOWNMAP_GRH_DrawClactSystem(int x)
{
    CLACT_DrawSystem(x);
}
