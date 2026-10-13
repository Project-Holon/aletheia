/*
 * function: func_02193D80
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
 *   func_0217EAC8  0x0217eac8  arm   ov009
 *   func_0217EC4C  0x0217ec4c  arm   ov009
 *   func_02193D00  0x02193d00  arm   ov009
 *   func_02194494  0x02194494  arm   ov009
 *   func_02092364  0x02092364  arm
 *   g_021A57C8     0x021a57c8  data
 *   g_021ADFE0     0x021adfe0  data
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
extern void *func_0217EAC8(void *ptr, unsigned long size);
extern int func_0217EC4C(int sock, char *buf, int len, int flags);
extern void func_02193D00(void);
extern int func_02194494(char *buff, int len);
extern void *func_02092364(void *dest, const void *src, unsigned int n);
extern struct StatsSocket g_021A57C8;
extern struct StatsConn g_021ADFE0;

int func_02193D80(void)
{
    int processed;
    int len;

    if (g_021A57C8.sock == -1)
        return 0;
    if (g_021ADFE0.state != 5)
        return 0;
    while (PersistCanReceiveOnSocket(g_021A57C8.sock)) {
        if (g_021ADFE0.inSize - g_021ADFE0.inLen < 0x80) {
            len = g_021ADFE0.inSize;
            if (len < 0x100) {
                len = 0x100;
                g_021ADFE0.inSize = len;
            } else {
                len = len * 2;
                g_021ADFE0.inSize = len;
            }
            g_021ADFE0.inBuff = (char *)func_0217EAC8(g_021ADFE0.inBuff, len + 1);
            if (g_021ADFE0.inBuff == 0)
                return 0;
        }
        len = func_0217EC4C(g_021A57C8.sock, g_021ADFE0.inBuff + g_021ADFE0.inLen,
                            g_021ADFE0.inSize - g_021ADFE0.inLen, 0);
        if (len <= 0) {
            func_02193D00();
            return 0;
        }
        g_021ADFE0.inLen += len;
        g_021ADFE0.inBuff[g_021ADFE0.inLen] = 0;
        processed = func_02194494(g_021ADFE0.inBuff, g_021ADFE0.inLen);
        if (processed == g_021ADFE0.inLen) {
            g_021ADFE0.inLen = 0;
        } else {
            func_02092364(g_021ADFE0.inBuff, g_021ADFE0.inBuff + processed, g_021ADFE0.inLen - processed);
            g_021ADFE0.inLen -= processed;
        }
    }
    if (g_021A57C8.sock == -1)
        return 0;
    return 1;
}
