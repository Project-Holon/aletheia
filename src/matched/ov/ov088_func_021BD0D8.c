/*
 * function: func_021BD0D8
 * address:  0x021BD0D8
 * packet:   pkt_ov088_021BD0D8
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020419E4  0x020419E4  arm
 *   SDK_AUTOLOAD_DTCM_START 0x02fe0000 data
 */

extern void func_020419E4(void);
extern unsigned int SDK_AUTOLOAD_DTCM_START;

void func_021BD0D8(void)
{
    func_020419E4();
    *(volatile unsigned int *)((char *)&SDK_AUTOLOAD_DTCM_START + 0x3FF8) |= 1;
}
