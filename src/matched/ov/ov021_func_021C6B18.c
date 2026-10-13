/*
 * function: FIELDMAP_TCB_CAMERA_ZOOM_Create
 * address:  0x021C6B18
 * packet:   pkt_ov021_021C6B18
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELDMAP_GetTcblSys  0x02188D30  thumb  ov021
 *   FIELD_CAMERA_GetDistance  0x0218ED54  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   FIELDMAP_TCB_CAMERA_ZOOM_Main  0x021C6B8C  thumb  ov021
 *   gFieldmapTcbCameraZoomFileName     0x021DE4B8  data  ov021  a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj06085.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *FIELDMAP_GetCamera(void *p);
extern u32 FIELDMAP_GetTcblSys(u8 *p);
extern u32 FIELD_CAMERA_GetDistance(u8 *p);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02030DA8(u32 a, void *cb, void *arg, int z);
extern void FIELDMAP_TCB_CAMERA_ZOOM_Main(void);
extern int gFieldmapTcbCameraZoomFileName;

void FIELDMAP_TCB_CAMERA_ZOOM_Create(u32 a, u16 b, u32 c)
{
    u32 h = FIELDMAP_GetHeapId((u8 *)a);
    u32 x = (u32)FIELDMAP_GetCamera((void *)a);
    u32 y = FIELDMAP_GetTcblSys((u8 *)a);
    u32 *e;

    e = (u32 *)func_02030734((u16)((h & 0x7FFF) | 0x8000), 0x10, 0, (const char *)&gFieldmapTcbCameraZoomFileName, 0x5F);
    ((struct Obj06085 *)e)->f4 = 0;
    ((struct Obj06085 *)e)->f6 = b;
    e[2] = FIELD_CAMERA_GetDistance((u8 *)x);
    e[3] = c + FIELD_CAMERA_GetDistance((u8 *)x);
    e[0] = a;
    func_02030DA8(y, (void *)FIELDMAP_TCB_CAMERA_ZOOM_Main, e, 0);
}
