/*
 * function: MYSTERY_GRAPHIC_ExitCamera
 * address:  0x021D9960
 * packet:   pkt_021D9960
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_CAMERA_Delete  0x02048AC4  arm
 *   G3D_SYSTEM_Exit  0x02046788  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj13948.h"

typedef unsigned int u32;

extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(void);

void MYSTERY_GRAPHIC_ExitCamera(char *p)
{
    ((struct Obj13948 *)p)->f4 = 0;
    G3D_CAMERA_Delete(((struct Obj13948 *)p)->f0);
    G3D_SYSTEM_Exit();
}
