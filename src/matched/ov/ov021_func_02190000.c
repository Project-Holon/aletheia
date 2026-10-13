/*
 * function: FIELD_CAMERA_ANIME_RestoreCameraState
 * address:  0x02190000
 * packet:   pkt_ov021_02190000
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
 *   FIELD_CAMERA_SetTraceTarget  0x0218EC30  thumb  ov021
 *   FIELD_CAMERA_SetMode  0x0218E13C  thumb  ov021
 *   FIELD_CAMERA_SetAreasEnabled  0x0218F1AC  thumb  ov021
 *   FIELDMAP_GetSceneArea  0x02189A18  thumb  ov021
 *   FLD_SCENEAREA_SetEnabled  0x021AB75C  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19578.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELD_CAMERA_ANIME_GetData(u8 *p);
extern u32 FIELDMAP_GetMoveKind(u8 *p);
extern u32 FIELDMAP_GetNogridMapper(u8 *p);
extern void FIELD_NOGRID_MAPPER_SetActive(u32 a, u32 b);
extern void FIELD_CAMERA_SetTraceTarget(u32 a, u32 b);
extern void FIELD_CAMERA_SetMode(u8 *a, u32 s);
extern void FIELD_CAMERA_SetAreasEnabled(u8 *p, u32 v);
extern u32 FIELDMAP_GetSceneArea(u8 *p);
extern void FLD_SCENEAREA_SetEnabled(u8 *p, u32 v);

void FIELD_CAMERA_ANIME_RestoreCameraState(u32 *p)
{
    u32 a = p[0];
    u32 b = p[1];
    u8 *r = (u8 *)FIELD_CAMERA_ANIME_GetData((u8 *)p);
    FLD_SCENEAREA_SetEnabled((u8 *)FIELDMAP_GetSceneArea((u8 *)a), 1);
    if (((struct Obj19578 *)r)->f48 != 0)
        FIELD_CAMERA_SetAreasEnabled((u8 *)b, p[5]);
    if (p[7] != 0)
        FIELD_CAMERA_SetTraceTarget(b, p[6]);
    FIELD_CAMERA_SetMode((u8 *)b, p[4]);
    if (FIELDMAP_GetMoveKind((u8 *)a) == 1)
        FIELD_NOGRID_MAPPER_SetActive(FIELDMAP_GetNogridMapper((u8 *)a), 1);
}
