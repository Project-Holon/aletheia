/*
 * function: DWCi_ProcessMatchSCClosing
 * address:  0x0216F1E8
 * packet:   pkt_ov009_0216F1E8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ProcessMatchSCClosing (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWCi_GetMatchCnt                  0x02175F3C arm
 *   DWCi_CancelPreConnectedServerProcess 0x021720D8 arm
 */

typedef unsigned char u8;

struct DWCstMatchControl
{
    u8 pad0[0x629];
    u8 closeState;
};

extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);
extern int DWCi_CancelPreConnectedServerProcess(int clientPid);

void DWCi_ProcessMatchSCClosing(int clientPid)
{
    if (DWCi_GetMatchCnt()->closeState == 1)
        return;
    DWCi_CancelPreConnectedServerProcess(clientPid);
}
