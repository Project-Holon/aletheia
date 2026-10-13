/*
 * function: DWCi_SCREENlSetPalette
 * address:  0x021CE818
 * packet:   pkt_021CE050
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SCREENlSetPalette   0x021CE818  arm
 *   DWCi_TSKlForm  0x021D7680  arm
 *
 * Record v and hand the companion entry point to the timer helper.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SCREENlSetPalette.c \
 *       --func DWCi_SCREENlSetPalette --addr 0x021CE818 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021CE844(void *task);
extern void DWCi_TSKlForm(unsigned int, void *, unsigned int, unsigned int);

void DWCi_SCREENlSetPalette(unsigned int v)
{
    char *g = (char *)0x021DE630;
    *(unsigned int *)(g + 4) = v;
    DWCi_TSKlForm(1, func_021CE844, 0, 0x78);
}
