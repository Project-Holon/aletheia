/*
 * function: CPS_SocConsume
 * address:  0x0215B064
 * packet:   pkt_ov009_0215B064
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPS_SocConsume (libcps.TWL.HYB.a network.o)
 * symbols:
 *   CPSi_SslConsume                  0x02162a94 arm
 *   CPSi_SocConsumeRaw               0x0215af14 arm
 *   OSi_ThreadInfo                   0x02150fec data
 */

struct _CPSSoc {
	unsigned char pad[9];
	unsigned char ssl;
};

extern void CPSi_SslConsume(unsigned long len, struct _CPSSoc *soc);
extern void CPSi_SocConsumeRaw(unsigned long len, struct _CPSSoc *soc);
extern int OSi_ThreadInfo;

void CPS_SocConsume(unsigned long len)
{
	struct _CPSSoc *soc = *(struct _CPSSoc **)((char *)*(unsigned long *)((char *)&OSi_ThreadInfo + 4) + 0xa4);

	if (soc == 0)
		return;
	if (soc->ssl != 0)
		CPSi_SslConsume(len, soc);
	else
		CPSi_SocConsumeRaw(len, soc);
}

