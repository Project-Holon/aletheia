/*
 * function: DWCi_MOV_WH_GetSystemState
 * address:  0x021D3250
 * packet:   pkt_021D3228
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_MOV_WH_GetSystemState   0x021D3250  arm
 *
 * Word at +0x40 of the object behind the pointer at 0x021DE664.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_MOV_WH_GetSystemState.c \
 *       --func DWCi_MOV_WH_GetSystemState --addr 0x021D3250 --region ov016 --cc dsi/1.1p1 --arm
 */

unsigned int DWCi_MOV_WH_GetSystemState(void)
{
    char **p = (char **)0x021DE660;
    unsigned int *q = (unsigned int *)(p[1] + 0x40);
    return *q;
}
