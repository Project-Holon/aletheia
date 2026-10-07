/*
 * function: DWC_IsValidCancelMatch
 * address:  0x0216C890
 * packet:   pkt_ov009_0216C890
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_IsValidCancelMatch (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWCi_IsError      0x02059F38 arm
 *   DWCi_GetMatchCnt  0x02175F3C arm
 *   DWC_GetState      0x0216B994 arm
 */

typedef unsigned char u8;

struct DWCstMatchControl
{
    u8 pad0[0x62a];
    u8 cancelState;
};

extern int DWCi_IsError(void);
extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);
extern int DWC_GetState(void);

int DWC_IsValidCancelMatch(void)
{
    if (DWCi_IsError())
        return 0;
    if (DWCi_GetMatchCnt() == 0 ||
        DWC_GetState() != 4 ||
        DWCi_GetMatchCnt()->cancelState != 0)
        return 0;
    return 1;
}
