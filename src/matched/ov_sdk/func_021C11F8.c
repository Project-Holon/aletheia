/*
 * function: DWCi_MOVlGetChild
 * address:  0x021C11F8
 * packet:   pkt_021C11B8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_MOVlGetChild   0x021C11F8  arm
 *
 * Address of the object behind the global pointer, +0x1e280.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_MOVlGetChild.c \
 *       --func DWCi_MOVlGetChild --addr 0x021C11F8 --region ov016 --cc dsi/1.1p1 --arm
 */

char *DWCi_MOVlGetChild(void)
{
    return *(char **)0x021DE590 + 0x1e280;
}
