/*
 * function: func_021BA194
 * address:  0x021BA194
 * packet:   pkt_ov172_021BA194
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Zero-fills n words, then runs CTVT_ADPCM_Decode over the buffer.
 *
 * symbols:
 *   func_02082A7C  0x02082A7C  arm
 *   CTVT_ADPCM_Decode  0x021B6A18  thumb  ov172
 *
 * Addresses are Black-image addresses.
 */

extern void func_02082A7C(int v, void *p, unsigned n);
extern int CTVT_ADPCM_Decode(int a, int b, int c);

int func_021BA194(int unused, int a, void *buf, unsigned n)
{
    func_02082A7C(0, buf, n << 2);
    return CTVT_ADPCM_Decode(a, (int)n, (int)buf);
}
