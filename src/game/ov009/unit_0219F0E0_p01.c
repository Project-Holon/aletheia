/*
 * file:     unit_0219F0E0_p01.c
 * unit:     yes
 * function: func_0219F0E0, func_0219F288, func_0219F2F8, func_0219F40C, func_0219F48C
 * address:  0x0219F0E0
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0219E120  0x0219E120  arm  ov009
 *   func_0219E1B8  0x0219E1B8  arm  ov009
 *   func_0219E0C0  0x0219E0C0  arm  ov009
 *   func_020948E0  0x020948E0  arm
 *   func_0209ABF8  0x0209ABF8  arm
 *   _dsub  0x0209AF34  arm
 *   _d2f  0x0209B64C  arm
 *   _fgr  0x0209BBB0  arm
 *   _fls  0x0209BC74  arm
 *   g_021AEB04  0x021AEB04  data
 *   g_021A8230  0x021A8230  data
 */
#include "../../matched/include/G_021AEB04.h"

struct _SBServer;
struct SBServer;
typedef struct {
    char sortkey[256];
    int sorttype;
} SBSortInfo_0219F0E0;

typedef struct {
    char pad0[0x498];
    SBSortInfo_0219F0E0 currsortinfo;
    SBSortInfo_0219F0E0 prevsortinfo;
    int sortascending;
} SBServerList;

typedef struct SBServer SBServer;

struct SBL { char pad0[0x498]; char sortkey[0x208]; int ascending; };

typedef struct {
    char sortkey[256];
    int pad100;
} SBSortInfo_0219F2F8;

extern int func_0219E120(struct SBServer *server, char *key, int idefault);
extern double func_0219E1B8(SBServer *server, char *key, double fdefault);
extern char *func_0219E0C0(struct _SBServer *server, char *keyname, char *def);
extern int func_020948E0(const char *a, const char *b);
extern int func_0209ABF8(const char *a, const char *b);
int func_0219F0E0(SBServer *server1, SBServer *server2);
int func_0219F288(void *entry1, void *entry2);
int func_0219F2F8(void *entry1, void *entry2);
int func_0219F40C(void *entry1, void *entry2);
int func_0219F48C(void *entry1, void *entry2);
extern struct G_021AEB04 g_021AEB04;
extern char g_021A8230[];


/*
 * sdk:      prevKeyCompare (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * _d2f (0x0209B64C) is a recorded MSL runtime row (layout/runtime_arm9.txt), matched in
 * src/matched/arm9/d2f.c, so its call sites are attested.
 */
int func_0219F0E0(SBServer *server1, SBServer *server2)
{
    char *prevsortkey;
    int diff;
    double f;

    prevsortkey = ((SBServerList *)g_021AEB04.slist)->prevsortinfo.sortkey;
    switch (((SBServerList *)g_021AEB04.slist)->prevsortinfo.sorttype) {
    case 0:
        diff = func_0219E120(server1, prevsortkey, 0) - func_0219E120(server2, prevsortkey, 0);
        break;
    case 1:
        f = func_0219E1B8(server1, prevsortkey, 0) - func_0219E1B8(server2, prevsortkey, 0);
        if (!((SBServerList *)g_021AEB04.slist)->sortascending)
            f = 0 - f;
        if ((float)f > 0)
            return 1;
        if ((float)f < 0)
            return -1;
        return 0;
    case 2:
        diff = func_020948E0(func_0219E0C0((struct _SBServer *)server1, prevsortkey, g_021A8230), func_0219E0C0((struct _SBServer *)server2, prevsortkey, g_021A8230));
        break;
    case 3:
        diff = func_0209ABF8(func_0219E0C0((struct _SBServer *)server1, prevsortkey, g_021A8230), func_0219E0C0((struct _SBServer *)server2, prevsortkey, g_021A8230));
        break;
    default:
        return 0;
    }
    if (!((SBServerList *)g_021AEB04.slist)->sortascending)
        diff = -diff;
    return diff;
}

/*
 * sdk:      IntKeyCompare (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int func_0219F288(void *entry1, void *entry2)
{
	char *currsortkey;
	int diff;
	void *server1;
	void *server2;
	server1 = *(void **)entry1;
	server2 = *(void **)entry2;
	currsortkey = g_021AEB04.slist->sortkey;
	diff = func_0219E120(server1, currsortkey, 0) - func_0219E120(server2, currsortkey, 0);
	if (diff == 0)
		return func_0219F0E0(server1, server2);
	if (g_021AEB04.slist->ascending == 0)
		diff = -diff;
	return diff;
}


/*
 * sdk:      FloatKeyCompare (libdwcgsserverbrowsing.TWL.HYB.a sb_serverlist.o)
 *
 * _d2f (0x0209B64C) is a recorded MSL runtime row (layout/runtime_arm9.txt), matched in
 * src/matched/arm9/d2f.c, so its call sites are attested.
 */
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

/*
 * sdk:      StrCaseKeyCompare (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int func_0219F40C(void *entry1, void *entry2)
{
	char *currsortkey;
	int diff;
	void *server1;
	void *server2;
	server1 = *(void **)entry1;
	server2 = *(void **)entry2;
	currsortkey = g_021AEB04.slist->sortkey;
	diff = func_020948E0(func_0219E0C0(server1, currsortkey, (char *)&g_021A8230), func_0219E0C0(server2, currsortkey, (char *)&g_021A8230));
	if (diff == 0)
		return func_0219F0E0(server1, server2);
	if (g_021AEB04.slist->ascending == 0)
		diff = -diff;
	return diff;
}

/*
 * sdk:      StrNoCaseKeyCompare (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int func_0219F48C(void *entry1, void *entry2)
{
	char *currsortkey;
	int diff;
	void *server1;
	void *server2;
	server1 = *(void **)entry1;
	server2 = *(void **)entry2;
	currsortkey = g_021AEB04.slist->sortkey;
	diff = func_0209ABF8(func_0219E0C0(server1, currsortkey, (char *)&g_021A8230), func_0219E0C0(server2, currsortkey, (char *)&g_021A8230));
	if (diff == 0)
		return func_0219F0E0(server1, server2);
	if (g_021AEB04.slist->ascending == 0)
		diff = -diff;
	return diff;
}
