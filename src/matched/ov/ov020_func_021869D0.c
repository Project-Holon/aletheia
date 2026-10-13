/*
 * function: FIELD_WFBC_DATA_LOCAL_ReadValue
 * address:  0x021869D0
 * packet:   pkt_021869D0
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj19469.h"

typedef unsigned short u16;

u16 FIELD_WFBC_DATA_LOCAL_ReadValue(char *p)
{
    return ((struct Obj19469 *)p)->f2;
}
