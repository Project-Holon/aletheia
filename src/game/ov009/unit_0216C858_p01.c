/*
 * file:     unit_0216C858_p01.c
 * unit:     yes
 * function: DWC_CancelMatch
 * address:  0x0216C858
 * packet:   pkt_ov009_0216C858
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_CancelMatch (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWC_IsValidCancelMatch  0x0216C890 arm
 *   DWCi_DoCancelMatch      0x021728B8 arm
 *   DWCi_GetMatchCnt        0x02175F3C arm
 */

typedef unsigned char u8;

struct DWCstMatchControl
{
    u8 pad0[0x7b5];
    u8 cancelFromConnection;
};

extern int DWC_IsValidCancelMatch(void);
extern void DWCi_DoCancelMatch(void);
extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);

int DWC_CancelMatch(void)
{
    int bRet;

    if (DWC_IsValidCancelMatch()) {
        DWCi_DoCancelMatch();
        bRet = 1;
    } else {
        DWCi_GetMatchCnt();
        bRet = 0;
    }
    DWCi_GetMatchCnt()->cancelFromConnection = 0;
    return bRet;
}
