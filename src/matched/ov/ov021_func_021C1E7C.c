/*
 * function: FLD3D_CI_EventMain
 * address:  0x021C1E7C
 * packet:   pkt_ov021_021C1E7C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   FLD3D_CI_SaveLayerPriorities  0x021C27A4  thumb  ov021
 *   FLD3D_CI_SaveVisiblePlanes  0x021C27C0  thumb  ov021
 *   FLD3D_CI_IsAltFadeSequence  0x021C2BD4  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FLD3D_CI_FadeOutTask  0x021C2B1C  thumb  ov021
 *   FLD3D_CI_FadeInAltTask  0x021C2B98  thumb  ov021
 *   FLD3D_CI_FadeInTask  0x021C2B5C  thumb  ov021
 *   FLD3D_CI_DisplayRestoreTask  0x021C3198  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_SetStatusBitVanish  0x0216DAC8  thumb  ov010
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   FLDMMDL_DeleteMmdl  0x0216CF2C  thumb  ov010
 *   FIELDMAP_SetUpdateStopped  0x02189A58  thumb  ov021
 *   FLD3D_CI_StartScreenCapture  0x021C2764  thumb  ov021
 *   BG_SYS_SetPriority  0x0204047C  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   func_0207FDCC  0x0207FDCC  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_02040588  0x02040588  arm
 *   FIELDMAP_GetFog  0x02188C64  thumb  ov021
 *   FIELD_FOG_SetFlag  0x021A01A4  thumb  ov021
 *   FLD3D_CI_SetupSequence  0x021C2320  thumb  ov021
 *   func_02030830  0x02030830  arm
 *   FIELDMAP_SetDrawMode  0x021899F8  thumb  ov021
 *   FLD3D_CI_DarkenCapturedScreen  0x021C30D4  thumb  ov021
 *   GFL_USE_IsLoaderBusy  0x02005C64  thumb
 *   FLD3D_CI_UpdateStartDelays  0x021C21B4  thumb  ov021
 *   FLD3D_CI_UpdateTrackA  0x021C223C  thumb  ov021
 *   FLD3D_CI_UpdateTrackB  0x021C22AC  thumb  ov021
 *   FLD3D_CI_PlayCueSound  0x021C3158  thumb  ov021
 *   FLD3D_CI_EndSequence  0x021C2484  thumb  ov021
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   G3X_SetClearColor  0x0207DD24  arm
 *   FIELDMAP_GetLight  0x02188C60  thumb  ov021
 *   FIELD_LIGHT_Reflect  0x021A0568  thumb  ov021
 *   func_020056A0  0x020056A0  thumb
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELDMAP_GetPlaceName  0x02188D20  thumb  ov021
 *   FIELD_MSGBG_ReloadBg  0x02193068  thumb  ov021
 *   FIELD_PLACE_NAME_RestoreWindow  0x021BC5D4  thumb  ov021
 *   FIELD_MSGBG_RequestSysFrame  0x021904D0  thumb  ov021
 *   BG_SYS_FreeSlot  0x020414AC  arm
 *   FLD3D_CI_RestoreLayerPriorities  0x021C27CC  thumb  ov021
 *   FLD3D_CI_RestoreVisiblePlanes  0x021C27E8  thumb  ov021
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 *   d_021DA710     0x021DA710  data  ov021  a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00576.h"
#include "../include/Obj06072.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;
typedef volatile unsigned short vu16;

typedef struct { int a, b, c, d; } BgMode;

struct Desc;
struct Evt;
struct Obj;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
struct Ctx;
struct DispConfig;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetMmdlSys(unsigned char *p);
extern void FLDMMDL_SysPauseMove(void *o);
extern void FLD3D_CI_SaveLayerPriorities(u8 *p);
extern void FLD3D_CI_SaveVisiblePlanes(char *p);
extern int FLD3D_CI_IsAltFadeSequence(u16 a);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern int FLD3D_CI_FadeOutTask(int a, int *b);
extern int FLD3D_CI_FadeInAltTask(void *a, u32 *p);
extern int FLD3D_CI_FadeInTask(void *t, int *st);
extern void FLD3D_CI_DisplayRestoreTask(void *p, u32 *done);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern void FLDMMDL_SetStatusBitVanish(unsigned int *p, unsigned int v);
extern void *FLDMMDL_SysSearchObjId(void *map, u32 id);
extern void FLDMMDL_DeleteMmdl(u32 a);
extern void FIELDMAP_SetUpdateStopped(u8 *p, u32 v);
extern void FLD3D_CI_StartScreenCapture(u8 *p);
extern void BG_SYS_SetPriority(int idx, unsigned short val);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void func_0207FDCC(u32 a);
extern void func_0207D63C(int, int, int, int, int);
extern void func_02040588(unsigned char which, unsigned char enable);
extern u32 FIELDMAP_GetFog(u8 *p);
extern int FIELD_FOG_SetFlag(u32 a, u32 b);
extern void FLD3D_CI_SetupSequence(int a, char *p, char *q, int d);
extern void *func_02030830(u32 heapId);
extern void FIELDMAP_SetDrawMode(u8 *p, u32 v);
extern void FLD3D_CI_DarkenCapturedScreen(u32 a);
extern int GFL_USE_IsLoaderBusy(void);
extern int FLD3D_CI_UpdateStartDelays(char *p);
extern int FLD3D_CI_UpdateTrackA(char *p);
extern int FLD3D_CI_UpdateTrackB(char *p);
extern void FLD3D_CI_PlayCueSound(u8 *p);
extern int FLD3D_CI_EndSequence(u8 *a, u8 *b);
extern void FLDMMDL_SetDirDispCheckPause(int a0, int a1);
extern void G3X_SetClearColor(u16 rgb, int alpha, int depth, int polygonID, int fog);
extern u32 FIELDMAP_GetLight(u8 *p);
extern void FIELD_LIGHT_Reflect(u8 *p, int force);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern u32 FIELDMAP_GetPlaceName(u8 *p);
extern void FIELD_MSGBG_ReloadBg(char *p);
extern void FIELD_PLACE_NAME_RestoreWindow(u8 *p);
extern void FIELD_MSGBG_RequestSysFrame(u8 *p);
extern void BG_SYS_FreeSlot(int);
extern void FLD3D_CI_RestoreLayerPriorities(u8 *p);
extern void FLD3D_CI_RestoreVisiblePlanes(u8 *p);
extern u32 *FLDMMDL_SysResumeMove(void *c);
extern const BgMode d_021DA710;

typedef int (*StepFn)(int a, u8 *p);

int FLD3D_CI_EventMain(int a, int *st, u8 *ctx)
{
    u8 *p;
    int h;
    void *sys;
    int r1v;
    int r2v;
    u32 s10;
    u32 s14;
    BgMode m;

    p = *(u8 * *)&((struct Obj06072 *)ctx)->f0;
    h = (int)GAME_EVENT_GetGameSystem((struct Obj *)a);
    sys = GAMESYSTEM_GetFieldMap((void *)h);
    switch (*st) {
    case 0:
        if (((struct Obj06072 *)ctx)->f38)
            FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys((void *)sys));
        FLD3D_CI_SaveLayerPriorities(p);
        FLD3D_CI_SaveVisiblePlanes((char *)p);
        if (FLD3D_CI_IsAltFadeSequence(((struct Obj00576 *)p)->f66) == 0)
            GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)func_020122C0((void *)h, (void *)a, FLD3D_CI_FadeOutTask, 0));
        (*st)++;
        break;
    case 1:
        (*st)++;
        if (((struct Obj00576 *)p)->f66 == 0xb || ((struct Obj00576 *)p)->f66 == 0x12) {
            FLDMMDL_SetStatusBitVanish(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((void *)sys)), 1);
            break;
        }
        if (((struct Obj00576 *)p)->f66 == 0x11) {
            u32 x = (u32)FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)sys), (u16)((struct Obj00576 *)p)->f9C);
            if (x)
                FLDMMDL_DeleteMmdl(x);
            break;
        }
    case 2:
        FIELDMAP_SetUpdateStopped(sys, 1);
        FLD3D_CI_StartScreenCapture(p);
        (*st)++;
        break;
    case 3:
        if (((struct Obj00576 *)p)->f70 == 0)
            break;
        BG_SYS_SetPriority(0, 0);
        BG_SYS_SetPriority(2, 1);
        m = d_021DA710;
        BG_SYS_SetGraphicsMode((struct DispConfig *)(&m));
        *(vu16 *)0x0400000C = (*(vu16 *)0x0400000C & 0x43) | 0x4084;
        func_0207FDCC(8);
        func_0207D63C(0x04000050, 0, 4, 0, 0);
        func_02040588(2, 1);
        FIELD_FOG_SetFlag(FIELDMAP_GetFog(sys), 0);
        (*st)++;
        break;
    case 4:
        FLD3D_CI_SetupSequence(a, (char *)p, (char *)(ctx + 4), (u8)((struct Obj00576 *)p)->f66);
        func_02040588(2, 1);
        func_02040588(0, 1);
        func_02030830(((struct Obj00576 *)p)->f10);
        FIELDMAP_SetDrawMode(sys, 1);
        if (((struct Obj06072 *)ctx)->f34)
            FLD3D_CI_DarkenCapturedScreen(((struct Obj06072 *)ctx)->f34);
        (*st)++;
        break;
    case 5:
        if (FLD3D_CI_IsAltFadeSequence(((struct Obj00576 *)p)->f66))
            GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)func_020122C0((void *)h, (void *)a, FLD3D_CI_FadeInAltTask, 0));
        else
            GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)func_020122C0((void *)h, (void *)a, FLD3D_CI_FadeInTask, 0));
        (*st)++;
        break;
    case 6:
        if (GFL_USE_IsLoaderBusy())
            break;
        (*st)++;
    case 7:
        {
            int r7v;
            int ok;

            ((struct Obj00576 *)p)->f134 += 1;
            r7v = FLD3D_CI_UpdateStartDelays((char *)p);
            r1v = FLD3D_CI_UpdateTrackA((char *)p);
            r2v = FLD3D_CI_UpdateTrackB((char *)p);
            ((struct Obj00576 *)p)->f11C = r7v;
            ((struct Obj00576 *)p)->f120 = r1v;
            ((struct Obj00576 *)p)->f124 = r2v;
            FLD3D_CI_PlayCueSound(p);
            ok = 0;
            if (*(StepFn *)&((struct Obj00576 *)p)->f12C)
                ok = (*(StepFn *)(p + 0x12c))(a, p);
            else if (((struct Obj00576 *)p)->f11C && ((struct Obj00576 *)p)->f120 && ((struct Obj00576 *)p)->f124)
                ok = 1;
            if (ok == 0)
                break;
        }
        (*st)++;
        break;
    case 8:
        FIELDMAP_SetDrawMode(sys, 0);
        FLD3D_CI_EndSequence(p, ctx + 4);
        if (FLD3D_CI_IsAltFadeSequence(((struct Obj00576 *)p)->f66)) {
            void *o = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((void *)sys));
            FLDMMDL_SetStatusBitVanish(o, 0);
            FLDMMDL_SetDirDispCheckPause((int)o, 1);
            FIELDMAP_SetUpdateStopped(sys, 0);
        } else {
            func_02040588(0, 0);
            G3X_SetClearColor(0, 0x1f, 0x7fff, 0, 0);
        }
        FIELD_FOG_SetFlag(FIELDMAP_GetFog(sys), 1);
        (*st)++;
        break;
    case 9:
        FIELD_LIGHT_Reflect((u8 *)FIELDMAP_GetLight(sys), 1);
        ((struct Obj00576 *)p)->f74 = 0;
        func_020056A0(FLD3D_CI_DisplayRestoreTask, p + 0x74, 0);
        (*st)++;
        break;
    case 10:
        if (((struct Obj00576 *)p)->f74 == 0)
            break;
        func_02030830(((struct Obj00576 *)p)->f10);
        s10 = FIELDMAP_GetMsgBg(sys);
        s14 = FIELDMAP_GetPlaceName(sys);
        FIELD_MSGBG_ReloadBg((char *)s10);
        FIELD_PLACE_NAME_RestoreWindow((u8 *)s14);
        FIELD_MSGBG_RequestSysFrame((u8 *)s10);
        *(vu16 *)0x0400000C = (*(vu16 *)0x0400000C & 0x43) | 0x1f18;
        BG_SYS_FreeSlot(2);
        FLD3D_CI_RestoreLayerPriorities(p);
        FLD3D_CI_RestoreVisiblePlanes(p);
        FIELDMAP_SetUpdateStopped(sys, 0);
        if (((struct Obj06072 *)ctx)->f38)
            FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys((void *)sys));
        (*st)++;
        break;
    case 11:
        return 1;
    }
    return 0;
}
