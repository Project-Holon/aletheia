/*
 * function: ENTRANCE_CAMERA_Restore
 * address:  0x021BDD34
 * packet:   pkt_021BDD34
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x54.
 *
 * symbols:
 *   FIELD_CAMERA_ANIME_Restore  0x0218FF20  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18252.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_CAMERA_ANIME_Restore(u8 *a);

void ENTRANCE_CAMERA_Restore(u8 *p)
{
    FIELD_CAMERA_ANIME_Restore((u8 *)(((struct Obj18252 *)p)->f54));
}
