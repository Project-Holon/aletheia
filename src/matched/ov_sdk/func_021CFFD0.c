/*
 * function: func_021CFFD0
 * address:  0x021CFFD0
 * packet:   pkt_021CF3F0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CFFD0   0x021CFFD0  arm
 *   NNS_SndHandleSetSeqPriority  0x02072F34  arm  arm9
 *
 * Tail-call NNS_SndHandleSetSeqPriority with the global object +0xa0 and the argument.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CFFD0.c \
 *       --func func_021CFFD0 --addr 0x021CFFD0 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void NNS_SndHandleSetSeqPriority(char *, unsigned int);

void func_021CFFD0(unsigned int v)
{
    NNS_SndHandleSetSeqPriority(*(char **)0x021DE648 + 0xa0, v);
}
