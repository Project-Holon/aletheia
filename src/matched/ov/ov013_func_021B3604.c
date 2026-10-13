/*
 * function: VCT_DSP_SuppressEchoWithReference
 * address: 0x021B3604
 * packet: pkt_ov013_021B3604
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   gEchoReferenceFrame 0x021B4C8C data a4
 *   VCT_DSP_SuppressEcho 0x021B33F8 arm ov013
 */
extern short gEchoReferenceFrame[];
extern void VCT_DSP_SuppressEcho(short *,short *,unsigned int,unsigned int);
void VCT_DSP_SuppressEchoWithReference(short *a,unsigned int b,unsigned int c)
{
    VCT_DSP_SuppressEcho(a,gEchoReferenceFrame,b,c);
}
