/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_CreateView
 * address:  0x0217AF2C
 * packet:   pkt_0217AF2C
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * blocker:  every concrete byte reproduces; the single call to
 *   WIFIBATTLEMATCH_GRAPHIC_GetCamera (0x021E5548) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 *
 * symbols:
 *   WIFIBATTLEMATCH_GRAPHIC_GetCamera  0x021E5548  thumb  ov177
 *   func_021E567C  0x021E567C  thumb  ov177
 */
#include "../include/Obj10695.h"

extern int WIFIBATTLEMATCH_GRAPHIC_GetCamera(int *p);
typedef unsigned int   u32;
extern u32 *func_021E567C(int unused, int mode, int heap);

void BATTLE_CHAMPIONSHIP_FLOW_CreateView(int *p)
{
    ((struct Obj10695 *)p)->f20 = (int)func_021E567C(WIFIBATTLEMATCH_GRAPHIC_GetCamera((int *)(((struct Obj10695 *)p)->f24)), 1, ((struct Obj10695 *)p)->f0);
}
