/*
 * function: BUTTON_MAN_GetOffsetY
 * address:  0x02051808
 * packet:   pkt_02051790
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Returns the word at offset 0x68 as a short. Filed as the witness for ov094 BTLV_EFFVM_ParticleStartCallback.
 */
#include "../include/Obj16175.h"

short BUTTON_MAN_GetOffsetY(char *p)
{
    return ((struct Obj16175 *)p)->f68;
}
