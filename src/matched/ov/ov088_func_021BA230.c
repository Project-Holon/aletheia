/*
 * function: STARTMENU_StateSelectAnim
 * address:  0x021BA230
 * packet:   pkt_ov088_021BA230
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STARTMENU_RowTileY  0x021BB840  thumb  ov088
 *   STARTMENU_PaintRowPalette  0x021BB810  thumb  ov088
 */
#include "../include/Obj01369.h"

extern int STARTMENU_RowTileY(char *p, int y);
typedef unsigned char  u8;
extern void STARTMENU_PaintRowPalette(void *p, u8 row, int y, int pal);

int STARTMENU_StateSelectAnim(char *p)
{
    switch (((struct Obj01369 *)p)->f12D) {
    case 0:
    case 2:
        if (((struct Obj01369 *)p)->f12E == 0) {
            STARTMENU_PaintRowPalette(p, *(unsigned char *)(p + ((struct Obj01369 *)p)->f128 + 0x120),
                          STARTMENU_RowTileY(p, ((struct Obj01369 *)p)->f12F), 3);
            ((struct Obj01369 *)p)->f12E = 4;
            ((struct Obj01369 *)p)->f12D = ((struct Obj01369 *)p)->f12D + 1;
        } else {
            ((struct Obj01369 *)p)->f12E -= 1;
        }
        break;
    case 1:
    case 3:
        if (((struct Obj01369 *)p)->f12E == 0) {
            STARTMENU_PaintRowPalette(p, *(unsigned char *)(p + ((struct Obj01369 *)p)->f128 + 0x120),
                          STARTMENU_RowTileY(p, ((struct Obj01369 *)p)->f12F), 1);
            ((struct Obj01369 *)p)->f12E = 4;
            ((struct Obj01369 *)p)->f12D = ((struct Obj01369 *)p)->f12D + 1;
        } else {
            ((struct Obj01369 *)p)->f12E -= 1;
        }
        break;
    case 4:
        return ((struct Obj01369 *)p)->f140;
    }
    return 3;
}
