/*
 * function: func_02157290
 * address:  0x02157290
 * packet:   pkt_ov009_02157290
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker:  all but 4 instructions exact: a schedule difference at +0x10..+0x34.
 *           The image fills the load delay after ldr r1,[r1,#0x50] with
 *           str r0,[r2,#0x4c] (reason) and emits mov r5,#0 late, next to
 *           mov r3,#1; here mov r5,#0 is hoisted into that slot. Tried:
 *           every position of the reason store and of the had_ip read among
 *           the six zero stores, chained zero stores, ternary / if-set /
 *           unsigned char had_ip, enum-typed zeros, struct vs cast access,
 *           if-body instead of early return.
 *
 * sdk:      reset_network_vars (libcps.TWL.HYB.a network.o)
 *
 * symbols:
 *   MI_CpuFill8              0x02082BCC  arm
 *   OS_WakeupThreadDirect    0x02085868  arm
 *   CPSi_SslCleanup          0x02162FA4  arm  ov009
 *   g_021A826C               0x021A826C  data
 *   g_021A8384               0x021A8384  data
 *   g_02150FEC               0x02150FEC  data
 *   g_021A8A64               0x021A8A64  data
 */

struct _OSThread;

struct NetVars {
	unsigned char pad00[0x10];
	unsigned long netmask;          /* 0x10 */
	unsigned char pad14[0x08];
	unsigned long v1c;              /* 0x1c */
	unsigned char pad20[0x0c];
	unsigned long v2c;              /* 0x2c */
	unsigned char pad30[0x14];
	void (*free)(void *);           /* 0x44 */
	unsigned char pad48[0x04];
	int noip_reason;                /* 0x4c */
	unsigned long myip;             /* 0x50 */
	unsigned char pad54[0x1c];
	unsigned long v70;              /* 0x70 */
	unsigned long v74;              /* 0x74 */
};

struct FragEnt {
	unsigned char pad0[4];
	unsigned short used;
	unsigned char pad6[0x2e];
	void *buf;
};

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void OS_WakeupThreadDirect(struct _OSThread *thread);
extern void CPSi_SslCleanup(void);
extern struct NetVars g_021A826C;
extern unsigned char g_021A8384[];
extern int g_02150FEC;
extern struct FragEnt g_021A8A64[8];

void func_02157290(int reason)
{
	struct _OSThread *t;
	unsigned char *soc;
	int i;
	int had_ip;

	had_ip = g_021A826C.myip != 0;
	g_021A826C.noip_reason = reason;
	g_021A826C.myip = 0;
	g_021A826C.netmask = 0;
	g_021A826C.v2c = 0;
	g_021A826C.v70 = 0;
	g_021A826C.v74 = 0;
	g_021A826C.v1c = 0;
	if (!had_ip)
		return;
	MI_CpuFill8(g_021A8384, 0, 0x60);
	for (t = *(struct _OSThread **)((char *)&g_02150FEC + 8); t != 0; t = *(struct _OSThread **)((char *)t + 0x68)) {
		soc = *(unsigned char **)((char *)t + 0xa4);
		if (soc != 0 && *(struct _OSThread **)soc != 0) {
			if (soc[8] != 0xa && soc[8] != 0xb)
				soc[8] = 0;
			if (*(unsigned long *)(soc + 4) != 0) {
				*(unsigned long *)(soc + 4) = 0;
				OS_WakeupThreadDirect(*(struct _OSThread **)soc);
			}
		}
	}
	for (i = 0; i < 8; i++) {
		if (g_021A8A64[i].used != 0) {
			g_021A826C.free(g_021A8A64[i].buf);
			g_021A8A64[i].used = 0;
		}
	}
	CPSi_SslCleanup();
}
