/*
 * function: FIELD_PLAYER_Delete
 * address:  0x021A2E90
 * packet:   pkt_021A2E90
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
 *   FIELD_PLAYER_GRID_Delete  0x021A41A8  thumb  ov021
 *   FIELD_PLAYER_NOGRID_Delete  0x021A5920  thumb  ov021
 *   FIELD_PLAYER_CORE_Delete  0x021A3810  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05861.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(void *p);
extern void FIELD_PLAYER_CORE_Delete(u32 a0);
extern void FIELD_PLAYER_GRID_Delete(void);
extern void FIELD_PLAYER_NOGRID_Delete(void);

int FIELD_PLAYER_Delete(void *a)
{
if (((struct Obj05861 *)((u8 *)(a)))->f8 != 0) {
    FIELD_PLAYER_GRID_Delete();
}
if (((struct Obj05861 *)((u8 *)(a)))->fC != 0) {
    FIELD_PLAYER_NOGRID_Delete();
}
FIELD_PLAYER_CORE_Delete(((struct Obj05861 *)((u8 *)(a)))->f4);
return func_020307B0(a);
}

