/*
 * function: AddServerToDeadlist
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
 *   SBServerSetNext  0x0219E264  arm  ov009
 */

struct SBServer;
struct SBServerList {
    char pad[0x7d8];
    struct SBServer *deadlist;
};

extern void SBServerSetNext(int *p, int v);

void AddServerToDeadlist(struct SBServerList *slist, struct SBServer *server)
{
    if (slist->deadlist == 0)
        SBServerSetNext((int *)server, 0);
    else
        SBServerSetNext((int *)server, (int)slist->deadlist);
    slist->deadlist = server;
}
