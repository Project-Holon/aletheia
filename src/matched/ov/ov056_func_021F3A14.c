/*
 * function: FIELD_FK_DEMO_ExitCamera
 * address:  0x021F3A14
 * packet:   pkt_ov056_021F3A14
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_CAMERA_ResumeTargetTrace  0x0218EC60  thumb  ov021
 *   FIELD_CAMERA_GetTraceTarget  0x0218EC5C  thumb  ov021
 *   FIELD_CAMERA_SetTarget  0x0218EC90  thumb  ov021
 *   FIELD_CAMERA_SetTargetShift  0x0218ECD4  thumb  ov021
 *   FIELD_CAMERA_SetMode  0x0218E13C  thumb  ov021
 *   FIELD_CAMERA_SetAreasEnabled  0x0218F1AC  thumb  ov021
 *   FIELD_CAMERA_SetG3dUp  0x0218ED14  thumb  ov021
 *   FIELD_CAMERA_SetSetting  0x0218E17C  thumb  ov021
 *   FIELD_CAMERA_RestartDelay  0x0218F05C  thumb  ov021
 *   G3D_CAMERA_Delete  0x02048AC4  arm
 *   ICA_ANIME_Delete  0x02011558  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 */
#include "../include/Obj01680.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FIELD_CAMERA_ResumeTargetTrace(u32 a);
extern u32 FIELD_CAMERA_GetTraceTarget(u8 *p);
extern void FIELD_CAMERA_SetTarget(u32 a, u32 b);
extern void FIELD_CAMERA_SetTargetShift(u32 a, u32 b);
struct IcaAnime;
extern void FIELD_CAMERA_SetMode(u8 *a, u32 s);
extern void FIELD_CAMERA_SetAreasEnabled(u8 *p, u32 v);
extern void FIELD_CAMERA_SetG3dUp(u8 *p, u32 q);
extern void FIELD_CAMERA_SetSetting(u32 *p, u32 v);
extern void FIELD_CAMERA_RestartDelay(u8 *a);
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void ICA_ANIME_Delete(struct IcaAnime *p);
extern void MI_CpuFill8(void *, unsigned, unsigned);

void FIELD_FK_DEMO_ExitCamera(u8 *p)
{
    FIELD_CAMERA_ResumeTargetTrace(*(u32 *)&((struct Obj01680 *)p)->f8);
    FIELD_CAMERA_SetTarget(*(u32 *)&((struct Obj01680 *)p)->f8, FIELD_CAMERA_GetTraceTarget(*(u8 * *)&((struct Obj01680 *)p)->f8));
    FIELD_CAMERA_SetTargetShift(*(u32 *)&((struct Obj01680 *)p)->f8, (u32)(p + 0x10));
    FIELD_CAMERA_SetMode((u8 *)(*(u32 *)&((struct Obj01680 *)p)->f8), ((struct Obj01680 *)p)->fC);
    FIELD_CAMERA_SetAreasEnabled(*(u8 * *)&((struct Obj01680 *)p)->f8, ((struct Obj01680 *)p)->fE);
    FIELD_CAMERA_SetG3dUp((u8 *)(*(u32 *)&((struct Obj01680 *)p)->f8), (u32)(p + 0x1c));
    FIELD_CAMERA_SetSetting(*(u32 * *)&((struct Obj01680 *)p)->f8, ((struct Obj01680 *)p)->f2C);
    FIELD_CAMERA_RestartDelay(*(u8 * *)&((struct Obj01680 *)p)->f8);
    G3D_CAMERA_Delete((void *)(((struct Obj01680 *)p)->f4));
    ICA_ANIME_Delete((struct IcaAnime *)(((struct Obj01680 *)p)->f0));
    MI_CpuFill8(p, 0, 0x30);
}
