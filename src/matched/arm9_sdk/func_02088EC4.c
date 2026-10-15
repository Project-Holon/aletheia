/*
 * function: RtcGetResultCallback
 * address:  0x02088EC4
 * packet:   pkt_02088EC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     librtc external.o RtcGetResultCallback.
 *
 * symbols:
 *   g_02151428  0x02151428  data  a4
 */

extern int g_02151428[];

void RtcGetResultCallback(int result)
{
    g_02151428[9] = result;
}
