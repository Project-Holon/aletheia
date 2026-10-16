/*
 * function: PersistThink
 * address:  0x02193D80
 * packet:   pkt_ov009_02193D80
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      PersistThink (libdwcgsgstats.TWL.HYB.a gstats.o)
 *
 * symbols:
 *   PersistCanReceiveOnSocket  0x02193fe8  arm   ov009
 *   gsirealloc  0x0217eac8  arm   ov009
 *   recv  0x0217ec4c  arm   ov009
 *   CloseStatsConnection  0x02193d00  arm   ov009
 *   ProcessInBuffer  0x02194494  arm   ov009
 *   memmove  0x02092364  arm
 *   gGstatsSocket     0x021a57c8  data
 *   gGstatsConn     0x021adfe0  data
 */

#include "../include/G_StatsSocket.h"
#include "../include/G_StatsConn.h"

typedef struct {
    int pad;
    int sock;
} StatsSocket;
typedef struct {
    char pad0[8];
    int inLen;
    char pad1[0xc];
    int inSize;
    char pad2[0xc];
    char *inBuff;
    int state;
} StatsConn;

extern int PersistCanReceiveOnSocket(int s);
extern void *gsirealloc(void *ptr, unsigned long size);
extern int recv(int sock, char *buf, int len, int flags);
extern void CloseStatsConnection(void);
extern int ProcessInBuffer(char *buff, int len);
extern void *memmove(void *dest, const void *src, unsigned int n);
extern struct StatsSocket gGstatsSocket;
extern struct StatsConn gGstatsConn;

int PersistThink(void)
{
    int processed;
    int len;

    if (gGstatsSocket.sock == -1)
        return 0;
    if (gGstatsConn.state != 5)
        return 0;
    while (PersistCanReceiveOnSocket(gGstatsSocket.sock)) {
        if (gGstatsConn.inSize - gGstatsConn.inLen < 0x80) {
            len = gGstatsConn.inSize;
            if (len < 0x100) {
                len = 0x100;
                gGstatsConn.inSize = len;
            } else {
                len = len * 2;
                gGstatsConn.inSize = len;
            }
            gGstatsConn.inBuff = (char *)gsirealloc(gGstatsConn.inBuff, len + 1);
            if (gGstatsConn.inBuff == 0)
                return 0;
        }
        len = recv(gGstatsSocket.sock, gGstatsConn.inBuff + gGstatsConn.inLen,
                            gGstatsConn.inSize - gGstatsConn.inLen, 0);
        if (len <= 0) {
            CloseStatsConnection();
            return 0;
        }
        gGstatsConn.inLen += len;
        gGstatsConn.inBuff[gGstatsConn.inLen] = 0;
        processed = ProcessInBuffer(gGstatsConn.inBuff, gGstatsConn.inLen);
        if (processed == gGstatsConn.inLen) {
            gGstatsConn.inLen = 0;
        } else {
            memmove(gGstatsConn.inBuff, gGstatsConn.inBuff + processed, gGstatsConn.inLen - processed);
            gGstatsConn.inLen -= processed;
        }
    }
    if (gGstatsSocket.sock == -1)
        return 0;
    return 1;
}
