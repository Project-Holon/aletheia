/*
 * function: BEACON_VIEW_RunSelect
 * address:  0x021F27CC
 * packet:   pkt_ov032_021F27CC
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BEACON_VIEW_RunSelect 0x021F27CC thumb
 *   BEACON_VIEW_UpdateSelect 0x021F0438 thumb ov032
 */

typedef unsigned char  u8;
extern int BEACON_VIEW_UpdateSelect(u8 *p);

int BEACON_VIEW_RunSelect(char *p)
{
    return BEACON_VIEW_UpdateSelect((u8 *)p);
}
