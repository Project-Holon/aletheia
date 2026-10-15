/*
 * function: SBFreeDeadList
 * address:  0x0219F7D8
 * packet:   pkt_ov009_0219F7D8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SBFreeDeadList (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   SBServerGetNext  0x0219E26C  arm  ov009
 *   func_0219DFF8  0x0219DFF8  arm  ov009
 */

struct SBL { char pad[0x7d8]; void *dead; };
extern int SBServerGetNext(const int *p);
extern void func_0219DFF8(void *elem);
void SBFreeDeadList(struct SBL *slist)
{
	void *next;
	void *server;
	next = slist->dead;
	if (next == 0)
		return;
	for (server = next; server != 0; server = next) {
		next = (void *)SBServerGetNext(server);
		func_0219DFF8(&server);
	}
	slist->dead = 0;
}
