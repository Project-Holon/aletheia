/*
 * function: FIELDMAP_SeqStart
 * address:  0x021885E8
 * packet:   pkt_ov021_021885E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_G3D_MAPPER_UpdateBlocking  0x0218CA78  thumb  ov021
 *   FLDMMDL_UpdateSysProc  0x0216CD64  thumb  ov010
 *   FLDMMDL_BLACT_RegisterLoadedRes  0x0219C624  thumb  ov021
 *   FLDMMDL_BLACT_IsReservePending  0x0219C630  thumb  ov021
 *   WEATHER_IsTaskActive  0x021A1B50  thumb  ov021
 *   WEATHER_Update  0x021A1AF4  thumb  ov021
 *   FIELDMAP_UpdateG3d  0x02189004  thumb  ov021
 *   FIELDMAP_DrawStart  0x02189084  thumb  ov021
 *   FIELDMAP_DrawEnd  0x021890AC  thumb  ov021
 *   CLACT_DrawSystem  0x0204A600  arm
 *   FIELD_MSGBG_Main  0x021903E0  thumb  ov021
 *   FIELD_EFFECT_Update  0x021ABE04  thumb  ov021
 *   FIELD_SUBPROC_MGR_RunUpdate  0x021BB948  thumb  ov021
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   FIELD_STATUS_GetContinueFlag  0x02014460  thumb
 *   FIELDMAP_IsLoaderWaitZone  0x02189B04  thumb  ov021
 *   GFL_USE_IsLoaderBusy  0x02005C64  thumb
 *   FIELD_STATUS_GetFieldInitFlag  0x02014458  thumb
 *   SCRIPT_SYS_RunFieldInitScript  0x02158AC8  thumb  ov010
 *   FIELD_STATUS_SetFieldInitFlag  0x02014454  thumb
 *   SCRIPT_SYS_RunFieldRecoverScript  0x02158AD4  thumb  ov010
 *   FIELD_STATUS_SetContinueFlag  0x0201445C  thumb
 *   ZONEDATA_IsZone1A6  0x02013CC8  thumb
 *   ZONEDATA_IsZone96Pair  0x02013CE0  thumb
 *   FIELDMAP_GetCtrlType  0x02188CF0  thumb  ov021
 *   func_0201209C  0x0201209C  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_SetWalkCountEnable  0x020129DC  thumb
 *   FIELD_EVENT_CHECK_CheckCommEvents  0x0218A0E4  thumb  ov021
 *   FIELD_EVENT_CHECK_RunRail  0x0218A240  thumb  ov021
 *   FIELD_EVENT_CHECK_Run  0x0218A4BC  thumb  ov021
 *   FIELD_EVENT_CHECK_RunGrid  0x0218A074  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00611.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BigObj;
struct Obj;
extern void FIELD_G3D_MAPPER_UpdateBlocking(char *p);
extern int FLDMMDL_UpdateSysProc(int a0);
extern int FLDMMDL_BLACT_RegisterLoadedRes(void *p);
extern int FLDMMDL_BLACT_IsReservePending(void *p);
extern int WEATHER_IsTaskActive(u32 a);
extern void WEATHER_Update(u8 *p, int x);
extern void FIELDMAP_UpdateG3d(u8 *p);
extern void FIELDMAP_DrawStart(u8 *p);
extern void FIELDMAP_DrawEnd(u8 *p);
extern void CLACT_DrawSystem(void);
extern void FIELD_MSGBG_Main(struct Obj *o);
extern void FIELD_EFFECT_Update(u32 a);
extern void FIELD_SUBPROC_MGR_RunUpdate(u8 *p);
extern void *GAME_DATA_GetMoveModelSys(const struct BigObj *p);
struct Ctx;
struct Sub02014444Obj;
extern u8 FIELD_STATUS_GetContinueFlag(struct Sub02014444Obj *o);
extern int FIELDMAP_IsLoaderWaitZone(int x);
extern int GFL_USE_IsLoaderBusy(void);
extern u8 FIELD_STATUS_GetFieldInitFlag(struct Sub02014444Obj *o);
extern void SCRIPT_SYS_RunFieldInitScript(int a, int b);
extern void FIELD_STATUS_SetFieldInitFlag(struct Sub02014444Obj *o, u8 v);
extern void SCRIPT_SYS_RunFieldRecoverScript(int a, int b);
extern void FIELD_STATUS_SetContinueFlag(struct Sub02014444Obj *o, u8 v);
extern u32 ZONEDATA_IsZone1A6(u32 id);
extern u32 ZONEDATA_IsZone96Pair(u32 id);
extern int FIELDMAP_GetCtrlType(u32 a);
extern void func_0201209C(void *o, u32 v1, u32 v2);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void GAME_DATA_SetWalkCountEnable(struct BigObj *p, u8 v);
struct Obj00020;
extern int FIELD_EVENT_CHECK_CheckCommEvents(void *sys, struct Obj00020 *pos);
extern int FIELD_EVENT_CHECK_RunRail(void *p, struct Obj00020 *pos);
extern int FIELD_EVENT_CHECK_Run(u32 a, u32 b, u32 c, u32 d);
extern int FIELD_EVENT_CHECK_RunGrid(void *a, int b);

int FIELDMAP_SeqStart(void *a, u8 *p)
{
    switch (p[0xC8]) {
    case 0:
        FIELD_G3D_MAPPER_UpdateBlocking((char *)(((struct Obj00611 *)p)->f48));
        if (((struct Obj00611 *)p)->f38 != 0) {
            do {
                FLDMMDL_UpdateSysProc(((struct Obj00611 *)p)->f38);
                FLDMMDL_BLACT_RegisterLoadedRes((void *)(((struct Obj00611 *)p)->f38));
            } while (FLDMMDL_BLACT_IsReservePending((void *)(((struct Obj00611 *)p)->f38)) == 1);
        }
        while (WEATHER_IsTaskActive(((struct Obj00611 *)p)->f20) != 0)
            WEATHER_Update((u8 *)(((struct Obj00611 *)p)->f20), 0x92);
        FIELDMAP_UpdateG3d(p);
        FIELDMAP_DrawStart(p);
        FIELDMAP_DrawEnd(p);
        CLACT_DrawSystem();
        if (((struct Obj00611 *)p)->f28 != 0)
            FIELD_MSGBG_Main((struct Obj *)(((struct Obj00611 *)p)->f28));
        FIELD_EFFECT_Update(((struct Obj00611 *)p)->f94);
        FIELD_SUBPROC_MGR_RunUpdate((u8 *)(((struct Obj00611 *)p)->fBC));
        p[0xC8]++;
    case 1:
        if (FIELD_STATUS_GetContinueFlag(GAME_DATA_GetMoveModelSys((const struct BigObj *)(((struct Obj00611 *)p)->f8))) == 1
            && FIELDMAP_IsLoaderWaitZone(((struct Obj00611 *)p)->fD0) == 1
            && GFL_USE_IsLoaderBusy() != 0)
            return 0;
        if (FIELD_STATUS_GetFieldInitFlag(GAME_DATA_GetMoveModelSys((const struct BigObj *)(((struct Obj00611 *)p)->f8))) != 0) {
            SCRIPT_SYS_RunFieldInitScript(((struct Obj00611 *)p)->f4, ((struct Obj00611 *)p)->f0);
            FIELD_STATUS_SetFieldInitFlag(GAME_DATA_GetMoveModelSys((const struct BigObj *)(((struct Obj00611 *)p)->f8)), 0);
        } else {
            SCRIPT_SYS_RunFieldRecoverScript(((struct Obj00611 *)p)->f4, ((struct Obj00611 *)p)->f0);
        }
        FIELD_STATUS_SetContinueFlag(GAME_DATA_GetMoveModelSys((const struct BigObj *)(((struct Obj00611 *)p)->f8)), 0);
        FIELD_G3D_MAPPER_UpdateBlocking((char *)(((struct Obj00611 *)p)->f48));
        if (ZONEDATA_IsZone1A6(((struct Obj00611 *)p)->fD0) == 1 || ZONEDATA_IsZone96Pair(((struct Obj00611 *)p)->fD0) == 1)
            func_0201209C(a, (u32)FIELD_EVENT_CHECK_CheckCommEvents, (u32)p);
        else if (FIELDMAP_GetCtrlType((u32)p) == 1)
            func_0201209C(a, (u32)FIELD_EVENT_CHECK_RunRail, (u32)p);
        else if (FIELDMAP_GetCtrlType((u32)p) == 2)
            func_0201209C(a, (u32)FIELD_EVENT_CHECK_Run, (u32)p);
        else
            func_0201209C(a, (u32)FIELD_EVENT_CHECK_RunGrid, (u32)p);
        ((struct Obj00611 *)p)->fC0 = 1;
        GAME_DATA_SetWalkCountEnable(GAMESYSTEM_GetGameData(a), 1);
        break;
    }
    return 1;
}
