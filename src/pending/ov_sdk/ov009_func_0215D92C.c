/*
 * function: func_0215D92C
 * address:  0x0215D92C
 * packet:   pkt_ov009_0215D92C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * lane07 (2026-10-01): DWARF has no `dgram` local (result, his_ip, his_port, my_port,
 *   cpsbuffer_len, cpsbuffer, recv_pipe, enable).  Spelled the mode test as the sibling's
 *   `isStream()` inline, recv_pipe at function scope in DWARF order, and the RMW as an
 *   inline consume(recv_pipe, result): all still 260/264, the arm is still predicated.
 *
 * lane A (2026-10-01, wave 8).  Two further levers measured against the +0x90
 * guard, both still fold to ldreq/addeq/streq (260/264, 101 bytes):
 *   - volatile *pointee* through an in-register pointer
 *     (`volatile struct SOCLRecvPipe *recv_pipe = socket->recv_pipe;`): the
 *     pointer does not spill, the flag load and the RMW stay `ldr r0,[r1,#..]`,
 *     and the arm is still predicated.  So `volatile` on the pointee neither
 *     changes selection nor blocks predication here.
 *   - `*(volatile signed char *)&recv_pipe->flag_noconsume` plus a
 *     `*(volatile long *)&recv_pipe->consumed` RMW cast through the same
 *     register: identical 260/101.
 * Confirms the idiom's bracket: only the volatile *local pointer* (which
 * spills) un-predicates the arm, and it costs +32 bytes (idiom
 * a-volatile-qualified-local-pointer-spills-and-un-predicates-a-short-arm.md),
 * so it is diagnostic, not a closing lever.
 * pending:  measured near miss, 260/264 bytes, 101 concrete bytes differ. The only
 *            residue is the +0x90 guard arm: the image keeps `bne #0x215d9ec` over
 *            `ldr r0,[r1,#0xf8] / add r0,r0,r5 / str r0,[r1,#0xf8]` closed by
 *            `b #0x215d9ec`, but dsi/1.1p1 -O4,p if-converts any <=5-instruction
 *            guard arm and emits `ldreq/addeq/streq/b` (4 bytes short; everything
 *            downstream shifts by four). Verified across ~30 spellings of the guard
 *            (if forms, mirror else, switch, goto, while/do, `||`, `&&`,
 *            ternary-as-statement, volatile field, s32/long field, double-deref
 *            `socket->recv_pipe->`, function-scope binding, casts: all fold).
 *            Only a call inside the arm restores the branch (probe `a_call`), which
 *            changes bytes elsewhere. ../2.0/sp2 keeps the branch but then branches
 *            the image's predicated `&&` tail chain and folds the else zero to
 *            `subne`/mis-orders `moveq` (best 264/16), so no front end of ours
 *            emits the full function. See docs/notes/func_0215D92C.c.txt.
 * blocker:  the +0x90 flag guard branch cannot be emitted by any pinned front end
 *            from plain C (see note); needs a front end that mixes 1.1p1 tail
 *            predication with a kept 3-instruction guard branch.
 *
 * lane U41 (2026-09-30).  Re-measured: still 260 compiled against 264, first
 * difference `image beq #0x215d9ec over ldr/add/str/b | ours ldreq/addeq/streq/b`
 * at +0x90, exactly the if-conversion the note names; everything downstream
 * shifts by four.  Seven further spellings measured, all identical (260/264,
 * 101 bytes): `volatile long consumed` field, `*(volatile long *)&...consumed
 * += result`, braced body, `result + consumed` operand order, a named `c`
 * local, `while (..==0) { ...; break; }`, a `long *pc = &consumed` pointer,
 * `goto`-shaped arms and a one-case `switch`.  This front end predicates the
 * arm from every one of them, so the cap is confirmed on a wider base.
 *
 * lane W8 (2026-09-30).  Four NEW levers from the idiom index, all still fold to
 * 260/264 at +0x90:
 *   - explicit `goto tail;` out of the guard arm to a shared tail label
 *     (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md third
 *     spelling) -- the `bne`-over-`b` shape the image has; still if-converted.
 *   - a dead `recv_pipe->consumed += 0;` sixth statement inside the arm, hoping
 *     it counts before DCE -- removed before if-conversion, no effect.
 *   - the `a-factored-tail` lever: the whole `if (result >= 0)` tail block
 *     duplicated into the guard arm (and again into the guard's else and after
 *     the outer if/else).  mwccarm did NOT cross-jump it at -O4,p: 324 compiled
 *     bytes (two copies written out), so the duplicated tail pushes the function
 *     size up without disabling predication.
 *   - a two-case `switch (flag_noconsume) { case 0: ...; break; case 1: break; }`
 *     (docs/idioms/a-two-case-switch-reproduces-branch-form-where-if-return-if-converts.md)
 *     -- still predicated.
 *   `volatile long consumed` no longer stops predication of a 3-instruction arm
 *   here: the field RMW is fully if-converted to `ldreq/addeq/streq`.  The cap is
 *   a front-end whole-function pin residue, as the note concluded; parked.
 *
 * sdk:      SOCLi_CopyCPSBuffer (libsoc.TWL.HYB.a(socl_read.o))
 *
 * symbols:
 *   func_02087988  0x02087988  arm
 *   func_0215DA34  0x0215DA34  arm  ov009
 *   func_02082EA4  0x02082EA4  arm
 *   func_0208799C  0x0208799C  arm
 */

struct SOCLRecvPipe {
	unsigned char pad[0xf8];
	long consumed;
	unsigned char padfc[2];
	signed char flag_noconsume;
};

struct SOCLSocket {
	unsigned char pad[0xa0];
	struct SOCLRecvPipe *recv_pipe;
	unsigned char pada4[8];
	short state;
	signed char flag_block;
	signed char flag_mode;
	unsigned short local_port;
};

extern unsigned long func_02087988(void);
extern unsigned long func_0208799C(unsigned long state);
extern unsigned char *func_0215DA34(struct SOCLSocket *socket, long *buffer_len, unsigned short *local_port,
				    unsigned short *remote_port, unsigned long *remote_ip);
extern void func_02082EA4(void *srcp, void *destp, unsigned long size);

static inline int isStream(signed char m)
{
	int r = 1;
	if (m != 0 && m != 4)
		r = 0;
	return r;
}

static int func_0215D92C(struct SOCLSocket *socket, void *buffer, int buffer_len, unsigned short *remote_port,
			 unsigned long *remote_ip)
{
	unsigned long enable;
	struct SOCLRecvPipe *recv_pipe;
	unsigned char *cpsbuffer;
	long cpsbuffer_len;
	unsigned short my_port;
	unsigned short his_port;
	unsigned long his_ip;
	int result;

	enable = func_02087988();
	cpsbuffer = func_0215DA34(socket, &cpsbuffer_len, &my_port, &his_port, &his_ip);
	if (cpsbuffer != 0) {
		result = cpsbuffer_len;
		if (result == 0) {
			result = -6;
		} else {
			if (buffer_len > result)
				buffer_len = result;
			if (isStream(socket->flag_mode))
				result = buffer_len;
			func_02082EA4(cpsbuffer, buffer, buffer_len);
			recv_pipe = socket->recv_pipe;
			if (recv_pipe->flag_noconsume == 0)
				recv_pipe->consumed += result;
		}
	} else {
		result = cpsbuffer_len == 0 ? 0 : -0x1c;
		socket->state &= ~6;
	}
	if (result >= 0) {
		if (remote_port != 0 && remote_ip != 0) {
			*remote_port = his_port;
			*remote_ip = his_ip;
		}
		if (socket->local_port == 0)
			socket->local_port = my_port;
	}
	func_0208799C(enable);
	return result;
}
