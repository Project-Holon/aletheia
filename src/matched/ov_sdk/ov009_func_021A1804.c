/*
 * function: ProcessLanData
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
 *   SBServerListFindServerByIP  0x0219F6C8  arm  ov009
 *   SBAllocServer  0x0219E900  arm  ov009
 *   SBIsNullServer  0x0219E9D8  arm  ov009
 *   SBServerSetFlags  0x0219E9AC  arm  ov009
 *   SBServerListAppendServer  0x0219F638  arm  ov009
 *   current_time  0x0217F264  arm  ov009
 *   closesocket  0x0217EB2C  arm  ov009
 *   gSBNullServer  0x021AEB00  data
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
struct SBL;
extern int SBServerListFindServerByIP(struct SBL *slist, unsigned int ip, unsigned short port);
extern struct SBServer *SBAllocServer(int unused, unsigned int publicip, unsigned short publicport);
extern int SBIsNullServer(int v);
extern void SBServerSetFlags(unsigned char *p, unsigned char v);
extern void SBServerListAppendServer(struct SBServerList *slist, struct SBServer *server);
extern unsigned int current_time(void);
extern int closesocket(int sock);
extern SBServer *gSBNullServer;

int ProcessLanData(SBServerList *slist)
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
        foundexisting = SBServerListFindServerByIP((struct SBL *)slist, saddr.addr, saddr.port);
        if (foundexisting != -1)
            continue;
        server = SBAllocServer((int)slist, saddr.addr, saddr.port);
        if (SBIsNullServer((int)server))
            return 5;
        SBServerSetFlags((unsigned char *)server, 0x11);
        SBServerListAppendServer(slist, server);
    }
    if (current_time() - slist->lanstarttime > 2000) {
        closesocket(slist->slsocket);
        slist->slsocket = -1;
        slist->state = 1;
        slist->ListCallback(slist, 3, gSBNullServer, slist->instance);
    }
    return 0;
}
