/*
 * function: DWC_RAPUTIL_ResetSystem
 * address:  0x021B6184
 * packet:   pkt_021B6184
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DWC_RAPUTIL_ResetSystem   0x021B6184  thumb
 *   OS_ResetSystem  0x02087BCC  arm  arm9
 *
 * Call OS_ResetSystem with 0, then return 1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWC_RAPUTIL_ResetSystem.c \
 *       --func DWC_RAPUTIL_ResetSystem --addr 0x021B6184 --region ov016 --cc dsi/1.1p1 --thumb
 */

extern void OS_ResetSystem(unsigned int);

int DWC_RAPUTIL_ResetSystem(void)
{
    OS_ResetSystem(0);
    return 1;
}
