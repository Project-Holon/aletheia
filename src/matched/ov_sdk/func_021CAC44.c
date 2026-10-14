/*
 * function: DWCi_SceneSetRakuButton_DetectFold
 * address:  0x021CAC44
 * packet:   pkt_021CA390
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SceneSetRakuButton_DetectFold   0x021CAC44  arm
 *
 * Bit 15 of the halfword at 0x02FFFFA8, as 0/1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetRakuButton_DetectFold.c \
 *       --func DWCi_SceneSetRakuButton_DetectFold --addr 0x021CAC44 --region ov016 --cc dsi/1.1p1 --arm
 */

int DWCi_SceneSetRakuButton_DetectFold(void)
{
    return ((*(unsigned short *)0x02FFFFA8 & 0x8000) >> 15) != 0;
}
