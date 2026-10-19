/*
 * function: FIELDMAP_SetupMmdlSys
 * address:  0x02189204
 * packet:   pkt_ov021_02189204
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetOccupyInfo  0x02012964  thumb
 *   FLDMMDL_SetupSysProc  0x0216CCDC  thumb  ov010
 *   FLDMMDL_BLACT_Init  0x0219C554  thumb
 *   FLDMMDL_BLACT_AddCachedRes  0x0219C680  thumb
 *   ZONEDATA_IsUnionRoom  0x02013CC8  thumb
 *   ZONEDATA_IsZone96Pair  0x02013CE0  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_FIELD_GetHostGender  0x0217C0A8  thumb  ov018
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   FIELD_PLAYER_GetObjCodeOfFormCode  0x021A31A4  thumb
 *   FLDMMDL_BLACT_AddResByCode  0x0219C658  thumb
 *   FLDMMDL_G3DOBJ_Create  0x0219D448  thumb
 *   FIELD_CAMERA_GetViewYawPtr  0x0218ED50  thumb
 *   FLDMMDL_SetAreaIdRef  0x0216CDB8  thumb  ov010
 *   FLDMMDL_SysPopAll  0x0216D2F8  thumb  ov010
 *   FIELDMAP_IsMmdlDrawEnabled  0x02189AE8  thumb
 *   FLDMMDL_SysSetDrawEnable  0x0216D974  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00571.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;
struct BigObj;
struct Ctx;
struct Sub0200852CObj;

extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetOccupyInfo(const struct BigObj *p);
extern void FLDMMDL_SetupSysProc(char *a, int b, int c, int d, int e, int f);
extern void FLDMMDL_BLACT_Init(u32 a, u32 b, u32 c);
extern void FLDMMDL_BLACT_AddCachedRes(u32 a);
extern u32 ZONEDATA_IsUnionRoom(u32 a);
extern u32 ZONEDATA_IsZone96Pair(u32 a);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern u8 INTRUDE_FIELD_GetHostGender(void *a0);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *p);
extern int FIELD_PLAYER_GetObjCodeOfFormCode(int i, int v);
extern void FLDMMDL_BLACT_AddResByCode(u32 a, u32 b);
extern void FLDMMDL_G3DOBJ_Create(int a, int b);
extern u8 *FIELD_CAMERA_GetViewYawPtr(u8 *p);
extern void FLDMMDL_SetAreaIdRef(u8 *p, u32 v);
extern void FLDMMDL_SysPopAll(u32 a);
extern int FIELDMAP_IsMmdlDrawEnabled(int a);
extern void FLDMMDL_SysSetDrawEnable(unsigned int *p, unsigned int v);

void FIELDMAP_SetupMmdlSys(u8 *a)
{
    u32 h;
    u32 x;
    u32 r;
    u32 t;

    h = (u32)GAMESYSTEM_GetGameData((const struct Ctx *)(((struct Obj00571 *)a)->f4));
    r = GAME_DATA_GetOccupyInfo((const struct BigObj *)h);
    ((struct Obj00571 *)a)->f38 = r;
    FLDMMDL_SetupSysProc((char *)r, ((struct Obj00571 *)a)->f0, h, (int)a, *(u32 *)&((struct Obj00571 *)a)->f48, ((struct Obj00571 *)a)->f3C);
    FLDMMDL_BLACT_Init(((struct Obj00571 *)a)->f38, ((struct Obj00571 *)a)->fB0, 0x20);
    FLDMMDL_BLACT_AddCachedRes(((struct Obj00571 *)a)->f38);
    x = ((struct Obj00571 *)a)->fD8;
    if (ZONEDATA_IsUnionRoom(x) == 0 && ZONEDATA_IsZone96Pair(x) == 0) {
        t = INTRUDE_FIELD_GetHostGender((void *)((void *)GAMESYSTEM_GetGameComm((const struct Ctx *)((struct Obj00571 *)a)->f4)));
    } else {
        t = func_02008550((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus((void *)h));
    }
    FLDMMDL_BLACT_AddResByCode(r, FIELD_PLAYER_GetObjCodeOfFormCode(t, 0));
    FLDMMDL_G3DOBJ_Create(((struct Obj00571 *)a)->f38, ((struct Obj00571 *)a)->f130);
    FLDMMDL_SetAreaIdRef((u8 *)(((struct Obj00571 *)a)->f38), (u32)FIELD_CAMERA_GetViewYawPtr((u8 *)(((struct Obj00571 *)a)->f10)));
    FLDMMDL_SysPopAll(((struct Obj00571 *)a)->f38);
    FLDMMDL_SysSetDrawEnable((unsigned int *)r, FIELDMAP_IsMmdlDrawEnabled(((struct Obj00571 *)a)->fD0));
}
