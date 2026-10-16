/*
 * function: DWC_ScGetSessionId
 * address:  0x021DF20C
 * packet:   pkt_ov175_021DF20C
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_ScGetSessionId (dwc_sc.o)
 *
 * scGetSessionId is the ARM leaf at 0x021DFA98 (add r0,r0,#0x5c; bx lr). It
 * had no listing label (disasm.py emitted a .word run); it is now seeded in
 * layout/function_starts.txt, so it attests as a code label.
 *
 * symbols:
 *   s_callback       0x021e4d08  data
 *   scGetSessionId   0x021dfa98  arm   ov175
 */

extern int s_callback[];
extern unsigned char *scGetSessionId(int);

unsigned char *DWC_ScGetSessionId(void)
{
    return scGetSessionId(s_callback[1]);
}
