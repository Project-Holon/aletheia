/*
 * function: SCRCMD_PROC_FLD_FreeItemSlots
 * address:  0x021B3B04
 * packet:   pkt_ov021_021B3B04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (tail-call stub), called from SCRCMD_PROC_FLD_StepShop.
 *
 * symbols:
 *   BMP_MENUWORK_Delete  0x0201F868  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19996.h"

typedef unsigned int   u32;
extern u32 BMP_MENUWORK_Delete(void *p);

void SCRCMD_PROC_FLD_FreeItemSlots(char *w)
{
    BMP_MENUWORK_Delete(((struct Obj19996 *)w)->f180);
}
