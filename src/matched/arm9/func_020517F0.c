/*
 * function: BUTTON_MAN_GetOffsetX
 * address:  0x020517F0
 * packet:   pkt_02051790
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Returns the word at offset 0x64 as a short. Filed as the witness for ov094 BTLV_EFFVM_ParticleStartCallback.
 */
#include "../include/Obj16173.h"

short BUTTON_MAN_GetOffsetX(char *p)
{
    return ((struct Obj16173 *)p)->f64;
}
