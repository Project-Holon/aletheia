/*
 * function: func_0219F888
 * address:  0x0219F888
 * packet:   pkt_ov009_0219F888
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SBAllocateServerList (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   func_02184144  0x02184144  arm  ov009
 */

struct SBServerList {
    char pad0[4];
    void *servers;
    char pad1[0x7d8 - 8];
    void *deadlist;
};

extern void *func_02184144(int elemSize, int numElemsToAllocate, void (*elemFreeFn)(void *));

void func_0219F888(struct SBServerList *slist)
{
    slist->servers = func_02184144(4, 100, 0);
    slist->deadlist = 0;
}
