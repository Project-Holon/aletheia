/*
 * function: func_02169210
 * address:  0x02169210
 * packet:   pkt_ov009_02169210
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GPProcess (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 *
 * symbols:
 *   func_020870D0  0x020870D0  arm
 *   func_02185948  0x02185948  arm  ov009
 *   _ll_udiv  0x0209C00C  arm
 *   g_021AA860  0x021AA860  data
 */

#include "../include/G_FriendGlobal.h"

typedef unsigned long long u64;
struct Work {
	char pad0[4];
	void *conn;
	int count;
	u64 last;
};
extern struct FriendGlobal g_021AA860;
extern u64 func_020870D0(void);
extern u64 _ll_udiv(u64 a, u64 b);
extern int func_02185948(void *conn);
int func_02169210(void)
{
	int result;
	struct Work *w;
	u64 tick;
	result = 0;
	tick = func_020870D0();
	w = g_021AA860.ctl;
	if ((tick - w->last) * 64 / 33514 >= 300) {
		w->count++;
		result = func_02185948(g_021AA860.ctl->conn);
		g_021AA860.ctl->last = func_020870D0();
	}
	return result;
}
