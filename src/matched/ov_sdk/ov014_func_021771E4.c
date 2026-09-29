/*
 * function: DWCi_IsShutdownMatch
 * address:  0x021771E4
 * packet:   pkt_ov014_021771E4
 * region:   ov014
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * sdk:      DWCi_IsShutdownMatch (libdwcmatch.TWL.HYB.thumb.a(dwc_match.o))
 *
 * symbols:
 *   DWCi_GetMatchCnt  0x02177A94  thumb  ov014
 */

extern void *DWCi_GetMatchCnt(void);

int DWCi_IsShutdownMatch(void)
{
    if (DWCi_GetMatchCnt() == 0)
        return 1;
    return 0;
}
