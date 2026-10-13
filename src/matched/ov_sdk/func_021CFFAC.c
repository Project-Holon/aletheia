/*
 * function: DWCi_SNDlPlay
 * address:  0x021CFFAC
 * packet:   pkt_021CF440
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SNDlPlay   0x021CFFAC  arm
 *
 * Tail-call func_02075618 with the global object +0xa0, a zero and the argument.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SNDlPlay.c \
 *       --func DWCi_SNDlPlay --addr 0x021CFFAC --region ov016 --cc dsi/1.1p1 --arm
 */

typedef unsigned int   u32;
extern u32 func_02075618(u32 a, u32 b, u32 c);

void DWCi_SNDlPlay(unsigned int v)
{
    func_02075618((u32)(*(char **)0x021DE648 + 0xa0), 0, v);
}
