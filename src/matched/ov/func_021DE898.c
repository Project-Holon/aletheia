/*
 * function: BOX2_MAIN_PlayMonCry
 * address:  0x021DE898
 * packet:   pkt_021DE898
 * region:   ov170
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * blocker:  every concrete byte reproduces; the single call to
 *   GAME_DATA_GetBoxSave (0x02012F98) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 *
 * symbols:
 *   GAME_DATA_GetBoxSave  0x02012F98  thumb
 *   func_02007C34  0x02007C34  thumb
 */
#include "../include/Obj09222.h"
#include "../include/Obj18454.h"

struct Sub02007AC8Entry;
extern struct Sub02007AC8Entry *GAME_DATA_GetBoxSave(void *p);
struct PerapVoice;
extern void func_02007C34(struct PerapVoice *p, void *a);

void BOX2_MAIN_PlayMonCry(int *q)
{
    int *r = *(int * *)&((struct Obj18454 *)q)->f0;

    if ((((struct Obj09222 *)r)->f24 - 4) > 1)
        func_02007C34((struct PerapVoice *)GAME_DATA_GetBoxSave((void *)(((struct Obj09222 *)r)->f0)), (void *)(((struct Obj09222 *)r)->f8));
}
