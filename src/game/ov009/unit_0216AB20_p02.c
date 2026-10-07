/*
 * file:     unit_0216AB20_p02.c
 * unit:     yes
 * function: func_0216AE88, func_0216B0E0, func_0216B1E0
 * address:  0x0216AE88
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
 *   func_02059F38  0x02059F38  arm
 *   MIi_CpuClear16 0x02082A48  arm
 *   func_021686E0  0x021686E0  arm  ov009
 *   MIi_CpuCopy16  0x02082A60  arm
 *   func_0205CA20  0x0205CA20  arm
 *   func_0216A3B8  0x0216A3B8  arm  ov009
 *   func_0216BC84  0x0216BC84  arm  ov009
 *   func_0217C750  0x0217C750  arm  ov009
 *   g_021AA878     0x021AA878  data
 *   func_02168D7C  0x02168D7C  arm  ov009
 *   func_02168DA4  0x02168DA4  arm  ov009
 *   func_0216BF98  0x0216BF98  arm  ov009
 */
#include "../../matched/include/G_DwcGlobal.h"

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

typedef unsigned short u16;

typedef unsigned long u32;

typedef struct {
    char pad0[0x24];
    int state;
    char pad28[8];
    u16 ingamesn[0x1a];
    char pad64[4];
    char *gamename;
    char pad6c[4];
    void (*callback)(int, int, void *);
    void *param;
} Ctl;

typedef struct DwcState {
	unsigned char pad0[0x24];
	int state;
	unsigned char pad1[0x3c];
	int profileID;
	unsigned char pad2[0x8];
	void (*loginCallback)(int, int, void *);
	void *loginParam;
	void *updateCallback;
	void *updateParam;
	unsigned char pad3[0x58];
	unsigned char updateBuf0[0x100];
	unsigned char updateBuf1[0x100];
} DwcState;

typedef struct DwcGlobal DwcGlobal;

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
extern int func_02059F38(void);
extern void MIi_CpuClear16(u16 data, void *destp, u32 size);
extern int func_021686E0(unsigned short *p);
extern void MIi_CpuCopy16(void *srcp, void *destp, u32 size);
extern int func_0205CA20(void);
extern void func_0216A3B8(int error, int errorCode);
extern void func_0216BC84(int state);
extern void func_0217C750(char *gamename);
extern int func_02168D7C(void);
extern void func_02168DA4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern void func_0216BF98(int error, int isChanged);
void DWC_ProcessFriendsMatch(void);
int func_0216B0E0(u16 *ingamesn, int reserved, void (*callback)(int, int, void *), void *param);
int func_0216B1E0(int unused, void *updateCallback, void *updateParam, void *statusCallback, void *statusParam, void *deleteCallback, void *deleteParam);
extern struct DWCstGlobal stLastSocketError;
extern struct DwcGlobal g_021AA878;


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


/*
 * sdk:      DWC_LoginAsync (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
int func_0216B0E0(u16 *ingamesn, int reserved, void (*callback)(int, int, void *), void *param)
{
    u32 len;

    if (!ingamesn)
        return 0;
    if (func_02059F38() || ((Ctl *)g_021AA878.st)->state != 0)
        return 0;
    ((Ctl *)g_021AA878.st)->callback = callback;
    ((Ctl *)g_021AA878.st)->param = param;
    if (!ingamesn || ingamesn[0] == 0) {
        len = 0;
    } else {
        MIi_CpuClear16(0, ((Ctl *)g_021AA878.st)->ingamesn, 0x34);
        len = (u32)func_021686E0(ingamesn) > 25 ? 25 : (u32)func_021686E0(ingamesn);
        MIi_CpuCopy16(ingamesn, ((Ctl *)g_021AA878.st)->ingamesn, len * 2);
    }
    ((Ctl *)g_021AA878.st)->ingamesn[len] = 0;
    if (func_0205CA20() != 4) {
        func_0216A3B8(2, -60010);
        return 0;
    }
    func_0216BC84(1);
    func_0217C750(((Ctl *)g_021AA878.st)->gamename);
    return 1;
}


/*
 * sdk:      DWC_UpdateServersAsync (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
int func_0216B1E0(int unused, void *updateCallback, void *updateParam, void *statusCallback, void *statusParam, void *deleteCallback, void *deleteParam)
{
	if (func_02059F38() || ((DwcState *)g_021AA878.st)->state < 3 || func_02168D7C())
		return 0;
	((DwcState *)g_021AA878.st)->updateCallback = updateCallback;
	((DwcState *)g_021AA878.st)->updateParam = updateParam;
	func_02168DA4((int)((DwcState *)g_021AA878.st)->updateBuf0, (int)((DwcState *)g_021AA878.st)->updateBuf1, (int)func_0216BF98, 0, (int)statusCallback, (int)statusParam, (int)deleteCallback, (int)deleteParam);
	return 1;
}
