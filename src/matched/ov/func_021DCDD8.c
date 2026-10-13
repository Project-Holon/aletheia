/*
 * function: func_021DCDD8
 * address:  0x021DCDD8
 * packet:   pkt_021DCDD8
 * region:   ov170
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocker:  every concrete byte reproduces; the single call to
 *   PALANM_Delete (0x02021540) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 *
 * symbols:
 *   PALANM_FreeSlotBuffers  0x020215A0  thumb
 *   PALANM_Delete  0x02021540  thumb
 */
#include "../include/Obj00000.h"

typedef unsigned int   u32;
struct PalAnmSlot;
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern u32 PALANM_Delete(void *a0);

void func_021DCDD8(int *p)
{
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x6c)), 0);
    PALANM_Delete((void *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x6c)));
}
