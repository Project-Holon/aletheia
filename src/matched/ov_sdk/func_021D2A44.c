/*
 * function: DWCi_MOV_WH_SetError
 * address:  0x021D2A44
 * packet:   pkt_021D28B4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_MOV_WH_SetError   0x021D2A44  arm
 *
 * Store v unless the state word at +0x40 is 9 or 10.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_MOV_WH_SetError.c \
 *       --func DWCi_MOV_WH_SetError --addr 0x021D2A44 --region ov016 --cc dsi/1.1p1 --arm
 */

void DWCi_MOV_WH_SetError(unsigned int v)
{
    char **p = (char **)0x021DE660;
    char *q = p[1];
    if (*(unsigned int *)(q + 0x40) - 9 > 1)
        *(unsigned int *)(q + 0x54) = v;
}
