/*
 * function: DWCi_Ndi_intToStrFigure
 * address:  0x021C7A74
 * packet:   pkt_ov114_021C7A74
 * region:   ov114
 * compiler: 1.2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Ndi_intToStrFigure (libdwcnd.TWL.HYB.a(dwci_nd.o))
 *
 * symbols:
 *   _ll_udiv  0x0209C00C  arm
 *   sDwciNdPowersOfTen  0x021CE138  data
 *
 * Renders the 64-bit value n as decimal into p, with `figure` digits of
 * minimum width (digits above the figure are suppressed until the first
 * significant one). Returns the number of characters written.
 *
 * Closed lane T8, 2026-09-30.  Two levers, both required:
 *
 *  1. the 64-bit update `n -= (u64)x * g[i]` is written BEFORE the store
 *     `p[len] = x + '0'`, not after it.  With the store first the scheduler
 *     keeps the umull/mla scratch one register pair lower (r2/r1 instead of
 *     r3/r2) and sinks the store above the subs/sbc, 15 bytes.
 *  2. `i` and `b` are both cleared in the `for` initialiser:
 *     `for (i = 0, b = 0; i < 16; i++)`.  With `b = 0;` on its own line ahead
 *     of the loop the initialiser is emitted `mov r0, r5` before `mov r4, r5`,
 *     2 bytes.
 *
 * This translation unit is a later build than the rest of the region: the
 * 1.1/1.1p1 trees produce 208 bytes (four short) with 118 concrete bytes off,
 * while 1.2 / 1.2p1 / 1.2p2 / 1.3 / 1.3p1 all reproduce the 212-byte original
 * byte for byte at -O4,p, -O4,s, -O4 and -O3.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov114_func_021C7A74.c \
 *       --func DWCi_Ndi_intToStrFigure --addr 0x021C7A74 --region ov114 --arm \
 *       --cc 1.2 --lang c99
 */

typedef unsigned long long u64;
extern u64 sDwciNdPowersOfTen[];

int DWCi_Ndi_intToStrFigure(char *p, u64 n, int figure)
{
	int i;
	int b;
	unsigned int x;
	int len = 0;
	if (n >= 100000000000000000ULL)
		return -1;
	for (i = 0, b = 0; i < 16; i++) {
		if (n >= sDwciNdPowersOfTen[i]) {
			x = n / sDwciNdPowersOfTen[i];
			n -= (u64)x * sDwciNdPowersOfTen[i];
			p[len] = x + '0';
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
