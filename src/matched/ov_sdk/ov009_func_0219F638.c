/*
 * function: SBServerListAppendServer
 * address:  0x0219F638
 * packet:   pkt_ov009_0219F638
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SBServerListAppendServer (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   func_02184234  0x02184234  arm  ov009
 */

struct SBServer;
struct SBServerList {
    char pad0[4];
    void *servers;
    char pad1[0x488 - 8];
    void (*ListCallback)(struct SBServerList *, int, struct SBServer *, void *);
    char pad2[8];
    void *instance;
};

extern void func_02184234(void *array, void *newElem);

void SBServerListAppendServer(struct SBServerList *slist, struct SBServer *server)
{
    func_02184234(slist->servers, &server);
    slist->ListCallback(slist, 0, server, slist->instance);
}
