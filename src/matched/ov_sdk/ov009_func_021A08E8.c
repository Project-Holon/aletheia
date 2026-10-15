/*
 * function: IncomingListParseServer
 * address:  0x021A08E8
 * packet:   pkt_ov009_021A08E8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      IncomingListParseServer (libdwcgsserverbrowsing.TWL.HYB.a sb_serverlist.o)
 *
 * symbols:
 *   ServerSizeForFlags  0x021A0414  arm  ov009
 *   AllKeysPresent  0x021A04C4  arm  ov009
 *   FullRulesPresent  0x021A0440  arm  ov009
 *   memcmp  0x020923F0  arm
 *   ParseServerIPPort  0x021A059C  arm  ov009
 *   SBAllocServer  0x0219E900  arm  ov009
 *   SBIsNullServer  0x0219E9D8  arm  ov009
 *   ParseServer  0x021A060C  arm  ov009
 *   SBServerListAppendServer  0x0219F638  arm  ov009
 *   gSBNatNegMagic  0x021A8250  data
 */

typedef struct SBServerList SBServerList;
typedef struct SBServer SBServer;

extern int ServerSizeForFlags(int flags);
struct SBL;
extern int AllKeysPresent(struct SBL *slist, char *buf, int len);
extern int FullRulesPresent(const char *p, int n);
extern int memcmp(const void *a, const void *b, unsigned long n);
extern void ParseServerIPPort(struct SBL *slist, unsigned char *buf, int len, unsigned int *ip, unsigned short *port);
extern struct SBServer *SBAllocServer(int unused, unsigned int publicip, unsigned short publicport);
extern int SBIsNullServer(int v);
extern int ParseServer(SBServerList *slist, SBServer *server, char *buf, int len, int usepopularlist);
extern void SBServerListAppendServer(struct SBServerList *slist, struct SBServer *server);
extern char gSBNatNegMagic[];

int IncomingListParseServer(SBServerList *slist, char *buf, int len)
{
    SBServer *server;
    unsigned short port;
    unsigned int ip;
    int i;
    int ret;
    unsigned char flags;

    if (len < 1)
        return 0;
    flags = buf[0];
    i = ServerSizeForFlags(flags);
    if (len < i)
        return 0;
    if (flags & 0x40) {
        if (!AllKeysPresent((struct SBL *)slist, buf + i, len - i))
            return 0;
    }
    if (flags & 0x80) {
        if (!FullRulesPresent(buf + i, len - i))
            return 0;
    }
    if (!memcmp(buf + 1, gSBNatNegMagic, 4))
        return -1;
    ParseServerIPPort((struct SBL *)slist, (unsigned char *)buf, len, &ip, &port);
    server = SBAllocServer((int)slist, ip, port);
    if (SBIsNullServer((int)server))
        return -2;
    ret = ParseServer(slist, server, buf, len, 1);
    SBServerListAppendServer(slist, server);
    return ret;
}
