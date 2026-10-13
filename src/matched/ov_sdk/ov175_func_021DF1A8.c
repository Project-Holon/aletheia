/*
 * function: DWCi_ScSubmitReportCallback
 * address:  0x021DF1A8
 * packet:   pkt_021DF1A8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gDwcScControl  0x021E4D08  data
 *
 * Invoke the fifth entry of the 0x021E4D08 dispatch block with the caller's
 * third and fourth arguments.
 */

typedef unsigned long u32;

extern u32 gDwcScControl[];

void DWCi_ScSubmitReportCallback(int a, int b, int c, int d)
{
    void (*fn)(int, int) = (void (*)(int, int))gDwcScControl[4];

    fn(c, d);
}

