/*
 * function: func_0219B540
 * address:  0x0219B540
 * packet:   pkt_ov009_0219B540
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      qr2_shutdown (qr2.o)
 *
 * symbols:
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_0219CE58  0x0219CE58  arm  ov009
 *   func_0217EB2C  0x0217EB2C  arm  ov009
 *   func_0217F260  0x0217F260  arm  ov009
 *   func_0219922C  0x0219922C  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   g_021A7674  0x021A7674  data
 *   g_021A6600  0x021A6600  data
 *   g_021A6604  0x021A6604  data
 */

typedef struct qr2_implementation_s {
    int hbsock;
    unsigned char pad4[0xA8];
    int natnegActive;
    unsigned char padAC2[4];
    int lastHeartbeat;
    unsigned char padB8[0xC];
    int stateChanged;
    unsigned char padC8[4];
    int ownsSocket;
} qr2_implementation_s;

extern char g_021A7674[];
extern qr2_implementation_s *g_021A6600;
extern qr2_implementation_s g_021A6604;
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void func_0219CE58(qr2_implementation_s *qrec, int statechanged);
extern int func_0217EB2C(int sock);
extern void func_0217F260();
extern void func_0219922C(void);
extern void func_0217EAE0(void *ptr);

void func_0219B540(qr2_implementation_s *qrec)
{
    func_0217D254(3, 0, 0x40, g_021A7674);
    if (!qrec)
        qrec = g_021A6600;
    if (qrec->stateChanged)
        func_0219CE58(qrec, 2);
    if (qrec->hbsock != -1 && qrec->ownsSocket)
        func_0217EB2C(qrec->hbsock);
    qrec->hbsock = -1;
    qrec->lastHeartbeat = 0;
    if (qrec->ownsSocket)
        func_0217F260();
    if (qrec->natnegActive)
        func_0219922C();
    if (qrec != &g_021A6604)
        func_0217EAE0(qrec);
}
