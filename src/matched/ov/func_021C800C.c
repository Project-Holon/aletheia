/*
 * function: FIELDSKILL_MAPEFF_ApplyFlash
 * address:  0x021C800C
 * packet:   pkt_021C8000
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards the object's first word to FIELD_FLASH_Apply.
 *
 * symbols:
 *   FIELD_FLASH_Apply  0x021C7E30  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18332.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_FLASH_Apply(u32 v);

void FIELDSKILL_MAPEFF_ApplyFlash(u8 *p)
{
    FIELD_FLASH_Apply(((struct Obj18332 *)p)->f0);
}
