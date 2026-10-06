/*
 * function: func_021A0340
 * address:  0x021A0340
 * packet:   pkt_ov009_021A0340
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SBServerListCleanup (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   func_021A02E0  0x021A02E0  arm  ov009
 *   func_0219F830  0x0219F830  arm  ov009
 *   func_0219DFC0  0x0219DFC0  arm  ov009
 *   func_021841B0  0x021841B0  arm  ov009
 */

struct SBServerList {
    char pad[4];
    void *servers;
};

struct SBL;
extern void func_021A02E0(struct SBL *slist);
extern void func_0219F830(struct SBL *slist);
extern void func_0219DFC0(struct SBServerList *slist);
extern void func_021841B0(void *array);

void func_021A0340(struct SBServerList *slist)
{
    func_021A02E0((struct SBL *)slist);
    func_0219F830((struct SBL *)slist);
    func_0219DFC0(slist);
    if (slist->servers != 0)
        func_021841B0(slist->servers);
    slist->servers = 0;
}
