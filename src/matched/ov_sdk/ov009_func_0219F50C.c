/*
 * function: SBServerListSort
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
 *   ArraySort  0x021843C8  arm  ov009
 *   IntKeyCompare  0x0219F288  arm  ov009
 *   FloatKeyCompare  0x0219F2F8  arm  ov009
 *   StrCaseKeyCompare  0x0219F40C  arm  ov009
 *   StrNoCaseKeyCompare  0x0219F48C  arm  ov009
 *   gSBSortContext  0x021AEB04  data
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
extern void ArraySort(int *p, int b);
extern int IntKeyCompare(void *entry1, void *entry2);
extern int FloatKeyCompare(void *entry1, void *entry2);
extern int StrCaseKeyCompare(void *entry1, void *entry2);
extern int StrNoCaseKeyCompare(void *entry1, void *entry2);
extern SBSortGlobals gSBSortContext;

void SBServerListSort(SBServerList *slist, int ascending, SBSortInfo sortinfo)
{
    int (*comparator)(void *, void *);

    switch (sortinfo.comparemode) {
    case 0:
        comparator = IntKeyCompare;
        break;
    case 1:
        comparator = FloatKeyCompare;
        break;
    case 2:
        comparator = StrCaseKeyCompare;
        break;
    case 3:
        comparator = StrNoCaseKeyCompare;
        break;
    default:
        comparator = StrNoCaseKeyCompare;
        break;
    }
    if (strlen(slist->prevsortinfo.sortkey) == 0) {
        slist->prevsortinfo = sortinfo;
    } else if (strcmp(sortinfo.sortkey, slist->currsortinfo.sortkey) != 0) {
        slist->prevsortinfo = slist->currsortinfo;
    }
    slist->currsortinfo = sortinfo;
    slist->sortascending = ascending;
    gSBSortContext.slist = slist;
    ArraySort(slist->servers, (int)comparator);
}
