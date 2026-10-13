/*
 * function: FIELDMAP_SetupWfbc
 * address:  0x02189614
 * packet:   pkt_ov021_02189614
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   ZONEDATA_IsZoneInTableDFC0  0x02013DD0  thumb
 *   func_0201444C  0x0201444C  thumb
 *   GAME_DATA_GetSecondUnionInfo  0x020127C4  thumb
 *   func_020127D0  0x020127D0  thumb
 *   FIELD_G3D_MAPPER_SetupWfbc  0x0218DC74  thumb  ov021
 *   FIELD_G3D_MAPPER_GetWfbc  0x0218DC70  thumb  ov021
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   FIELD_WFBC_DisableUnusedConnects  0x021939C0  thumb  ov021
 *   FIELD_WFBC_SetUpCamera  0x02193ABC  thumb  ov021
 *   GAME_DATA_GetOccupyInfo  0x02012964  thumb
 *   FIELD_WFBC_SetMmdlSys  0x02193AFC  thumb  ov021
 *
 */
#include "../include/Obj00571.h"

typedef unsigned short u16;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
struct Sub02014444Obj;
extern void *GAME_DATA_GetMoveModelSys(const struct BigObj *p);
extern int ZONEDATA_IsZoneInTableDFC0(int v);
extern u32 func_0201444C(struct Sub02014444Obj *o);
extern u8 *GAME_DATA_GetSecondUnionInfo(void *p);
extern u8 *func_020127D0(u8 *o, u32 idx);
extern int FIELD_G3D_MAPPER_SetupWfbc(u32 a, u32 b, u32 c);
extern void *FIELD_G3D_MAPPER_GetWfbc(u8 *p);
extern u32 GAME_DATA_GetEventData(const struct BigObj *p);
extern void FIELD_WFBC_DisableUnusedConnects(u8 *o, void *dst, int skip, u32 heap);
extern void FIELD_WFBC_SetUpCamera(char *p, int a, int b);
extern u32 GAME_DATA_GetOccupyInfo(const struct BigObj *p);
extern void FIELD_WFBC_SetMmdlSys(u8 *p, u32 v);

void FIELDMAP_SetupWfbc(void *p, char *q, u16 id)
{
    void *t;
    int k;
    void *m;
    void *a;

    t = GAME_DATA_GetMoveModelSys(p);
    if (ZONEDATA_IsZoneInTableDFC0(((struct Obj00571 *)q)->fD0) != 0) {
        k = func_0201444C(t);
        if (k == 0)
            m = GAME_DATA_GetSecondUnionInfo(((struct Obj00571 *)q)->f8);
        else
            m = func_020127D0(((struct Obj00571 *)q)->f8, 0);
        FIELD_G3D_MAPPER_SetupWfbc((u32)(((struct Obj00571 *)q)->f48), (u32)m, k);
        a = FIELD_G3D_MAPPER_GetWfbc(((struct Obj00571 *)q)->f48);
        FIELD_WFBC_DisableUnusedConnects(a, (void *)GAME_DATA_GetEventData(p), k, ((struct Obj00571 *)q)->f0);
        FIELD_WFBC_SetUpCamera(a, *(int *)&((struct Obj00571 *)q)->f10, ((struct Obj00571 *)q)->f0);
        FIELD_WFBC_SetMmdlSys(a, GAME_DATA_GetOccupyInfo(((struct Obj00571 *)q)->f8));
    }
}
