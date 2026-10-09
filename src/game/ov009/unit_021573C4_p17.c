/*
 * file:     unit_021573C4_p17.c
 * unit:     yes
 * function: func_02159494, func_021594A4
 * address:  0x02159494
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
 *   func_021593A8  0x021593A8  arm
 *   MI_CpuFill8              0x02082BCC  arm
 *   g_021A8484               0x021A8484  data
 */
#define SWAP16(x) ((unsigned short)(((x) >> 8) | ((x) << 8)))
#define GET16(p) SWAP16(*(unsigned short *)(p))
#define GET32(p) (((unsigned long)GET16(p) << 16) | GET16((p) + 2))
struct _CPSSoc {
	unsigned char pad0[0xa];
	unsigned short local_port;      /* 0x0a */
	unsigned char padc[0xc];
	unsigned short remote_port;     /* 0x18 */
	unsigned char pad1a[2];
	unsigned long remote_ip;        /* 0x1c */
	unsigned char pad20[4];
	unsigned long ackno;            /* 0x24 */
	unsigned char pad28[0xc];
	unsigned long seqno;            /* 0x34 */
	unsigned char pad38[0x68];
};

extern void func_021593A8(char *soc, unsigned char flag);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
void func_02159494(int a);
void func_021594A4(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
extern struct _CPSSoc g_021A8484;


/*
 * Tail call that supplies the second argument 0x11.
 */
void func_02159494(int a)
{
    func_021593A8((char *)a, 0x11);
}


/*
 * sdk:      _tcp_send_rst (libcps.TWL.HYB.a network.o)
 */
void func_021594A4(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len)
{
	struct _CPSSoc *soc;

	soc = &g_021A8484;
	MI_CpuFill8(soc, 0, sizeof(struct _CPSSoc));
	soc->local_port = GET16(tcphdr + 2);
	soc->remote_port = GET16(tcphdr);
	soc->remote_ip = GET32(iphdr + 0xc);
	if (tcphdr[0xd] & 0x10) {
		soc->seqno = GET32(tcphdr + 8);
		func_021593A8((char *)soc, 4);
		return;
	}
	soc->seqno = 0;
	soc->ackno = GET32(tcphdr + 4) + len;
	if (tcphdr[0xd] & 3)
		soc->ackno++;
	func_021593A8((char *)soc, 0x14);
}
