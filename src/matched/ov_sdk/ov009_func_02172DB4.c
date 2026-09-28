/*
 * function: DWCi_RestartFromTimeout
 * address:  0x02172DB4
 * packet:   pkt_ov009_02172DB4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_RestartFromTimeout (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWCi_GetMatchCnt                  0x02175F3C arm
 *   DWCi_CloseAllConnectionsByTimeout 0x02172E7C arm
 *   DWCi_RestartFromCancel            0x02172BB8 arm
 */

typedef unsigned char u8;

struct DWCstMatchControl
{
    u8 pad0[0x15];
    u8 qr2MatchTypeExt;
};

extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);
extern void DWCi_CloseAllConnectionsByTimeout(void);
extern void DWCi_RestartFromCancel(int level);

void DWCi_RestartFromTimeout(void)
{
    if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 2)
        return;
    if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 3)
        return;
    DWCi_CloseAllConnectionsByTimeout();
    DWCi_RestartFromCancel(1);
}
