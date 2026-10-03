/*
 * function: func_021A1804
 * address:  0x021A1804
 * packet:   pkt_ov009_021A1804
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ProcessLanData (libdwcgsserverbrowsing.TWL.HYB.a sb_serverlist.o)
 *
 * symbols:
 *   func_0217EF50  0x0217EF50  arm  ov009
 *   func_0217EC60  0x0217EC60  arm  ov009
 *   func_0219F6C8  0x0219F6C8  arm  ov009
 *   func_0219E900  0x0219E900  arm  ov009
 *   func_0219E9D8  0x0219E9D8  arm  ov009
 *   func_0219E9AC  0x0219E9AC  arm  ov009
 *   func_0219F638  0x0219F638  arm  ov009
 *   func_0217F264  0x0217F264  arm  ov009
 *   func_0217EB2C  0x0217EB2C  arm  ov009
 *   g_021AEB00  0x021AEB00  data
 */

typedef struct SBServer SBServer;
typedef struct SBServerList {
    int state;
    char pad4[0x484];
    void (*ListCallback)(struct SBServerList *, int, SBServer *, void *);
    char pad48c[8];
    void *instance;
    char pad498[0x21c];
    int slsocket;
    unsigned int lanstarttime;
} SBServerList;
typedef struct {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned int addr;
} SOCSockAddrIn;

extern int func_0217EF50(int sock);
extern int func_0217EC60(int sock, char *buf, int len, int flags, SOCSockAddrIn *addr, int *fromlen);
extern int func_0219F6C8(SBServerList *slist, unsigned int ip, unsigned short port);
extern SBServer *func_0219E900(SBServerList *slist, unsigned int publicip, unsigned short publicport);
extern int func_0219E9D8(SBServer *server);
extern void func_0219E9AC(SBServer *server, int flags);
extern void func_0219F638(struct SBServerList *slist, struct SBServer *server);
extern unsigned int func_0217F264(void);
extern int func_0217EB2C(int sock);
extern SBServer *g_021AEB00;

int func_021A1804(SBServerList *slist)
{
    char indata[1500];
    SOCSockAddrIn saddr;
    int saddrlen;
    int error;
    int foundexisting;
    SBServer *server;

    saddrlen = 8;
    while (func_0217EF50(slist->slsocket)) {
        error = func_0217EC60(slist->slsocket, indata, 1499, 0, &saddr, &saddrlen);
        if (error == -1)
            continue;
        foundexisting = func_0219F6C8(slist, saddr.addr, saddr.port);
        if (foundexisting != -1)
            continue;
        server = func_0219E900(slist, saddr.addr, saddr.port);
        if (func_0219E9D8(server))
            return 5;
        func_0219E9AC(server, 0x11);
        func_0219F638(slist, server);
    }
    if (func_0217F264() - slist->lanstarttime > 2000) {
        func_0217EB2C(slist->slsocket);
        slist->slsocket = -1;
        slist->state = 1;
        slist->ListCallback(slist, 3, g_021AEB00, slist->instance);
    }
    return 0;
}
