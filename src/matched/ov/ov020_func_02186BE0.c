/*
 * function: FIELD_WFBC_DATA_LOCAL_SetMood
 * address:  0x02186BE0
 * packet:   pkt_02186BE0
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj19474.h"

typedef unsigned char u8;

void FIELD_WFBC_DATA_LOCAL_SetMood(char *p, int v)
{
    ((struct Obj19474 *)p)->f2 = v;
}
