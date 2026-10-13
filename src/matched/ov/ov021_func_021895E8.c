/*
 * function: FIELDMAP_SetupCameraArea
 * address:  0x021895E8
 * packet:   pkt_ov021_021895E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02013BD0  0x02013BD0  thumb
 *   FIELD_CAMERA_LoadAreas  0x0218F14C  thumb  ov021
 *   FIELD_CAMERA_ClearAreas  0x0218F134  thumb  ov021
 */
#include "../include/Obj09444.h"

unsigned short func_02013BD0(unsigned short id);
typedef unsigned int   u32;
typedef unsigned char  u8;
void FIELD_CAMERA_LoadAreas(u8 *p, u32 a, u32 b);
void FIELD_CAMERA_ClearAreas(u8 *a);

void FIELDMAP_SetupCameraArea(unsigned char *p, int id, int c)
{
    int r = func_02013BD0(id);
    if (r != 0xFFFF)
        FIELD_CAMERA_LoadAreas((u8 *)(((struct Obj09444 *)p)->f10), r, c);
    else
        FIELD_CAMERA_ClearAreas((u8 *)(((struct Obj09444 *)p)->f10));
}
