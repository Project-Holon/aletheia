/*
 * unit:     no
 * function: NNSi_SndPlayerFreeSeqPlayer
 * address:  0x020733DC
 * packet:   pkt_02072EA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_SndSeqPlayerRelease  0x0207368C  arm
 */

struct Voice;
extern void NNSi_SndSeqPlayerRelease(struct Voice *v);
void NNSi_SndPlayerFreeSeqPlayer(void *h){ NNSi_SndSeqPlayerRelease(h); }
