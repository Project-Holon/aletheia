/*
 * function: FIELDMAP_RequestClose
 * address:  0x02188BD8
 * packet:   pkt_02188BD8
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sets the two words at +0xC0 and +0xC4 of its argument to 2 and 4.  A leaf
 * with no lr-saving prologue that nothing in ov021 branches to (its caller
 * is FIELD_STATUS_FieldCloseEvent in arm9), so the listing emits it as data words after
 * pool_02188BD4.
 */
#include "../include/Obj12061.h"

typedef unsigned char u8;
typedef unsigned int  u32;

void FIELDMAP_RequestClose(u8 *obj)
{
    ((struct Obj12061 *)obj)->fC0 = 2;
    ((struct Obj12061 *)obj)->fC4 = 4;
}
