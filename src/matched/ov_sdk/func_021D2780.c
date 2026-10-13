/*
 * function: DWCi_MOV_MBP_GetState
 * address:  0x021D2780
 * packet:   pkt_021D276C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_MOV_MBP_GetState   0x021D2780  arm
 *
 * Read the halfword at the head of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_MOV_MBP_GetState.c \
 *       --func DWCi_MOV_MBP_GetState --addr 0x021D2780 --region ov016 --cc dsi/1.1p1 --arm
 */

unsigned short DWCi_MOV_MBP_GetState(void)
{
    return *(unsigned short *)(*(char **)0x021DE65C);
}
