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
