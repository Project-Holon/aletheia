/*
 * function: func_0215C910
 * address:  0x0215C910
 * packet:   pkt_ov009_0215C910
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker:  all but 6 instructions exact: two schedule swaps in the id set-up.
 *           The image loads the pool base before mov r1,#0 (ip = 0), and
 *           stores the new rand x after the first id orr. The id is
 *           (u16)rand32(ctx, 0x10000) with rand32 the 64-bit LCG inline;
 *           the multiply-by-0x10000 form is what yields the unfolded
 *           lsl r7,r5,#16 / orr r7,r7,fp,lsr #16 pair. Tried: every order of
 *           ip/retries/id statements, initialisers, split LCG temp, u16/u64
 *           max, u16 return, a local context pointer (worse).
 *
 * sdk:      CPS_Resolve (libcps.TWL.HYB.a network.o)
 *
 * symbols:
 *   func_0215C814            0x0215C814  arm  ov009
 *   func_021578C8            0x021578C8  arm  ov009
 *   func_02157D8C            0x02157D8C  arm  ov009
 *   func_02157F60            0x02157F60  arm  ov009
 *   func_0215C8B4            0x0215C8B4  arm  ov009
 *   g_021A826C               0x021A826C  data
 *   g_021A82DC               0x021A82DC  data
 *
 * lane T5 (2026-09-30).  Pin sweep (all 9 dsi compilers x 4 flag sets): 1.1p1
 * -O4,p at 380 bytes / 24 concrete bytes is the unique best (1.6sp1/sp2 give 30).
 * Residue already named in the blocker above (the two schedule swaps in the id
 * set-up); no new spelling was spent on it this wave.
 *
 * lane U41 (2026-09-30).  Re-measured: still 380 compiled / 380 extent with 24
 * concrete bytes, three one-slot schedule swaps:
 *   +0008  image `ldr r2, [pc, #0x164]` | ours `mov r1, #0`
 *   +006c  image `orr r7, r7, fp, lsr #16` | ours `str r6, [r2, #0x78]`
 *   +007c  image `mov sl, r0` | ours `str r4, [r2, #0x7c]`
 * Eleven more spellings measured, all 24 diffs: `retries = 0;` before `ip = 0;`,
 * the two id stores first, a split id[i] pair, `ask_this` before the ids,
 * `ip = 0, retries = 0;` comma, the initialisers moved into the declarations,
 * `retries` declared `long`, `0u`, and the loop counter fixed in the `for`
 * header.  The 5/5 pool words and all 7 relocations resolve; this is the list
 * scheduler's slot tie-break, not a body shape.
 *
 * lane W8 (2026-09-30).  Two more spellings against the same three one-slot
 * swaps, both no better: computing rand32's return into a temp BEFORE the
 * context->x store (the compute-a-stores-operands-before-the-store lever) is
 * still 24 (the front end canonicalises it back); an aggregate initialiser
 * `unsigned short id[2] = { rand32(...), rand32(...) };` disables the
 * cross-call interleaving and blows up to 97.  Residue unchanged; all 7
 * relocations resolve.
 *
 * lane W8.2 (2026-10-01).  Three more spellings, all still exactly these three
 * one-slot schedule swaps at 380/24: `rand32` rewritten to compute both the
 * LCG x and the return into named temps before the `context->x` store (the
 * store-operands-first lever) stays 24; `const char *name` on the read-only
 * source parameter (the const-source-pointer tie lever) stays 24; `const` on
 * the read-only extern `g_021A82DC[2]` blows up to 384/159.  Reverted to the
 * 24-byte state.  This is the list scheduler's slot tie-break, not a body
 * shape: all 7 relocations resolve and every instruction opcode is right.
 *
 * lane W8.3 (2026-10-01).  Confirmed this is the same list-scheduler tie the
 * sibling rand32 consumer in this very overlay already documents:
 * docs/idioms/a-pool-word-order-residue-is-a-list-scheduler-tie.md
 * (ov009_func_021685CC.c, DWCi_GetMathRand32, identical 64-bit LCG rand32
 * body).  The three residue slots (+0008 context ldr above mov r1,#0; +006c
 * orr above str r6; +007c mov sl above str r4) are all independent-issue
 * hoists around the inlined rand32 epilogue, i.e. the same scheduler
 * slot tie-break the idiom says no C shape reaches.  No new spelling spent;
 * 380/24 unchanged, all 7 relocations resolve.
 */

typedef struct {
	unsigned long long x;
	unsigned long long mul;
	unsigned long long add;
} RandCtx;

extern int func_0215C814(unsigned char *name, unsigned long *pip);
extern unsigned long func_021578C8(unsigned long ip);
extern unsigned char (*func_02157D8C(unsigned long ip))[6];
extern unsigned char (*func_02157F60(unsigned long ip))[6];
extern unsigned long func_0215C8B4(unsigned char *name, unsigned long dnsip, unsigned short id);
struct NetVars {
	unsigned char pad0[0x78];
	RandCtx rand;
};
extern struct NetVars g_021A826C;
extern unsigned long g_021A82DC[2];

static inline unsigned long rand32(RandCtx *context, unsigned long max)
{
	context->x = context->mul * context->x + context->add;
	return (unsigned long)(max ? (((context->x >> 32) * max) >> 32) : (context->x >> 32));
}

unsigned long func_0215C910(char *name)
{
	unsigned long ip;
	int retries;
	int server;
	unsigned short id[2];
	unsigned char ask_this[2];
	unsigned long t;

	ip = 0;
	retries = 0;
	id[0] = (unsigned short)rand32(&g_021A826C.rand, 0x10000);
	id[1] = (unsigned short)rand32(&g_021A826C.rand, 0x10000);
	if (func_0215C814((unsigned char *)name, &ip))
		return ip;
	ask_this[0] = 1;
	ask_this[1] = 1;
	for (; retries < 3; retries++) {
		for (server = 0; server < 2; server++) {
			if (!ask_this[server])
				continue;
			if (g_021A82DC[server] == 0 || (t = func_021578C8(g_021A82DC[server])) == 0) {
				ask_this[server] = 0;
				continue;
			}
			if (func_02157D8C(t) == 0 && func_02157F60(t) == 0) {
				ask_this[server] = 0;
				continue;
			}
			ip = func_0215C8B4((unsigned char *)name, g_021A82DC[server], id[server]);
			if (ip != 0 && ip != 0xffffffff)
				goto done;
			if (ip == 0xffffffff)
				ask_this[server] = 0;
		}
	}
done:
	if (ip == 0xffffffff)
		ip = 0;
	return ip;
}
