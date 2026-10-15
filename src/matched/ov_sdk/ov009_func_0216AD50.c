/*
 * function: DWC_ShutdownFriendsMatch
 * address:  0x0216AD50
 * packet:   pkt_ov009_0216AD50
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_ShutdownFriendsMatch (libdwcmatch.TWL.HYB.a(dwc_main.o))
 *
 * symbols:
 *   qr2_shutdown  0x0219B540  arm  ov009
 *   ServerBrowserFree  0x0219ED4C  arm  ov009
 *   func_02176B34  0x02176B34  arm  ov009
 *   DWCi_BeginCloseStatsConnection  0x02169FF8  arm  ov009
 *   CloseStatsConnection  0x02193D00  arm  ov009
 *   DWCi_EndCloseStatsConnection  0x0216A00C  arm  ov009
 *   func_0218597C  0x0218597C  arm  ov009
 *   func_02185948  0x02185948  arm  ov009
 *   func_0218592C  0x0218592C  arm  ov009
 *   DWCi_ShutdownLogin  0x0216A404  arm  ov009
 *   DWCi_ShutdownFriend  0x021691FC  arm  ov009
 *   func_0216F334  0x0216F334  arm  ov009
 *   DWCi_ShutdownTransport  0x0217772C  arm  ov009
 *   func_02195AD8  0x02195AD8  arm  ov009
 *   func_0205A1B0  0x0205A1B0  arm
 *   g_021AA878     0x021AA878  data
 */

#include "../include/G_DwcGlobal.h"

typedef unsigned char u8;

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

extern struct DwcGlobal g_021AA878;

struct ServerBrowser;
struct qr2_implementation_s;
extern void qr2_shutdown(struct qr2_implementation_s *qrec);
extern void ServerBrowserFree(struct ServerBrowser *sb);
extern void func_02176B34(void);
extern void DWCi_BeginCloseStatsConnection(void);
extern void CloseStatsConnection(void);
extern void DWCi_EndCloseStatsConnection(void);
extern int func_0218597C(void **conn, int func, void *callback, void *param);
extern int func_02185948(void **conn);
extern void func_0218592C(int **p);
extern void DWCi_ShutdownLogin(void);
extern void DWCi_ShutdownFriend(void);
extern void func_0216F334(void);
extern void DWCi_ShutdownTransport(void);
extern void func_02195AD8(void *socket);
extern void func_0205A1B0(int name, void *ptr, long size);

void DWC_ShutdownFriendsMatch(void)
{
    if (g_021AA878.st == 0)
        return;
    if (((Ctl *)g_021AA878.st)->qr2 != 0) {
        qr2_shutdown(((Ctl *)g_021AA878.st)->qr2);
        ((Ctl *)g_021AA878.st)->qr2 = 0;
    }
    ((Ctl *)g_021AA878.st)->flag = 0;
    if (((Ctl *)g_021AA878.st)->sb != 0) {
        ServerBrowserFree(((Ctl *)g_021AA878.st)->sb);
        ((Ctl *)g_021AA878.st)->sb = 0;
    }
    func_02176B34();
    DWCi_BeginCloseStatsConnection();
    CloseStatsConnection();
    DWCi_EndCloseStatsConnection();
    if (((Ctl *)g_021AA878.st)->gpConn != 0) {
        func_0218597C(&((Ctl *)g_021AA878.st)->gpConn, 0, 0, 0);
        func_0218597C(&((Ctl *)g_021AA878.st)->gpConn, 3, 0, 0);
        func_0218597C(&((Ctl *)g_021AA878.st)->gpConn, 1, 0, 0);
        func_0218597C(&((Ctl *)g_021AA878.st)->gpConn, 2, 0, 0);
        func_02185948(&((Ctl *)g_021AA878.st)->gpConn);
        func_0218592C((int **)(&((Ctl *)g_021AA878.st)->gpConn));
        ((Ctl *)g_021AA878.st)->gpConn = 0;
    }
    DWCi_ShutdownLogin();
    DWCi_ShutdownFriend();
    func_0216F334();
    DWCi_ShutdownTransport();
    if (((Ctl *)g_021AA878.st)->socket != 0) {
        func_02195AD8(((Ctl *)g_021AA878.st)->socket);
        ((Ctl *)g_021AA878.st)->socket = 0;
    }
    func_0205A1B0(4, g_021AA878.st, 0);
    g_021AA878.st = 0;
}
