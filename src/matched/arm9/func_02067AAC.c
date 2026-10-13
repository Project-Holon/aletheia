/*
 * function: NNS_G2dSetRndCoreOamRegisterFunc
 * address:  0x02067AAC
 * packet:   pkt_02067AAC
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dSetRndCoreOamRegisterFunc.c \
 *       --func NNS_G2dSetRndCoreOamRegisterFunc --addr 0x02067AAC --arm --cc 1.1p1
 */

void NNS_G2dSetRndCoreOamRegisterFunc(int *p, int a, int b)
{
    p[7] = a;
    p[8] = b;
}
