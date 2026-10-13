/*
 * function: FIELD_WFBC_SetUpCamera
 * address:  0x02193ABC
 * packet:   pkt_ov021_02193ABC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ARC_UTIL_LoadHandleMember  0x0204A380  arm
 *   FIELD_WFBC_GetPeopleNum  0x021938F4  thumb  ov021
 *   FIELD_CAMERA_SetSetting  0x0218E17C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj19614.h"

typedef unsigned short u16;

typedef unsigned int   u32;
extern void *ARC_UTIL_LoadHandleMember(void *a0, u32 a1, u32 a2, u32 a3);
extern int FIELD_WFBC_GetPeopleNum(unsigned char *p);
extern void FIELD_CAMERA_SetSetting(u32 *p, u32 v);
extern u32 func_020307B0(void *p);

void FIELD_WFBC_SetUpCamera(char *p, int a, int b)
{
    u16 *h;

    h = ARC_UTIL_LoadHandleMember((void *)(((struct Obj19614 *)p)->f10), 0x24, 0, (u16)((b & 0x7fff) | 0x8000));
    FIELD_CAMERA_SetSetting((u32 *)a, h[FIELD_WFBC_GetPeopleNum((unsigned char *)p)]);
    func_020307B0(h);
}
