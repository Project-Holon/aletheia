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
 * blocker:  size exact (180), 21 concrete bytes, first at +0004. This lane cut the
 *           residue from 51 to 21 with two source levers (see
 *           docs/idioms/write-the-complemented-compound-condition-so-the-short-else-is-the-fall-through.md):
 *             (a) the `profileid>0 && buddyIdx!=-1` exit is now written as
 *                 `if (!(...)) { ret = 0; } else { int res = <call>; ret = 0; if (res == 0) ret = 1; }`,
 *                 which puts the short else first with `bne` to the call (the image's
 *                 layout) instead of `beq` to a trailing else, and lets the callee
 *                 result land in a named local so the post-call `mov r5,#0` schedules
 *                 exactly where the image has it (+009C). The whole else/call arm is
 *                 now byte-identical.
 *           The remaining 21 bytes are one prologue scheduler tie: image
 *           `ldr r4,[pc]; mov r5,#0; ldr r2,[r4,#0xc]; mov r6,r0; mov r7,r1; str r5,[sp]`
 *           vs ours `mov r5,#0; ldr r4,[pc]; str r5,[sp]; ldr r2,[r4,#0xc]; mov r6,r0; mov r7,r1`.
 *           The single `mov r5,#0` (shared zero of `ret` and `buddyIdx`) and its
 *           `str r5,[sp]` are scheduled around the base/field loads. ~20 measured
 *           shapes this wave (decl/init orderings, split guards, `buddyIdx = ret`,
 *           named g pointer) all leave this exact 21-byte residue: it is a scheduler
 *           tie, not a spelling. Ruled out: nested if (172B), goto-call (164B),
 *           A||B, `FriendGlobal *g` local (176B). No unresolved byte.
 *           Wave 8 reconfirmed with 24 more shapes (copy-zero, decl/assign order,
 *           named `fd`/`st` parameter locals, positive-guard wrap, late assign,
 *           uninit neighbour, volatile/u16 cast) - all 21-byte residue, some size
 *           changes. Filed docs/idioms/a-spilled-zero-init-store-schedules-independently-of-the-guards-loads.md.
 *
 * u21: the defining object is .comment 4.0.0.1025; per the brief the stamp is not a blocker
 *      and this is plain source-level scheduler residue.
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
	unsigned char ret = 0;
	int buddyIdx = 0;
	int profileid;
	if (g_021AA860.ctl == 0 || !func_0216AA70())
		return 0;
	profileid = func_020598EC(func_0216A39C(), friendData);
	if (profileid > 0) {
		if (func_02186108(g_021AA860.ctl->connection, profileid, &buddyIdx) != 0)
			goto end;
	}
	if (!(profileid > 0 && buddyIdx != -1)) {
		ret = 0;
	} else {
		int res = func_02185FD4(g_021AA860.ctl->connection, buddyIdx, status);
		ret = 0;
		if (res == 0)
			ret = 1;
	}
end:
	return ret;
}
