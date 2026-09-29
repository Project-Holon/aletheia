/*
 * function: func_0216EAB8
 * address:  0x0216EAB8
 * packet:   pkt_ov009_0216EAB8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_MatchGPRecvBuddyMsgCallback (dwc_match.o)
 *
 * symbols:
 *   strlen         0x0209477C  arm
 *   func_02059CBC  0x02059CBC  arm
 *   func_021702A0  0x021702A0  arm  ov009
 */

#include "../arm9_sdk/libc/string.h"

extern int func_02059CBC(const char *src, int srclen, void *dst, int dstlen);
extern void func_0216EAB8(int unused, int profileID, char *message)
{
    unsigned long data[128];
    int msgLen;
    int dataLen;

    msgLen = strlen(message);
    if (msgLen - 1 == 0) {
        dataLen = 0;
    } else {
        int len = func_02059CBC(message + 1, msgLen - 1, data, 512);

        if (len == -1)
            return;
        if (len % 4 != 0)
            return;
        if (len > 512)
            return;
        dataLen = len / 4;
    }
    func_021702A0(*(unsigned char *)message, profileID, 0, 0, data, dataLen);
}
