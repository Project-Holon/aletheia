/*
 * function: STARTMENU_RowTileY
 * address:  0x021BB840
 * packet:   pkt_ov088_021BB840
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Screen row of a menu row top y: y plus the scroll offset at +0x130 / 8.
 */
#include "../include/Obj20820.h"

typedef signed char s8;

int STARTMENU_RowTileY(char *p, int y)
{
    return (s8)(y + ((struct Obj20820 *)p)->f130 / 8);
}
