/*
 * function: sakeiStartCreateRecordRequest
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
 *   sCreateRecordRequestInfo  0x021E39A0  data
 *   sakeiStartRequest  0x021DDB10  arm
 */

extern int sakeiStartRequest(void *, int);
extern char sCreateRecordRequestInfo[];

void sakeiStartCreateRecordRequest(void *p)
{
    sakeiStartRequest(p, (int)sCreateRecordRequestInfo);
}
