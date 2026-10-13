/*
 * function: IRC_SetRecvCallback
 * address:  0x0217A584
 * packet:   pkt_ov015_0217A584
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_0217ABA8                   0x0217ABA8  data
*/

extern unsigned char d_0217ABA8[];

void IRC_SetRecvCallback(void *cb)
{
	*(void **)(d_0217ABA8 + 8) = cb;
}

