/*
 * function: DWCi_MOV_WH_GetBitmap
 * address:  0x021D323C
 * packet:   pkt_021D3228
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_MOV_WH_GetBitmap   0x021D323C  arm
 *
 * Halfword at +0x52 of the object behind the pointer at 0x021DE664.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_MOV_WH_GetBitmap.c \
 *       --func DWCi_MOV_WH_GetBitmap --addr 0x021D323C --region ov016 --cc dsi/1.1p1 --arm
 */

unsigned short DWCi_MOV_WH_GetBitmap(void)
{
    char **p = (char **)0x021DE660;
    unsigned short *q = (unsigned short *)(p[1] + 0x52);
    return *q;
}
