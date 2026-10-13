/*
 * function: BUTTON_MAN_GetBlock
 * address:  0x02051788
 * packet:   pkt_02051788
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * Returns the word at offset 0x20. Filed as the witness for ov094 func_021FA458.
 */
#include "../include/Obj16168.h"

int BUTTON_MAN_GetBlock(char *p)
{
    return ((struct Obj16168 *)p)->f20;
}
