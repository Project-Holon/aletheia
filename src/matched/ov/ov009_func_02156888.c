/*
 * function: DWC_RAP_StartFriendMatch
 * address:  0x02156888
 * packet:   pkt_ov009_02156888
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _pRapWork     0x021A8264  data  ov009  a4
 *   DWC_RAP_IsUserDataChanged  0x02156C84  thumb  ov009
 *   DWC_RAP_FreeRecvBuffers  0x02156C60  thumb  ov009
 *   GFL_NET_GetUserArg  0x0203D650  arm
 *   DWC_SetupGameServer  0x0216B354  arm  ov009
 *   DWC_ConnectToGameServerAsync  0x0216B408  arm  ov009
 *   DWC_RAP_OnFriendServerMatched  0x02156A58  thumb  ov009
 *   DWC_RAP_OnFriendClientMatched  0x02156B18  thumb  ov009
 *   DWC_RAP_OnNewClient  0x02156B3C  thumb  ov009
 *   DWC_RAP_AttemptCallback  0x02155678  thumb  ov009
 *   GFL_NET_STATE_SetError  0x0203C9AC  arm
 *   DWC_RAP_AllocRecvBuffer  0x02156C00  thumb  ov009
 *   DWC_RAP_SetState  0x02155374  thumb  ov009
 *   DWC_SetUserSendCallback  0x02177138  arm  ov009
 *   DWC_SetUserRecvCallback  0x02177160  arm  ov009
 *   DWC_SetConnectionClosedCallback  0x0216B634  arm  ov009
 *   DWC_SetUserRecvTimeoutCallback  0x02177188  arm  ov009
 *   DWC_RAP_OnSendComplete  0x02155D80  thumb  ov009
 *   DWC_RAP_OnReceive  0x02155DCC  thumb  ov009
 *   DWC_RAP_OnConnectionClosed  0x02155E9C  thumb  ov009
 *   DWC_RAP_OnReceiveTimeout  0x02155BDC  thumb  ov009
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    char pad[0x750];
    int f750;           /* 0x750 */
    int state;          /* 0x754 */
    char pad1[0x75c - 0x758];
    int f75c;           /* 0x75c */
    int f760;           /* 0x760 */
    int n;              /* 0x764 */
    char pad2[0x770 - 0x768];
    int aid;            /* 0x770 */
    char pad3[0x778 - 0x774];
    int f778;           /* 0x778 */
    char pad4[0x780 - 0x77c];
    short s780;         /* 0x780 */
    char pad5[0x78c - 0x782];
    int retry;          /* 0x78c */
    char pad6[0x798 - 0x790];
    int f798;           /* 0x798 */
    char pad7[0x7a1 - 0x79c];
    u8 b7a1;            /* 0x7a1 */
} G;

extern G *_pRapWork;
unsigned char DWC_RAP_IsUserDataChanged(void);
void DWC_RAP_FreeRecvBuffers(void);
u32 GFL_NET_GetUserArg(void);
int DWC_SetupGameServer(int topology, unsigned char maxEntry, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *attemptCallback, void *connectionUserData, void *attemptParam);
int DWC_ConnectToGameServerAsync(int, int, void *, u32, void *, u32, void *, int *, u32);
void DWC_RAP_OnFriendServerMatched(int a, int b, int c, int d, int e);
void DWC_RAP_OnFriendClientMatched(int a, int b, int c, int d, int e);
void DWC_RAP_OnNewClient(int a);
u8 DWC_RAP_AttemptCallback(void);
void GFL_NET_STATE_SetError(int a, u32 b, u32 c, u32 d);
void DWC_RAP_AllocRecvBuffer(u32 a);
void DWC_RAP_SetState(int);
int DWC_SetUserSendCallback(int a, int b);
int DWC_SetUserRecvCallback(int a, int b);
int DWC_SetConnectionClosedCallback(int a, int b);
int DWC_SetUserRecvTimeoutCallback(int a, int b);
void DWC_RAP_OnSendComplete(int a, u32 i);
void DWC_RAP_OnReceive(u32 a, u8 *p, int c);
void DWC_RAP_OnConnectionClosed(int a, int b, int c, u32 d);
void DWC_RAP_OnReceiveTimeout(unsigned int n);

int DWC_RAP_StartFriendMatch(int a, int b, int c)
{
    int n = b;
    int r;
    int i;

    if (DWC_RAP_IsUserDataChanged() != 0)
        return -4;
    if (_pRapWork->state != 6) {
        _pRapWork->retry++;
        if (_pRapWork->retry > 0x78)
            return -3;
        return -1;
    }
    DWC_RAP_FreeRecvBuffers();
    _pRapWork->f798 = 0;
    _pRapWork->b7a1 = 1;
    _pRapWork->aid = a;
    _pRapWork->n = b;
    _pRapWork->s780 = -1;
    if (c != 0)
        n = 2;
    _pRapWork->f778 = 1;
    if (a < 0) {
        r = DWC_SetupGameServer(2, n, DWC_RAP_OnFriendServerMatched, (void *)GFL_NET_GetUserArg(), DWC_RAP_OnNewClient,
                          (void *)GFL_NET_GetUserArg(), DWC_RAP_AttemptCallback, &_pRapWork->f750,
                          (void *)GFL_NET_GetUserArg());
        _pRapWork->f75c = 1;
    } else {
        r = DWC_ConnectToGameServerAsync(2, a, DWC_RAP_OnFriendClientMatched, 0, DWC_RAP_OnNewClient,
                          GFL_NET_GetUserArg(), DWC_RAP_AttemptCallback, &_pRapWork->f750,
                          GFL_NET_GetUserArg());
        _pRapWork->f75c = 2;
    }
    if (r == 0) {
        _pRapWork->retry++;
        if (_pRapWork->retry > 0x78)
            GFL_NET_STATE_SetError(0, 0, 0, 0x3f1);
        return -2;
    }
    _pRapWork->retry = 0;
    for (i = 0; i < b; i++)
        DWC_RAP_AllocRecvBuffer(i);
    DWC_RAP_SetState(7);
    DWC_SetUserSendCallback((int)DWC_RAP_OnSendComplete, 0);
    DWC_SetUserRecvCallback((int)DWC_RAP_OnReceive, 0);
    DWC_SetConnectionClosedCallback((int)DWC_RAP_OnConnectionClosed, 0);
    DWC_SetUserRecvTimeoutCallback((int)DWC_RAP_OnReceiveTimeout, 0);
    _pRapWork->f760 = 0;
    return 0;
}
