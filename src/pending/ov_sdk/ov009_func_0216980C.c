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
 * blocker:  size now exact (180), 51 concrete bytes, first at +0004. Writing the
 *           func_02186108 guard's early `return ret` as `goto end` (per
 *           docs/idioms/an-early-return-branching-to-a-shared-epilogue-is-a-goto.md)
 *           removed the if-converted `movne/popne` and recovered the 180-byte size.
 *           Two residues remain, both scheduler/regalloc, not spelling (>=10 shapes
 *           measured this wave):
 *             (1) prologue order. image `ldr r4,[pc]; mov r5,#0; ldr r2,[r4,#0xc];
 *                 mov r6,r0; mov r7,r1; str r5,[sp]`; ours `mov r5,#0; ldr r4,[pc];
 *                 str r5,[sp]; ldr r2,[r4,#0xc]; mov r6,r0; mov r7,r1` — the zero and
 *                 its store are scheduled around the base/field loads.
 *             (2) the `profileid>0 && buddyIdx!=-1` arm: image lays the else first
 *                 (`ble else; ldr r1,[sp]; cmn r1,#1; bne call; else: mov r5,#0; b end`)
 *                 and keeps `mov r5,#0` after the call; ours branches to the else
 *                 (`beq else`) with the else last and materialises ret=0 before the call.
 *           Ruled out: nested if (172B, merges both ret=0), goto-call / success-goto
 *           (164B, swaps r6/r7 and profileid into r1), A||B. No unresolved byte.
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
			goto end;
	}
	if (profileid > 0 && buddyIdx != -1) {
		ret = 0;
		if (func_02185FD4(g_021AA860.ctl->connection, buddyIdx, status) == 0)
			ret = 1;
	} else
		ret = 0;
end:
	return ret;
}
