/*
 * function: prevKeyCompare
 * address:  0x0219F0E0
 * packet:   pkt_ov009_0219F0E0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      prevKeyCompare (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * _d2f (0x0209B64C) is a recorded MSL runtime row (layout/runtime_arm9.txt), matched in
 * src/matched/arm9/d2f.c, so its call sites are attested.
 *
 * symbols:
 *   func_0219E120  0x0219E120  arm  ov009
 *   func_0219E1B8  0x0219E1B8  arm  ov009
 *   func_0219E0C0  0x0219E0C0  arm  ov009
 *   func_020948E0  0x020948E0  arm
 *   strcmp_nocase  0x0209ABF8  arm
 *   _dsub  0x0209AF34  arm
 *   _d2f  0x0209B64C  arm
 *   _fgr  0x0209BBB0  arm
 *   _fls  0x0209BC74  arm
 *   gSBSortContext  0x021AEB04  data
 *   gSBEmptyString  0x021A8230  data
 */

#include "../include/G_021AEB04.h"

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
typedef struct SBServer SBServer;

extern int func_0219E120(struct SBServer *server, char *key, int idefault);
extern double func_0219E1B8(SBServer *server, char *key, double fdefault);
struct _SBServer;
extern char *func_0219E0C0(struct _SBServer *server, char *keyname, char *def);
extern int func_020948E0(const char *a, const char *b);
extern int strcmp_nocase(const char *a, const char *b);
extern struct G_021AEB04 gSBSortContext;
extern char gSBEmptyString[];

int prevKeyCompare(SBServer *server1, SBServer *server2)
{
    char *prevsortkey;
    int diff;
    double f;

    prevsortkey = ((SBServerList *)gSBSortContext.slist)->prevsortinfo.sortkey;
    switch (((SBServerList *)gSBSortContext.slist)->prevsortinfo.sorttype) {
    case 0:
        diff = func_0219E120(server1, prevsortkey, 0) - func_0219E120(server2, prevsortkey, 0);
        break;
    case 1:
        f = func_0219E1B8(server1, prevsortkey, 0) - func_0219E1B8(server2, prevsortkey, 0);
        if (!((SBServerList *)gSBSortContext.slist)->sortascending)
            f = 0 - f;
        if ((float)f > 0)
            return 1;
        if ((float)f < 0)
            return -1;
        return 0;
    case 2:
        diff = func_020948E0(func_0219E0C0((struct _SBServer *)server1, prevsortkey, gSBEmptyString), func_0219E0C0((struct _SBServer *)server2, prevsortkey, gSBEmptyString));
        break;
    case 3:
        diff = strcmp_nocase(func_0219E0C0((struct _SBServer *)server1, prevsortkey, gSBEmptyString), func_0219E0C0((struct _SBServer *)server2, prevsortkey, gSBEmptyString));
        break;
    default:
        return 0;
    }
    if (!((SBServerList *)gSBSortContext.slist)->sortascending)
        diff = -diff;
    return diff;
}
