/*
 * function: func_021BE6A4
 * address:  0x021BE6A4
 * packet:   pkt_021BE6A4
 * region:   ov204
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SAVE_CONTROL_INTR_Start 0x021BD2B0 thumb
 */
#include "../include/Obj25360.h"

extern void SAVE_CONTROL_INTR_Start(int);

int func_021BE6A4(char *a)
{
    SAVE_CONTROL_INTR_Start(((struct Obj25360 *)a)->fA4);
    return 1;
}
