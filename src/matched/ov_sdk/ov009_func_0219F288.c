/*
 * function: IntKeyCompare
 * address:  0x0219F288
 * packet:   pkt_ov009_0219F288
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      IntKeyCompare (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   SBServerGetIntValueA  0x0219E120  arm  ov009
 *   prevKeyCompare  0x0219F0E0  arm  ov009
 *   gSBSortContext  0x021AEB04  data
 */

#include "../include/G_021AEB04.h"

struct SBL { char pad0[0x498]; char sortkey[0x208]; int ascending; };
extern struct G_021AEB04 gSBSortContext;
struct SBServer;
extern int SBServerGetIntValueA(struct SBServer *server, char *key, int idefault);
extern int prevKeyCompare(void *s1, void *s2);
int IntKeyCompare(void *entry1, void *entry2)
{
	char *currsortkey;
	int diff;
	void *server1;
	void *server2;
	server1 = *(void **)entry1;
	server2 = *(void **)entry2;
	currsortkey = gSBSortContext.slist->sortkey;
	diff = SBServerGetIntValueA(server1, currsortkey, 0) - SBServerGetIntValueA(server2, currsortkey, 0);
	if (diff == 0)
		return prevKeyCompare(server1, server2);
	if (gSBSortContext.slist->ascending == 0)
		diff = -diff;
	return diff;
}
