/*
 * function: INTRO_GRAPHIC_DeleteCamera
 * address:  0x021BE0D4
 * packet:   pkt_021BE0D4
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_SYSTEM_Exit  0x02046788  arm  arm9
 *   G3D_CAMERA_Delete  0x02048AC4  arm  arm9
 *   G3D_LIGHT_DeleteSlots  0x02048C4C  arm  arm9
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14603.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void G3D_LIGHT_DeleteSlots(u32);
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(void);

void INTRO_GRAPHIC_DeleteCamera(u8 *p)
{
    G3D_LIGHT_DeleteSlots(((struct Obj14603 *)p)->f4);
    G3D_CAMERA_Delete((void *)(((struct Obj14603 *)p)->f0));
    G3D_SYSTEM_Exit();
}

