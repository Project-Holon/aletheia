/*
 * function: DWCi_IsShutdownMatch
 * address:  0x068982AC
 * packet:   pkt_ov095_068982AC
 * region:   ov095
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * sdk:      DWCi_IsShutdownMatch (libdwcmatch.TWL.HYB.thumb.a(dwc_match.o))
 *
 * symbols:
 *   DWCi_GetMatchCnt  0x068982C0  thumb  ov095
 */

extern void *DWCi_GetMatchCnt(void);

int DWCi_IsShutdownMatch(void)
{
    if (DWCi_GetMatchCnt() == 0)
        return 1;
    return 0;
}
