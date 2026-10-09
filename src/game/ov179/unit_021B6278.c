/*
 * file:     unit_021B6278.c
 * function: OSi_VBlankIntr
 * address:  0x021B6278
 * packet:   pkt_ov179_021B6278
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * sdk:      OSi_VBlankIntr (libos.TWL.LTD.thumb.a(os_attention.o))
 *
 * symbols:
 *   SDK_AUTOLOAD_DTCM_START 0x02fe0000 data
 */

extern unsigned int SDK_AUTOLOAD_DTCM_START;

void OSi_VBlankIntr(void)
{
    *(volatile unsigned int *)((char *)&SDK_AUTOLOAD_DTCM_START + 0x3FF8) |= 1;
}
