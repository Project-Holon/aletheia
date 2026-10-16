/*
 * function: NNSi_G2dSetRndCoreImageProxyVeneer
 * address:  0x02066748
 * packet:   pkt_02066748
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_G2dSetRndCoreImageProxy  0x02067AA0  arm
 */

extern void NNS_G2dSetRndCoreImageProxy(int *p, int a, int b);
void NNSi_G2dSetRndCoreImageProxyVeneer(int *a0, int a1, int a2){ NNS_G2dSetRndCoreImageProxy(a0, a1, a2); }
