/*
 * function: FIELDSKILL_MAPEFF_UpdateFlash
 * address:  0x021C8000
 * packet:   pkt_021C8000
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards the object's first word to FIELD_FLASH_Update.
 *
 * symbols:
 *   FIELD_FLASH_Update  0x021C7DFC  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18331.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_FLASH_Update(u32 v);

void FIELDSKILL_MAPEFF_UpdateFlash(u8 *p)
{
    FIELD_FLASH_Update(((struct Obj18331 *)p)->f0);
}
