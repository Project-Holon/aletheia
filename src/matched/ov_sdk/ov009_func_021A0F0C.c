/*
 * function: ProcessPlayerSearch
 * address:  0x021A0F0C
 * packet:   pkt_ov009_021A0F0C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ProcessPlayerSearch (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   NTSLengthSB  0x0219F978  arm  ov009
 */

#include "../arm9_sdk/libc/string.h"

#define SWAP32(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))

typedef struct SBServerList SBServerList;
struct SBServerList {
    char pad0[0x490];
    void (*PlayerSearchCallback)(SBServerList *, char *, unsigned int, unsigned short, long, char *, void *);
    void *instance;
};

extern int NTSLengthSB(char *buf, int len);

int ProcessPlayerSearch(SBServerList *slist, char *buf, int len)
{
    unsigned char isFinal;
    unsigned char resultCount;
    unsigned int ip;
    unsigned short port;
    char *nick;
    long lastSeen;
    int i;
    int slen;

    if (len < 2)
        return 4;
    isFinal = buf[0];
    resultCount = buf[1];
    buf += 2;
    len -= 2;
    for (i = 0; i < resultCount; i++) {
        nick = buf;
        slen = NTSLengthSB(buf, len);
        if (slen == -1)
            return 4;
        buf += slen;
        len -= slen;
        if (len < 11)
            return 4;
        memcpy(&ip, buf, 4);
        memcpy(&port, buf + 4, 2);
        memcpy(&lastSeen, buf + 6, 4);
        lastSeen = SWAP32((unsigned int)lastSeen);
        buf += 10;
        len -= 10;
        slen = NTSLengthSB(buf, len);
        if (slen == -1)
            return 4;
        slist->PlayerSearchCallback(slist, nick, ip, port, lastSeen, buf, slist->instance);
        buf += slen;
        len -= slen;
    }
    if (isFinal)
        slist->PlayerSearchCallback(slist, 0, 0, 0, 0, 0, slist->instance);
    return 0;
}
