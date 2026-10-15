/*
 * function: SODATEYA_HasEgg
 * address:  0x021C3400
 * packet:   pkt_021C3400
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf in ov021 (the listing prints it as a `.word` run at
 * 0x021C3400, next to ov010's field-VM code); ov010's SCRCMD_PROC_GetDaycareState reaches
 * it across the overlay pair.  Eight-byte thunk: load [a+8] and tail-call
 * the ARM9 helper.
 *
 * symbols:
 *   DAYCARE_GetEggReady  0x0200BCA0  thumb
 */
#include "../include/Obj18300.h"

typedef int s32;

struct Obj11233;
extern int DAYCARE_GetEggReady(struct Obj11233 *p);

int SODATEYA_HasEgg(void *a)
{
    return DAYCARE_GetEggReady((struct Obj11233 *)(((struct Obj18300 *)a)->f8));
}
