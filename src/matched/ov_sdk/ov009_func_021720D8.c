/*
 * function: DWCi_CancelPreConnectedServerProcess
 * address:  0x021720D8
 * packet:   pkt_ov009_021720D8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CancelPreConnectedServerProcess (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWCi_GetMatchCnt                                  0x02175F3C arm
 *   DWCi_CancelPreConnectedServerProcessWithResetLevel 0x02171FD4 arm
 */

typedef unsigned char u8;

struct DWCstMatchControl
{
    u8 pad0[0xd];
    u8 connectedOnceBefore;  /* +0xd */
    u8 pad1[0x15 - 0xe];
    u8 qr2MatchTypeExt;      /* +0x15 */
};

extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);
extern int DWCi_CancelPreConnectedServerProcessWithResetLevel(int clientPid, int resetLevel);

int DWCi_CancelPreConnectedServerProcess(int clientPid)
{
    int resetLevel = 2;

    if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 0 ||
        DWCi_GetMatchCnt()->qr2MatchTypeExt == 1) {
        if (DWCi_GetMatchCnt()->connectedOnceBefore == 0)
            resetLevel = 1;
    }
    return DWCi_CancelPreConnectedServerProcessWithResetLevel(clientPid, resetLevel);
}
