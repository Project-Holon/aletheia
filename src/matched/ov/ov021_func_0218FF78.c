/*
 * function: FIELD_CAMERA_ANIME_SaveCameraState
 * address:  0x0218FF78
 * packet:   pkt_ov021_0218FF78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_CAMERA_ANIME_GetData  0x021901E8  thumb  ov021
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb  ov021
 *   FIELDMAP_GetNogridMapper  0x02188C5C  thumb  ov021
 *   FIELD_NOGRID_MAPPER_SetActive  0x021BB260  thumb  ov021
 *   FIELD_CAMERA_GetTraceTarget  0x0218EC5C  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FIELD_CAMERA_GetAreasEnabled  0x0218F1B4  thumb  ov021
 *   FIELD_CAMERA_SetAreasEnabled  0x0218F1AC  thumb  ov021
 *   FIELDMAP_GetSceneArea  0x02189A18  thumb  ov021
 *   FLD_SCENEAREA_SetEnabled  0x021AB75C  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12599.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELD_CAMERA_ANIME_GetData(u8 *p);
extern u32 FIELDMAP_GetMoveKind(u8 *p);
extern u32 FIELDMAP_GetNogridMapper(u8 *p);
extern void FIELD_NOGRID_MAPPER_SetActive(u32 a, u32 b);
extern u32 FIELD_CAMERA_GetTraceTarget(u8 *p);
extern void FIELD_CAMERA_StopTargetTrace(u8 *p);
extern u8 FIELD_CAMERA_GetAreasEnabled(u8 *p);
extern void FIELD_CAMERA_SetAreasEnabled(u8 *p, u32 v);
extern u32 FIELDMAP_GetSceneArea(u8 *p);
extern void FLD_SCENEAREA_SetEnabled(u8 *p, u32 v);

u32 FIELD_CAMERA_ANIME_SaveCameraState(u32 *p)
{
    u32 a = p[0];
    u32 b = p[1];
    u8 *r = (u8 *)FIELD_CAMERA_ANIME_GetData((u8 *)p);
    if (FIELDMAP_GetMoveKind((u8 *)a) == 1)
        FIELD_NOGRID_MAPPER_SetActive(FIELDMAP_GetNogridMapper((u8 *)a), 0);
    if (((struct Obj12599 *)r)->f44 != 0) {
        if (FIELD_CAMERA_GetTraceTarget((u8 *)p[1]) != 0) {
            p[7] = 1;
            p[6] = FIELD_CAMERA_GetTraceTarget((u8 *)b);
            FIELD_CAMERA_StopTargetTrace((u8 *)b);
        }
    }
    if (((struct Obj12599 *)r)->f48 != 0) {
        p[5] = FIELD_CAMERA_GetAreasEnabled((u8 *)b);
        FIELD_CAMERA_SetAreasEnabled((u8 *)b, 0);
    }
    FLD_SCENEAREA_SetEnabled((u8 *)FIELDMAP_GetSceneArea((u8 *)a), 0);
    p[3] = 1;
    return p[3];
}
