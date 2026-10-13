/*
 * function: FIELD_CAMERA_SetG3dRoll
 * address:  0x0218EC7C
 * packet:   pkt_ov021_0218EC7C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_CAMERA_SetRoll  0x02048B6C  arm  arm9
 */
#include "../include/Obj19563.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Light;
extern void G3D_CAMERA_SetRoll(struct Light *l, const u32 *in);

void FIELD_CAMERA_SetG3dRoll(u8 *a, u32 first, ...)
{
    G3D_CAMERA_SetRoll((struct Light *)(((struct Obj19563 *)a)->fC), &first);
}
