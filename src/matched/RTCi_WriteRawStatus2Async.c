/*
 * function: RTCi_WriteRawStatus2Async
 * address:  0x02088F1C
 * packet:   pkt_02088F1C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK librtc external.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 *
 * symbols:
 *   RtcSendPxiCommand  0x02088F2C  arm
 */

extern int RtcSendPxiCommand(unsigned long command);

int RTCi_WriteRawStatus2Async(void)
{
    return RtcSendPxiCommand(0x27);
}
