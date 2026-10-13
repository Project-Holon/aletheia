/*
 * function: FIELD_PLAYER_StepFormChange
 * address:  0x021A2F54
 * packet:   pkt_021A2F48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x4.
 *
 * symbols:
 *   FIELD_PLAYER_CORE_StepFormChange  0x021A3CC0  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18008.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FIELD_PLAYER_CORE_StepFormChange(void *p);

int FIELD_PLAYER_StepFormChange(u8 *p)
{
    return FIELD_PLAYER_CORE_StepFormChange(((struct Obj18008 *)p)->f4);
}
