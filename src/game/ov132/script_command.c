/*
 * file:     script_command.c
 * unit:     yes
 * function: SCRIPT_COMMAND_CmdCameraTo224, SCRIPT_COMMAND_CmdCameraTo0, SCRIPT_COMMAND_CmdSetCameraPos, SCRIPT_COMMAND_TaskCameraPos, SCRIPT_COMMAND_CmdSetCameraTarget, SCRIPT_COMMAND_TaskCameraTarget, SCRIPT_COMMAND_CmdSkipArg, SCRIPT_COMMAND_CmdShowAnim, SCRIPT_COMMAND_CmdHideAnim, SCRIPT_COMMAND_GetActorMask, SCRIPT_COMMAND_CmdSetActorFrame, SCRIPT_COMMAND_CmdSetActorVisible, SCRIPT_COMMAND_CmdSetActorPos, SCRIPT_COMMAND_CmdAddActorPos, SCRIPT_COMMAND_TaskActorMove, SCRIPT_COMMAND_CmdActorAnimRestart, SCRIPT_COMMAND_CmdActorAnimPause, SCRIPT_COMMAND_CmdSetActorFlag, SCRIPT_COMMAND_CmdSetActorScale, SCRIPT_COMMAND_CmdSetActorLight, SCRIPT_COMMAND_CmdPositionAnim, SCRIPT_COMMAND_CmdSetSelection, SCRIPT_COMMAND_CmdClearSelection, SCRIPT_COMMAND_CmdLoadRankAnim, SCRIPT_COMMAND_CmdLoadAnimMember, SCRIPT_COMMAND_CmdStartShake, SCRIPT_COMMAND_TaskShake, SCRIPT_COMMAND_CmdRotateActor, SCRIPT_COMMAND_TaskRotate, SCRIPT_COMMAND_CmdCompareScores, SCRIPT_COMMAND_CmdSetFlags, SCRIPT_COMMAND_CmdAddEntry, SCRIPT_COMMAND_CmdFreeEntry, SCRIPT_COMMAND_CmdShowEntry, SCRIPT_COMMAND_CmdHideEntry, SCRIPT_COMMAND_CmdSetEntryTarget, SCRIPT_COMMAND_TaskEntryTarget, SCRIPT_COMMAND_CmdSetAnimSlot, SCRIPT_COMMAND_CmdFreeAnimSlot, SCRIPT_COMMAND_CmdStartEffect, SCRIPT_COMMAND_CmdKillEffect, SCRIPT_COMMAND_CmdMoveEffect, SCRIPT_COMMAND_TaskMoveEffect, SCRIPT_COMMAND_CmdSetChar, SCRIPT_COMMAND_CmdFreeChar, SCRIPT_COMMAND_CmdSetCharPos, SCRIPT_COMMAND_TaskCharMove, SCRIPT_COMMAND_CmdCharFollowActor, SCRIPT_COMMAND_TaskCharFollow, SCRIPT_COMMAND_CmdSetCharColor, SCRIPT_COMMAND_CmdPrintText, SCRIPT_COMMAND_CmdClearText, SCRIPT_COMMAND_CmdSetTextColor, SCRIPT_COMMAND_CmdInstallBgm, SCRIPT_COMMAND_CmdStartSeq, SCRIPT_COMMAND_CmdStopSeq, SCRIPT_COMMAND_CmdReplaceWave, SCRIPT_COMMAND_CmdPlayBgm, SCRIPT_COMMAND_CmdStopBgm
 * address:  0x021FAF70
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from sta_acting.c, script_command.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   STA_ACT_LIGHT_SetActorPos 0x021F8054 thumb ov112
 *   STA_ACT_LIGHT_CopyActorPos 0x021F8044 thumb ov112
 *   STA_ACT_LIGHT_GetElemPos 0x021F6F04 thumb ov112
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   GFL_USE_GetRandomBelow 0x02005728 thumb
 *   STA_ACT_EFFECT_StartSystem  0x021F9EDC  thumb
 *   STA_ACT_EFFECT_KillSystem  0x021F9F58  thumb
 *   STA_ACT_EFFECT_StartEffect 0x021F9F74 thumb ov132
 *   STA_ACTING_GetCameraPos 0x021F9DFC thumb ov132
 *   STA_ACTING_GetCameraTarget 0x021F9E04 thumb ov132
 *   STA_ACTING_GetActorSystem 0x021F9DA0 thumb ov132
 *   STA_ACTING_GetActor 0x021F9DA4 thumb ov132
 *   STA_ACTING_GetCharSystem 0x021F9DD4 thumb ov132
 *   STA_ACTING_GetCharSlot 0x021F9DDC thumb ov132
 *   VEC_Add 0x0207C9D0 arm
 *   VM_GetU32 0x0201134C thumb
 *   d_021FDD00 0x021FDD00 data ov132 a4
 *   STA_ACTING_PlayRankSe 0x021F96D0 thumb ov132
 *   STA_ACTING_SetCameraPos 0x021F9E00 thumb ov132
 *   STA_ACTING_SetCameraTarget 0x021F9E08 thumb ov132
 *   STA_ACTING_ShowAnim  0x021F9D80  thumb
 *   STA_ACTING_ScheduleActions  0x021F9AD8  thumb
 *   STA_ACTING_HideAnim  0x021F9D90  thumb
 *   STA_ACT_LIGHT_SetSlotVisible 0x021F80D4 thumb ov112
 *   STA_ACT_LIGHT_SetActorFlagB 0x021F812C thumb ov112
 *   VEC_Subtract 0x0207CA00 arm
 *   STA_ACT_LIGHT_ResetRenderAnim 0x021F80B0 thumb ov112
 *   STA_ACT_LIGHT_StartRenderAnim 0x021F80A0 thumb ov112
 *   STA_ACT_LIGHT_SetRenderAnim 0x021F80C8 thumb ov112
 *   STA_ACT_LIGHT_SetActorVisible 0x021F8140 thumb ov112
 *   STA_ACT_LIGHT_SetElemValue 0x021F8154 thumb ov112
 *   STA_ACTING_PositionAnim 0x021F9D18 thumb ov132
 *   STA_ACTING_SetSelection 0x021F95CC thumb ov132
 *   STA_ACTING_LoadRankAnim 0x021F9140 thumb ov132
 *   STA_ACTING_LoadAnimMember 0x021F91A8 thumb ov132
 *   STA_ACT_LIGHT_SetActorOffset 0x021F8084 thumb ov112
 *   func_0209C0A4  0x0209C0A4  arm
 *   STA_ACT_LIGHT_SetActorAngle  0x021F8068  thumb  ov112
 *   STA_ACTING_GetRecordScore 0x021F9E20 thumb ov132
 *   STA_ACTING_GetBonus 0x021F9E34 thumb ov132
 *   STA_ACTING_SetField10 0x021F9E3C thumb ov132
 *   _s32_to_float 0x0209BDBC arm
 *   _ffix 0x0209C494 arm
 *   _fsub 0x0209CB8C arm
 *   __fdiv 0x0209CE10 arm
 *   STA_ACTING_GetActObj 0x021F9DAC thumb ov132
 *   STA_ACT_OBJ_AddEntry 0x021F6B18 thumb ov112
 *   STA_ACTING_SetSlot 0x021F9DB8 thumb ov132
 *   STA_ACTING_GetSlot 0x021F9DB0 thumb ov132
 *   STA_ACT_OBJ_FreeEntry 0x021F6B80 thumb ov112
 *   STA_ACT_LIGHT_SetElemVisible 0x021F6BC0 thumb ov112
 *   STA_ACT_OBJ_SetEntryTarget 0x021F6B9C thumb ov112
 *   STA_ACT_OBJ_GetEntryTarget 0x021F6BB0 thumb ov112
 *   STA_ACTING_GetAnimHandle 0x021F9DC0 thumb ov132
 *   STA_ACTING_SetAnimSlot 0x021F9DCC thumb ov132
 *   STA_ACTING_GetAnimSlot 0x021F9DC4 thumb ov132
 *   STA_ACT_LIGHT_CreateActor 0x021F6E78 thumb ov112
 *   STA_ACT_LIGHT_SetElemA 0x021F6F14 thumb ov112
 *   STA_ACT_LIGHT_SetElemB 0x021F6F1C thumb ov112
 *   STA_ACTING_SetCharSlot 0x021F9DE8 thumb ov132
 *   STA_ACTING_MarkDirty 0x021F95E8 thumb ov132
 *   STA_ACT_LIGHT_DeleteActor 0x021F6EE4 thumb ov112
 *   STA_ACT_LIGHT_CopyElemA 0x021F6EF4 thumb ov112
 *   STA_ACTING_GetBoard 0x021F9DF4 thumb ov132
 *   STA_ACTING_PrintText 0x021F93D8 thumb ov132
 *   STA_ACTING_ClearText  0x021F94B0  thumb
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   STA_ACTING_InstallBgm  0x021F9664  thumb
 *   STA_ACTING_StartSeq  0x021F9680  thumb
 *   STA_ACTING_StopSeq  0x021F9690  thumb
 *   STA_ACTING_ReplaceWaveData 0x021F969C thumb ov132
 *   STA_ACTING_PlayBgm  0x021F96B0  thumb
 *   STA_ACTING_StopBgm  0x021F96C4  thumb
 *   STA_ACT_EFFECT_SetSceneField14 0x021F9E40 thumb ov132
 *   STA_ACT_EFFECT_KillEffect 0x021F9FB4 thumb ov132
 *   STA_ACT_SCRIPT_AddTask 0x021FADA0 thumb ov132
 *   STA_ACT_SCRIPT_RemoveTask 0x021FADF8 thumb ov132
 *   STA_ACT_SCRIPT_StepTaskInt 0x021FAE1C thumb ov132
 *   STA_ACT_SCRIPT_StepTaskVec 0x021FAE4C thumb ov132
 *   STA_ACT_SCRIPT_StepTaskActor 0x021FAEA8 thumb ov132
 *   STA_ACT_SCRIPT_TickSlot 0x021FAEE8 thumb ov132
 */
#include "ov132_types.h"
#include "sta_acting_shared_types.h"
#include "sta_act_script_shared_types.h"
#include "script_command_shared_types.h"

extern void STA_ACT_LIGHT_SetActorPos(void *unused, u32 *p, const u32 *q);

extern void STA_ACT_LIGHT_CopyActorPos(void *unused, u32 *p, u32 *q);

#define ABS(x) ((x) < 0 ? -(x) : (x))

typedef signed short s16;

typedef enum { COORD_ZERO } Coord;

typedef struct TaskData { void *context; int tick, duration, count; void *slot; int amplitude; void *owner; void *task; } TaskData;

typedef struct Vec3 { u32 x, y, z; } Vec3;

typedef struct Tag { u32 v; } Tag;

typedef struct Msg { struct ScriptOwner *f0; void *f4; u8 pad8[0xC]; u16 f14; } Msg;

typedef struct ScriptActorMoveTask {
    u32 f00; char *f04; Vec3 f08; Vec3 f14; Vec3 f20; u16 f2C; u16 f2E; struct ScriptOwner *f30; void *f34;
} ScriptActorMoveTask;

typedef struct ScriptShakeTask { char *f00; u32 f04; u32 f08; u32 f0C; void *f10; u32 f14; struct ScriptOwner *f18; void *f1C; } ScriptShakeTask;

typedef struct ScriptCameraTargetTask { char *f00; u32 f04; u32 f08; u16 f0C; u16 f0E; struct ScriptOwner *f10; void *f14; } ScriptCameraTargetTask;

extern void *GFL_HEAP_Alloc(unsigned, unsigned, int, const char *, u16);

extern u16 STA_ACTING_GetCameraPos(void *p);

extern unsigned GFL_USE_GetRandomBelow(unsigned);

extern u16 STA_ACTING_GetCameraTarget(u8 *p);

extern void *STA_ACTING_GetActorSystem(char *p);

extern void *STA_ACTING_GetActor(char *p, u32 i);

extern void *STA_ACTING_GetCharSystem(void *);

extern void *STA_ACTING_GetCharSlot(void *,u8);

extern void STA_ACT_LIGHT_GetElemPos(void *,char *,Vec *);

extern void VEC_Add(const Vec *, const Vec *, Vec *);

extern u32 VM_GetU32(struct Cursor *p);

extern void STA_ACTING_PlayRankSe(char *p);

extern void STA_ACTING_SetCameraPos(void *, u16);

extern void STA_ACTING_SetCameraTarget(u8 *p, u16 v);

extern void STA_ACTING_ShowAnim(char *p);

extern void STA_ACTING_ScheduleActions(char *p, int mode, u8 slot);

extern void STA_ACTING_HideAnim(char *p);

extern void STA_ACT_LIGHT_SetSlotVisible(char *, char *, int);

extern int STA_ACT_LIGHT_SetActorFlagB(int unused, int *p, int flag);

extern void VEC_Subtract(void *,void *,void *);

extern void STA_ACT_LIGHT_ResetRenderAnim(char *, char *);

extern void STA_ACT_LIGHT_StartRenderAnim(int a, u8 *p);

extern void STA_ACT_LIGHT_SetRenderAnim(int, void *, u8);

extern void STA_ACT_LIGHT_SetActorVisible(int a, u8 *p, int b);

extern int STA_ACT_LIGHT_SetElemValue(int a0, int *a1, int a2);

extern void STA_ACTING_PositionAnim(char *p, unsigned i);

extern void STA_ACTING_SetSelection(char *,unsigned char,int);

extern void STA_ACTING_LoadRankAnim(unsigned char *,unsigned char,unsigned char);

extern void STA_ACTING_LoadAnimMember(char *p, u8 n, u8 mask);

extern void STA_ACT_LIGHT_SetActorOffset(void *unused, u32 *p, const u32 *q);

extern int func_0209C0A4();

extern void STA_ACT_LIGHT_SetActorAngle(int self, char *p, u16 v);

extern u16 STA_ACTING_GetRecordScore(char *p, u32 i);

extern u16 STA_ACTING_GetBonus(char *p, u32 i);

extern void STA_ACTING_SetField10(char *p, u32 v);

extern int _s32_to_float(int a);

extern u32 _ffix(u32 a);

extern u32 _fsub(u32 a, u32 b);

extern u32 __fdiv(u32 a, u32 b);

extern void *STA_ACTING_GetActObj(void *p);

extern struct Entry *STA_ACT_OBJ_AddEntry(struct Object *,unsigned short);

extern void STA_ACTING_SetSlot(void *p, void *v, u32 i);

extern unsigned int *STA_ACTING_GetSlot(void *,unsigned char);

extern void STA_ACT_OBJ_FreeEntry(unsigned int *,unsigned int *);

extern void STA_ACT_LIGHT_SetElemVisible(char *,unsigned int *,unsigned int);

extern void STA_ACT_OBJ_SetEntryTarget(void *,u32 *,u32 *);

extern void STA_ACT_OBJ_GetEntryTarget(void *,u32 *,u32 *);

extern void *STA_ACTING_GetAnimHandle(void *p);

extern void STA_ACTING_SetAnimSlot(void *p, void *v, u32 i);

extern void *STA_ACTING_GetAnimSlot(void *,u8);

extern u8 *STA_ACT_LIGHT_CreateActor(u8 *p, int v);

extern void STA_ACT_LIGHT_SetElemA(void *a, char *p, u16 b, u8 c);

extern void STA_ACT_LIGHT_SetElemB(void *a, char *p, u32 b, u32 c);

extern void STA_ACTING_SetCharSlot(void *,void *,u8);

extern void STA_ACTING_MarkDirty(char *p);

extern void STA_ACT_LIGHT_DeleteActor(void *,u8 *);

extern void STA_ACT_LIGHT_CopyElemA(void *unused, u32 *p, const u32 *q);

extern void *STA_ACTING_GetBoard(void *p);

extern void STA_ACTING_PrintText(u8 *,u16,u32);

extern void STA_ACTING_ClearText(u8 *p);

extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);

extern void STA_ACTING_InstallBgm(char *p, int a);

extern void STA_ACTING_StartSeq(char *p, int a);

extern void STA_ACTING_StopSeq(char *p);

extern int STA_ACTING_ReplaceWaveData(char *p, u32 a, u32 b, u32 d);

extern void STA_ACTING_PlayBgm(char *p, int a);

extern void STA_ACTING_StopBgm(char *p);

void STA_ACT_EFFECT_SetSceneField14(u8 *p,u32 v);

char *STA_ACT_EFFECT_StartSystem(char *p, u32 a);

void STA_ACT_EFFECT_KillSystem(u8 *unused,u8 *p);

void STA_ACT_EFFECT_StartEffect(char *p, unsigned i, Vec *v);

void STA_ACT_EFFECT_KillEffect(char *p, int i);

void *STA_ACT_SCRIPT_AddTask(char *p, u32 fn, u32 arg, u32 key);

void STA_ACT_SCRIPT_RemoveTask(char *p, char *q);

int STA_ACT_SCRIPT_StepTaskInt(char *p, int *out);

int STA_ACT_SCRIPT_StepTaskVec(char *p, int *out);

int STA_ACT_SCRIPT_StepTaskActor(char *p, void *out);

int STA_ACT_SCRIPT_TickSlot(char *p);

int SCRIPT_COMMAND_CmdCameraTo224(void *unused, char *ctx);

int SCRIPT_COMMAND_CmdCameraTo0(void *unused, char *ctx);

int SCRIPT_COMMAND_CmdSetCameraPos(void *unused, char *ctx);

void SCRIPT_COMMAND_TaskCameraPos(void *unused, char *p);

int SCRIPT_COMMAND_CmdSetCameraTarget(void *unused, char *ctx);

void SCRIPT_COMMAND_TaskCameraTarget(void *unused, char *p);

int SCRIPT_COMMAND_CmdSkipArg(void *unused,char *p);

int SCRIPT_COMMAND_CmdShowAnim(int a, char **pp);

int SCRIPT_COMMAND_CmdHideAnim(void *a, void **pp);

int SCRIPT_COMMAND_GetActorMask(char *p, int i);

int SCRIPT_COMMAND_CmdSetActorFrame(int unused, char *p);

int SCRIPT_COMMAND_CmdSetActorVisible(int unused, char *p);

int SCRIPT_COMMAND_CmdSetActorPos(int unused,char *p);

int SCRIPT_COMMAND_CmdAddActorPos(int unused,char *p);

void SCRIPT_COMMAND_TaskActorMove(int unused,char *p);

int SCRIPT_COMMAND_CmdActorAnimRestart(int unused, char *p);

int SCRIPT_COMMAND_CmdActorAnimPause(int unused, char *p);

int SCRIPT_COMMAND_CmdSetActorFlag(int unused, char *p);

int SCRIPT_COMMAND_CmdSetActorScale(int unused, char *p);

int SCRIPT_COMMAND_CmdSetActorLight(int unused, char *p);

int SCRIPT_COMMAND_CmdPositionAnim(int unused, char *p);

int SCRIPT_COMMAND_CmdSetSelection(int unused,char *p);

int SCRIPT_COMMAND_CmdClearSelection(int unused,char *p);

int SCRIPT_COMMAND_CmdLoadRankAnim(int unused,char *p);

int SCRIPT_COMMAND_CmdLoadAnimMember(int unused,char *p);

int SCRIPT_COMMAND_CmdStartShake(int unused, char *p);

void SCRIPT_COMMAND_TaskShake(int unused, char *p);

int SCRIPT_COMMAND_CmdRotateActor(int unused,char *p);

void SCRIPT_COMMAND_TaskRotate(int a0, int *a1);

int SCRIPT_COMMAND_CmdCompareScores(int unused, Msg *m);

int SCRIPT_COMMAND_CmdSetFlags(int unused, char *p);

int SCRIPT_COMMAND_CmdAddEntry(int unused,char *p);

int SCRIPT_COMMAND_CmdFreeEntry(int unused,char *p);

int SCRIPT_COMMAND_CmdShowEntry(int unused,char *p);

int SCRIPT_COMMAND_CmdHideEntry(int unused,char *p);

int SCRIPT_COMMAND_CmdSetEntryTarget(int unused,char *p);

void SCRIPT_COMMAND_TaskEntryTarget(int unused,char *p);

int SCRIPT_COMMAND_CmdSetAnimSlot(int unused,char *p);

int SCRIPT_COMMAND_CmdFreeAnimSlot(int unused,char *p);

int SCRIPT_COMMAND_CmdStartEffect(int unused, char *p);

int SCRIPT_COMMAND_CmdKillEffect(int unused,char *p);

int SCRIPT_COMMAND_CmdMoveEffect(int unused,char *p);

void SCRIPT_COMMAND_TaskMoveEffect(int a, char *p);

int SCRIPT_COMMAND_CmdSetChar(int a,char **p);

int SCRIPT_COMMAND_CmdFreeChar(int unused,char *p);

int SCRIPT_COMMAND_CmdSetCharPos(int unused,char *p);

void SCRIPT_COMMAND_TaskCharMove(int unused,char *p);

int SCRIPT_COMMAND_CmdCharFollowActor(int unused,char *p);

void SCRIPT_COMMAND_TaskCharFollow(int unused,char *p);

int SCRIPT_COMMAND_CmdSetCharColor(int a,char **p);

int SCRIPT_COMMAND_CmdPrintText(int unused,char *p);

int SCRIPT_COMMAND_CmdClearText(void *a, void **pp);

int SCRIPT_COMMAND_CmdSetTextColor(int unused,char *p);

int SCRIPT_COMMAND_CmdInstallBgm(int a, char **pp);

int SCRIPT_COMMAND_CmdStartSeq(int a, char **pp);

int SCRIPT_COMMAND_CmdStopSeq(int a, char **pp);

int SCRIPT_COMMAND_CmdReplaceWave(int unused,char *p);

int SCRIPT_COMMAND_CmdPlayBgm(int a, char **pp);

int SCRIPT_COMMAND_CmdStopBgm(int a, char **pp);

extern const char d_021FDD00[];

extern const s16 FX_SinCosTable_[];

int SCRIPT_COMMAND_CmdCameraTo224(void *unused, char *ctx)
{
    char *owner;
    char *p;
    int wait;
    int delta;
    owner = *(char * *)&((struct ScriptCtx *)ctx)->f0;
    wait = VM_GetU32(((struct ScriptCtx *)ctx)->f4.p);
    p = GFL_HEAP_Alloc(((struct ScriptOwner *)owner)->f0, 0x18, 0, d_021FDD00, 0x1a4);
    *(char * *)&((struct ScriptTask *)p)->f10 = owner;
    ((struct ScriptTask *)p)->f0 = ((struct ScriptOwner *)owner)->f34;
    ((struct ScriptTask *)p)->fE = 0;
    ((struct ScriptTask *)p)->f4.s = STA_ACTING_GetCameraPos(((struct ScriptOwner *)owner)->f34);
    ((struct ScriptTask *)p)->f8.s = 224;
    delta = 224 - ((struct ScriptTask *)p)->f4.s;
    if (delta < 0) delta = -delta;
    ((struct ScriptTask *)p)->fC = delta / 2;
    ((struct ScriptTask *)p)->f14 = STA_ACT_SCRIPT_AddTask(owner, (u32)SCRIPT_COMMAND_TaskCameraPos, (u32)p, 10);
    if (wait == 1) {
        ((struct ScriptCtx *)ctx)->f14 = ((struct ScriptTask *)p)->fC;
        return 1;
    }
    return 0;
}

int SCRIPT_COMMAND_CmdCameraTo0(void *unused, char *ctx)
{
    char *owner;
    char *p;
    int wait;
    int delta;
    owner = *(char * *)&((struct ScriptCtx *)ctx)->f0;
    wait = VM_GetU32(((struct ScriptCtx *)ctx)->f4.p);
    p = GFL_HEAP_Alloc(((struct ScriptOwner *)owner)->f0, 0x18, 0, d_021FDD00, 0x1c1);
    *(char * *)&((struct ScriptTask *)p)->f10 = owner;
    ((struct ScriptTask *)p)->f0 = ((struct ScriptOwner *)owner)->f34;
    ((struct ScriptTask *)p)->fE = 0;
    ((struct ScriptTask *)p)->f4.s = STA_ACTING_GetCameraPos(((struct ScriptOwner *)owner)->f34);
    ((struct ScriptTask *)p)->f8.s = 0;
    delta = ((struct ScriptTask *)p)->f8.s - ((struct ScriptTask *)p)->f4.s;
    if (delta < 0) delta = -delta;
    ((struct ScriptTask *)p)->fC = delta / 2;
    ((struct ScriptTask *)p)->f14 = STA_ACT_SCRIPT_AddTask(owner, (u32)SCRIPT_COMMAND_TaskCameraPos, (u32)p, 10);
    STA_ACTING_PlayRankSe(((struct ScriptOwner *)owner)->f34);
    if (wait == 1) {
        ((struct ScriptCtx *)ctx)->f14 = ((struct ScriptTask *)p)->fC;
        return 1;
    }
    return 0;
}

int SCRIPT_COMMAND_CmdSetCameraPos(void *unused, char *ctx)
{
    char *p;
    char *owner;
    int time;
    int target;
    int wait;
    owner = *(char * *)&((struct ScriptCtx *)ctx)->f0;
    time = VM_GetU32(((struct ScriptCtx *)ctx)->f4.p);
    target = VM_GetU32(((struct ScriptCtx *)ctx)->f4.p);
    wait = VM_GetU32(((struct ScriptCtx *)ctx)->f4.p);
    if (time == 0) {
        STA_ACTING_SetCameraPos(((struct ScriptOwner *)owner)->f34, target);
    } else {
        p = GFL_HEAP_Alloc(((struct ScriptOwner *)owner)->f0, 0x18, 0, d_021FDD00, 0x1e9);
        *(char * *)&((struct ScriptTask *)p)->f10 = owner;
        ((struct ScriptTask *)p)->f0 = ((struct ScriptOwner *)owner)->f34;
        ((struct ScriptTask *)p)->fE = 0;
        ((struct ScriptTask *)p)->f4.s = STA_ACTING_GetCameraPos(((struct ScriptOwner *)owner)->f34);
        ((struct ScriptTask *)p)->f8.s = target;
        ((struct ScriptTask *)p)->fC = time;
        ((struct ScriptTask *)p)->f14 = STA_ACT_SCRIPT_AddTask(owner, (u32)SCRIPT_COMMAND_TaskCameraPos, (u32)p, 10);
        if (wait == 1) {
            ((struct ScriptCtx *)ctx)->f14 = ((struct ScriptTask *)p)->fC;
            return 1;
        }
    }
    return 0;
}

void SCRIPT_COMMAND_TaskCameraPos(void *unused, char *p)
{
    int v;
    int done = STA_ACT_SCRIPT_StepTaskInt(p, &v);
    STA_ACTING_SetCameraPos(((struct ScriptTask *)p)->f0, v);
    if (done == 1) STA_ACT_SCRIPT_RemoveTask(*(char * *)&((struct ScriptTask *)p)->f10, *(char * *)&((struct ScriptTask *)p)->f14);
}

int SCRIPT_COMMAND_CmdSetCameraTarget(void *unused, char *ctx)
{
    char *p;
    char *owner;
    int time;
    int target;
    int wait;
    owner = *(char * *)&((struct ScriptCtx *)ctx)->f0;
    time = VM_GetU32(((struct ScriptCtx *)ctx)->f4.p);
    target = VM_GetU32(((struct ScriptCtx *)ctx)->f4.p);
    wait = VM_GetU32(((struct ScriptCtx *)ctx)->f4.p);
    if (time == 0) {
        STA_ACTING_SetCameraTarget(((struct ScriptOwner *)owner)->f34, target);
    } else {
        p = GFL_HEAP_Alloc(((struct ScriptOwner *)owner)->f0, 0x18, 0, d_021FDD00, 0x225);
        *(char * *)&((struct ScriptTask *)p)->f10 = owner;
        ((struct ScriptTask *)p)->f0 = ((struct ScriptOwner *)owner)->f34;
        ((struct ScriptTask *)p)->fE = 0;
        ((struct ScriptTask *)p)->f4.s = STA_ACTING_GetCameraTarget(((struct ScriptOwner *)owner)->f34);
        ((struct ScriptTask *)p)->f8.s = target;
        ((struct ScriptTask *)p)->fC = time;
        ((struct ScriptTask *)p)->f14 = STA_ACT_SCRIPT_AddTask(owner, (u32)SCRIPT_COMMAND_TaskCameraTarget, (u32)p, 10);
        if (wait == 1) {
            ((struct ScriptCtx *)ctx)->f14 = ((struct ScriptTask *)p)->fC;
            return 1;
        }
    }
    return 0;
}

void SCRIPT_COMMAND_TaskCameraTarget(void *unused, char *p)
{
    int v;
    int done = STA_ACT_SCRIPT_StepTaskInt(p, &v);
    STA_ACTING_SetCameraTarget(((struct ScriptTask *)p)->f0, v);
    if (done == 1) {
        STA_ACT_EFFECT_SetSceneField14(((struct ScriptTask *)p)->f0, 0);
        STA_ACT_SCRIPT_RemoveTask(*(char * *)&((struct ScriptTask *)p)->f10, *(char * *)&((struct ScriptTask *)p)->f14);
    }
}

int SCRIPT_COMMAND_CmdSkipArg(void *unused,char *p) { VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4); return 0; }

int SCRIPT_COMMAND_CmdShowAnim(int a, char **pp)
{
    char *p = *pp;

    STA_ACTING_ShowAnim(((struct ScriptOwner *)p)->f34);
    STA_ACTING_ScheduleActions(((struct ScriptOwner *)p)->f34, 0, 0);
    return 0;
}

int SCRIPT_COMMAND_CmdHideAnim(void *a, void **pp)
{
    STA_ACTING_HideAnim(((struct ScriptOwner *)((u8 *)*pp))->f34);
    return 0;
}

int SCRIPT_COMMAND_GetActorMask(char *p, int i)
{
    if (i == -1)
        return ((struct ScriptCtx *)p)->f18;
    return 1 << i;
}

int SCRIPT_COMMAND_CmdSetActorFrame(int unused, char *p)
{
    char *obj;
    int mask;
    char *ctx;
    int value;
    u8 i;
    obj = *(char * *)&((struct ScriptCtx *)p)->f0;
    mask = SCRIPT_COMMAND_GetActorMask(p, VM_GetU32(((struct ScriptCtx *)p)->f4.p));
    value = VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    ctx = STA_ACTING_GetActorSystem(((struct ScriptOwner *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            STA_ACT_LIGHT_SetSlotVisible(ctx, STA_ACTING_GetActor(((struct ScriptOwner *)obj)->f34, i), value);
        }
    }
    return 0;
}

/*
 * note: inferred extent ends with two zero padding bytes before the next labelled function.
 */
int SCRIPT_COMMAND_CmdSetActorVisible(int unused, char *p)
{
    char *obj;
    int mask;
    int value;
    char *ctx;
    u8 i;
    obj = *(char * *)&((struct ScriptCtx *)p)->f0;
    mask = SCRIPT_COMMAND_GetActorMask(p, VM_GetU32(((struct ScriptCtx *)p)->f4.p));
    value = VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    ctx = STA_ACTING_GetActorSystem(((struct ScriptOwner *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            char *slot;
            int flag;
            slot = STA_ACTING_GetActor(((struct ScriptOwner *)obj)->f34, i);
            flag = 0;
            if (value != 0) flag = 1;
            STA_ACT_LIGHT_SetActorFlagB((int)ctx, (int *)slot, flag);
        }
    }
    return 0;
}

int SCRIPT_COMMAND_CmdSetActorPos(int unused,char *p)
{
    int mask;
    char *owner,*q,*target;
    Vec pos;
    int delta[3];
    u32 wait,z,y,x,rate;
    char *ctx;
    u8 i;
    owner=*(char * *)&((struct ScriptCtx *)p)->f0;
    mask=SCRIPT_COMMAND_GetActorMask(p,VM_GetU32(((struct ScriptCtx *)p)->f4.p));
    rate=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    x=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    y=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    z=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    wait=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    ctx=STA_ACTING_GetActorSystem(((struct ScriptOwner *)owner)->f34);
    for(i=0;i<4;i++) {
        if(mask&(1<<i)) {
            target=STA_ACTING_GetActor(((struct ScriptOwner *)owner)->f34,i);
            if (rate==0) {
                pos.x=x;pos.y=y;pos.z=z;
                STA_ACT_LIGHT_SetActorPos(ctx,(u32 *)target,(const u32 *)(&pos));
            } else {
                q=GFL_HEAP_Alloc(((struct ScriptOwner *)owner)->f0,56,0,d_021FDD00,0x2DA);
                *(char * *)&((struct ScriptSlot *)q)->f30=owner;
                *(char * *)&((struct ScriptSlot *)q)->f0=target;
                ((struct ScriptSlot *)q)->f4.p=((struct ScriptOwner *)owner)->f34;
                ((struct ScriptSlot *)q)->f2E=0;
                STA_ACT_LIGHT_CopyActorPos(ctx,(u32 *)target,(u32 *)(q+8));
                ((struct ScriptSlot *)q)->f14.u=x;((struct ScriptSlot *)q)->f18.u=y;((struct ScriptSlot *)q)->f1C.u=z;
                ((struct ScriptSlot *)q)->f2C=rate;
                VEC_Subtract(q+20,q+8,delta);
                ((struct ScriptSlot *)q)->f20.s=delta[0]/(int)rate;
                ((struct ScriptSlot *)q)->f24.s=delta[1]/(int)rate;
                ((struct ScriptSlot *)q)->f28.s=delta[2]/(int)rate;
                ((struct ScriptSlot *)q)->f34=STA_ACT_SCRIPT_AddTask(owner,(u32)SCRIPT_COMMAND_TaskActorMove,(u32)q,10);
            }
        }
    }
    if(wait==1) {((struct ScriptCtx *)p)->f14=rate;return 1;}
    return 0;
}

static inline void vset(Vec *v,Coord x,Coord y,Coord z)
{
    v->x=x;v->y=y;v->z=z;
}

#pragma opt_loop_invariants off

/*
 * pass 2 2026-10-06 P2L34: EXACT in --lang c99 and --lang c. The last 23 bytes were spill slots:
 *   with loop invariant motion on, x,y,z (each used two or three times inside the loop) got new
 *   loop webs and fell below the other spills.  for this function
 *   keeps them as declared locals, and the slots then follow declaration order
 *   (mask, x, y, z, wait / i, ctx).
 */
int SCRIPT_COMMAND_CmdAddActorPos(int unused,char *p)
{
    int mask;
    Coord x,y,z;
    char *owner;
    int rate;
    Coord wait;
    owner=*(char **)p;
    mask=SCRIPT_COMMAND_GetActorMask(p,VM_GetU32(*(void **)(p+4)));
    rate=VM_GetU32(*(void **)(p+4));
    x=VM_GetU32(*(void **)(p+4));
    y=VM_GetU32(*(void **)(p+4));
    z=VM_GetU32(*(void **)(p+4));
    wait=VM_GetU32(*(void **)(p+4));
    {
    u8 i;
    void *ctx;
    char *q,*target;
    u32 pos[3];
    ctx=STA_ACTING_GetActorSystem(*(void **)(owner+52));
    for(i=0;i<4;i++) {
        if(mask&(1<<i)) {
            target=STA_ACTING_GetActor(*(void **)(owner+52),i);
            if (rate==0) {
                STA_ACT_LIGHT_CopyActorPos(ctx,(u32 *)target,pos);
                pos[0]+=x;pos[1]+=y;pos[2]+=z;
                STA_ACT_LIGHT_SetActorPos(ctx,(u32 *)target,pos);
            } else {
                q=GFL_HEAP_Alloc(*(u16 *)owner,56,0,d_021FDD00,0x31B);
                *(char **)(q+48)=owner;
                *(char **)q=target;
                *(void **)(q+4)=*(void **)(owner+52);
                *(u16 *)(q+46)=0;
                STA_ACT_LIGHT_CopyActorPos(ctx,(u32 *)target,(u32 *)(q+8));
                vset((Vec *)(q+20),*(int *)(q+8)+x,*(int *)(q+12)+y,*(int *)(q+16)+z);
                *(u16 *)(q+44)=rate;
                *(int *)(q+32)=(int)x/(int)rate;
                *(int *)(q+36)=(int)y/(int)rate;
                *(int *)(q+40)=(int)z/(int)rate;
                *(void **)(q+52)=STA_ACT_SCRIPT_AddTask(owner,(u32)SCRIPT_COMMAND_TaskActorMove,(u32)q,10);
            }
        }
    }
    }
    if(wait==1) {*(u16 *)(p+20)=rate;return 1;}
    return 0;
}

#pragma opt_loop_invariants reset

/*
 * lever: Void callback return omits the extra zero result instruction.
 */
void SCRIPT_COMMAND_TaskActorMove(int unused,char *p) { int pos[3]; void *ctx; int result; ctx=STA_ACTING_GetActorSystem(((struct ScriptSlot *)p)->f4.p); result=STA_ACT_SCRIPT_StepTaskVec(p+4,pos); STA_ACT_LIGHT_SetActorPos(ctx,*(unsigned int * *)&((struct ScriptSlot *)p)->f0,(unsigned int *)pos); if(result==1)STA_ACT_SCRIPT_RemoveTask(((struct ScriptSlot *)p)->f30,((struct ScriptSlot *)p)->f34); }

int SCRIPT_COMMAND_CmdActorAnimRestart(int unused, char *p)
{
    char *obj;
    int mask;
    char *ctx;
    u8 i;
    obj = *(char * *)&((struct ScriptCtx *)p)->f0;
    mask = SCRIPT_COMMAND_GetActorMask(p, VM_GetU32(((struct ScriptCtx *)p)->f4.p));
    ctx = STA_ACTING_GetActorSystem(((struct ScriptOwner *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            STA_ACT_LIGHT_ResetRenderAnim(ctx, STA_ACTING_GetActor(((struct ScriptOwner *)obj)->f34, i));
        }
    }
    return 0;
}

int SCRIPT_COMMAND_CmdActorAnimPause(int unused, char *p)
{
    char *obj;
    int mask;
    char *ctx;
    u8 i;
    obj = *(char * *)&((struct ScriptCtx *)p)->f0;
    mask = SCRIPT_COMMAND_GetActorMask(p, VM_GetU32(((struct ScriptCtx *)p)->f4.p));
    ctx = STA_ACTING_GetActorSystem(((struct ScriptOwner *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            STA_ACT_LIGHT_StartRenderAnim((int)ctx, STA_ACTING_GetActor(((struct ScriptOwner *)obj)->f34, i));
        }
    }
    return 0;
}

/*
 * note: STA_ACT_LIGHT_SetRenderAnim is called with a u8 third parameter (its matched unit declares unsigned int; the narrowing is loop-invariant and hoisted).
 * note: older draft in docs/notes/pkt_ov132_021FB5EC.c.txt (DIFF6) is superseded.
 */
int SCRIPT_COMMAND_CmdSetActorFlag(int unused, char *p)
{
    char *obj;
    int mask;
    int value;
    char *ctx;
    u8 i;
    obj = *(char **)p;
    mask = SCRIPT_COMMAND_GetActorMask(p, VM_GetU32(*(void **)(p + 4)));
    value = VM_GetU32(*(void **)(p + 4));
    ctx = STA_ACTING_GetActorSystem(*(char **)(obj + 0x34));
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            STA_ACT_LIGHT_SetRenderAnim((int)ctx, STA_ACTING_GetActor(*(char **)(obj + 0x34), i), value);
        }
    }
    return 0;
}

int SCRIPT_COMMAND_CmdSetActorScale(int unused, char *p)
{
    char *obj;
    int mask;
    int value;
    char *ctx;
    u8 i;
    obj = *(char * *)&((struct ScriptCtx *)p)->f0;
    mask = SCRIPT_COMMAND_GetActorMask(p, VM_GetU32(((struct ScriptCtx *)p)->f4.p));
    value = VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    ctx = STA_ACTING_GetActorSystem(((struct ScriptOwner *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            STA_ACT_LIGHT_SetActorVisible((int)ctx, STA_ACTING_GetActor(((struct ScriptOwner *)obj)->f34, i), value != 0);
        }
    }
    return 0;
}

int SCRIPT_COMMAND_CmdSetActorLight(int unused, char *p)
{
    char *obj;
    int mask;
    int value;
    char *ctx;
    u8 i;
    obj = *(char * *)&((struct ScriptCtx *)p)->f0;
    mask = SCRIPT_COMMAND_GetActorMask(p, VM_GetU32(((struct ScriptCtx *)p)->f4.p));
    value = VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    ctx = STA_ACTING_GetActorSystem(((struct ScriptOwner *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            STA_ACT_LIGHT_SetElemValue((int)ctx, STA_ACTING_GetActor(((struct ScriptOwner *)obj)->f34, i), value != 0);
        }
    }
    return 0;
}

int SCRIPT_COMMAND_CmdPositionAnim(int unused, char *p)
{
    char *obj;
    int mask;
    char *ctx;
    u8 i;
    obj = *(char * *)&((struct ScriptCtx *)p)->f0;
    mask = SCRIPT_COMMAND_GetActorMask(p, VM_GetU32(((struct ScriptCtx *)p)->f4.p));
    ctx = STA_ACTING_GetActorSystem(((struct ScriptOwner *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            STA_ACTING_GetActor(((struct ScriptOwner *)obj)->f34, i);
            STA_ACTING_PositionAnim(((struct ScriptOwner *)obj)->f34, i);
        }
    }
    return 0;
}

/*
 * extent: Two bytes of zero alignment padding follow the 58-byte body.
 */
int SCRIPT_COMMAND_CmdSetSelection(int unused,char *p) { char *obj; int mask; unsigned char i; obj=*(char * *)&((struct ScriptCtx *)p)->f0; mask=SCRIPT_COMMAND_GetActorMask(p,VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4)); for(i=0;i<4;i++)if((1<<i)&mask)STA_ACTING_SetSelection(*(char * *)&((struct ScriptOwner *)obj)->f34,i,1); return 0; }

int SCRIPT_COMMAND_CmdClearSelection(int unused,char *p) { char *obj; obj=*(char * *)&((struct ScriptCtx *)p)->f0; STA_ACTING_SetSelection(*(char * *)&((struct ScriptOwner *)obj)->f34,0,0);STA_ACTING_SetSelection(*(char * *)&((struct ScriptOwner *)obj)->f34,1,0);STA_ACTING_SetSelection(*(char * *)&((struct ScriptOwner *)obj)->f34,2,0);STA_ACTING_SetSelection(*(char * *)&((struct ScriptOwner *)obj)->f34,3,0);return 0; }

/*
 * prototype: Original caller narrows both 021F9140 arguments to bytes,
 * overriding its own source's wider parameters; 021F9AD8 index is byte too.
 */
int SCRIPT_COMMAND_CmdLoadRankAnim(int unused,char *p) { char *obj; unsigned int index,n; obj=*(char * *)&((struct ScriptCtx *)p)->f0;index=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4);n=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4);STA_ACTING_LoadRankAnim(*(unsigned char * *)&((struct ScriptOwner *)obj)->f34,n,index);STA_ACTING_ScheduleActions(*(char * *)&((struct ScriptOwner *)obj)->f34,1,index);return 0; }

int SCRIPT_COMMAND_CmdLoadAnimMember(int unused,char *p) { char *obj; int mask; unsigned int n; obj=*(char * *)&((struct ScriptCtx *)p)->f0;mask=SCRIPT_COMMAND_GetActorMask(p,VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4));n=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4);STA_ACTING_LoadAnimMember((char *)(*(unsigned char * *)&((struct ScriptOwner *)obj)->f34),n,mask);return 0; }

/*
 * note: task allocation is 32 bytes; the product local reproduces count-first multiply scheduling.
 */
int SCRIPT_COMMAND_CmdStartShake(int unused, char *p)
{
    char *obj;
    int mask, wait, amplitude, duration, count;
    u8 i;
    TaskData *data;
    obj = *(char * *)&((struct ScriptCtx *)p)->f0;
    mask = SCRIPT_COMMAND_GetActorMask(p, VM_GetU32(((struct ScriptCtx *)p)->f4.p));
    duration = VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    count = VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    amplitude = VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    wait = VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    STA_ACTING_GetActorSystem(((struct ScriptOwner *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            data = GFL_HEAP_Alloc(((struct ScriptOwner *)obj)->f0, 0x20, 0, d_021FDD00, 0x443);
            data->owner = obj;
            data->slot = STA_ACTING_GetActor(((struct ScriptOwner *)obj)->f34, i);
            data->amplitude = amplitude;
            data->context = ((struct ScriptOwner *)obj)->f34;
            data->tick = 0;
            data->duration = duration;
            data->count = count;
            data->task = STA_ACT_SCRIPT_AddTask(obj, (u32)SCRIPT_COMMAND_TaskShake, (u32)data, 10);
        }
    }
    if (wait == 1) {
        int product;
        product = count;
        product *= duration;
        ((struct ScriptCtx *)p)->f14 = product;
        return 1;
    }
    return 0;
}

void SCRIPT_COMMAND_TaskShake(int unused, char *p)
{
    void *ctx;
    ctx = STA_ACTING_GetActorSystem(((struct ScriptSlot *)p)->f0);
    if (STA_ACT_SCRIPT_TickSlot(p) == 2) {
        Vec zero = { 0, 0, 0 };
        STA_ACT_LIGHT_SetActorOffset(ctx, ((struct ScriptSlot *)p)->f10, (const u32 *)(&zero));
        STA_ACT_SCRIPT_RemoveTask(((struct ScriptSlot *)p)->f18.p, ((struct ScriptSlot *)p)->f1C.p);
        return;
    }
    else {
        Vec v;
        int sine;
        v.x = 0;
        sine = FX_SinCosTable_[((int)(((u32)((struct ScriptSlot *)p)->f4.s << 15) / (u32)((struct ScriptSlot *)p)->f8.s) >> 4) * 2];
        v.y = -(int)(((long long)sine * ((struct ScriptSlot *)p)->f14.s + 0x800) >> 12);
        v.z = 0;
        STA_ACT_LIGHT_SetActorOffset(ctx, ((struct ScriptSlot *)p)->f10, (const u32 *)(&v));
    }
}

int SCRIPT_COMMAND_CmdRotateActor(int unused,char *p)
{
    char *owner,*q;
    int mask;
    u32 rate,start,delta,wait;
    u8 i;
    owner=*(char * *)&((struct ScriptCtx *)p)->f0;
    mask=SCRIPT_COMMAND_GetActorMask(p,VM_GetU32(((struct ScriptCtx *)p)->f4.p));
    rate=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    start=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    delta=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    wait=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    STA_ACTING_GetActorSystem(((struct ScriptOwner *)owner)->f34);
    for(i=0;i<4;i++) {
        if(mask&(1<<i)) {
            q=GFL_HEAP_Alloc(((struct ScriptOwner *)owner)->f0,36,0,d_021FDD00,0x493);
            *(char * *)&((struct ScriptTask *)q)->f1C=owner;
            ((struct ScriptTask *)q)->f18.p=STA_ACTING_GetActor(((struct ScriptOwner *)owner)->f34,i);
            ((struct ScriptTask *)q)->f0=((struct ScriptOwner *)owner)->f34;
            ((struct ScriptTask *)q)->f4.u=start;
            ((struct ScriptTask *)q)->f8.u=start+delta;
            ((struct ScriptTask *)q)->fC=rate;
            ((struct ScriptTask *)q)->fE=0;
            ((struct ScriptTask *)q)->f20=STA_ACT_SCRIPT_AddTask(owner,(u32)SCRIPT_COMMAND_TaskRotate,(u32)q,10);
        }
    }
    if(wait==1) {((struct ScriptCtx *)p)->f14=rate;return 1;}
    return 0;
}

/*
 * note:     the bl to 0x021F8068 named an unlabelled leaf in the co-resident
 *           ov112 (ov112 0x021F36C0..0x021F8480 abuts ov132 0x021F8480..);
 *           it was filed EXACT as src/matched/STA_ACT_LIGHT_SetActorAngle.c, so the
 *           site now attests as `matched` and every concrete byte reproduces.
 *           EXACT* only because the inferred extent runs into an unlabelled
 *           follower in ov132; there is no byte difference.
 */
void SCRIPT_COMMAND_TaskRotate(int a0, int *a1)
{
    int r4 = (int)STA_ACTING_GetActorSystem((char *)a1[0]);
    int local;
    if (STA_ACT_SCRIPT_StepTaskInt((char *)a1, &local) == 1) {
        STA_ACT_LIGHT_SetActorAngle(r4, (char *)a1[6], (u16)func_0209C0A4(a1[2] << 16, 0x168));
        STA_ACT_SCRIPT_RemoveTask((char *)a1[7], (char *)a1[8]);
    } else {
        STA_ACT_LIGHT_SetActorAngle(r4, (char *)a1[6], (u16)func_0209C0A4(local << 16, 0x168));
    }
}

int SCRIPT_COMMAND_CmdCompareScores(int unused, Msg *m)
{
    struct ScriptOwner *o = m->f0;
    u32 vec[4];
    Vec3 v;
    Tag tag;
    u32 x = VM_GetU32(m->f4);
    u32 y = VM_GetU32(m->f4);
    void *h = STA_ACTING_GetActorSystem(o->f34);
    u32 idx;
    u32 total;
    u32 base;
    u32 maxabs = 0;
    s8 dir[4] = { 0, 0, 0, 0 };
    u16 max = 0;
    u8 i, j, k;

    for (i = 0; i < 4; i++) {
        u16 v = STA_ACTING_GetBonus(o->f34, i) + STA_ACTING_GetRecordScore(o->f34, i);
        if (max < v)
            max = v;
    }
    for (i = 0; i < 4; i++) {
        u16 v = STA_ACTING_GetBonus(o->f34, i) + STA_ACTING_GetRecordScore(o->f34, i);
        if (max == v)
            idx = i;
    }
    for (i = 0; i < 4; i++) {
        STA_ACT_LIGHT_CopyActorPos(h, STA_ACTING_GetActor(o->f34, i), &v.x);
        vec[i] = v.x;
        if (i == idx)
            base = v.x;
    }
    for (i = 0; i < 4; i++)
        vec[i] = vec[i] - base;
    for (i = 0; i < 4; i++) {
        if (i == idx)
            continue;
        for (j = 0; j < 4; j++) {
            if (i == j)
                continue;
            if ((int)vec[i] > 0 && (int)vec[j] >= 0 && (int)vec[i] > (int)vec[j])
                dir[i]++;
            else if ((int)vec[i] < 0 && (int)vec[j] <= 0 && (int)vec[i] < (int)vec[j])
                dir[i]--;
        }
        if ((int)maxabs < ABS(dir[i]))
            maxabs = (u8)ABS(dir[i]);
    }
    total = 0;
    for (k = 0; k < 4; k++) {
        ScriptActorMoveTask *a;
        tag.v = 0x54B;
        tag.v -= 0x1B;
        a = GFL_HEAP_Alloc(o->f0, 0x38, 0, d_021FDD00, tag.v);
        a->f30 = o;
        a->f00 = (u32)STA_ACTING_GetActor(o->f34, k);
        a->f04 = o->f34;
        a->f2E = 0;
        STA_ACT_LIGHT_CopyActorPos(h, (void *)a->f00, (u32 *)&a->f08);
        a->f14.x = base + (dir[k] << 18);
        a->f14.y = a->f08.y;
        a->f14.z = a->f08.z;
        a->f2C = func_0209C0A4(ABS(dir[k]) * x, maxabs);
        a->f20.x = func_0209C0A4(a->f14.x - a->f08.x, a->f2C);
        a->f20.y = func_0209C0A4(a->f14.y - a->f08.y, a->f2C);
        a->f20.z = func_0209C0A4(a->f14.z - a->f08.z, a->f2C);
        a->f34 = STA_ACT_SCRIPT_AddTask((char *)o, (u32)SCRIPT_COMMAND_TaskActorMove, (u32)a, 10);
        if (a->f2C != 0) {
            ScriptShakeTask *b = GFL_HEAP_Alloc(o->f0, 0x20, 0, d_021FDD00, 0x54B);
            u16 t = a->f2C;
            int rem = (u8)(t % 15) ? 1 : 0;
            b->f18 = o;
            b->f10 = STA_ACTING_GetActor(o->f34, k);
            b->f14 = 0x8000;
            b->f00 = o->f34;
            b->f04 = 0;
            b->f08 = 15;
            b->f0C = (u8)(t / 15 + rem);
            b->f1C = STA_ACT_SCRIPT_AddTask((char *)o, (u32)SCRIPT_COMMAND_TaskShake, (u32)b, 10);
        }
        total += a->f14.x;
    }
    {
        ScriptCameraTargetTask *c = GFL_HEAP_Alloc(o->f0, 0x18, 0, d_021FDD00, 0x563);
        u32 f;
        c->f10 = o;
        c->f00 = o->f34;
        c->f0E = 0;
        c->f04 = STA_ACTING_GetCameraTarget((u8 *)o->f34);
        f = _s32_to_float((int)total / 4);
        f = __fdiv(f, 0x45800000);
        f = _fsub(f, 0x43000000);
        c->f08 = _ffix(f);
        c->f0C = x;
        c->f14 = STA_ACT_SCRIPT_AddTask((char *)o, (u32)SCRIPT_COMMAND_TaskCameraTarget, (u32)c, 10);
        STA_ACT_EFFECT_SetSceneField14((u8 *)o->f34, 1);
        STA_ACTING_SetField10(o->f34, 1);
        if (y == 1) {
            m->f14 = x;
            return 1;
        }
        return 0;
    }
}

int SCRIPT_COMMAND_CmdSetFlags(int unused, char *p)
{
    int a, b, c, d;
    a = VM_GetU32(((struct ScriptTask *)p)->f4.p);
    b = VM_GetU32(((struct ScriptTask *)p)->f4.p);
    c = VM_GetU32(((struct ScriptTask *)p)->f4.p);
    d = VM_GetU32(((struct ScriptTask *)p)->f4.p);
    ((struct ScriptTask *)p)->f18.b = 0;
    if (a == 1) ((struct ScriptTask *)p)->f18.b += 1;
    if (b == 1) ((struct ScriptTask *)p)->f18.b += 2;
    if (c == 1) ((struct ScriptTask *)p)->f18.b += 4;
    if (d == 1) ((struct ScriptTask *)p)->f18.b += 8;
    return 0;
}

/*
 * prototype: 021F6B18's own source reads r0 only; this caller additionally
 * supplies r1 as a narrowed halfword, retained as an unused second input.
 */
int SCRIPT_COMMAND_CmdAddEntry(int unused,char *p) { char *obj; unsigned int a,b; struct Entry *entry;obj=*(char * *)&((struct ScriptCtx *)p)->f0;a=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4);b=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4);entry=STA_ACT_OBJ_AddEntry(STA_ACTING_GetActObj(((struct ScriptOwner *)obj)->f34),b);STA_ACTING_SetSlot(((struct ScriptOwner *)obj)->f34,entry,(unsigned char)a);return 0; }

/*
 * extent: Two bytes of zero alignment padding follow the 54-byte body.
 */
int SCRIPT_COMMAND_CmdFreeEntry(int unused,char *p) { char *obj; unsigned int n; void *ctx; obj=*(char * *)&((struct ScriptCtx *)p)->f0;n=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4);ctx=STA_ACTING_GetActObj(((struct ScriptOwner *)obj)->f34);STA_ACT_OBJ_FreeEntry(ctx,STA_ACTING_GetSlot(((struct ScriptOwner *)obj)->f34,n));STA_ACTING_SetSlot(((struct ScriptOwner *)obj)->f34,0,(unsigned char)n);return 0; }

int SCRIPT_COMMAND_CmdShowEntry(int unused,char *p) { char *obj; unsigned int n; void *ctx; obj=*(char * *)&((struct ScriptCtx *)p)->f0;n=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4);ctx=STA_ACTING_GetActObj(((struct ScriptOwner *)obj)->f34);STA_ACT_LIGHT_SetElemVisible(ctx,STA_ACTING_GetSlot(((struct ScriptOwner *)obj)->f34,n),1);return 0; }

int SCRIPT_COMMAND_CmdHideEntry(int unused,char *p) { char *obj; unsigned int n; void *ctx; obj=*(char * *)&((struct ScriptCtx *)p)->f0;n=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4);ctx=STA_ACTING_GetActObj(((struct ScriptOwner *)obj)->f34);STA_ACT_LIGHT_SetElemVisible(ctx,STA_ACTING_GetSlot(((struct ScriptOwner *)obj)->f34,n),0);return 0; }

int SCRIPT_COMMAND_CmdSetEntryTarget(int unused,char *p)
{
    char *owner,*q;
    u32 pos[3];
    int delta[3];
    u32 e,d,c,b,a;
    u32 *target;
    void *ctx;
    owner=*(char * *)&((struct ScriptCtx *)p)->f0;
    a=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    b=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    c=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    d=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    e=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    ctx=STA_ACTING_GetActObj(((struct ScriptOwner *)owner)->f34);
    target=STA_ACTING_GetSlot(((struct ScriptOwner *)owner)->f34,a);
    if (b==0) {
        pos[0]=c;pos[1]=d;pos[2]=e;
        STA_ACT_OBJ_SetEntryTarget(ctx,target,pos);
    } else {
        q=GFL_HEAP_Alloc(((struct ScriptOwner *)owner)->f0,56,0,d_021FDD00,0x601);
        *(char * *)&((struct ScriptSlot *)q)->f30=owner;
        *(u32 * *)&((struct ScriptSlot *)q)->f0=target;
        ((struct ScriptSlot *)q)->f4.p=((struct ScriptOwner *)owner)->f34;
        ((struct ScriptSlot *)q)->f2E=0;
        STA_ACT_OBJ_GetEntryTarget(ctx,target,(u32 *)(q+8));
        ((struct ScriptSlot *)q)->f14.u=c;((struct ScriptSlot *)q)->f18.u=d;((struct ScriptSlot *)q)->f1C.u=e;
        ((struct ScriptSlot *)q)->f2C=b;
        VEC_Subtract(q+20,q+8,delta);
        ((struct ScriptSlot *)q)->f20.s=delta[0]/(int)b;
        ((struct ScriptSlot *)q)->f24.s=delta[1]/(int)b;
        ((struct ScriptSlot *)q)->f28.s=delta[2]/(int)b;
        ((struct ScriptSlot *)q)->f34=STA_ACT_SCRIPT_AddTask(owner,(u32)SCRIPT_COMMAND_TaskEntryTarget,(u32)q,10);
    }
    return 0;
}

void SCRIPT_COMMAND_TaskEntryTarget(int unused,char *p) { int pos[3]; void *ctx; int result;ctx=STA_ACTING_GetActObj(((struct ScriptSlot *)p)->f4.p);result=STA_ACT_SCRIPT_StepTaskVec(p+4,pos);STA_ACT_OBJ_SetEntryTarget(ctx,*(unsigned int * *)&((struct ScriptSlot *)p)->f0,(unsigned int *)pos);if(result==1)STA_ACT_SCRIPT_RemoveTask(((struct ScriptSlot *)p)->f30,((struct ScriptSlot *)p)->f34);}

/*
 * prototype: Own 021F9EDC source takes u16; original caller passes the
 * full word b+0x33 without truncation, so the extern parameter is widened.
 */
int SCRIPT_COMMAND_CmdSetAnimSlot(int unused,char *p) { char *obj; unsigned int a,b; char *entry;obj=*(char * *)&((struct ScriptCtx *)p)->f0;a=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4);b=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4);entry=STA_ACT_EFFECT_StartSystem(STA_ACTING_GetAnimHandle(((struct ScriptOwner *)obj)->f34),b+0x33);STA_ACTING_SetAnimSlot(((struct ScriptOwner *)obj)->f34,entry,(unsigned char)a);return 0; }

int SCRIPT_COMMAND_CmdFreeAnimSlot(int unused,char *p) { char *o; u32 a; void *ctx; o=*(char * *)&((struct ScriptCtx *)p)->f0; a=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4); ctx=STA_ACTING_GetAnimHandle(((struct ScriptOwner *)o)->f34); STA_ACT_EFFECT_KillSystem(ctx,STA_ACTING_GetAnimSlot(((struct ScriptOwner *)o)->f34,a)); STA_ACTING_SetAnimSlot(((struct ScriptOwner *)o)->f34,0,(u8)a); return 0; }

int SCRIPT_COMMAND_CmdStartEffect(int unused, char *p)
{
    char *obj;
    int a, b, c, d, e;
    void *target;
    Vec vec;
    obj = *(char * *)&((struct ScriptCtx *)p)->f0;
    a = VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    b = VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    c = VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    d = VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    e = VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    target = STA_ACTING_GetAnimSlot(((struct ScriptOwner *)obj)->f34, (u8)a);
    vec.x = c / 16;
    vec.y = (0xC0000 - d) / 16;
    vec.z = e;
    STA_ACT_EFFECT_StartEffect((char *)target, (u16)b, &vec);
    return 0;
}

int SCRIPT_COMMAND_CmdKillEffect(int unused,char *p) { char *o; u32 a,b; o=*(char * *)&((struct ScriptCtx *)p)->f0; a=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4); b=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4); STA_ACT_EFFECT_KillEffect(STA_ACTING_GetAnimSlot(((struct ScriptOwner *)o)->f34,a),(u16)b); return 0; }

int SCRIPT_COMMAND_CmdMoveEffect(int unused,char *p)
{
    char *owner,*q;
    void *target;
    u32 j,i,h,g,f,e,d,c,b,a;
    owner=*(char * *)&((struct ScriptCtx *)p)->f0;
    a=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    b=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    c=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    d=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    e=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    f=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    g=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    h=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    i=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    j=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    target=STA_ACTING_GetAnimSlot(((struct ScriptOwner *)owner)->f34,a);
    q=GFL_HEAP_Alloc(((struct ScriptOwner *)owner)->f0,56,0,d_021FDD00,0x691);
    *(char * *)&((struct ScriptSlot *)q)->f30=owner;
    ((struct ScriptSlot *)q)->f10=target;
    ((struct ScriptSlot *)q)->f2C=b;
    ((struct ScriptSlot *)q)->f14.u=e;
    ((struct ScriptSlot *)q)->f18.u=f;
    ((struct ScriptSlot *)q)->f1C.u=g;
    ((struct ScriptSlot *)q)->f20.u=h-e;
    ((struct ScriptSlot *)q)->f24.u=i-f;
    ((struct ScriptSlot *)q)->f28.u=j-g;
    ((struct ScriptSlot *)q)->f0=((struct ScriptOwner *)owner)->f34;
    ((struct ScriptSlot *)q)->f4.u=0;
    ((struct ScriptSlot *)q)->f8.u=c;
    ((struct ScriptSlot *)q)->fC=d;
    ((struct ScriptSlot *)q)->f34=STA_ACT_SCRIPT_AddTask(owner,(u32)SCRIPT_COMMAND_TaskMoveEffect,(u32)q,10);
    return 0;
}

void SCRIPT_COMMAND_TaskMoveEffect(int a, char *p)
{
    u32 v[3];
    int s;
    s=STA_ACT_SCRIPT_TickSlot(p);
    if(s==2) {
        STA_ACT_SCRIPT_RemoveTask(((struct ScriptSlot *)p)->f30,((struct ScriptSlot *)p)->f34);
        return;
    }
    if(s==1) {
        v[0]=(((struct ScriptSlot *)p)->f14.u+GFL_USE_GetRandomBelow(((struct ScriptSlot *)p)->f20.u))>>4;
        v[1]=(0xc0000-(((struct ScriptSlot *)p)->f18.u+GFL_USE_GetRandomBelow(((struct ScriptSlot *)p)->f24.u)))>>4;
        v[2]=((struct ScriptSlot *)p)->f1C.u+GFL_USE_GetRandomBelow(((struct ScriptSlot *)p)->f28.u);
        STA_ACT_EFFECT_StartEffect((char *)((struct ScriptSlot *)p)->f10,((struct ScriptSlot *)p)->f2C,(Vec *)v);
    }
}

int SCRIPT_COMMAND_CmdSetChar(int a,char **p)
{
    char *q;
    u32 x,y;
    void *r,*s;
    q=p[0];
    x=VM_GetU32((struct Cursor *)p[1]);
    y=VM_GetU32((struct Cursor *)p[1]);
    r=STA_ACTING_GetCharSystem(((struct ScriptOwner *)q)->f34);
    s=STA_ACT_LIGHT_CreateActor(r,1);
    STA_ACT_LIGHT_SetElemA(r,s,0x3ff,0x10);
    STA_ACT_LIGHT_SetElemB(r,s,y,0);
    STA_ACTING_SetCharSlot(((struct ScriptOwner *)q)->f34,s,x);
    STA_ACTING_MarkDirty(((struct ScriptOwner *)q)->f34);
    return 0;
}

int SCRIPT_COMMAND_CmdFreeChar(int unused,char *p) { char *o; u32 a; void *ctx; o=*(char * *)&((struct ScriptCtx *)p)->f0; a=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4); ctx=STA_ACTING_GetCharSystem(((struct ScriptOwner *)o)->f34); STA_ACT_LIGHT_DeleteActor(ctx,STA_ACTING_GetCharSlot(((struct ScriptOwner *)o)->f34,a)); STA_ACTING_SetCharSlot(((struct ScriptOwner *)o)->f34,0,a); STA_ACTING_MarkDirty(((struct ScriptOwner *)o)->f34); return 0; }

int SCRIPT_COMMAND_CmdSetCharPos(int unused,char *p)
{
    char *owner,*q;
    Vec pos;
    int delta[3];
    u32 e,d,c,b,a;
    void *target;
    void *ctx;
    owner=*(char * *)&((struct ScriptCtx *)p)->f0;
    a=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    b=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    c=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    d=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    e=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    ctx=STA_ACTING_GetCharSystem(((struct ScriptOwner *)owner)->f34);
    target=STA_ACTING_GetCharSlot(((struct ScriptOwner *)owner)->f34,a);
    if (b==0) {
        pos.x=c;pos.y=d;pos.z=e;
        STA_ACT_LIGHT_CopyElemA(ctx,target,(const u32 *)(&pos));
    } else {
        q=GFL_HEAP_Alloc(((struct ScriptOwner *)owner)->f0,56,0,d_021FDD00,0x704);
        *(char * *)&((struct ScriptSlot *)q)->f30=owner;
        *(u32 * *)&((struct ScriptSlot *)q)->f0=target;
        ((struct ScriptSlot *)q)->f4.p=((struct ScriptOwner *)owner)->f34;
        ((struct ScriptSlot *)q)->f2E=0;
        STA_ACT_LIGHT_GetElemPos(ctx,target,(Vec *)(q+8));
        ((struct ScriptSlot *)q)->f14.u=c;((struct ScriptSlot *)q)->f18.u=d;((struct ScriptSlot *)q)->f1C.u=e;
        ((struct ScriptSlot *)q)->f2C=b;
        VEC_Subtract(q+20,q+8,delta);
        ((struct ScriptSlot *)q)->f20.s=delta[0]/(int)b;
        ((struct ScriptSlot *)q)->f24.s=delta[1]/(int)b;
        ((struct ScriptSlot *)q)->f28.s=delta[2]/(int)b;
        ((struct ScriptSlot *)q)->f34=STA_ACT_SCRIPT_AddTask(owner,(u32)SCRIPT_COMMAND_TaskCharMove,(u32)q,10);
    }
    return 0;
}

void SCRIPT_COMMAND_TaskCharMove(int unused,char *p) { int pos[3]; void *ctx; int result; ctx=STA_ACTING_GetCharSystem(((struct ScriptSlot *)p)->f4.p); result=STA_ACT_SCRIPT_StepTaskVec(p+4,pos); STA_ACT_LIGHT_CopyElemA(ctx,*(u32 * *)&((struct ScriptSlot *)p)->f0,(u32 *)pos); if(result==1) STA_ACT_SCRIPT_RemoveTask(*(char * *)&((struct ScriptSlot *)p)->f30,*(char * *)&((struct ScriptSlot *)p)->f34); }

int SCRIPT_COMMAND_CmdCharFollowActor(int unused,char *p)
{
 char *owner,*q;
 Vec pos,delta;
 u16 duration;
 u32 f,e,d,b,c,a;
 void *ctx,*target,*scene,*obj;
 u8 i;
 owner=*(char * *)&((struct ScriptCtx *)p)->f0;
 a=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
 b=SCRIPT_COMMAND_GetActorMask(p,VM_GetU32(((struct ScriptCtx *)p)->f4.p));
 c=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
 d=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
 e=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
 f=VM_GetU32(((struct ScriptCtx *)p)->f4.p);
 ctx=STA_ACTING_GetCharSystem(((struct ScriptOwner *)owner)->f34);
 target=STA_ACTING_GetCharSlot(((struct ScriptOwner *)owner)->f34,a);
 scene=STA_ACTING_GetActorSystem(((struct ScriptOwner *)owner)->f34);
 duration=c;
 for(i=0;i<4;i++) {
  obj=STA_ACTING_GetActor(((struct ScriptOwner *)owner)->f34,i);
  if(b&(1<<i)) {
   if(c==0) {
    STA_ACT_LIGHT_CopyActorPos(scene,obj,(u32 *)(&pos));
    delta.x=d;delta.y=e;delta.z=f;
    VEC_Add(&pos,&delta,&pos);
    STA_ACT_LIGHT_CopyElemA(ctx,target,(const u32 *)(&pos));
   } else {
    STA_ACTING_GetBoard(((struct ScriptOwner *)owner)->f34);
    q=GFL_HEAP_Alloc(((struct ScriptOwner *)owner)->f0,0x30,0,d_021FDD00,0x74D);
    *(char * *)&((struct ScriptCharFollowTask *)q)->owner=owner;
    ((struct ScriptCharFollowTask *)q)->index=i;
    ((struct ScriptCharFollowTask *)q)->target=target;
    ((struct ScriptCharFollowTask *)q)->step.scene=((struct ScriptOwner *)owner)->f34;
    ((struct ScriptCharFollowTask *)q)->step.actor=obj;
    ((struct ScriptCharFollowTask *)q)->step.counter=0;
    ((struct ScriptCharFollowTask *)q)->step.dx=d;((struct ScriptCharFollowTask *)q)->step.dy=e;((struct ScriptCharFollowTask *)q)->step.dz=f;
    ((struct ScriptCharFollowTask *)q)->step.duration=duration;
    ((struct ScriptCharFollowTask *)q)->task=STA_ACT_SCRIPT_AddTask(owner,(u32)SCRIPT_COMMAND_TaskCharFollow,(u32)q,7);
   }
  }
 }
 return 0;
}

void SCRIPT_COMMAND_TaskCharFollow(int unused,char *p) { int pos[3]; void *ctx; int result; ctx=STA_ACTING_GetCharSystem(((struct ScriptCharFollowTask *)p)->step.scene); STA_ACTING_GetBoard(((struct ScriptCharFollowTask *)p)->step.scene); result=STA_ACT_SCRIPT_StepTaskActor((char *)&((struct ScriptCharFollowTask *)p)->step,pos); STA_ACT_LIGHT_CopyElemA(ctx,*(u32 * *)&((struct ScriptCharFollowTask *)p)->target,(u32 *)pos); if(result==1) STA_ACT_SCRIPT_RemoveTask(*(char * *)&((struct ScriptCharFollowTask *)p)->owner,*(char * *)&((struct ScriptCharFollowTask *)p)->task); }

/*
 * follower: two-byte zero alignment padding at 021FC53A.
 */
int SCRIPT_COMMAND_CmdSetCharColor(int a,char **p)
{
    char *q;
    u32 v,w,x,y,z;
    void *r,*s;
    q=p[0];
    v=VM_GetU32((struct Cursor *)p[1]);
    w=VM_GetU32((struct Cursor *)p[1]);
    x=VM_GetU32((struct Cursor *)p[1]);
    y=VM_GetU32((struct Cursor *)p[1]);
    z=VM_GetU32((struct Cursor *)p[1]);
    r=STA_ACTING_GetCharSystem(((struct ScriptOwner *)q)->f34);
    s=STA_ACTING_GetCharSlot(((struct ScriptOwner *)q)->f34,v);
    STA_ACT_LIGHT_SetElemA(r,s,(u8)w|((u8)x<<5)|((u8)y<<10),z);
    return 0;
}

int SCRIPT_COMMAND_CmdPrintText(int unused,char *p) { char *o; u32 a,b; o=*(char * *)&((struct ScriptCtx *)p)->f0; a=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4); b=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4); STA_ACTING_PrintText(*(u8 * *)&((struct ScriptOwner *)o)->f34,a,b); return 0; }

int SCRIPT_COMMAND_CmdClearText(void *a, void **pp)
{
    STA_ACTING_ClearText(((struct ScriptOwner *)((u8 *)*pp))->f34);
    return 0;
}

int SCRIPT_COMMAND_CmdSetTextColor(int unused,char *p) { u32 a,b,c; a=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4); b=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4); c=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4); GF_FONT_SetTextColor((u8)a,(u8)b,(u8)c); return 0; }

int SCRIPT_COMMAND_CmdInstallBgm(int a, char **pp)
{
    char *p = *pp;
    int x = VM_GetU32((struct Cursor *)(((struct ScriptCtx *)pp)->f4.s));

    STA_ACTING_InstallBgm(((struct ScriptOwner *)p)->f34, (unsigned short)x);
    return 0;
}

int SCRIPT_COMMAND_CmdStartSeq(int a, char **pp)
{
    char *p = *pp;
    int x = VM_GetU32((struct Cursor *)(((struct ScriptCtx *)pp)->f4.s));

    STA_ACTING_StartSeq(((struct ScriptOwner *)p)->f34, (unsigned short)x);
    return 0;
}

int SCRIPT_COMMAND_CmdStopSeq(int a, char **pp)
{
    STA_ACTING_StopSeq(((struct ScriptOwner *)(*pp))->f34);
    return 0;
}

int SCRIPT_COMMAND_CmdReplaceWave(int unused,char *p) { char *o; u32 a,b,c; o=*(char * *)&((struct ScriptCtx *)p)->f0; a=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4); b=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4); c=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4); STA_ACTING_ReplaceWaveData(*(char * *)&((struct ScriptOwner *)o)->f34,(u16)a,(u16)b,(u16)c); return 0; }

int SCRIPT_COMMAND_CmdPlayBgm(int a, char **pp)
{
    char *p = *pp;
    int x = VM_GetU32((struct Cursor *)(((struct ScriptCtx *)pp)->f4.s));

    STA_ACTING_PlayBgm(((struct ScriptOwner *)p)->f34, x);
    return 0;
}

int SCRIPT_COMMAND_CmdStopBgm(int a, char **pp)
{
    STA_ACTING_StopBgm(((struct ScriptOwner *)(*pp))->f34);
    return 0;
}
