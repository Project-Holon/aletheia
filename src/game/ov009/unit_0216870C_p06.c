/*
 * file:     unit_0216870C_p06.c
 * unit:     yes
 * function: func_02169210, func_02169294
 * address:  0x02169210
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
 *   func_020870D0  0x020870D0  arm
 *   func_02185948  0x02185948  arm  ov009
 *   _ll_udiv  0x0209C00C  arm
 *   g_021AA860  0x021AA860  data
 */
#include "../../matched/include/G_FriendGlobal.h"

typedef unsigned long long u64;

struct Work {
	char pad0[4];
	void *conn;
	int count;
	u64 last;
};

extern u64 func_020870D0(void);
extern u64 _ll_udiv(u64 a, u64 b);
extern int func_02185948(void *conn);
int func_02169210(void);
void func_02169294(void);
extern struct FriendGlobal g_021AA860;

/*
 * sdk:      DWCi_GPProcess (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 */
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


/*
 * Clears the word and the two bytes at +0x1e and +0x1f of the object at
 * +0xc of the current root.
 */
void func_02169294(void)
{
    char *p = *(char **)(((char *)&g_021AA860) + 0xc);
    char *q;

    if (p == 0) return;
    *(int *)p = 0;
    q = *(char **)(((char *)&g_021AA860) + 0xc);
    *(unsigned char *)(q + 0x1e) = 0;
    q = *(char **)(((char *)&g_021AA860) + 0xc);
    *(unsigned char *)(q + 0x1f) = 0;
}
