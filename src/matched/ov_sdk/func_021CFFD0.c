/*
 * function: DWCi_SNDlSetVolume
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
 *   DWCi_SNDlSetVolume   0x021CFFD0  arm
 *   NNS_SndHandleSetVolume  0x02072F34  arm  arm9
 *
 * Tail-call NNS_SndHandleSetVolume with the global object +0xa0 and the argument.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SNDlSetVolume.c \
 *       --func DWCi_SNDlSetVolume --addr 0x021CFFD0 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void NNS_SndHandleSetVolume(char *, unsigned int);

void DWCi_SNDlSetVolume(unsigned int v)
{
    NNS_SndHandleSetVolume(*(char **)0x021DE648 + 0xa0, v);
}
