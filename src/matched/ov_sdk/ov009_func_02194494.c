/*
 * function: ProcessInBuffer
 * address:  0x02194494
 * packet:   pkt_ov009_02194494
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ProcessInBuffer (gstats.o)
 *
 * symbols:
 *   FindFinal 0x02193FF4  arm
 *   xcode_buf 0x02193EB8  arm
 *   ProcessStatement 0x021943A4  arm
 *   gGstatsNullKey   0x021A57F0  data
 *   gGstatsSocket   0x021A57C8  data
 */

#include "../include/G_StatsSocket.h"

extern char *FindFinal(char *buff, int len);
extern void xcode_buf(char *buf, int len);
extern void ProcessStatement(char *buff, int len);
extern struct StatsSocket gGstatsSocket;
extern char gGstatsNullKey[];

int ProcessInBuffer(char *buff, int len)
{
    char *pos;
    int oldlen;

    oldlen = len;
    pos = FindFinal(buff, len);

    while (len > 0 && pos != 0) {
        (*(char * *)&gGstatsSocket) = gGstatsNullKey;
        xcode_buf(buff, pos - buff);
        ProcessStatement(buff, pos - buff);
        len -= (pos - buff) + 7;
        buff = pos + 7;
        if (len > 0)
            pos = FindFinal(buff, len);
    }
    return oldlen - len;
}
