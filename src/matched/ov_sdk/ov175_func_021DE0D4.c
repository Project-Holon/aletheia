/*
 * function: func_021DE0D4
 * address:  0x021DE0D4
 * packet:   pkt_ov175_021DE0D4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK provenance: DSP_MapProcessSegment (TwlSDK/libdsp.TWL.HYB.a, dsp_process.o),
 * ov175.  ARM tail-forwarder to func_021DDB10 with a fixed second argument.
 *
 * symbols:
 *   d_021E3978  0x021E3978  data
 */

extern int func_021DDB10(void *, int);
extern char d_021E3978[];

void func_021DE0D4(void *p)
{
    func_021DDB10(p, (int)d_021E3978);
}
