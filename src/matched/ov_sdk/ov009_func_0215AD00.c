/*
 * function: CPS_TcpShutdown
 * address:  0x0215AD00
 * packet:   pkt_ov009_0215AD00
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPS_TcpShutdown (libcps.TWL.HYB.a network.o)
 * symbols:
 *   CPSi_SslShutdown                 0x02162dd8 arm
 *   CPSi_TcpShutdownRaw              0x0215aca0 arm
 *   OSi_ThreadInfo                   0x02150fec data
 */

struct _CPSSoc {
	unsigned char pad[9];
	unsigned char ssl;
};

extern void CPSi_SslShutdown(struct _CPSSoc *soc);
extern void CPSi_TcpShutdownRaw(struct _CPSSoc *soc);
extern int OSi_ThreadInfo;

void CPS_TcpShutdown(void)
{
	struct _CPSSoc *soc = *(struct _CPSSoc **)((char *)*(unsigned long *)((char *)&OSi_ThreadInfo + 4) + 0xa4);

	if (soc == 0)
		return;
	if (soc->ssl != 0)
		CPSi_SslShutdown(soc);
	CPSi_TcpShutdownRaw(soc);
}

