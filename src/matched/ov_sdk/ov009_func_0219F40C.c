/*
 * function: StrCaseKeyCompare
 * address:  0x0219F40C
 * packet:   pkt_ov009_0219F40C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      StrCaseKeyCompare (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   func_0219E0C0  0x0219E0C0  arm  ov009
 *   strcmp  0x020948E0  arm
 *   prevKeyCompare  0x0219F0E0  arm  ov009
 *   gSBSortContext  0x021AEB04  data
 *   gSBEmptyString  0x021A8230  data
 */

#include "../include/G_021AEB04.h"

struct SBL { char pad0[0x498]; char sortkey[0x208]; int ascending; };
extern struct G_021AEB04 gSBSortContext;
extern int gSBEmptyString;
struct _SBServer;
extern char *func_0219E0C0(struct _SBServer *server, char *keyname, char *def);
extern int strcmp(const char *s1, const char *s2);
extern int prevKeyCompare(void *s1, void *s2);
int StrCaseKeyCompare(void *entry1, void *entry2)
{
	char *currsortkey;
	int diff;
	void *server1;
	void *server2;
	server1 = *(void **)entry1;
	server2 = *(void **)entry2;
	currsortkey = gSBSortContext.slist->sortkey;
	diff = strcmp(func_0219E0C0(server1, currsortkey, (char *)&gSBEmptyString), func_0219E0C0(server2, currsortkey, (char *)&gSBEmptyString));
	if (diff == 0)
		return prevKeyCompare(server1, server2);
	if (gSBSortContext.slist->ascending == 0)
		diff = -diff;
	return diff;
}
