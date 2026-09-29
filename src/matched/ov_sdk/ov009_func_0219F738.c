/*
 * function: func_0219F738
 * address:  0x0219F738
 * packet:   pkt_ov009_0219F738
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      AddServerToDeadlist (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   func_0219E264  0x0219E264  arm  ov009
 */

struct SBServer;
struct SBServerList {
    char pad[0x7d8];
    struct SBServer *deadlist;
};

extern void func_0219E264(struct SBServer *server, struct SBServer *next);

void func_0219F738(struct SBServerList *slist, struct SBServer *server)
{
    if (slist->deadlist == 0)
        func_0219E264(server, 0);
    else
        func_0219E264(server, slist->deadlist);
    slist->deadlist = server;
}
