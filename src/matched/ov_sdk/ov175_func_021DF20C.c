/*
 * function: DWC_ScGetConnectionId
 * address:  0x021DF20C
 * packet:   pkt_ov175_021DF20C
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_ScGetConnectionId (dwc_sc.o)
 *
 * scGetConnectionId is an unlabelled ARM leaf at 0x021DFA98 (add r0,r0,#0x5c;
 * bx lr) that disasm.py emits as a .word run, so it attests as sole-ref/data
 * with the ov175 hint rather than a code label.
 *
 * symbols:
 *   s_callback         0x021e4d08  data
 *   scGetConnectionId  0x021dfa98  data  ov175
 */

extern int s_callback[];
extern unsigned char *scGetConnectionId(int);

unsigned char *DWC_ScGetConnectionId(void)
{
    return scGetConnectionId(s_callback[1]);
}
