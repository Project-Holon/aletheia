/*
 * function: DWCi_USBAPlSetCallback
 * address:  0x021D0DC8
 * packet:   pkt_021D0014
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_USBAPlSetCallback   0x021D0DC8  arm
 *
 * Store a word at +0x1370 of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_USBAPlSetCallback.c \
 *       --func DWCi_USBAPlSetCallback --addr 0x021D0DC8 --region ov016 --cc dsi/1.1p1 --arm
 */

void DWCi_USBAPlSetCallback(unsigned int v)
{
    *(unsigned int *)(*(char **)0x021DE654 + 0x1370) = v;
}
