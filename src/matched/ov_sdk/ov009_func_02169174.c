/*
 * function: func_02169174
 * address:  0x02169174
 * packet:   pkt_ov009_02169174
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CallBuddyFriendCallback (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 *
 * symbols:
 *   func_0216870C  0x0216870C  arm  ov009
 *   g_021AA860  0x021AA860  data
 */

struct Friend { int a, b, c; };
struct Work {
	int state;
	char pad0[0x18 - 4];
	struct Friend *friends;
	char pad1[0x34 - 0x1c];
	void (*cb34)(int index, unsigned char status, char *str, void *arg);
	void *arg38;
	char pad2[0x44 - 0x3c];
	void (*cb44)(int index, void *arg);
	void *arg48;
};
struct Root { char pad[0xc]; struct Work *w; };
extern struct Root g_021AA860;
extern unsigned char func_0216870C(struct Friend *f, char *str);
void func_02169174(int index)
{
	struct { char pad[0x108]; char s[0x10c]; } status;
	unsigned char st;
	if (g_021AA860.w->cb44 != 0 && g_021AA860.w->state != 1)
		g_021AA860.w->cb44(index, g_021AA860.w->arg48);
	if (g_021AA860.w->cb34 == 0)
		return;
	st = func_0216870C(&g_021AA860.w->friends[index], status.s);
	g_021AA860.w->cb34(index, st, status.s, g_021AA860.w->arg38);
}
