/*
 * function: func_021A1620
 * address:  0x021A1620
 * packet:   pkt_ov009_021A1620
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SBSendMessageToServer (libdwcgsserverbrowsing.TWL.HYB.a sb_serverlist.o)
 *
 * symbols:
 *   func_0219FFD4  0x0219FFD4  arm  ov009
 *   func_0219FF30  0x0219FF30  arm  ov009
 *   func_0217EC90  0x0217EC90  arm  ov009
 */

#include "../arm9_sdk/libc/string.h"
typedef struct {
    int state;
    char pad4[0x6b0];
    int slsocket;
} SBServerList;

#define HTONS(x) ((((x) >> 8) & 0xff) | (((x) << 8) & 0xff00))
extern int func_0219FFD4(SBServerList *slist, char *fieldList, char *serverFilter, int options, int maxServers);
extern int func_0219FF30(SBServerList *slist, char *data, int len);
extern int func_0217EC90(int sock, char *buf, int len, int flags);

int func_021A1620(SBServerList *slist, unsigned int ip, unsigned short port, char *data, int len)
{
    int i;
    int ret;
    unsigned short tmp;
    char requestBuffer[16];

    if (slist->state == 1)
        func_0219FFD4(slist, 0, 0, 2, 0);
    if (slist->state == 1)
        return 3;
    tmp = HTONS((unsigned short)(len + 9));
    memcpy(&requestBuffer[0], &tmp, 2);
    requestBuffer[2] = 2;
    memcpy(&requestBuffer[3], &ip, 4);
    memcpy(&requestBuffer[7], &port, 2);
    i = func_0219FF30(slist, requestBuffer, 9);
    if (i != 0)
        return i;
    ret = 0;
    i = func_0217EC90(slist->slsocket, data, len, 0);
    if (i < 0)
        ret = 3;
    return ret;
}
