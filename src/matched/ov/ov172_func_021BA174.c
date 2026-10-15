/*
 * function: CTVT_MIC_EncodeAdpcm
 * address:  0x021BA174
 * packet:   pkt_ov172_021BA174
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Zero-fills a byte buffer, then runs CTVT_ADPCM_Encode over it.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   CTVT_ADPCM_Encode  0x021B6A00  thumb  ov172
 *
 * Addresses are Black-image addresses.
 */

extern void MI_CpuFill8(void *p, int v, int n);
extern int CTVT_ADPCM_Encode(void *a0, unsigned a1, void *a2);

int CTVT_MIC_EncodeAdpcm(int unused, void *a, void *buf, unsigned n)
{
    MI_CpuFill8(buf, 0, n);
    return CTVT_ADPCM_Encode(a, n, buf);
}
