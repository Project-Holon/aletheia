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
 *   func_0219F674  0x0219F674  arm  ov009
 *   func_0219F768  0x0219F768  arm  ov009
 */

struct SBServer;
struct ServerBrowser {
    char pad[0x60];
    char list[1];
};

struct SBL;
extern int func_0219F674(struct SBL *slist, void *findserver);
extern void func_0219F768(struct SBL *slist, int index);

void func_0219EFA8(struct ServerBrowser *sb, struct SBServer *server)
{
    int i;

    i = func_0219F674((struct SBL *)(&sb->list), server);
    if (i != -1)
        func_0219F768((struct SBL *)(&sb->list), i);
}
