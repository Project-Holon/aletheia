/*
 * function: BEACON_VIEW_SetEntryPosition
 * address:  0x021F1218
 * packet:   pkt_ov032_021F1218
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BEACON_VIEW_SetEntryPosition 0x021F1218 thumb
 *   BEACON_VIEW_MoveActorSurface 0x021F0DE0 thumb
 *   BMP_OAM_SetPos 0x0202590C thumb
 */
#include "../include/Obj00225.h"

extern void BEACON_VIEW_MoveActorSurface(void *, short, short);
typedef signed short   s16;
struct Grid;
extern void BMP_OAM_SetPos(struct Grid *g, s16 x, s16 y);

void BEACON_VIEW_SetEntryPosition(char *p, short x, short y)
{
    ((struct Obj00225 *)p)->f8 = x;
    ((struct Obj00225 *)p)->fA = y;
    BEACON_VIEW_MoveActorSurface(((struct Obj00225 *)p)->fC, x, y);
    BEACON_VIEW_MoveActorSurface(((struct Obj00225 *)p)->f10, x + 0x20, y + 0x18);
    BEACON_VIEW_MoveActorSurface(((struct Obj00225 *)p)->f14, x + 0x3c, y + 0x18);
    BMP_OAM_SetPos(((struct Obj00225 *)p)->f18, x + 0x48, y + 0x10);
}
