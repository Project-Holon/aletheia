/*
 * file:     unit_0216AB20_p01.c
 * unit:     yes
 * function: func_0216AB20, func_0216AD50
 * address:  0x0216AB20
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
 *   DWC_Alloc                        0x0205a16c arm
 *   MI_CpuFill8                      0x02082bcc arm
 *   DWC_ClearError                   0x02059f18 arm
 *   DWCi_ClearGT2ConnectionList      0x0216bb98 arm
 *   DWCi_LoginInit                   0x0216a1f4 arm
 *   DWCi_FriendInit                  0x021689bc arm
 *   DWCi_MatchInit                   0x0216cc28 arm
 *   DWCi_InitTransport               0x021772f8 arm
 *   strlen                           0x0209477c arm
 *   MI_CpuCopy8                      0x02082d44 arm
 *   stLastSocketError                0x021aa878 data
 *   DWCi_GT2ConnectedCallback        0x0216e834 arm
 *   DWCi_GT2ReceivedCallback         0x0216c224 arm
 *   DWCi_GT2ClosedCallback           0x0216c788 arm
 *   DWCi_GT2PingCallback             0x0216c79c arm
 *   gcd_gamename                     0x021ae01c data
 *   gcd_secret_key                   0x021ae11c data
 *   DWCi_LoginCallback               0x0216bf38 arm
 *   func_0219B540  0x0219B540  arm  ov009
 *   func_0219ED4C  0x0219ED4C  arm  ov009
 *   func_02176B34  0x02176B34  arm  ov009
 *   func_02169FF8  0x02169FF8  arm  ov009
 *   func_02193D00  0x02193D00  arm  ov009
 *   func_0216A00C  0x0216A00C  arm  ov009
 *   func_0218597C  0x0218597C  arm  ov009
 *   func_02185948  0x02185948  arm  ov009
 *   func_0218592C  0x0218592C  arm  ov009
 *   func_0216A404  0x0216A404  arm  ov009
 *   func_021691FC  0x021691FC  arm  ov009
 *   func_0216F334  0x0216F334  arm  ov009
 *   func_0217772C  0x0217772C  arm  ov009
 *   func_02195AD8  0x02195AD8  arm  ov009
 *   func_0205A1B0  0x0205A1B0  arm
 *   g_021AA878     0x021AA878  data
 */
#include "../../matched/include/G_DwcGlobal.h"

struct ServerBrowser;
struct qr2_implementation_s;
typedef unsigned char u8;

struct DWCstAccUserData
{
    u8 pad0[0x24];
    unsigned long gamecode;         /* +0x24 */
};

struct DWCstDwcCnt
{
	int field0;
	void (*gt2Connected)(void);
	void (*gt2Received)(void);
	void (*gt2Closed)(void);
	void (*gt2Ping)(void);
	unsigned long sendBufSize;
	unsigned long recvBufSize;
	void *gp;
	struct DWCstAccUserData *userdata;
	int state;
	int field28;
	unsigned char pad2c[0x1];
	unsigned char flag2d;
	unsigned char pad2e[0x36];
	int field64;
	void *gameName;
	void *secretKey;
	int field70;
	int field74;
	int field78;
	int field7c;
	void (*field80)(int, int, int, int, int, void *);
	void *field84;
	int field88;
	int field8c;
	unsigned char pad90[0x8];
	int field98;
	unsigned char pad9c[0x2c4];
	void *qr2;
	volatile unsigned char status364;
	unsigned char pad365[0x37];
	unsigned char flag39c;
	unsigned char pad39d[0x3];
};

struct DWCstGlobal
{
    int lastSocketError;            /* +0x00 */
    struct DWCstDwcCnt *pDwc;       /* +0x04 */
};

typedef struct {
    void *socket;
    char pad4[0x18];
    void *gpConn;
    char pad20[0x340];
    void *qr2;
    char pad364[0x38];
    u8 flag;
    char pad39d[0x593];
    void *sb;
} Ctl;

extern void *DWC_Alloc(int name, unsigned long size);
extern void MI_CpuFill8(void *dstp, u8 data, unsigned long size);
extern void DWC_ClearError(void);
extern void DWCi_ClearGT2ConnectionList(void);
extern void DWCi_LoginInit(void *logcnt, struct DWCstAccUserData *userdata,
                           void **pGpObj, int productID, unsigned long gamecode,
                           unsigned short *playerName,
                           void (*callback)(void), void *param);
extern void DWCi_FriendInit(void *friendcnt, void **pGpObj,
                            unsigned short *playerName, void *friendList,
                            int friendListLen);
extern void DWCi_MatchInit(void *matchcnt, void **pGpObj, void *pGt2Socket,
                           void *gt2Callbacks, char *gameName, char *secretKey,
                           void *friendList, int friendListLen);
extern void DWCi_InitTransport(void *info);
extern unsigned long strlen(const char *s);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void DWCi_GT2ConnectedCallback(void);
extern void DWCi_GT2ReceivedCallback(void);
extern void DWCi_GT2ClosedCallback(void);
extern void DWCi_GT2PingCallback(void);
extern void DWCi_LoginCallback(void);
extern void func_0219B540(struct qr2_implementation_s *qrec);
extern void func_0219ED4C(struct ServerBrowser *sb);
extern void func_02176B34(void);
extern void func_02169FF8(void);
extern void func_02193D00(void);
extern void func_0216A00C(void);
extern int func_0218597C(void **conn, int func, void *callback, void *param);
extern int func_02185948(void **conn);
extern void func_0218592C(int **p);
extern void func_0216A404(void);
extern void func_021691FC(void);
extern void func_0216F334(void);
extern void func_0217772C(void);
extern void func_02195AD8(void *socket);
extern void func_0205A1B0(int name, void *ptr, long size);
void DWC_InitFriendsMatch(struct DWCstAccUserData *userdata, int productID, char *secretKey, int sendBufSize, int recvBufSize, void *friendList, int friendListLen);
void func_0216AD50(void);
extern struct DWCstGlobal stLastSocketError;
extern char gcd_gamename[];
extern char gcd_secret_key[];
extern struct DwcGlobal g_021AA878;


void DWC_InitFriendsMatch(struct DWCstAccUserData *userdata, int productID,
                          char *secretKey, int sendBufSize, int recvBufSize,
                          void *friendList, int friendListLen)
{
    int len;

    stLastSocketError.pDwc = DWC_Alloc(4, 0x1250);
    MI_CpuFill8(stLastSocketError.pDwc, 0, 0x1250);
    DWC_ClearError();

    stLastSocketError.pDwc->field0 = 0;
    stLastSocketError.pDwc->gt2Connected = DWCi_GT2ConnectedCallback;
    stLastSocketError.pDwc->gt2Received = DWCi_GT2ReceivedCallback;
    stLastSocketError.pDwc->gt2Closed = DWCi_GT2ClosedCallback;
    stLastSocketError.pDwc->gt2Ping = DWCi_GT2PingCallback;
    stLastSocketError.pDwc->sendBufSize =
        sendBufSize == 0 ? 0x2000 : (unsigned long)sendBufSize;
    stLastSocketError.pDwc->recvBufSize =
        recvBufSize == 0 ? 0x2000 : (unsigned long)recvBufSize;
    stLastSocketError.pDwc->gp = 0;
    stLastSocketError.pDwc->userdata = userdata;
    stLastSocketError.pDwc->state = 0;
    stLastSocketError.pDwc->field28 = 0;
    stLastSocketError.pDwc->flag2d = 0;
    stLastSocketError.pDwc->field64 = 0;
    stLastSocketError.pDwc->gameName = gcd_gamename;
    stLastSocketError.pDwc->secretKey = gcd_secret_key;
    stLastSocketError.pDwc->field70 = 0;
    stLastSocketError.pDwc->field74 = 0;
    stLastSocketError.pDwc->field78 = 0;
    stLastSocketError.pDwc->field7c = 0;
    stLastSocketError.pDwc->field80 = 0;
    stLastSocketError.pDwc->field84 = 0;
    stLastSocketError.pDwc->field88 = 0;
    stLastSocketError.pDwc->field8c = 0;

    DWCi_ClearGT2ConnectionList();

    DWCi_LoginInit((char *)stLastSocketError.pDwc + 0x90, userdata,
                   &stLastSocketError.pDwc->gp, productID, userdata->gamecode,
                   (unsigned short *)((char *)stLastSocketError.pDwc + 0x30),
                   DWCi_LoginCallback, 0);

    DWCi_FriendInit((char *)stLastSocketError.pDwc + 0x2f0,
                    &stLastSocketError.pDwc->gp,
                    (unsigned short *)((char *)stLastSocketError.pDwc + 0x30),
                    friendList, friendListLen);

    DWCi_MatchInit((char *)stLastSocketError.pDwc + 0x350,
                   &stLastSocketError.pDwc->gp, stLastSocketError.pDwc,
                   (char *)stLastSocketError.pDwc + 4, gcd_gamename,
                   gcd_secret_key, friendList, friendListLen);

    DWCi_InitTransport((char *)stLastSocketError.pDwc + 0xb28);

    if (strlen(secretKey) >= 0x100)
        len = 0xff;
    else
        len = (int)strlen(secretKey);
    MI_CpuCopy8(secretKey, gcd_secret_key, len);
    gcd_secret_key[len] = 0;
}


/*
 * sdk:      DWC_ShutdownFriendsMatch (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
void func_0216AD50(void)
{
    if (g_021AA878.st == 0)
        return;
    if (((Ctl *)g_021AA878.st)->qr2 != 0) {
        func_0219B540(((Ctl *)g_021AA878.st)->qr2);
        ((Ctl *)g_021AA878.st)->qr2 = 0;
    }
    ((Ctl *)g_021AA878.st)->flag = 0;
    if (((Ctl *)g_021AA878.st)->sb != 0) {
        func_0219ED4C(((Ctl *)g_021AA878.st)->sb);
        ((Ctl *)g_021AA878.st)->sb = 0;
    }
    func_02176B34();
    func_02169FF8();
    func_02193D00();
    func_0216A00C();
    if (((Ctl *)g_021AA878.st)->gpConn != 0) {
        func_0218597C(&((Ctl *)g_021AA878.st)->gpConn, 0, 0, 0);
        func_0218597C(&((Ctl *)g_021AA878.st)->gpConn, 3, 0, 0);
        func_0218597C(&((Ctl *)g_021AA878.st)->gpConn, 1, 0, 0);
        func_0218597C(&((Ctl *)g_021AA878.st)->gpConn, 2, 0, 0);
        func_02185948(&((Ctl *)g_021AA878.st)->gpConn);
        func_0218592C((int **)(&((Ctl *)g_021AA878.st)->gpConn));
        ((Ctl *)g_021AA878.st)->gpConn = 0;
    }
    func_0216A404();
    func_021691FC();
    func_0216F334();
    func_0217772C();
    if (((Ctl *)g_021AA878.st)->socket != 0) {
        func_02195AD8(((Ctl *)g_021AA878.st)->socket);
        ((Ctl *)g_021AA878.st)->socket = 0;
    }
    func_0205A1B0(4, g_021AA878.st, 0);
    g_021AA878.st = 0;
}
