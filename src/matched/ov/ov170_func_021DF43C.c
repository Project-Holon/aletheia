/*
 * function: BOX2_MAIN_MoveCursorActor
 * address:  0x021DF43C
 * packet:   pkt_ov170_021DF43C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_AddActorSurfacePos 0x021EC08C thumb
 *   BOX2_SEQ_MoveCursorToSlot 0x021ED7C4 thumb
 */
#include "../include/Obj00000.h"
#include "../include/Obj23865.h"
#include "../include/Obj23866.h"
#include "../include/Obj23867.h"

extern void BOX2_SEQ_AddActorSurfacePos(char *p, int i, short a, short b, short c);
extern void BOX2_SEQ_MoveCursorToSlot(char *p, int i);

void BOX2_MAIN_MoveCursorActor(char *p, int x, int y)
{
    BOX2_SEQ_AddActorSurfacePos(*(char * *)&((struct Obj00000 *)p)->f2C, ((struct Obj23865 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f3DF6, x, (short)y - 8, 0);
    BOX2_SEQ_MoveCursorToSlot(*(char * *)&((struct Obj00000 *)p)->f2C, 0x24);
    ((struct Obj23866 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA180 = x;
    ((struct Obj23867 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA184 = y;
}
