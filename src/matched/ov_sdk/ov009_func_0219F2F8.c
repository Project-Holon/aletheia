/*
 * function: func_0219F2F8
 * address:  0x0219F2F8
 * packet:   pkt_ov009_0219F2F8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FloatKeyCompare (libdwcgsserverbrowsing.TWL.HYB.a sb_serverlist.o)
 *
 * _d2f (0x0209B64C) is a recorded MSL runtime row (layout/runtime_arm9.txt), matched in
 * src/matched/arm9/d2f.c, so its call sites are attested.
 *
 * symbols:
 *   func_0219E1B8  0x0219E1B8  arm  ov009
 *   _dsub  0x0209AF34  arm
 *   _d2f  0x0209B64C  arm
 *   _fgr  0x0209BBB0  arm
 *   _fls  0x0209BC74  arm
 *   func_0219F0E0  0x0219F0E0  arm  ov009
 *   g_021AEB04  0x021AEB04  data
 */

#include "../include/G_021AEB04.h"

typedef struct {
    char sortkey[256];
    int pad100;
} SBSortInfo;
typedef struct {
    char pad0[0x498];
    SBSortInfo currsortinfo;
    SBSortInfo prevsortinfo;
    int sortascending;
} SBServerList;
typedef struct SBServer SBServer;

extern double func_0219E1B8(SBServer *server, char *key, double fdefault);
extern int func_0219F0E0(SBServer *server1, SBServer *server2);
extern struct G_021AEB04 g_021AEB04;

int func_0219F2F8(void *entry1, void *entry2)
{
    SBServer *server1 = *(SBServer **)entry1;
    SBServer *server2 = *(SBServer **)entry2;
    double f;
    char *currsortkey = ((SBServerList *)g_021AEB04.slist)->currsortinfo.sortkey;

    f = func_0219E1B8(server1, currsortkey, 0) - func_0219E1B8(server2, currsortkey, 0);
    if (!((float)f > 0 || (float)f < 0))
        return func_0219F0E0(server1, server2);
    if (!((SBServerList *)g_021AEB04.slist)->sortascending)
        f = 0 - f;
    if ((float)f > 0)
        return 1;
    if ((float)f < 0)
        return -1;
    return 0;
}
