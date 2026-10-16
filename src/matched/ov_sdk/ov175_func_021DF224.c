/*
 * function: DWC_ScGetConnectionId
 * address:  0x021DF224
 * packet:   pkt_021DF224
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gDwcScControl     0x021E4D08  data
 *   scGetConnectionId  0x021DFAA0  arm  ov175
 *
 * One-line tail thunk: the object's +4 word is forwarded to the +0x84 accessor
 * that sits at the tail of scThink's extent.
 */

typedef unsigned int u32;

extern u32  gDwcScControl[];
extern u32 scGetConnectionId(u32 p);

void DWC_ScGetConnectionId(void)
{
    scGetConnectionId(gDwcScControl[1]);
}
