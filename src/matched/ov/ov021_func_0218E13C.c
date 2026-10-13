/*
 * function: FIELD_CAMERA_SetMode
 * address:  0x0218E13C
 * packet:   pkt_ov021_0218E13C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_CAMERA_EnterMode  0x0218E124  thumb
 *   gFieldCameraPrepareModeFuncs  0x021DDA00  data  ov021  a4
 */
#include "../include/Obj19557.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef void (*StateFunc)(void *a);
extern StateFunc gFieldCameraPrepareModeFuncs[];
extern void FIELD_CAMERA_EnterMode(u8 *a, u32 s);

void FIELD_CAMERA_SetMode(u8 *a, u32 s)
{
    if (((struct Obj19557 *)a)->f14 != s) {
        gFieldCameraPrepareModeFuncs[s](a);
        FIELD_CAMERA_EnterMode(a, s);
    }
}
