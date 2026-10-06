/*
 * function: func_0216AD50
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

typedef struct {
    int pad;
    Ctl *ctl;
} Root;

extern Root g_021AA878;

struct ServerBrowser;
struct qr2_implementation_s;
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

void func_0216AD50(void)
{
    if (g_021AA878.ctl == 0)
        return;
    if (g_021AA878.ctl->qr2 != 0) {
        func_0219B540(g_021AA878.ctl->qr2);
        g_021AA878.ctl->qr2 = 0;
    }
    g_021AA878.ctl->flag = 0;
    if (g_021AA878.ctl->sb != 0) {
        func_0219ED4C(g_021AA878.ctl->sb);
        g_021AA878.ctl->sb = 0;
    }
    func_02176B34();
    func_02169FF8();
    func_02193D00();
    func_0216A00C();
    if (g_021AA878.ctl->gpConn != 0) {
        func_0218597C(&g_021AA878.ctl->gpConn, 0, 0, 0);
        func_0218597C(&g_021AA878.ctl->gpConn, 3, 0, 0);
        func_0218597C(&g_021AA878.ctl->gpConn, 1, 0, 0);
        func_0218597C(&g_021AA878.ctl->gpConn, 2, 0, 0);
        func_02185948(&g_021AA878.ctl->gpConn);
        func_0218592C((int **)(&g_021AA878.ctl->gpConn));
        g_021AA878.ctl->gpConn = 0;
    }
    func_0216A404();
    func_021691FC();
    func_0216F334();
    func_0217772C();
    if (g_021AA878.ctl->socket != 0) {
        func_02195AD8(g_021AA878.ctl->socket);
        g_021AA878.ctl->socket = 0;
    }
    func_0205A1B0(4, g_021AA878.ctl, 0);
    g_021AA878.ctl = 0;
}
