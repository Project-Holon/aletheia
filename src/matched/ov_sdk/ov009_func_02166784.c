/*
 * function: func_02166784
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
 *   g_021AA814  0x021AA814  data ov009
 *   g_021AA815  0x021AA815  data ov009
 *
 * Averages the sheltered RSSI ring buffer: 16 samples once the ring is full, otherwise the samples stored so far.
 */

extern unsigned char g_021AA814;
extern unsigned char g_021AA815[16];
extern void _s32_div_f();

unsigned char func_02166784(void)
{
    long sum;
    long i;

    sum = 0;
    if (g_021AA814 > 16) {
        for (i = 0; i < 16; i++) {
            sum += g_021AA815[i];
        }
        sum = sum / 16;
    } else if (g_021AA814 != 0) {
        for (i = 0; i < g_021AA814; i++) {
            sum += g_021AA815[i];
        }
        sum = sum / g_021AA814;
    }
    return (unsigned char)sum;
}
