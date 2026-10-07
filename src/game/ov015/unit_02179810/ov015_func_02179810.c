/*
 * function: DWCi_IsShutdownMatch
 * address:  0x02179810
 * packet:   pkt_ov015_02179810
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * sdk:      DWCi_IsShutdownMatch (libdwcmatch.TWL.HYB.thumb.a(dwc_match.o))
 *
 * symbols:
 *   DWCi_GetMatchCnt  0x021799F0  thumb  ov015
 */

extern void *DWCi_GetMatchCnt(void);

int DWCi_IsShutdownMatch(void)
{
    if (DWCi_GetMatchCnt() == 0)
        return 1;
    return 0;
}
