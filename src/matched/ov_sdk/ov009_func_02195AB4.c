/*
 * function: func_02195AB4
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
 *   func_02197D94  0x02197D94  arm  ov009
 */

extern int func_02197D94(void **sock, char *addr, int outSize, int inSize, void *callback, int type);

int func_02195AB4(void **sock, char *addr, int outSize, int inSize, void *callback)
{
	return func_02197D94(sock, addr, outSize, inSize, callback, 0);
}
