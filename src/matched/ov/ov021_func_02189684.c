/*
 * function: FIELDMAP_SetupSceneArea
 * address:  0x02189684
 * packet:   pkt_ov021_02189684
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZONEDATA_GetSecondSpecialKind  0x02013FA8  thumb
 *   ZONEDATA_HasSpecialKind  0x02013C80  thumb
 *   FLD_SCENEAREA_ClearData  0x021AB650  thumb  ov021
 *   FLD_SCENEAREA_LOADER_Unload  0x021AB868  thumb  ov021
 *   FLD_SCENEAREA_LOADER_Load  0x021AB840  thumb  ov021
 *   FLD_SCENEAREA_LOADER_GetRecs  0x021AB880  thumb  ov021
 *   FLD_SCENEAREA_LOADER_GetRecCount  0x021AB884  thumb  ov021
 *   FLD_SCENEAREA_LOADER_GetCallbacks  0x021AB888  thumb  ov021
 *   FLD_SCENEAREA_SetData  0x021AB634  thumb  ov021
 */
#include "../include/Obj03105.h"

typedef unsigned short u16;

extern int ZONEDATA_GetSecondSpecialKind(u16 id);
extern int ZONEDATA_HasSpecialKind(int a0);
extern void FLD_SCENEAREA_ClearData(void *p);
extern void FLD_SCENEAREA_LOADER_Unload(void *p);
extern void FLD_SCENEAREA_LOADER_Load(void *p, int a, int b, int c);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 FLD_SCENEAREA_LOADER_GetRecs(u8 *p);
extern u32 FLD_SCENEAREA_LOADER_GetRecCount(u8 *p);
extern int FLD_SCENEAREA_LOADER_GetCallbacks(void *p);
extern void FLD_SCENEAREA_SetData(void *p, int a, int b, int c);

void FIELDMAP_SetupSceneArea(char *p, unsigned int id)
{
    int k;
    int a;
    int b;

    k = ZONEDATA_GetSecondSpecialKind(id);
    if (k != 0xFFFF) {
        FLD_SCENEAREA_ClearData(((struct Obj03105 *)p)->f40);
        FLD_SCENEAREA_LOADER_Unload(((struct Obj03105 *)p)->f44);
        FLD_SCENEAREA_LOADER_Load(((struct Obj03105 *)p)->f44, 1, k, 0x96);
        a = FLD_SCENEAREA_LOADER_GetRecs(((struct Obj03105 *)p)->f44);
        b = FLD_SCENEAREA_LOADER_GetRecCount(((struct Obj03105 *)p)->f44);
        FLD_SCENEAREA_SetData(((struct Obj03105 *)p)->f40, a, b, FLD_SCENEAREA_LOADER_GetCallbacks(((struct Obj03105 *)p)->f44));
        return;
    }
    if (ZONEDATA_HasSpecialKind((u16)id) == 0) {
        FLD_SCENEAREA_ClearData(((struct Obj03105 *)p)->f40);
        FLD_SCENEAREA_LOADER_Unload(((struct Obj03105 *)p)->f44);
    }
}
