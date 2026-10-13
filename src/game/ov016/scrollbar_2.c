/*
 * file:     scrollbar_2.c
 * function: DWCi_SBlDisp
 * address:  0x021CE9AC
 * packet:   pkt_021CE9AC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SBlDisp   0x021CE9AC  arm
 *
 * ARM tail-call thunk into func_021CEEE8.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SBlDisp.c \
 *       --func DWCi_SBlDisp --addr 0x021CE9AC --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021CEEE8(int scrollPos);

void DWCi_SBlDisp(int scrollPos)
{
    func_021CEEE8(scrollPos);
}
