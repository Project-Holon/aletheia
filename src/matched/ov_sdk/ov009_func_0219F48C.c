/*
 * function: func_0219F48C
 * address:  0x0219F48C
 * packet:   pkt_ov009_0219F48C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      StrNoCaseKeyCompare (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   func_0219E0C0  0x0219E0C0  arm  ov009
 *   func_0209ABF8  0x0209ABF8  arm
 *   func_0219F0E0  0x0219F0E0  arm  ov009
 *   g_021AEB04  0x021AEB04  data
 *   g_021A8230  0x021A8230  data
 */

#include "../include/G_021AEB04.h"

struct SBL { char pad0[0x498]; char sortkey[0x208]; int ascending; };
extern struct G_021AEB04 g_021AEB04;
extern int g_021A8230;
struct _SBServer;
extern char *func_0219E0C0(struct _SBServer *server, char *keyname, char *def);
extern int func_0209ABF8(char *a, char *b);
extern int func_0219F0E0(void *s1, void *s2);
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
