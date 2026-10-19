/*
 * function: BOX2_UI_DeleteCursorMove
 * address:  0x021EE3CC
 * packet:   pkt_021EE3CC
 * region:   ov170
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocker:  every concrete byte reproduces; the single call to
 *   CURSOR_MOVE_Delete (0x02025D14) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 *
 * symbols:
 *   CURSOR_MOVE_Delete  0x02025D14  thumb
 */
#include "../include/Obj00000.h"

extern void CURSOR_MOVE_Delete(void);

void BOX2_UI_DeleteCursorMove(int *p)
{
    if (*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x70)) {
        CURSOR_MOVE_Delete();
        *(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x70) = 0;
    }
}
