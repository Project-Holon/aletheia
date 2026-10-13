/*
 * function: ENTRANCE_CAMERA_HasRecord
 * address:  0x021BE1A0
 * packet:   pkt_021BE1A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * EVENT_FIELD_PROCLINK_IsSlotIndexOutOfRange (0x02162370) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   ENTRANCE_CAMERA_GetRequest  0x021BE180  thumb  ov021
 *   EVENT_FIELD_PROCLINK_IsSlotIndexOutOfRange  0x02162370  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18255.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 EVENT_FIELD_PROCLINK_IsSlotIndexOutOfRange(u32);
extern u8 *ENTRANCE_CAMERA_GetRequest(u8 *p);

int ENTRANCE_CAMERA_HasRecord(u32 a)
{
return EVENT_FIELD_PROCLINK_IsSlotIndexOutOfRange(((struct Obj18255 *)((u8 *)(ENTRANCE_CAMERA_GetRequest((u8 *)a))))->f0);
}

