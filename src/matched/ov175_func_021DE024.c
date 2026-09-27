/*
 * function: func_021DE024
 * address:  0x021DE024
 * packet:   pkt_ov175_021DE024
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK provenance: DSP_MapProcessSegment (TwlSDK/libdsp.TWL.HYB.a, dsp_process.o),
 * ov175.  ARM tail-forwarder: r0 is passed through, the constant data pointer
 * goes in as the second argument.
 *
 * symbols:
 *   d_021E39A0  0x021E39A0  data
 */

extern int func_021DDB10(void *, int);
extern char d_021E39A0[];

void func_021DE024(void *p)
{
    func_021DDB10(p, (int)d_021E39A0);
}
