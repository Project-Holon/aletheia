/*
 * function: sakeiStartGetSpecificRecordsRequest
 * address:  0x021DECE8
 * packet:   pkt_ov175_021DECE8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK provenance: DSP_MapProcessSegment (TwlSDK/libdsp.TWL.HYB.a, dsp_process.o),
 * ov175.  ARM tail-forwarder to sakeiStartRequest with a fixed second argument.
 *
 * symbols:
 *   sGetSpecificRecordsRequestInfo  0x021E3C78  data
 *   sakeiStartRequest  0x021DDB10  arm
 */

extern int sakeiStartRequest(void *, int);
extern char sGetSpecificRecordsRequestInfo[];

void sakeiStartGetSpecificRecordsRequest(void *p)
{
    sakeiStartRequest(p, (int)sGetSpecificRecordsRequestInfo);
}
