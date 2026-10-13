/*
 * function: FIELD_PLAYER_GRID_EVENT_IsJumpDone
 * address:  0x021C12C4
 * packet:   pkt_021C12C4
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
#include "../include/Obj18276.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct S02030EE8;
extern u32 TCBL_GetTaskUserData(struct S02030EE8 *p);

int FIELD_PLAYER_GRID_EVENT_IsJumpDone(void *a)
{
return ((struct Obj18276 *)((u8 *)(TCBL_GetTaskUserData((struct S02030EE8 *)a))))->f6;
}

