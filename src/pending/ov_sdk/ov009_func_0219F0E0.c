/*
 * function: func_0219F0E0
 * address:  0x0219F0E0
 * packet:   pkt_ov009_0219F0E0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      prevKeyCompare (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * PARKED: every byte reproduces; the _d2f call sites (0x0209B64C) have no witness
 * (same blocker as FloatKeyCompare 0x0219F2F8).
 *
 * symbols:
 *   func_0219E120  0x0219E120  arm  ov009
 *   func_0219E1B8  0x0219E1B8  arm  ov009
 *   func_0219E0C0  0x0219E0C0  arm  ov009
 *   func_020948E0  0x020948E0  arm
 *   func_0209ABF8  0x0209ABF8  arm
 *   func_0209AF34  0x0209AF34  arm
 *   func_0209B64C  0x0209B64C  arm
 *   func_0209BBB0  0x0209BBB0  arm
 *   func_0209BC74  0x0209BC74  arm
 *   g_021AEB04  0x021AEB04  data
 *   g_021A8230  0x021A8230  data
 */

typedef struct {
    char sortkey[256];
    int sorttype;
} SBSortInfo;
typedef struct {
    char pad0[0x498];
    SBSortInfo currsortinfo;
    SBSortInfo prevsortinfo;
    int sortascending;
} SBServerList;
typedef struct {
    int pad0;
    SBServerList *slist;
} SBSortGlobals;
typedef struct SBServer SBServer;

extern int func_0219E120(SBServer *server, char *key, int idefault);
extern double func_0219E1B8(SBServer *server, char *key, double fdefault);
extern char *func_0219E0C0(SBServer *server, char *keyname, char *def);
extern int func_020948E0(const char *a, const char *b);
extern int func_0209ABF8(const char *a, const char *b);
extern SBSortGlobals g_021AEB04;
extern char g_021A8230[];

int func_0219F0E0(SBServer *server1, SBServer *server2)
{
    char *prevsortkey;
    int diff;
    double f;

    prevsortkey = g_021AEB04.slist->prevsortinfo.sortkey;
    switch (g_021AEB04.slist->prevsortinfo.sorttype) {
    case 0:
        diff = func_0219E120(server1, prevsortkey, 0) - func_0219E120(server2, prevsortkey, 0);
        break;
    case 1:
        f = func_0219E1B8(server1, prevsortkey, 0) - func_0219E1B8(server2, prevsortkey, 0);
        if (!g_021AEB04.slist->sortascending)
            f = 0 - f;
        if ((float)f > 0)
            return 1;
        if ((float)f < 0)
            return -1;
        return 0;
    case 2:
        diff = func_020948E0(func_0219E0C0(server1, prevsortkey, g_021A8230), func_0219E0C0(server2, prevsortkey, g_021A8230));
        break;
    case 3:
        diff = func_0209ABF8(func_0219E0C0(server1, prevsortkey, g_021A8230), func_0219E0C0(server2, prevsortkey, g_021A8230));
        break;
    default:
        return 0;
    }
    if (!g_021AEB04.slist->sortascending)
        diff = -diff;
    return diff;
}
