/*
 * function: func_0219EFA8
 * address:  0x0219EFA8
 * packet:   pkt_ov009_0219EFA8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ServerBrowserRemoveServer (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o))
 *
 * symbols:
 *   SBServerListFindServer  0x0219F674  arm  ov009
 *   SBServerListRemoveAt  0x0219F768  arm  ov009
 */

struct SBServer;
struct ServerBrowser {
    char pad[0x60];
    char list[1];
};

struct SBL;
extern int SBServerListFindServer(struct SBL *slist, void *findserver);
extern void SBServerListRemoveAt(struct SBL *slist, int index);

void func_0219EFA8(struct ServerBrowser *sb, struct SBServer *server)
{
    int i;

    i = SBServerListFindServer((struct SBL *)(&sb->list), server);
    if (i != -1)
        SBServerListRemoveAt((struct SBL *)(&sb->list), i);
}
