/*
 * function: func_021B6A30
 * address:  0x021B6A30
 * packet:   pkt_021C12F4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Packs the halfwords of src[0..n) into nibble pairs through func_021B6ADC and
 * writes the pair bytes to dst.
 *
 * symbols:
 *   func_021B6ADC  0x021B6ADC  thumb  ov172
 *
 * Addresses are Black-image addresses.
 */

typedef signed char    s8;
extern s8 func_021B6ADC(int sample, char *p);

void func_021B6A30(short *src, unsigned char *dst, int n, int ctx)
{
    int i;
    int out = 0;
    int pend = 0;
    int have = 0;

    for (i = 0; i < n; i++) {
        unsigned char v = (unsigned char)func_021B6ADC(src[i], (char *)ctx);

        if (have == 0) {
            pend = v;
            have = 1;
        } else {
            have = 0;
            dst[out] = (unsigned char)(pend + ((v & 0xf) << 4));
            pend = 0;
            out++;
        }
    }

    if (have == 1)
        dst[out] = (unsigned char)pend;
}
