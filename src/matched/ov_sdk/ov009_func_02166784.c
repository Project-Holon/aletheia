/*
 * function: WCMi_GetRssiAverage
 * address:  0x02166784
 * packet:   pkt_ov009_02166784
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCMi_GetRssiAverage (libwcm.TWL.HYB.a util.o)
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 *   gWcmUtilLength  0x021AA814  data ov009
 *   gWcmUtilData  0x021AA815  data ov009
 *
 * Averages the sheltered RSSI ring buffer: 16 samples once the ring is full, otherwise the samples stored so far.
 */

extern unsigned char gWcmUtilLength;
extern unsigned char gWcmUtilData[16];
extern void _s32_div_f();

unsigned char WCMi_GetRssiAverage(void)
{
    long sum;
    long i;

    sum = 0;
    if (gWcmUtilLength > 16) {
        for (i = 0; i < 16; i++) {
            sum += gWcmUtilData[i];
        }
        sum = sum / 16;
    } else if (gWcmUtilLength != 0) {
        for (i = 0; i < gWcmUtilLength; i++) {
            sum += gWcmUtilData[i];
        }
        sum = sum / gWcmUtilLength;
    }
    return (unsigned char)sum;
}
