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

static int func_0215D92C(struct SOCLSocket *socket, void *buffer, int buffer_len, unsigned short *remote_port,
			 unsigned long *remote_ip)
{
	unsigned long enable;
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
			int dgram = 1;

			if (buffer_len > result)
				buffer_len = result;
			if (socket->flag_mode != 0 && socket->flag_mode != 4)
				dgram = 0;
			if (dgram != 0)
				result = buffer_len;
			func_02082EA4(cpsbuffer, buffer, buffer_len);
			{
				struct SOCLRecvPipe *recv_pipe = socket->recv_pipe;

				if (recv_pipe->flag_noconsume == 0)
					recv_pipe->consumed += result;
			}
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
