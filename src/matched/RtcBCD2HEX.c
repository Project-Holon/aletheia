/*
 * function: RtcBCD2HEX
 * address:  0x02088E5C
 * packet:   pkt_02088E5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * TwlSDK librtc external.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 */

unsigned long RtcBCD2HEX(unsigned long bcd)
{
    unsigned long hex = 0;
    long i;
    long w;

    for (i = 0; i < 8; i++) {
        if (((bcd >> (i * 4)) & 0xF) >= 10)
            return 0;
    }
    for (i = 0, w = 1; i < 8; i++) {
        hex += ((bcd >> (i * 4)) & 0xF) * w;
        w *= 10;
    }
    return hex;
}
