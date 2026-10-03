/*
 * function: func_0219F288
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
 *   func_0219E120  0x0219E120  arm  ov009
 *   func_0219F0E0  0x0219F0E0  arm  ov009
 *   g_021AEB04  0x021AEB04  data
 */

struct SBL { char pad0[0x498]; char sortkey[0x208]; int ascending; };
struct G { int pad; struct SBL *slist; };
extern struct G g_021AEB04;
struct SBServer;
extern int func_0219E120(struct SBServer *server, char *key, int idefault);
extern int func_0219F0E0(void *s1, void *s2);
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
