/*
 * function: qr2_shutdown
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
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   send_heartbeat  0x0219CE58  arm  ov009
 *   closesocket  0x0217EB2C  arm  ov009
 *   SocketShutDown  0x0217F260  arm  ov009
 *   NNFreeNegotiateList  0x0219922C  arm  ov009
 *   gsifree  0x0217EAE0  arm  ov009
 *   g_021A7674  0x021A7674  data
 *   g_021A6600  0x021A6600  data
 *   g_021A6604  0x021A6604  data
 */

#include "../include/G_021A6604.h"

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
extern struct G_021A6604 g_021A6604;
extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
extern void send_heartbeat(qr2_implementation_s *qrec, int statechanged);
extern int closesocket(int sock);
extern void SocketShutDown();
extern void NNFreeNegotiateList(void);
extern void gsifree(void *ptr);

void qr2_shutdown(qr2_implementation_s *qrec)
{
    gsDebugFormat(3, 0, 0x40, g_021A7674);
    if (!qrec)
        qrec = g_021A6600;
    if (qrec->stateChanged)
        send_heartbeat(qrec, 2);
    if (qrec->hbsock != -1 && qrec->ownsSocket)
        closesocket(qrec->hbsock);
    qrec->hbsock = -1;
    qrec->lastHeartbeat = 0;
    if (qrec->ownsSocket)
        SocketShutDown();
    if (qrec->natnegActive)
        NNFreeNegotiateList();
    if (qrec != ((qr2_implementation_s *)&g_021A6604))
        gsifree(qrec);
}
