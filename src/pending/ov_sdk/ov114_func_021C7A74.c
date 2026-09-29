/*
 * function: func_021C7A74
 * address:  0x021C7A74
 * packet:   pkt_ov114_021C7A74
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      DWCi_Ndi_intToStrFigure (libdwcnd.TWL.HYB.a(dwci_nd.o))
 *
 * symbols:
 *   _ll_udiv  0x0209C00C  arm
 *   g_021CE138  0x021CE138  data
 *
 * near miss (w4_s4): register allocation only. Original keeps the sticky flag b in r0
 * (mov r0,r5 before the loop) and loads the u64 table twice (hi word then lo word
 * from two pool loads); mine keeps b in r1 and one table load. 15+ variants tried.
 */

typedef unsigned long long u64;
extern u64 g_021CE138[];

int func_021C7A74(char *p, u64 n, int figure)
{
	int i;
	int b;
	unsigned int x;
	int len = 0;
	if (n >= 100000000000000000ULL)
		return -1;
	b = 0;
	for (i = 0; i < 16; i++) {
		if (n >= g_021CE138[i]) {
			x = n / g_021CE138[i];
			p[len] = x + '0';
			n -= (u64)x * g_021CE138[i];
			b = 1;
		} else {
			if (b == 0 && 17 - i > figure)
				continue;
			p[len] = '0';
		}
		len++;
	}
	p[len] = n + '0';
	return len + 1;
}
