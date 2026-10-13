/*
 * function: FIELD_CAMERA_ReloadSetting
 * address:  0x0218E160
 * packet:   pkt_0218E160
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
 *   FIELD_CAMERA_EnterMode  0x0218E124  thumb  ov021
 *   FIELD_CAMERA_LoadSetting  0x0218E18C  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01653.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void FIELD_CAMERA_EnterMode(u8 *a, u32 s);
extern u32 FIELD_CAMERA_LoadSetting(u32, u32);

int FIELD_CAMERA_ReloadSetting(u32 a)
{
FIELD_CAMERA_EnterMode((u8 *)a, 0);
FIELD_CAMERA_LoadSetting(a, ((struct Obj01653 *)((u8 *)(a)))->f18);
*(u8 *)((u8 *)((a + 233))) = 1;
return 1;
}

