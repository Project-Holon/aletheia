/*
 * file:     unit_021573C4_p14.c
 * unit:     yes
 * function: func_02159FE8, func_0215A0CC, func_0215A108
 * address:  0x02159FE8
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
 *   func_02159244  0x02159244  arm  ov009
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   func_02159404  0x02159404  arm  ov009
 *   func_02085868  0x02085868  arm
 *   func_02159494  0x02159494  arm  ov009
 *   func_021594A4  0x021594A4  arm  ov009
 *   find_socket                      0x02159244 arm
 *   OS_YieldThread                   0x020858d8 arm
 *   OS_WakeupThreadDirect            0x02085868 arm
 *   func_02157838            0x02157838  arm  ov009
 *   func_02159720            0x02159720  arm  ov009
 *   func_021597F8            0x021597F8  arm  ov009
 *   func_02159A80            0x02159A80  arm  ov009
 *   func_0215A0CC            0x0215A0CC  arm  ov009
 */
struct _OSThread;
struct _CPSSoc_02159FE8 {
	void *thread;
	unsigned long waiting;
	unsigned char state;
	unsigned char pad0[0x1b];
	unsigned long ackno;
};

struct _CPSSoc_0215A0CC {
	struct _OSThread *thread;
	unsigned long block_type;
	unsigned char state;
};

extern struct _CPSSoc_02159FE8 *func_02159244(unsigned char *iphdr, unsigned char *tcphdr);
extern unsigned long func_02087988(void);
extern unsigned long func_0208799C(unsigned long state);
extern void func_02159404(struct _CPSSoc_02159FE8 *soc, int flush);
extern void func_02085868(void *thread);
extern void func_02159494(int a);
extern void func_021594A4(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
extern struct _CPSSoc_0215A0CC *find_socket(unsigned char *iphdr, unsigned char *tcphdr);
extern void OS_YieldThread(void);
extern void OS_WakeupThreadDirect(struct _OSThread *thread);
extern unsigned long func_02157838(unsigned char *tcpudp_hdr, unsigned long len, unsigned char *ip_hdr, unsigned short proto);
extern void func_02159720(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
extern void func_021597F8(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
extern void func_02159A80(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
extern void func_0215A0CC(unsigned char *iphdr, unsigned char *tcphdr);
void func_02159FE8(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
void func_0215A108(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);


/*
 * sdk:      dt_fin (libcps.TWL.HYB.a(network.o))
 */
void func_02159FE8(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len)
{
	struct _CPSSoc_02159FE8 *soc;
	unsigned long enabled;

	soc = func_02159244(iphdr, tcphdr);
	if (soc == 0)
		return;
	enabled = func_02087988();
	switch (soc->state) {
	case 7:
		soc->ackno++;
		soc->state = 9;
		func_0208799C(enabled);
		func_02159404(soc, 2);
		break;
	case 8:
		soc->ackno++;
		func_0208799C(enabled);
		func_02159404(soc, 2);
		soc->state = 0;
		if (soc->waiting == 2) {
			soc->waiting = 0;
			func_02085868(soc->thread);
		}
		break;
	case 4:
		soc->ackno++;
		soc->state = 6;
		func_0208799C(enabled);
		func_02159494((int)soc);
		break;
	default:
		func_0208799C(enabled);
		func_021594A4(iphdr, tcphdr, len);
		break;
	}
}


static void dt_rst(unsigned char *iphdr, unsigned char *tcphdr)
{
	struct _CPSSoc_0215A0CC *soc = find_socket(iphdr, tcphdr);

	if (soc == 0)
		return;
	OS_YieldThread();
	soc->state = 0;
	if (soc->block_type - 1 <= 1) {
		soc->block_type = 0;
		OS_WakeupThreadDirect(soc->thread);
	}
}


/*
 * sdk:      dispatch_tcp (libcps.TWL.HYB.a network.o)
 */
void func_0215A108(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len)
{
	if (len < 20)
		return;
	if ((tcphdr[0xc] & 0xf0) < 0x50)
		return;
	if (len < ((unsigned long)(tcphdr[0xc] & 0xf0) >> 2))
		return;
	if (func_02157838(tcphdr, len, iphdr, 6) != 0)
		return;
	len -= (unsigned long)(tcphdr[0xc] & 0xf0) >> 2;
	switch (tcphdr[0xd] & 0x17) {
	case 0x02:
		if (tcphdr[0xd] & 0x28)
			return;
		func_02159720(iphdr, tcphdr, len);
		break;
	case 0x12:
		if (tcphdr[0xd] & 0x28)
			return;
		func_021597F8(iphdr, tcphdr, len);
		break;
	case 0x10:
	case 0x11:
		func_02159A80(iphdr, tcphdr, len);
		break;
	case 0x01:
		func_02159FE8(iphdr, tcphdr, len);
		break;
	default:
		if (tcphdr[0xd] & 0x04)
			func_0215A0CC(iphdr, tcphdr);
		else
			func_021594A4(iphdr, tcphdr, len);
		break;
	}
}
