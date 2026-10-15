/*
 * function: POKE_SUMMARY_ACTOR_UpdateSound
 * address:  0x021B7C7C
 * packet:   pkt_021B7C7C
 * region:   ov173
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
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
#include "../include/Obj24188.h"

typedef unsigned int   u32;
extern u32 CURSOR_MOVE_Delete(void *a0);

int POKE_SUMMARY_ACTOR_UpdateSound(int *p)
{
    return CURSOR_MOVE_Delete((void *)(((struct Obj24188 *)p)->f1C8));
}
