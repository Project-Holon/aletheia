/*
 * function: NNS_G2dSetRndCoreImageProxy
 * address:  0x02067AA0
 * packet:   pkt_02067AA0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dSetRndCoreImageProxy.c \
 *       --func NNS_G2dSetRndCoreImageProxy --addr 0x02067AA0 --arm --cc 1.1p1
 */

void NNS_G2dSetRndCoreImageProxy(int *p, int a, int b)
{
    p[2] = a;
    p[3] = b;
}
