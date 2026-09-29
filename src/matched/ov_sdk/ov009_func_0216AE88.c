/*
 * function: DWC_ProcessFriendsMatch
 * address:  0x0216AE88
 * packet:   pkt_ov009_0216AE88
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_ProcessFriendsMatch (libdwcmatch.TWL.HYB.a(dwc_main.o))
 *
 * symbols:
 *   DWC_UpdateConnection               0x0205D074  arm
 *   DWCi_IsError                       0x02059F38  arm
 *   GSIAvailableCheckThink             0x0217C900  arm
 *   gpInitialize                       0x021858FC  arm
 *   DWCi_HandleGPError                 0x0216BD04  arm
 *   gpSetCallback                      0x0218597C  arm
 *   DWCi_SetState                      0x0216BC84  arm
 *   DWCi_LoginAsync                    0x0216A278  arm
 *   DWCi_StopLogin                     0x0216A3B8  arm
 *   DWCi_LoginProcess                  0x0216A2B0  arm
 *   DWCi_FriendProcess                 0x02168AD4  arm
 *   DWCi_MatchProcess                  0x0216D57C  arm
 *   DWCi_TransportProcess              0x021773D8  arm
 *   qr2_shutdown                       0x0219B540  arm
 *   stLastSocketError                  0x021AA878  data
 *   DWCi_GPErrorCallback               0x0216C08C  arm
 *   DWCi_GPRecvBuddyMessageCallback    0x0216C0C4  arm
 *   DWCi_GPRecvBuddyAuthCallback       0x02168F18  arm
 *   DWCi_GPRecvBuddyRequestCallback    0x02168ECC  arm
 *   DWCi_GPRecvBuddyStatusCallback     0x02168F4C  arm
 */

typedef unsigned char u8;

struct DWCstDwcCnt
{
    u8 pad0[0x1c];
    void *gp;                       /* +0x1c */
    u8 pad1[4];
    int state;                      /* +0x24 */
    u8 pad2[0x98 - 0x28];
    int field98;                    /* +0x98 */
    u8 pad3[0x360 - 0x9c];
    void *qr2;                      /* +0x360 */
    volatile u8 status364;          /* +0x364 */
    u8 pad4[0x39c - 0x365];
    u8 flag39c;                     /* +0x39c */
};

struct DWCstGlobal
{
    int lastSocketError;            /* +0x00 */
    struct DWCstDwcCnt *pDwc;       /* +0x04 */
};

extern struct DWCstGlobal stLastSocketError;

extern int DWC_UpdateConnection(void);
extern int DWCi_IsError(void);
extern int GSIAvailableCheckThink(void);
extern int gpInitialize(void **connection, int productID, int namespaceID, int partnerID);
extern int DWCi_HandleGPError(int result);
extern int gpSetCallback(void **connection, int func, void (*callback)(void **, void *, void *), void *param);
extern void DWCi_SetState(int state);
extern int DWCi_LoginAsync(void);
extern void DWCi_StopLogin(int error, int errorCode);
extern void DWCi_LoginProcess(void);
extern void DWCi_FriendProcess(void);
extern void DWCi_MatchProcess(int fullSpec);
extern void DWCi_TransportProcess(void);
extern void qr2_shutdown(void *qrec);
extern void DWCi_GPErrorCallback(void **, void *, void *);
extern void DWCi_GPRecvBuddyMessageCallback(void **, void *, void *);
extern void DWCi_GPRecvBuddyAuthCallback(void **, void *, void *);
extern void DWCi_GPRecvBuddyRequestCallback(void **, void *, void *);
extern void DWCi_GPRecvBuddyStatusCallback(void **, void *, void *);

void DWC_ProcessFriendsMatch(void)
{
    DWC_UpdateConnection();
    if (stLastSocketError.pDwc == 0 || stLastSocketError.pDwc->state == 0)
        return;
    if (DWCi_IsError())
        return;

    switch (stLastSocketError.pDwc->state)
    {
    case 0:
        break;
    case 1:
        switch (GSIAvailableCheckThink())
        {
        case 1:
            if (DWCi_HandleGPError(gpInitialize(&stLastSocketError.pDwc->gp,
                    stLastSocketError.pDwc->field98, 0x10, 0xb)))
                return;
            if (DWCi_HandleGPError(gpSetCallback(&stLastSocketError.pDwc->gp,
                    0, DWCi_GPErrorCallback, 0)))
                return;
            if (DWCi_HandleGPError(gpSetCallback(&stLastSocketError.pDwc->gp,
                    3, DWCi_GPRecvBuddyMessageCallback, 0)))
                return;
            if (DWCi_HandleGPError(gpSetCallback(&stLastSocketError.pDwc->gp,
                    7, DWCi_GPRecvBuddyAuthCallback, 0)))
                return;
            if (DWCi_HandleGPError(gpSetCallback(&stLastSocketError.pDwc->gp,
                    1, DWCi_GPRecvBuddyRequestCallback, 0)))
                return;
            if (DWCi_HandleGPError(gpSetCallback(&stLastSocketError.pDwc->gp,
                    2, DWCi_GPRecvBuddyStatusCallback, 0)))
                return;
            DWCi_SetState(2);
            if (DWCi_LoginAsync() == 0)
                DWCi_StopLogin(2, 0xffffb17c);
            break;
        case 2:
            DWCi_StopLogin(3, 0xffffb172);
            return;
        case 3:
            DWCi_StopLogin(4, 0xffffb17b);
            return;
        }
        break;
    case 2:
        DWCi_LoginProcess();
        break;
    case 3:
        DWCi_FriendProcess();
        DWCi_MatchProcess(0);
        break;
    case 4:
        DWCi_MatchProcess(1);
        DWCi_FriendProcess();
        break;
    case 5:
        DWCi_TransportProcess();
        DWCi_FriendProcess();
        if (stLastSocketError.pDwc->status364 == 2
                || stLastSocketError.pDwc->status364 == 3)
            DWCi_MatchProcess(1);
        else if (*(int *)stLastSocketError.pDwc != 0)
            DWCi_MatchProcess(0);
        break;
    }

    if (stLastSocketError.pDwc->flag39c == 1)
    {
        if (stLastSocketError.pDwc->qr2 != 0)
        {
            qr2_shutdown(stLastSocketError.pDwc->qr2);
            stLastSocketError.pDwc->qr2 = 0;
        }
        stLastSocketError.pDwc->flag39c = 0;
    }
}
