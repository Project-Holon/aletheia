/*
 * function: FIELD_PLAYER_GRID_EVENT_IsHopDone
 * address:  0x021C1094
 * packet:   pkt_021C1094
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   TCBL_GetTaskUserData  0x02030EE8  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18274.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct S02030EE8;
extern u32 TCBL_GetTaskUserData(struct S02030EE8 *p);

int FIELD_PLAYER_GRID_EVENT_IsHopDone(void *a)
{
return ((struct Obj18274 *)((u8 *)(TCBL_GetTaskUserData((struct S02030EE8 *)a))))->f4;
}

