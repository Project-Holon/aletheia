/*
 * function: DWCi_MOVlChangeCallback
 * address:  0x021C11D4
 * packet:   pkt_021C1030
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_MOVlChangeCallback   0x021C11D4  arm
 *
 * Store a word at +0x1e298 of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_MOVlChangeCallback.c \
 *       --func DWCi_MOVlChangeCallback --addr 0x021C11D4 --region ov016 --cc dsi/1.1p1 --arm
 */

void DWCi_MOVlChangeCallback(unsigned int v)
{
    char *p = *(char **)0x021DE590 + 0x1e000;
    unsigned int *q = (unsigned int *)(p + 0x298);
    *q = v;
}
