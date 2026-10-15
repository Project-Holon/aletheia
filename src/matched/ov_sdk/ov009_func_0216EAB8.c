/*
 * function: DWCi_MatchGPRecvBuddyMsgCallback
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
 *   DWC_Base64Decode  0x02059CBC  arm
 *   DWCi_ProcessRecvMatchCommand  0x021702A0  arm  ov009
 */

#include "../arm9_sdk/libc/string.h"

extern int DWC_Base64Decode(const char *src, int srclen, void *dst, int dstlen);
extern void DWCi_MatchGPRecvBuddyMsgCallback(int unused, int profileID, char *message)
{
    unsigned long data[128];
    int msgLen;
    int dataLen;

    msgLen = strlen(message);
    if (msgLen - 1 == 0) {
        dataLen = 0;
    } else {
        int len = DWC_Base64Decode(message + 1, msgLen - 1, data, 512);

        if (len == -1)
            return;
        if (len % 4 != 0)
            return;
        if (len > 512)
            return;
        dataLen = len / 4;
    }
    DWCi_ProcessRecvMatchCommand(*(unsigned char *)message, profileID, 0, 0, data, dataLen);
}
