/*
 * function: func_0219ED4C
 * address:  0x0219ED4C
 * packet:   pkt_ov009_0219ED4C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ServerBrowserFree (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o))
 *
 * symbols:
 *   func_021A0340  0x021A0340  arm  ov009
 *   SBEngineCleanup  0x0219D8FC  arm  ov009
 *   func_0219922C  0x0219922C  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 */

struct ServerBrowser {
    char engine[0x60];
    char list[0x850 - 0x60];
    void *ConnectCallback;
};

struct SBServerList;
extern void func_021A0340(struct SBServerList *slist);
extern void SBEngineCleanup(void *engine);
extern void func_0219922C(void);
extern void func_0217EAE0(void *ptr);

void func_0219ED4C(struct ServerBrowser *sb)
{
    func_021A0340((struct SBServerList *)(&sb->list));
    SBEngineCleanup(&sb->engine);
    if (sb->ConnectCallback != 0)
        func_0219922C();
    func_0217EAE0(sb);
}
