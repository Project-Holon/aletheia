/*
 * function: func_0219F50C
 * address:  0x0219F50C
 * packet:   pkt_ov009_0219F50C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SBServerListSort (libdwcgsserverbrowsing.TWL.HYB.a sb_serverlist.o)
 *
 * symbols:
 *   strlen  0x0209477C  arm
 *   strcmp  0x020948E0  arm
 *   func_021843C8  0x021843C8  arm  ov009
 *   func_0219F288  0x0219F288  arm  ov009
 *   func_0219F2F8  0x0219F2F8  arm  ov009
 *   func_0219F40C  0x0219F40C  arm  ov009
 *   func_0219F48C  0x0219F48C  arm  ov009
 *   g_021AEB04  0x021AEB04  data
 */

typedef struct {
    char sortkey[255];
    int comparemode;
} SBSortInfo;
typedef struct {
    int state;
    void *servers;
    char pad8[0x490];
    SBSortInfo currsortinfo;
    SBSortInfo prevsortinfo;
    int sortascending;
} SBServerList;
typedef struct {
    int pad0;
    SBServerList *slist;
} SBSortGlobals;

extern unsigned long strlen(const char *s);
extern int strcmp(const char *a, const char *b);
extern void func_021843C8(int *p, int b);
extern int func_0219F288(void *entry1, void *entry2);
extern int func_0219F2F8(void *entry1, void *entry2);
extern int func_0219F40C(void *entry1, void *entry2);
extern int func_0219F48C(void *entry1, void *entry2);
extern SBSortGlobals g_021AEB04;

void func_0219F50C(SBServerList *slist, int ascending, SBSortInfo sortinfo)
{
    int (*comparator)(void *, void *);

    switch (sortinfo.comparemode) {
    case 0:
        comparator = func_0219F288;
        break;
    case 1:
        comparator = func_0219F2F8;
        break;
    case 2:
        comparator = func_0219F40C;
        break;
    case 3:
        comparator = func_0219F48C;
        break;
    default:
        comparator = func_0219F48C;
        break;
    }
    if (strlen(slist->prevsortinfo.sortkey) == 0) {
        slist->prevsortinfo = sortinfo;
    } else if (strcmp(sortinfo.sortkey, slist->currsortinfo.sortkey) != 0) {
        slist->prevsortinfo = slist->currsortinfo;
    }
    slist->currsortinfo = sortinfo;
    slist->sortascending = ascending;
    g_021AEB04.slist = slist;
    func_021843C8(slist->servers, (int)comparator);
}
