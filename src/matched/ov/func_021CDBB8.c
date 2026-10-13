/*
 * function: DWCi_SceneSetUsbCompleteNop
 * address:  0x021CDBB8
 * packet:   pkt_021CC0E4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SceneSetUsbCompleteNop   0x021CDBB8  arm
 *
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetUsbCompleteNop.c \
 *       --func DWCi_SceneSetUsbCompleteNop --addr 0x021CDBB8 --region ov016 --cc dsi/1.1p1 --arm
 */

void DWCi_SceneSetUsbCompleteNop(void)
{
}
