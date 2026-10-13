/*
 * function: DWCi_SNDlStop
 * address:  0x021D0014
 * packet:   pkt_021D0014
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SNDlStop   0x021D0014  arm
 *   NNS_SndHandleStopSeq  0x02072E7C  arm  arm9
 *
 * Tail-call NNS_SndHandleStopSeq with the global object +0xa0 and a zero.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SNDlStop.c \
 *       --func DWCi_SNDlStop --addr 0x021D0014 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void NNS_SndHandleStopSeq(void **r0, int fadeFrame);

void DWCi_SNDlStop(void)
{
    NNS_SndHandleStopSeq((void **)(*(char **)0x021DE648 + 0xa0), 0);
}
