/*
 * function: MIC_GetLastSamplingAddress
 * address:  0x0208B4B8
 * packet:   pkt_0208B4B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MIC_GetLastSamplingAddress (libspi.TWL.HYB.a mic.o)
 */

void *MIC_GetLastSamplingAddress(void)
{
    return *(void **)0x02FFFF90;
}
