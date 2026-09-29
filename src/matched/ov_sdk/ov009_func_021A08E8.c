/*
 * function: func_021A08E8
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
 *   func_021A0414  0x021A0414  arm  ov009
 *   func_021A04C4  0x021A04C4  arm  ov009
 *   func_021A0440  0x021A0440  arm  ov009
 *   memcmp  0x020923F0  arm
 *   func_021A059C  0x021A059C  arm  ov009
 *   func_0219E900  0x0219E900  arm  ov009
 *   func_0219E9D8  0x0219E9D8  arm  ov009
 *   func_021A060C  0x021A060C  arm  ov009
 *   func_0219F638  0x0219F638  arm  ov009
 *   g_021A8250  0x021A8250  data
 */

typedef struct SBServerList SBServerList;
typedef struct SBServer SBServer;

extern int func_021A0414(int flags);
extern int func_021A04C4(SBServerList *slist, char *buf, int len);
extern int func_021A0440(char *buf, int len);
extern int memcmp(const void *a, const void *b, unsigned long n);
extern void func_021A059C(SBServerList *slist, char *buf, int len, unsigned int *ip, unsigned short *port);
extern SBServer *func_0219E900(SBServerList *slist, unsigned int publicip, unsigned short publicport);
extern int func_0219E9D8(SBServer *server);
extern int func_021A060C(SBServerList *slist, SBServer *server, char *buf, int len, int usepopularlist);
extern void func_0219F638(SBServerList *slist, SBServer *server);
extern char g_021A8250[];

int func_021A08E8(SBServerList *slist, char *buf, int len)
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
    i = func_021A0414(flags);
    if (len < i)
        return 0;
    if (flags & 0x40) {
        if (!func_021A04C4(slist, buf + i, len - i))
            return 0;
    }
    if (flags & 0x80) {
        if (!func_021A0440(buf + i, len - i))
            return 0;
    }
    if (!memcmp(buf + 1, g_021A8250, 4))
        return -1;
    func_021A059C(slist, buf, len, &ip, &port);
    server = func_0219E900(slist, ip, port);
    if (func_0219E9D8(server))
        return -2;
    ret = func_021A060C(slist, server, buf, len, 1);
    func_0219F638(slist, server);
    return ret;
}
