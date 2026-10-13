/*
 * function: DWCi_SNDlSetPitch
 * address:  0x021CFFF0
 * packet:   pkt_021CF440
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SNDlSetPitch   0x021CFFF0  arm
 *   NNS_SndHandleSetTrackPitch  0x02073018  arm  arm9
 *
 * Tail-call NNS_SndHandleSetTrackPitch with the global object +0xa0 and two arguments.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SNDlSetPitch.c \
 *       --func DWCi_SNDlSetPitch --addr 0x021CFFF0 --region ov016 --cc dsi/1.1p1 --arm
 */

typedef unsigned int   u32;
struct Obj;
extern void NNS_SndHandleSetTrackPitch(struct Obj *o, u32 v, u32 w);

void DWCi_SNDlSetPitch(unsigned int a, unsigned int b)
{
    NNS_SndHandleSetTrackPitch((struct Obj *)(*(char **)0x021DE648 + 0xa0), a, b);
}
