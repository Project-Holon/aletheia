/*
 * function: func_0216980C
 * address:  0x0216980C
 * packet:   pkt_ov009_0216980C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  86 concrete bytes, first at +0004; compiled 184 vs image 180. The object hoists the
 *           g_021AA860 base load (ldr r4,[pc]) ahead of the zero constant and keeps ret in r5, then
 *           lowers the `return ret` from the func_02186108 guard as a branch to a shared epilogue;
 *           1.1p1 materialises ret=0 first, renames ret to r4 in the tail and inlines an early pop.
 *           Ruled out this wave: w10 v1 (buddyIdx before ret), v2 (declaration initialisers), v3
 *           (ctl local), v4 (int ret) all 86 B; v5 (single-return nesting) 119 B. The defining
 *           object is 4.0.0.1025 and the divergence is scheduler/regalloc from the first
 *           instruction, not a spelling.
 *
 * u21: the defining object is .comment 4.0.0.1025, a stamp no local build writes. The image hoists
 *      the negotiate-list pool load to +0004 and keeps the list pointer in r4 across the whole
 *      function; 1.1p1 zeroes the stack word first and is 4 bytes longer (184 vs 180). First
 *      divergence +0004 image `ldr r4, [pc, #0xa4]` | ours `mov r5, #0`.
 * u1: family check done - ../2.0/base + ../2.0/sp1p2 192 B / 113 B, ../1.2/sp3 208 B. Hoist order plus branch layout.
 *
 * sdk:      DWCi_GetFriendBuddyStatus (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 *
 * symbols:
 *   func_0216AA70  0x0216AA70  arm  ov009
 *   func_0216A39C  0x0216A39C  arm  ov009
 *   func_020598EC  0x020598EC  arm
 *   func_02186108  0x02186108  arm  ov009
 *   func_02185FD4  0x02185FD4  arm  ov009
 *   g_021AA860  0x021AA860  data
 *
 * near miss: 24 words differ (branch layout after gpGetBuddyIndex, ret init order)
 */

typedef struct FriendCtl {
	unsigned char pad0[4];
	void **connection;
	unsigned char pad1[0x28];
	void (*statusCallback)(int, unsigned char, char *, void *);
	void *statusParam;
	unsigned char pad2[0x30];
	unsigned char needRefresh;
} FriendCtl;

typedef struct FriendGlobal {
	int pad0[3];
	FriendCtl *ctl;
} FriendGlobal;

extern FriendGlobal g_021AA860;

typedef struct BuddyStatus {
	int profile;
	int status;
	char statusString[256];
	char locationString[256];
	unsigned char pad[0xc];
} BuddyStatus;

extern int func_0216AA70(void);
extern void *func_0216A39C(void);
extern int func_020598EC(void *userdata, void *friendData);
extern int func_02186108(void **connection, int profile, int *index);
extern int func_02185FD4(void **connection, int index, BuddyStatus *status);

int func_0216980C(void *friendData, BuddyStatus *status)
{
	unsigned char ret;
	int profileid;
	int buddyIdx;
	ret = 0;
	buddyIdx = 0;
	if (g_021AA860.ctl == 0 || !func_0216AA70())
		return 0;
	profileid = func_020598EC(func_0216A39C(), friendData);
	if (profileid > 0) {
		if (func_02186108(g_021AA860.ctl->connection, profileid, &buddyIdx) != 0)
			return ret;
	}
	if (profileid > 0 && buddyIdx != -1) {
		ret = 0;
		if (func_02185FD4(g_021AA860.ctl->connection, buddyIdx, status) == 0)
			ret = 1;
	} else
		ret = 0;
	return ret;
}
