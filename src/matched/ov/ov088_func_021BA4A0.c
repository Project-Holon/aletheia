/*
 * function: STARTMENU_StateScroll
 * address:  0x021BA4A0
 * packet:   pkt_ov088_021BA4A0
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BLINK_PALANM_ResetPhase  0x0202EB04  thumb
 *   BG_SYS_ResetSlot  0x02041EE4  arm
 *   STARTMENU_RowTileY  0x021BB840  thumb  ov088
 *   STARTMENU_PaintRowPalette  0x021BB810  thumb  ov088
 *   STARTMENU_ScrollRowActors  0x021BB858  thumb  ov088
 */
#include "../include/Obj01228.h"

struct CodeIn;
extern void BLINK_PALANM_ResetPhase(struct CodeIn *p);
typedef unsigned int   u32;
extern void BG_SYS_ResetSlot(u32 index, u32 a, u32 b);
extern int STARTMENU_RowTileY(char *p, int y);
typedef unsigned char  u8;
extern void STARTMENU_PaintRowPalette(void *p, u8 row, int y, int pal);
extern void STARTMENU_ScrollRowActors(char *p, int d);

int STARTMENU_StateScroll(char *p)
{
    if (((struct Obj01228 *)p)->f134 == 3) {
        ((struct Obj01228 *)p)->f134 = 0;
        ((struct Obj01228 *)p)->f138 = 0;
        BLINK_PALANM_ResetPhase((struct CodeIn *)(((struct Obj01228 *)p)->f11C));
        STARTMENU_PaintRowPalette(p, *(unsigned char *)(p + ((struct Obj01228 *)p)->f128 + 0x120),
                      STARTMENU_RowTileY(p, ((struct Obj01228 *)p)->f12F), 2);
        return 5;
    }
    ((struct Obj01228 *)p)->f130 += ((struct Obj01228 *)p)->f138;
    if (((struct Obj01228 *)p)->f130 < 0)
        ((struct Obj01228 *)p)->f130 += 0x200;
    else if (((struct Obj01228 *)p)->f130 >= 0x200)
        ((struct Obj01228 *)p)->f130 -= 0x200;
    BG_SYS_ResetSlot(1, 3, ((struct Obj01228 *)p)->f130);
    BG_SYS_ResetSlot(2, 3, ((struct Obj01228 *)p)->f130);
    STARTMENU_ScrollRowActors(p, -((struct Obj01228 *)p)->f138);
    ((struct Obj01228 *)p)->f134 = ((struct Obj01228 *)p)->f134 + 1;
    return 6;
}
