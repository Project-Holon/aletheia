/*
 * function: gt2CreateSocket
 * address:  0x02195AB4
 * packet:   pkt_ov009_02195AB4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gt2CreateSocket (libdwcgsgt2.TWL.HYB.a(gt2main.o))
 *
 * symbols:
 *   gti2CreateSocket  0x02197D94  arm  ov009
 */

extern int gti2CreateSocket(void **sock, char *addr, int outSize, int inSize, void *callback, int type);

int gt2CreateSocket(void **sock, char *addr, int outSize, int inSize, void *callback)
{
	return gti2CreateSocket(sock, addr, outSize, inSize, callback, 0);
}
