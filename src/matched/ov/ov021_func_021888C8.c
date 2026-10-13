/*
 * function: FIELDMAP_UpdateCameraAndDraw
 * address:  0x021888C8
 * packet:   pkt_ov021_021888C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_ResetDrawCounts  0x02047CE4  arm
 *   KEY_GetCont  0x0203630C  arm
 *   FIELD_CAMERA_Main  0x0218E104  thumb  ov021
 *   FIELDMAP_CalcCameraPitchScale  0x02189A80  thumb  ov021
 *   FIELDMAP_DrawStart  0x02189084  thumb  ov021
 */
#include "../include/Obj12555.h"

typedef unsigned short u16;

void G3D_SYSTEM_ResetDrawCounts(void);
unsigned int KEY_GetCont(void);
typedef unsigned int   u32;
typedef unsigned char  u8;
void FIELD_CAMERA_Main(u8 *a, u32 b);
int FIELDMAP_CalcCameraPitchScale(char *p);
void FIELDMAP_DrawStart(unsigned char *p);

void FIELDMAP_UpdateCameraAndDraw(char *o)
{
    volatile u16 *r = (volatile u16 *)0x04000204;

    G3D_SYSTEM_ResetDrawCounts();
    FIELD_CAMERA_Main((u8 *)(((struct Obj12555 *)o)->f10), (u16)KEY_GetCont());
    ((struct Obj12555 *)o)->f100 = FIELDMAP_CalcCameraPitchScale(o);
    *r = *r & 0xFFFF7FFF;
    FIELDMAP_DrawStart((unsigned char *)o);
    *r = *r | 0x8000;
}
