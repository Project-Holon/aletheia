/*
 * function: DWC_RAP_StartMatchWithKey
 * address:  0x0215568C
 * packet:   pkt_ov009_0215568C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sibling of DWC_RAP_StartMatchWithFilter: in state 6, formats a 0x80-byte name at +0x2AC,
 * resets n slots, enters state 7 and hands DWC_ConnectToAnybodyAsync (mode 2) and three
 * registrars the ov009 callbacks.
 *
 * The four callback leaves it passes were unlabelled; their own EXACT
 * shards (wave 2) witness them.
 *
 * symbols:
 *   _pRapWork     0x021A8264  data  ov009  a4
 *   d_021A1C5C     0x021A1C5C  data  ov009  a1
 *   d_021A1C74     0x021A1C74  data  ov009  a1
 *   d_021A1974     0x021A1974  data  ov009  a1
 *   func_02034714  0x02034714  arm
 *   DWC_RAP_FreeRecvBuffers  0x02156C60  thumb  ov009
 *   DWC_AddMatchKeyString  0x0216CA04  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   sprintf  0x02094530  arm
 *   GF_STANDARD_GetStringLength  0x0203F004  arm
 *   DWC_RAP_AllocRecvBuffer  0x02156C00  thumb  ov009
 *   DWC_RAP_SetState  0x02155374  thumb  ov009
 *   GFL_NET_GetUserArg  0x0203D650  arm
 *   DWC_ConnectToAnybodyAsync  0x0216B284  arm
 *   DWC_SetUserSendCallback  0x02177138  arm
 *   DWC_SetUserRecvCallback  0x02177160  arm
 *   DWC_SetConnectionClosedCallback  0x0216B634  arm
 *   DWC_SetUserRecvTimeoutCallback  0x02177188  arm
 *   DWC_RAP_OnNewClientNop  0x02155674  thumb  ov009
 *   DWC_RAP_AttemptCallback  0x02155678  thumb  ov009
 *   DWC_RAP_OnMatched  0x02155D3C  thumb  ov009
 *   DWC_RAP_EvalCallbackAccept  0x02155D7C  thumb  ov009
 *   DWC_RAP_OnSendComplete  0x02155D80  thumb  ov009
 *   DWC_RAP_OnReceive  0x02155DCC  thumb  ov009
 *   DWC_RAP_OnConnectionClosed  0x02155E9C  thumb  ov009
 *   DWC_RAP_OnReceiveTimeout  0x02155BDC  thumb  ov009
 */

typedef unsigned char  u8;

typedef struct {
    char pad0[0x2AC];
    char name[0x80];
    char pad32C[0x750 - 0x32C];
    int w750;
    int state;
    int w758;
    int w75C;
    int w760;
    int n;
    char pad768[0x7A1 - 0x768];
    u8 b7A1;
} G;

typedef void (*Fn)(void);

extern G *_pRapWork;
extern char d_021A1C5C[];
extern char d_021A1C74[];
extern char d_021A1974[];
typedef unsigned int   u32;
void func_02034714(const char *expr, u32 line, const char *file);
void DWC_RAP_FreeRecvBuffers(void);
u8 DWC_AddMatchKeyString(u8 keyID, char *keyString, char *valueSrc);
void MI_CpuFill8(void *p, int v, int n);
u32 sprintf(char *dst, u32 n, ...);
u32 GF_STANDARD_GetStringLength(const u8 *s);
void DWC_RAP_AllocRecvBuffer(u32 a);
void DWC_RAP_SetState(int v);
u32 GFL_NET_GetUserArg(void);
int DWC_ConnectToAnybodyAsync(int topology, unsigned char maxEntry, char *addFilter, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *evalCallback, void *evalParam, void *attemptCallback, void *connectionUserData, void *attemptParam);
int DWC_SetUserSendCallback(int a, int b);
int DWC_SetUserRecvCallback(int a, int b);
int DWC_SetConnectionClosedCallback(int a, int b);
int DWC_SetUserRecvTimeoutCallback(int a, int b);
void DWC_RAP_OnNewClientNop(void);
u8 DWC_RAP_AttemptCallback(void);
void DWC_RAP_OnMatched(int a, int b, int c, int d, int e);
int DWC_RAP_EvalCallbackAccept(void);
void DWC_RAP_OnSendComplete(int a, u32 i);
void DWC_RAP_OnReceive(u32 a, u8 *p, int c);
void DWC_RAP_OnConnectionClosed(int a, int b, int c, u32 d);
void DWC_RAP_OnReceiveTimeout(unsigned int n);

int DWC_RAP_StartMatchWithKey(void *a0, int n, int a2)
{
    int i;

    if (_pRapWork == 0)
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
    if (_pRapWork->state != 6)
        return 0;
    DWC_RAP_FreeRecvBuffers();
    if (DWC_AddMatchKeyString(0, d_021A1C74, a0) == 0)
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
    MI_CpuFill8(_pRapWork->name, 0, 0x80);
    sprintf(_pRapWork->name, (u32)d_021A1974, d_021A1C74, a0);
    if ((int)GF_STANDARD_GetStringLength((const u8 *)_pRapWork->name) >= 0x80)
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
    if (a2)
        DWC_AddMatchKeyString(1, _pRapWork->name, _pRapWork->name);
    for (i = 0; i < n; i++)
        DWC_RAP_AllocRecvBuffer(i);
    DWC_RAP_SetState(7);
    _pRapWork->n = n;
    if (DWC_ConnectToAnybodyAsync(2, n, _pRapWork->name, (Fn)DWC_RAP_OnMatched,
                      (void *)GFL_NET_GetUserArg(), DWC_RAP_OnNewClientNop,
                      (void *)GFL_NET_GetUserArg(), (Fn)DWC_RAP_EvalCallbackAccept,
                      (void *)GFL_NET_GetUserArg(), (Fn)DWC_RAP_AttemptCallback,
                      &_pRapWork->w750, (void *)GFL_NET_GetUserArg()) == 0)
        return 0;
    _pRapWork->w75C = 0;
    DWC_SetUserSendCallback((int)((Fn)DWC_RAP_OnSendComplete), 0);
    DWC_SetUserRecvCallback((int)((Fn)DWC_RAP_OnReceive), 0);
    DWC_SetConnectionClosedCallback((int)((Fn)DWC_RAP_OnConnectionClosed), 0);
    DWC_SetUserRecvTimeoutCallback((int)((Fn)DWC_RAP_OnReceiveTimeout), 0);
    _pRapWork->w760 = 0;
    _pRapWork->b7A1 = 1;
    return 1;
}
