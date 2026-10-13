/*
 * function: FIELD_PLACE_NAME_DeleteClactUnit
 * address:  0x021BC7B0
 * packet:   pkt_021BC788
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x34.
 *
 * symbols:
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18191.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Bank;
extern u32 CLACT_DeleteUnit(struct Bank *bank);

void FIELD_PLACE_NAME_DeleteClactUnit(u8 *p)
{
    CLACT_DeleteUnit((struct Bank *)(((struct Obj18191 *)p)->f34));
}
