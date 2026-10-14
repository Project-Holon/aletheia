/*
 * function: DWCi_SceneOptMovWait_DetectFold
 * address:  0x021C44EC
 * packet:   pkt_021C44EC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SceneOptMovWait_DetectFold   0x021C44EC  arm
 *
 * Bit 15 of the halfword at 0x02FFFFA8, as 0/1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovWait_DetectFold.c \
 *       --func DWCi_SceneOptMovWait_DetectFold --addr 0x021C44EC --region ov016 --cc dsi/1.1p1 --arm
 */

int DWCi_SceneOptMovWait_DetectFold(void)
{
    return ((*(unsigned short *)0x02FFFFA8 & 0x8000) >> 15) != 0;
}
