/*
 * function: MB_SEQ_StateOpenActionMenu
 * address:  0x021C6E98
 * packet:   pkt_ov136_021C6E98
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MB_SEQ_OpenFourEntryMenu  0x021C5AEC  thumb
 */

typedef unsigned char u8;
extern void MB_SEQ_OpenFourEntryMenu(u8 *);
int MB_SEQ_StateOpenActionMenu(u8 *p)
{
    MB_SEQ_OpenFourEntryMenu(p);
    return 0xE;
}
