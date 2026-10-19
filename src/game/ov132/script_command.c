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
 *   _s32_div_f  0x0209C0A4  arm
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

typedef struct Msg { struct ScriptOwner *system; void *vm; u8 pad8[0xC]; u16 waitFrames; } Msg;

typedef struct ScriptActorMoveTask {
    u32 actor; char *scene; Vec3 start; Vec3 end; Vec3 step; u16 duration; u16 counter; struct ScriptOwner *system; void *node;
} ScriptActorMoveTask;

typedef struct ScriptShakeTask { char *scene; u32 counter; u32 interval; u32 remaining; void *actor; int amplitude; void *system; void *node; } ScriptShakeTask;

typedef struct ScriptCameraTargetTask { char *scene; u32 start; u32 end; u16 duration; u16 counter; struct ScriptOwner *system; void *node; } ScriptCameraTargetTask;

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

extern int _s32_div_f(int a, int b);

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

void SCRIPT_COMMAND_TaskRotate(int unused, int *task);

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
    owner = *(char * *)&((struct ScriptCtx *)ctx)->system;
    wait = VM_GetU32(((struct ScriptCtx *)ctx)->vm.p);
    p = GFL_HEAP_Alloc(((struct ScriptOwner *)owner)->heapId, 0x18, 0, d_021FDD00, 0x1a4);
    *(char * *)&((struct ScriptTask *)p)->system = owner;
    ((struct ScriptTask *)p)->scene = ((struct ScriptOwner *)owner)->scene;
    ((struct ScriptTask *)p)->counter = 0;
    ((struct ScriptTask *)p)->start.s = STA_ACTING_GetCameraPos(((struct ScriptOwner *)owner)->scene);
    ((struct ScriptTask *)p)->end.s = 224;
    delta = 224 - ((struct ScriptTask *)p)->start.s;
    if (delta < 0) delta = -delta;
    ((struct ScriptTask *)p)->duration = delta / 2;
    ((struct ScriptTask *)p)->node = STA_ACT_SCRIPT_AddTask(owner, (u32)SCRIPT_COMMAND_TaskCameraPos, (u32)p, 10);
    if (wait == 1) {
        ((struct ScriptCtx *)ctx)->waitFrames = ((struct ScriptTask *)p)->duration;
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
    owner = *(char * *)&((struct ScriptCtx *)ctx)->system;
    wait = VM_GetU32(((struct ScriptCtx *)ctx)->vm.p);
    p = GFL_HEAP_Alloc(((struct ScriptOwner *)owner)->heapId, 0x18, 0, d_021FDD00, 0x1c1);
    *(char * *)&((struct ScriptTask *)p)->system = owner;
    ((struct ScriptTask *)p)->scene = ((struct ScriptOwner *)owner)->scene;
    ((struct ScriptTask *)p)->counter = 0;
    ((struct ScriptTask *)p)->start.s = STA_ACTING_GetCameraPos(((struct ScriptOwner *)owner)->scene);
    ((struct ScriptTask *)p)->end.s = 0;
    delta = ((struct ScriptTask *)p)->end.s - ((struct ScriptTask *)p)->start.s;
    if (delta < 0) delta = -delta;
    ((struct ScriptTask *)p)->duration = delta / 2;
    ((struct ScriptTask *)p)->node = STA_ACT_SCRIPT_AddTask(owner, (u32)SCRIPT_COMMAND_TaskCameraPos, (u32)p, 10);
    STA_ACTING_PlayRankSe(((struct ScriptOwner *)owner)->scene);
    if (wait == 1) {
        ((struct ScriptCtx *)ctx)->waitFrames = ((struct ScriptTask *)p)->duration;
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
    owner = *(char * *)&((struct ScriptCtx *)ctx)->system;
    time = VM_GetU32(((struct ScriptCtx *)ctx)->vm.p);
    target = VM_GetU32(((struct ScriptCtx *)ctx)->vm.p);
    wait = VM_GetU32(((struct ScriptCtx *)ctx)->vm.p);
    if (time == 0) {
        STA_ACTING_SetCameraPos(((struct ScriptOwner *)owner)->scene, target);
    } else {
        p = GFL_HEAP_Alloc(((struct ScriptOwner *)owner)->heapId, 0x18, 0, d_021FDD00, 0x1e9);
        *(char * *)&((struct ScriptTask *)p)->system = owner;
        ((struct ScriptTask *)p)->scene = ((struct ScriptOwner *)owner)->scene;
        ((struct ScriptTask *)p)->counter = 0;
        ((struct ScriptTask *)p)->start.s = STA_ACTING_GetCameraPos(((struct ScriptOwner *)owner)->scene);
        ((struct ScriptTask *)p)->end.s = target;
        ((struct ScriptTask *)p)->duration = time;
        ((struct ScriptTask *)p)->node = STA_ACT_SCRIPT_AddTask(owner, (u32)SCRIPT_COMMAND_TaskCameraPos, (u32)p, 10);
        if (wait == 1) {
            ((struct ScriptCtx *)ctx)->waitFrames = ((struct ScriptTask *)p)->duration;
            return 1;
        }
    }
    return 0;
}

void SCRIPT_COMMAND_TaskCameraPos(void *unused, char *p)
{
    int v;
    int done = STA_ACT_SCRIPT_StepTaskInt(p, &v);
    STA_ACTING_SetCameraPos(((struct ScriptTask *)p)->scene, v);
    if (done == 1) STA_ACT_SCRIPT_RemoveTask(*(char * *)&((struct ScriptTask *)p)->system, *(char * *)&((struct ScriptTask *)p)->node);
}

int SCRIPT_COMMAND_CmdSetCameraTarget(void *unused, char *ctx)
{
    char *p;
    char *owner;
    int time;
    int target;
    int wait;
    owner = *(char * *)&((struct ScriptCtx *)ctx)->system;
    time = VM_GetU32(((struct ScriptCtx *)ctx)->vm.p);
    target = VM_GetU32(((struct ScriptCtx *)ctx)->vm.p);
    wait = VM_GetU32(((struct ScriptCtx *)ctx)->vm.p);
    if (time == 0) {
        STA_ACTING_SetCameraTarget(((struct ScriptOwner *)owner)->scene, target);
    } else {
        p = GFL_HEAP_Alloc(((struct ScriptOwner *)owner)->heapId, 0x18, 0, d_021FDD00, 0x225);
        *(char * *)&((struct ScriptTask *)p)->system = owner;
        ((struct ScriptTask *)p)->scene = ((struct ScriptOwner *)owner)->scene;
        ((struct ScriptTask *)p)->counter = 0;
        ((struct ScriptTask *)p)->start.s = STA_ACTING_GetCameraTarget(((struct ScriptOwner *)owner)->scene);
        ((struct ScriptTask *)p)->end.s = target;
        ((struct ScriptTask *)p)->duration = time;
        ((struct ScriptTask *)p)->node = STA_ACT_SCRIPT_AddTask(owner, (u32)SCRIPT_COMMAND_TaskCameraTarget, (u32)p, 10);
        if (wait == 1) {
            ((struct ScriptCtx *)ctx)->waitFrames = ((struct ScriptTask *)p)->duration;
            return 1;
        }
    }
    return 0;
}

void SCRIPT_COMMAND_TaskCameraTarget(void *unused, char *p)
{
    int v;
    int done = STA_ACT_SCRIPT_StepTaskInt(p, &v);
    STA_ACTING_SetCameraTarget(((struct ScriptTask *)p)->scene, v);
    if (done == 1) {
        STA_ACT_EFFECT_SetSceneField14(((struct ScriptTask *)p)->scene, 0);
        STA_ACT_SCRIPT_RemoveTask(*(char * *)&((struct ScriptTask *)p)->system, *(char * *)&((struct ScriptTask *)p)->node);
    }
}

int SCRIPT_COMMAND_CmdSkipArg(void *unused,char *p) { VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->vm); return 0; }

int SCRIPT_COMMAND_CmdShowAnim(int unused, char **ctx)
{
    char *p = *ctx;

    STA_ACTING_ShowAnim(((struct ScriptOwner *)p)->scene);
    STA_ACTING_ScheduleActions(((struct ScriptOwner *)p)->scene, 0, 0);
    return 0;
}

int SCRIPT_COMMAND_CmdHideAnim(void *unused, void **ctx)
{
    STA_ACTING_HideAnim(((struct ScriptOwner *)((u8 *)*ctx))->scene);
    return 0;
}

int SCRIPT_COMMAND_GetActorMask(char *p, int requestedMask)
{
    if (requestedMask == -1)
        return ((struct ScriptCtx *)p)->actorMask;
    return 1 << requestedMask;
}

int SCRIPT_COMMAND_CmdSetActorFrame(int unused, char *p)
{
    char *obj;
    int mask;
    char *ctx;
    int value;
    u8 i;
    obj = *(char * *)&((struct ScriptCtx *)p)->system;
    mask = SCRIPT_COMMAND_GetActorMask(p, VM_GetU32(((struct ScriptCtx *)p)->vm.p));
    value = VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    ctx = STA_ACTING_GetActorSystem(((struct ScriptOwner *)obj)->scene);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            STA_ACT_LIGHT_SetSlotVisible(ctx, STA_ACTING_GetActor(((struct ScriptOwner *)obj)->scene, i), value);
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
    obj = *(char * *)&((struct ScriptCtx *)p)->system;
    mask = SCRIPT_COMMAND_GetActorMask(p, VM_GetU32(((struct ScriptCtx *)p)->vm.p));
    value = VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    ctx = STA_ACTING_GetActorSystem(((struct ScriptOwner *)obj)->scene);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            char *slot;
            int flag;
            slot = STA_ACTING_GetActor(((struct ScriptOwner *)obj)->scene, i);
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
    owner=*(char * *)&((struct ScriptCtx *)p)->system;
    mask=SCRIPT_COMMAND_GetActorMask(p,VM_GetU32(((struct ScriptCtx *)p)->vm.p));
    rate=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    x=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    y=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    z=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    wait=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    ctx=STA_ACTING_GetActorSystem(((struct ScriptOwner *)owner)->scene);
    for(i=0;i<4;i++) {
        if(mask&(1<<i)) {
            target=STA_ACTING_GetActor(((struct ScriptOwner *)owner)->scene,i);
            if (rate==0) {
                pos.x=x;pos.y=y;pos.z=z;
                STA_ACT_LIGHT_SetActorPos(ctx,(u32 *)target,(const u32 *)(&pos));
            } else {
                q=GFL_HEAP_Alloc(((struct ScriptOwner *)owner)->heapId,56,0,d_021FDD00,0x2DA);
                *(char * *)&((struct ScriptSlot *)q)->system=owner;
                *(char * *)&((struct ScriptSlot *)q)->target=target;
                ((struct ScriptSlot *)q)->scene=((struct ScriptOwner *)owner)->scene;
                ((struct ScriptSlot *)q)->counter=0;
                STA_ACT_LIGHT_CopyActorPos(ctx,(u32 *)target,(u32 *)(q+8));
                ((struct ScriptSlot *)q)->end[0]=x;((struct ScriptSlot *)q)->end[1]=y;((struct ScriptSlot *)q)->end[2]=z;
                ((struct ScriptSlot *)q)->duration=rate;
                VEC_Subtract(q+20,q+8,delta);
                ((struct ScriptSlot *)q)->step[0]=delta[0]/(int)rate;
                ((struct ScriptSlot *)q)->step[1]=delta[1]/(int)rate;
                ((struct ScriptSlot *)q)->step[2]=delta[2]/(int)rate;
                ((struct ScriptSlot *)q)->node=STA_ACT_SCRIPT_AddTask(owner,(u32)SCRIPT_COMMAND_TaskActorMove,(u32)q,10);
            }
        }
    }
    if(wait==1) {((struct ScriptCtx *)p)->waitFrames=rate;return 1;}
    return 0;
}

static inline void vset(Vec *vec,Coord x,Coord y,Coord z)
{
    vec->x=x;vec->y=y;vec->z=z;
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
void SCRIPT_COMMAND_TaskActorMove(int unused,char *p) { int pos[3]; void *ctx; int result; ctx=STA_ACTING_GetActorSystem(((struct ScriptSlot *)p)->scene); result=STA_ACT_SCRIPT_StepTaskVec(p+4,pos); STA_ACT_LIGHT_SetActorPos(ctx,*(unsigned int * *)&((struct ScriptSlot *)p)->target,(unsigned int *)pos); if(result==1)STA_ACT_SCRIPT_RemoveTask(((struct ScriptSlot *)p)->system,((struct ScriptSlot *)p)->node); }

int SCRIPT_COMMAND_CmdActorAnimRestart(int unused, char *p)
{
    char *obj;
    int mask;
    char *ctx;
    u8 i;
    obj = *(char * *)&((struct ScriptCtx *)p)->system;
    mask = SCRIPT_COMMAND_GetActorMask(p, VM_GetU32(((struct ScriptCtx *)p)->vm.p));
    ctx = STA_ACTING_GetActorSystem(((struct ScriptOwner *)obj)->scene);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            STA_ACT_LIGHT_ResetRenderAnim(ctx, STA_ACTING_GetActor(((struct ScriptOwner *)obj)->scene, i));
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
    obj = *(char * *)&((struct ScriptCtx *)p)->system;
    mask = SCRIPT_COMMAND_GetActorMask(p, VM_GetU32(((struct ScriptCtx *)p)->vm.p));
    ctx = STA_ACTING_GetActorSystem(((struct ScriptOwner *)obj)->scene);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            STA_ACT_LIGHT_StartRenderAnim((int)ctx, STA_ACTING_GetActor(((struct ScriptOwner *)obj)->scene, i));
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
    obj = *(char * *)&((struct ScriptCtx *)p)->system;
    mask = SCRIPT_COMMAND_GetActorMask(p, VM_GetU32(((struct ScriptCtx *)p)->vm.p));
    value = VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    ctx = STA_ACTING_GetActorSystem(((struct ScriptOwner *)obj)->scene);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            STA_ACT_LIGHT_SetActorVisible((int)ctx, STA_ACTING_GetActor(((struct ScriptOwner *)obj)->scene, i), value != 0);
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
    obj = *(char * *)&((struct ScriptCtx *)p)->system;
    mask = SCRIPT_COMMAND_GetActorMask(p, VM_GetU32(((struct ScriptCtx *)p)->vm.p));
    value = VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    ctx = STA_ACTING_GetActorSystem(((struct ScriptOwner *)obj)->scene);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            STA_ACT_LIGHT_SetElemValue((int)ctx, STA_ACTING_GetActor(((struct ScriptOwner *)obj)->scene, i), value != 0);
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
    obj = *(char * *)&((struct ScriptCtx *)p)->system;
    mask = SCRIPT_COMMAND_GetActorMask(p, VM_GetU32(((struct ScriptCtx *)p)->vm.p));
    ctx = STA_ACTING_GetActorSystem(((struct ScriptOwner *)obj)->scene);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            STA_ACTING_GetActor(((struct ScriptOwner *)obj)->scene, i);
            STA_ACTING_PositionAnim(((struct ScriptOwner *)obj)->scene, i);
        }
    }
    return 0;
}

/*
 * extent: Two bytes of zero alignment padding follow the 58-byte body.
 */
int SCRIPT_COMMAND_CmdSetSelection(int unused,char *p) { char *obj; int mask; unsigned char i; obj=*(char * *)&((struct ScriptCtx *)p)->system; mask=SCRIPT_COMMAND_GetActorMask(p,VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->vm)); for(i=0;i<4;i++)if((1<<i)&mask)STA_ACTING_SetSelection(*(char * *)&((struct ScriptOwner *)obj)->scene,i,1); return 0; }

int SCRIPT_COMMAND_CmdClearSelection(int unused,char *p) { char *obj; obj=*(char * *)&((struct ScriptCtx *)p)->system; STA_ACTING_SetSelection(*(char * *)&((struct ScriptOwner *)obj)->scene,0,0);STA_ACTING_SetSelection(*(char * *)&((struct ScriptOwner *)obj)->scene,1,0);STA_ACTING_SetSelection(*(char * *)&((struct ScriptOwner *)obj)->scene,2,0);STA_ACTING_SetSelection(*(char * *)&((struct ScriptOwner *)obj)->scene,3,0);return 0; }

/*
 * prototype: Original caller narrows both 021F9140 arguments to bytes,
 * overriding its own source's wider parameters; 021F9AD8 index is byte too.
 */
int SCRIPT_COMMAND_CmdLoadRankAnim(int unused,char *p) { char *obj; unsigned int index,n; obj=*(char * *)&((struct ScriptCtx *)p)->system;index=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->vm);n=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->vm);STA_ACTING_LoadRankAnim(*(unsigned char * *)&((struct ScriptOwner *)obj)->scene,n,index);STA_ACTING_ScheduleActions(*(char * *)&((struct ScriptOwner *)obj)->scene,1,index);return 0; }

int SCRIPT_COMMAND_CmdLoadAnimMember(int unused,char *p) { char *obj; int mask; unsigned int n; obj=*(char * *)&((struct ScriptCtx *)p)->system;mask=SCRIPT_COMMAND_GetActorMask(p,VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->vm));n=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->vm);STA_ACTING_LoadAnimMember((char *)(*(unsigned char * *)&((struct ScriptOwner *)obj)->scene),n,mask);return 0; }

/*
 * note: task allocation is 32 bytes; the product local reproduces count-first multiply scheduling.
 */
int SCRIPT_COMMAND_CmdStartShake(int unused, char *p)
{
    char *obj;
    int mask, wait, amplitude, duration, count;
    u8 i;
    TaskData *data;
    obj = *(char * *)&((struct ScriptCtx *)p)->system;
    mask = SCRIPT_COMMAND_GetActorMask(p, VM_GetU32(((struct ScriptCtx *)p)->vm.p));
    duration = VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    count = VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    amplitude = VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    wait = VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    STA_ACTING_GetActorSystem(((struct ScriptOwner *)obj)->scene);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            data = GFL_HEAP_Alloc(((struct ScriptOwner *)obj)->heapId, 0x20, 0, d_021FDD00, 0x443);
            data->owner = obj;
            data->slot = STA_ACTING_GetActor(((struct ScriptOwner *)obj)->scene, i);
            data->amplitude = amplitude;
            data->context = ((struct ScriptOwner *)obj)->scene;
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
        ((struct ScriptCtx *)p)->waitFrames = product;
        return 1;
    }
    return 0;
}

void SCRIPT_COMMAND_TaskShake(int unused, char *p)
{
    void *ctx;
    ctx = STA_ACTING_GetActorSystem(((ScriptShakeTask *)p)->scene);
    if (STA_ACT_SCRIPT_TickSlot(p) == 2) {
        Vec zero = { 0, 0, 0 };
        STA_ACT_LIGHT_SetActorOffset(ctx, ((ScriptShakeTask *)p)->actor, (const u32 *)(&zero));
        STA_ACT_SCRIPT_RemoveTask(((ScriptShakeTask *)p)->system, ((ScriptShakeTask *)p)->node);
        return;
    }
    else {
        Vec v;
        int sine;
        v.x = 0;
        sine = FX_SinCosTable_[((int)(((u32)((ScriptShakeTask *)p)->counter << 15) / (u32)((ScriptShakeTask *)p)->interval) >> 4) * 2];
        v.y = -(int)(((long long)sine * ((ScriptShakeTask *)p)->amplitude + 0x800) >> 12);
        v.z = 0;
        STA_ACT_LIGHT_SetActorOffset(ctx, ((ScriptShakeTask *)p)->actor, (const u32 *)(&v));
    }
}

int SCRIPT_COMMAND_CmdRotateActor(int unused,char *p)
{
    char *owner,*q;
    int mask;
    u32 rate,start,delta,wait;
    u8 i;
    owner=*(char * *)&((struct ScriptCtx *)p)->system;
    mask=SCRIPT_COMMAND_GetActorMask(p,VM_GetU32(((struct ScriptCtx *)p)->vm.p));
    rate=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    start=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    delta=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    wait=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    STA_ACTING_GetActorSystem(((struct ScriptOwner *)owner)->scene);
    for(i=0;i<4;i++) {
        if(mask&(1<<i)) {
            q=GFL_HEAP_Alloc(((struct ScriptOwner *)owner)->heapId,36,0,d_021FDD00,0x493);
            *(char * *)&((struct ScriptTask *)q)->rotateSystem=owner;
            ((struct ScriptTask *)q)->actor=STA_ACTING_GetActor(((struct ScriptOwner *)owner)->scene,i);
            ((struct ScriptTask *)q)->scene=((struct ScriptOwner *)owner)->scene;
            ((struct ScriptTask *)q)->start.u=start;
            ((struct ScriptTask *)q)->end.u=start+delta;
            ((struct ScriptTask *)q)->duration=rate;
            ((struct ScriptTask *)q)->counter=0;
            ((struct ScriptTask *)q)->rotateNode=STA_ACT_SCRIPT_AddTask(owner,(u32)SCRIPT_COMMAND_TaskRotate,(u32)q,10);
        }
    }
    if(wait==1) {((struct ScriptCtx *)p)->waitFrames=rate;return 1;}
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
void SCRIPT_COMMAND_TaskRotate(int unused, int *task)
{
    int r4 = (int)STA_ACTING_GetActorSystem((char *)task[0]);
    int local;
    if (STA_ACT_SCRIPT_StepTaskInt((char *)task, &local) == 1) {
        STA_ACT_LIGHT_SetActorAngle(r4, (char *)task[6], (u16)_s32_div_f(task[2] << 16, 0x168));
        STA_ACT_SCRIPT_RemoveTask((char *)task[7], (char *)task[8]);
    } else {
        STA_ACT_LIGHT_SetActorAngle(r4, (char *)task[6], (u16)_s32_div_f(local << 16, 0x168));
    }
}

int SCRIPT_COMMAND_CmdCompareScores(int unused, Msg *ctx)
{
    struct ScriptOwner *o = ctx->system;
    u32 vec[4];
    Vec3 v;
    Tag tag;
    u32 x = VM_GetU32(ctx->vm);
    u32 y = VM_GetU32(ctx->vm);
    void *h = STA_ACTING_GetActorSystem(o->scene);
    u32 idx;
    u32 total;
    u32 base;
    u32 maxabs = 0;
    s8 dir[4] = { 0, 0, 0, 0 };
    u16 max = 0;
    u8 i, j, k;

    for (i = 0; i < 4; i++) {
        u16 v = STA_ACTING_GetBonus(o->scene, i) + STA_ACTING_GetRecordScore(o->scene, i);
        if (max < v)
            max = v;
    }
    for (i = 0; i < 4; i++) {
        u16 v = STA_ACTING_GetBonus(o->scene, i) + STA_ACTING_GetRecordScore(o->scene, i);
        if (max == v)
            idx = i;
    }
    for (i = 0; i < 4; i++) {
        STA_ACT_LIGHT_CopyActorPos(h, STA_ACTING_GetActor(o->scene, i), &v.x);
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
        a = GFL_HEAP_Alloc(o->heapId, 0x38, 0, d_021FDD00, tag.v);
        a->system = o;
        a->actor = (u32)STA_ACTING_GetActor(o->scene, k);
        a->scene = o->scene;
        a->counter = 0;
        STA_ACT_LIGHT_CopyActorPos(h, (void *)a->actor, (u32 *)&a->start);
        a->end.x = base + (dir[k] << 18);
        a->end.y = a->start.y;
        a->end.z = a->start.z;
        a->duration = _s32_div_f(ABS(dir[k]) * x, maxabs);
        a->step.x = _s32_div_f(a->end.x - a->start.x, a->duration);
        a->step.y = _s32_div_f(a->end.y - a->start.y, a->duration);
        a->step.z = _s32_div_f(a->end.z - a->start.z, a->duration);
        a->node = STA_ACT_SCRIPT_AddTask((char *)o, (u32)SCRIPT_COMMAND_TaskActorMove, (u32)a, 10);
        if (a->duration != 0) {
            ScriptShakeTask *b = GFL_HEAP_Alloc(o->heapId, 0x20, 0, d_021FDD00, 0x54B);
            u16 t = a->duration;
            int rem = (u8)(t % 15) ? 1 : 0;
            b->system = o;
            b->actor = STA_ACTING_GetActor(o->scene, k);
            b->amplitude = 0x8000;
            b->scene = o->scene;
            b->counter = 0;
            b->interval = 15;
            b->remaining = (u8)(t / 15 + rem);
            b->node = STA_ACT_SCRIPT_AddTask((char *)o, (u32)SCRIPT_COMMAND_TaskShake, (u32)b, 10);
        }
        total += a->end.x;
    }
    {
        ScriptCameraTargetTask *c = GFL_HEAP_Alloc(o->heapId, 0x18, 0, d_021FDD00, 0x563);
        u32 f;
        c->system = o;
        c->scene = o->scene;
        c->counter = 0;
        c->start = STA_ACTING_GetCameraTarget((u8 *)o->scene);
        f = _s32_to_float((int)total / 4);
        f = __fdiv(f, 0x45800000);
        f = _fsub(f, 0x43000000);
        c->end = _ffix(f);
        c->duration = x;
        c->node = STA_ACT_SCRIPT_AddTask((char *)o, (u32)SCRIPT_COMMAND_TaskCameraTarget, (u32)c, 10);
        STA_ACT_EFFECT_SetSceneField14((u8 *)o->scene, 1);
        STA_ACTING_SetField10(o->scene, 1);
        if (y == 1) {
            ctx->waitFrames = x;
            return 1;
        }
        return 0;
    }
}

int SCRIPT_COMMAND_CmdSetFlags(int unused, char *p)
{
    int a, b, c, d;
    a = VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    b = VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    c = VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    d = VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    ((struct ScriptCtx *)p)->actorMask = 0;
    if (a == 1) ((struct ScriptCtx *)p)->actorMask += 1;
    if (b == 1) ((struct ScriptCtx *)p)->actorMask += 2;
    if (c == 1) ((struct ScriptCtx *)p)->actorMask += 4;
    if (d == 1) ((struct ScriptCtx *)p)->actorMask += 8;
    return 0;
}

/*
 * prototype: 021F6B18's own source reads r0 only; this caller additionally
 * supplies r1 as a narrowed halfword, retained as an unused second input.
 */
int SCRIPT_COMMAND_CmdAddEntry(int unused,char *p) { char *obj; unsigned int a,b; struct Entry *entry;obj=*(char * *)&((struct ScriptCtx *)p)->system;a=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->vm);b=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->vm);entry=STA_ACT_OBJ_AddEntry(STA_ACTING_GetActObj(((struct ScriptOwner *)obj)->scene),b);STA_ACTING_SetSlot(((struct ScriptOwner *)obj)->scene,entry,(unsigned char)a);return 0; }

/*
 * extent: Two bytes of zero alignment padding follow the 54-byte body.
 */
int SCRIPT_COMMAND_CmdFreeEntry(int unused,char *p) { char *obj; unsigned int n; void *ctx; obj=*(char * *)&((struct ScriptCtx *)p)->system;n=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->vm);ctx=STA_ACTING_GetActObj(((struct ScriptOwner *)obj)->scene);STA_ACT_OBJ_FreeEntry(ctx,STA_ACTING_GetSlot(((struct ScriptOwner *)obj)->scene,n));STA_ACTING_SetSlot(((struct ScriptOwner *)obj)->scene,0,(unsigned char)n);return 0; }

int SCRIPT_COMMAND_CmdShowEntry(int unused,char *p) { char *obj; unsigned int n; void *ctx; obj=*(char * *)&((struct ScriptCtx *)p)->system;n=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->vm);ctx=STA_ACTING_GetActObj(((struct ScriptOwner *)obj)->scene);STA_ACT_LIGHT_SetElemVisible(ctx,STA_ACTING_GetSlot(((struct ScriptOwner *)obj)->scene,n),1);return 0; }

int SCRIPT_COMMAND_CmdHideEntry(int unused,char *p) { char *obj; unsigned int n; void *ctx; obj=*(char * *)&((struct ScriptCtx *)p)->system;n=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->vm);ctx=STA_ACTING_GetActObj(((struct ScriptOwner *)obj)->scene);STA_ACT_LIGHT_SetElemVisible(ctx,STA_ACTING_GetSlot(((struct ScriptOwner *)obj)->scene,n),0);return 0; }

int SCRIPT_COMMAND_CmdSetEntryTarget(int unused,char *p)
{
    char *owner,*q;
    u32 pos[3];
    int delta[3];
    u32 e,d,c,b,a;
    u32 *target;
    void *ctx;
    owner=*(char * *)&((struct ScriptCtx *)p)->system;
    a=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    b=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    c=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    d=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    e=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    ctx=STA_ACTING_GetActObj(((struct ScriptOwner *)owner)->scene);
    target=STA_ACTING_GetSlot(((struct ScriptOwner *)owner)->scene,a);
    if (b==0) {
        pos[0]=c;pos[1]=d;pos[2]=e;
        STA_ACT_OBJ_SetEntryTarget(ctx,target,pos);
    } else {
        q=GFL_HEAP_Alloc(((struct ScriptOwner *)owner)->heapId,56,0,d_021FDD00,0x601);
        *(char * *)&((struct ScriptSlot *)q)->system=owner;
        *(u32 * *)&((struct ScriptSlot *)q)->target=target;
        ((struct ScriptSlot *)q)->scene=((struct ScriptOwner *)owner)->scene;
        ((struct ScriptSlot *)q)->counter=0;
        STA_ACT_OBJ_GetEntryTarget(ctx,target,(u32 *)(q+8));
        ((struct ScriptSlot *)q)->end[0]=c;((struct ScriptSlot *)q)->end[1]=d;((struct ScriptSlot *)q)->end[2]=e;
        ((struct ScriptSlot *)q)->duration=b;
        VEC_Subtract(q+20,q+8,delta);
        ((struct ScriptSlot *)q)->step[0]=delta[0]/(int)b;
        ((struct ScriptSlot *)q)->step[1]=delta[1]/(int)b;
        ((struct ScriptSlot *)q)->step[2]=delta[2]/(int)b;
        ((struct ScriptSlot *)q)->node=STA_ACT_SCRIPT_AddTask(owner,(u32)SCRIPT_COMMAND_TaskEntryTarget,(u32)q,10);
    }
    return 0;
}

void SCRIPT_COMMAND_TaskEntryTarget(int unused,char *p) { int pos[3]; void *ctx; int result;ctx=STA_ACTING_GetActObj(((struct ScriptSlot *)p)->scene);result=STA_ACT_SCRIPT_StepTaskVec(p+4,pos);STA_ACT_OBJ_SetEntryTarget(ctx,*(unsigned int * *)&((struct ScriptSlot *)p)->target,(unsigned int *)pos);if(result==1)STA_ACT_SCRIPT_RemoveTask(((struct ScriptSlot *)p)->system,((struct ScriptSlot *)p)->node);}

/*
 * prototype: Own 021F9EDC source takes u16; original caller passes the
 * full word b+0x33 without truncation, so the extern parameter is widened.
 */
int SCRIPT_COMMAND_CmdSetAnimSlot(int unused,char *p) { char *obj; unsigned int a,b; char *entry;obj=*(char * *)&((struct ScriptCtx *)p)->system;a=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->vm);b=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->vm);entry=STA_ACT_EFFECT_StartSystem(STA_ACTING_GetAnimHandle(((struct ScriptOwner *)obj)->scene),b+0x33);STA_ACTING_SetAnimSlot(((struct ScriptOwner *)obj)->scene,entry,(unsigned char)a);return 0; }

int SCRIPT_COMMAND_CmdFreeAnimSlot(int unused,char *p) { char *o; u32 a; void *ctx; o=*(char * *)&((struct ScriptCtx *)p)->system; a=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->vm); ctx=STA_ACTING_GetAnimHandle(((struct ScriptOwner *)o)->scene); STA_ACT_EFFECT_KillSystem(ctx,STA_ACTING_GetAnimSlot(((struct ScriptOwner *)o)->scene,a)); STA_ACTING_SetAnimSlot(((struct ScriptOwner *)o)->scene,0,(u8)a); return 0; }

int SCRIPT_COMMAND_CmdStartEffect(int unused, char *p)
{
    char *obj;
    int a, b, c, d, e;
    void *target;
    Vec vec;
    obj = *(char * *)&((struct ScriptCtx *)p)->system;
    a = VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    b = VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    c = VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    d = VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    e = VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    target = STA_ACTING_GetAnimSlot(((struct ScriptOwner *)obj)->scene, (u8)a);
    vec.x = c / 16;
    vec.y = (0xC0000 - d) / 16;
    vec.z = e;
    STA_ACT_EFFECT_StartEffect((char *)target, (u16)b, &vec);
    return 0;
}

int SCRIPT_COMMAND_CmdKillEffect(int unused,char *p) { char *o; u32 a,b; o=*(char * *)&((struct ScriptCtx *)p)->system; a=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->vm); b=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->vm); STA_ACT_EFFECT_KillEffect(STA_ACTING_GetAnimSlot(((struct ScriptOwner *)o)->scene,a),(u16)b); return 0; }

int SCRIPT_COMMAND_CmdMoveEffect(int unused,char *p)
{
    char *owner,*q;
    void *target;
    u32 j,i,h,g,f,e,d,c,b,a;
    owner=*(char * *)&((struct ScriptCtx *)p)->system;
    a=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    b=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    c=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    d=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    e=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    f=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    g=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    h=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    i=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    j=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    target=STA_ACTING_GetAnimSlot(((struct ScriptOwner *)owner)->scene,a);
    q=GFL_HEAP_Alloc(((struct ScriptOwner *)owner)->heapId,56,0,d_021FDD00,0x691);
    *(char * *)&((struct ScriptEffectTask *)q)->system=owner;
    ((struct ScriptEffectTask *)q)->effectSystem=target;
    ((struct ScriptEffectTask *)q)->effectIndex=b;
    ((struct ScriptEffectTask *)q)->baseX=e;
    ((struct ScriptEffectTask *)q)->baseY=f;
    ((struct ScriptEffectTask *)q)->baseZ=g;
    ((struct ScriptEffectTask *)q)->rangeX=h-e;
    ((struct ScriptEffectTask *)q)->rangeY=i-f;
    ((struct ScriptEffectTask *)q)->rangeZ=j-g;
    ((struct ScriptEffectTask *)q)->scene=((struct ScriptOwner *)owner)->scene;
    ((struct ScriptEffectTask *)q)->counter=0;
    ((struct ScriptEffectTask *)q)->interval=c;
    ((struct ScriptEffectTask *)q)->remaining=d;
    ((struct ScriptEffectTask *)q)->node=STA_ACT_SCRIPT_AddTask(owner,(u32)SCRIPT_COMMAND_TaskMoveEffect,(u32)q,10);
    return 0;
}

void SCRIPT_COMMAND_TaskMoveEffect(int unused, char *p)
{
    u32 v[3];
    int s;
    s=STA_ACT_SCRIPT_TickSlot(p);
    if(s==2) {
        STA_ACT_SCRIPT_RemoveTask(((struct ScriptEffectTask *)p)->system,((struct ScriptEffectTask *)p)->node);
        return;
    }
    if(s==1) {
        v[0]=(((struct ScriptEffectTask *)p)->baseX+GFL_USE_GetRandomBelow(((struct ScriptEffectTask *)p)->rangeX))>>4;
        v[1]=(0xc0000-(((struct ScriptEffectTask *)p)->baseY+GFL_USE_GetRandomBelow(((struct ScriptEffectTask *)p)->rangeY)))>>4;
        v[2]=((struct ScriptEffectTask *)p)->baseZ+GFL_USE_GetRandomBelow(((struct ScriptEffectTask *)p)->rangeZ);
        STA_ACT_EFFECT_StartEffect((char *)((struct ScriptEffectTask *)p)->effectSystem,((struct ScriptEffectTask *)p)->effectIndex,(Vec *)v);
    }
}

int SCRIPT_COMMAND_CmdSetChar(int unused,char **p)
{
    char *q;
    u32 x,y;
    void *r,*s;
    q=p[0];
    x=VM_GetU32((struct Cursor *)p[1]);
    y=VM_GetU32((struct Cursor *)p[1]);
    r=STA_ACTING_GetCharSystem(((struct ScriptOwner *)q)->scene);
    s=STA_ACT_LIGHT_CreateActor(r,1);
    STA_ACT_LIGHT_SetElemA(r,s,0x3ff,0x10);
    STA_ACT_LIGHT_SetElemB(r,s,y,0);
    STA_ACTING_SetCharSlot(((struct ScriptOwner *)q)->scene,s,x);
    STA_ACTING_MarkDirty(((struct ScriptOwner *)q)->scene);
    return 0;
}

int SCRIPT_COMMAND_CmdFreeChar(int unused,char *p) { char *o; u32 a; void *ctx; o=*(char * *)&((struct ScriptCtx *)p)->system; a=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->vm); ctx=STA_ACTING_GetCharSystem(((struct ScriptOwner *)o)->scene); STA_ACT_LIGHT_DeleteActor(ctx,STA_ACTING_GetCharSlot(((struct ScriptOwner *)o)->scene,a)); STA_ACTING_SetCharSlot(((struct ScriptOwner *)o)->scene,0,a); STA_ACTING_MarkDirty(((struct ScriptOwner *)o)->scene); return 0; }

int SCRIPT_COMMAND_CmdSetCharPos(int unused,char *p)
{
    char *owner,*q;
    Vec pos;
    int delta[3];
    u32 e,d,c,b,a;
    void *target;
    void *ctx;
    owner=*(char * *)&((struct ScriptCtx *)p)->system;
    a=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    b=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    c=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    d=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    e=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
    ctx=STA_ACTING_GetCharSystem(((struct ScriptOwner *)owner)->scene);
    target=STA_ACTING_GetCharSlot(((struct ScriptOwner *)owner)->scene,a);
    if (b==0) {
        pos.x=c;pos.y=d;pos.z=e;
        STA_ACT_LIGHT_CopyElemA(ctx,target,(const u32 *)(&pos));
    } else {
        q=GFL_HEAP_Alloc(((struct ScriptOwner *)owner)->heapId,56,0,d_021FDD00,0x704);
        *(char * *)&((struct ScriptSlot *)q)->system=owner;
        *(u32 * *)&((struct ScriptSlot *)q)->target=target;
        ((struct ScriptSlot *)q)->scene=((struct ScriptOwner *)owner)->scene;
        ((struct ScriptSlot *)q)->counter=0;
        STA_ACT_LIGHT_GetElemPos(ctx,target,(Vec *)(q+8));
        ((struct ScriptSlot *)q)->end[0]=c;((struct ScriptSlot *)q)->end[1]=d;((struct ScriptSlot *)q)->end[2]=e;
        ((struct ScriptSlot *)q)->duration=b;
        VEC_Subtract(q+20,q+8,delta);
        ((struct ScriptSlot *)q)->step[0]=delta[0]/(int)b;
        ((struct ScriptSlot *)q)->step[1]=delta[1]/(int)b;
        ((struct ScriptSlot *)q)->step[2]=delta[2]/(int)b;
        ((struct ScriptSlot *)q)->node=STA_ACT_SCRIPT_AddTask(owner,(u32)SCRIPT_COMMAND_TaskCharMove,(u32)q,10);
    }
    return 0;
}

void SCRIPT_COMMAND_TaskCharMove(int unused,char *p) { int pos[3]; void *ctx; int result; ctx=STA_ACTING_GetCharSystem(((struct ScriptSlot *)p)->scene); result=STA_ACT_SCRIPT_StepTaskVec(p+4,pos); STA_ACT_LIGHT_CopyElemA(ctx,*(u32 * *)&((struct ScriptSlot *)p)->target,(u32 *)pos); if(result==1) STA_ACT_SCRIPT_RemoveTask(*(char * *)&((struct ScriptSlot *)p)->system,*(char * *)&((struct ScriptSlot *)p)->node); }

int SCRIPT_COMMAND_CmdCharFollowActor(int unused,char *p)
{
 char *owner,*q;
 Vec pos,delta;
 u16 duration;
 u32 f,e,d,b,c,a;
 void *ctx,*target,*scene,*obj;
 u8 i;
 owner=*(char * *)&((struct ScriptCtx *)p)->system;
 a=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
 b=SCRIPT_COMMAND_GetActorMask(p,VM_GetU32(((struct ScriptCtx *)p)->vm.p));
 c=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
 d=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
 e=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
 f=VM_GetU32(((struct ScriptCtx *)p)->vm.p);
 ctx=STA_ACTING_GetCharSystem(((struct ScriptOwner *)owner)->scene);
 target=STA_ACTING_GetCharSlot(((struct ScriptOwner *)owner)->scene,a);
 scene=STA_ACTING_GetActorSystem(((struct ScriptOwner *)owner)->scene);
 duration=c;
 for(i=0;i<4;i++) {
  obj=STA_ACTING_GetActor(((struct ScriptOwner *)owner)->scene,i);
  if(b&(1<<i)) {
   if(c==0) {
    STA_ACT_LIGHT_CopyActorPos(scene,obj,(u32 *)(&pos));
    delta.x=d;delta.y=e;delta.z=f;
    VEC_Add(&pos,&delta,&pos);
    STA_ACT_LIGHT_CopyElemA(ctx,target,(const u32 *)(&pos));
   } else {
    STA_ACTING_GetBoard(((struct ScriptOwner *)owner)->scene);
    q=GFL_HEAP_Alloc(((struct ScriptOwner *)owner)->heapId,0x30,0,d_021FDD00,0x74D);
    *(char * *)&((struct ScriptCharFollowTask *)q)->owner=owner;
    ((struct ScriptCharFollowTask *)q)->index=i;
    ((struct ScriptCharFollowTask *)q)->target=target;
    ((struct ScriptCharFollowTask *)q)->step.scene=((struct ScriptOwner *)owner)->scene;
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
int SCRIPT_COMMAND_CmdSetCharColor(int unused,char **p)
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
    r=STA_ACTING_GetCharSystem(((struct ScriptOwner *)q)->scene);
    s=STA_ACTING_GetCharSlot(((struct ScriptOwner *)q)->scene,v);
    STA_ACT_LIGHT_SetElemA(r,s,(u8)w|((u8)x<<5)|((u8)y<<10),z);
    return 0;
}

int SCRIPT_COMMAND_CmdPrintText(int unused,char *p) { char *o; u32 a,b; o=*(char * *)&((struct ScriptCtx *)p)->system; a=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->vm); b=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->vm); STA_ACTING_PrintText(*(u8 * *)&((struct ScriptOwner *)o)->scene,a,b); return 0; }

int SCRIPT_COMMAND_CmdClearText(void *unused, void **ctx)
{
    STA_ACTING_ClearText(((struct ScriptOwner *)((u8 *)*ctx))->scene);
    return 0;
}

int SCRIPT_COMMAND_CmdSetTextColor(int unused,char *p) { u32 a,b,c; a=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->vm); b=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->vm); c=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->vm); GF_FONT_SetTextColor((u8)a,(u8)b,(u8)c); return 0; }

int SCRIPT_COMMAND_CmdInstallBgm(int unused, char **ctx)
{
    char *p = *ctx;
    int x = VM_GetU32((struct Cursor *)(((struct ScriptCtx *)ctx)->vm.s));

    STA_ACTING_InstallBgm(((struct ScriptOwner *)p)->scene, (unsigned short)x);
    return 0;
}

int SCRIPT_COMMAND_CmdStartSeq(int unused, char **ctx)
{
    char *p = *ctx;
    int x = VM_GetU32((struct Cursor *)(((struct ScriptCtx *)ctx)->vm.s));

    STA_ACTING_StartSeq(((struct ScriptOwner *)p)->scene, (unsigned short)x);
    return 0;
}

int SCRIPT_COMMAND_CmdStopSeq(int unused, char **ctx)
{
    STA_ACTING_StopSeq(((struct ScriptOwner *)(*ctx))->scene);
    return 0;
}

int SCRIPT_COMMAND_CmdReplaceWave(int unused,char *p) { char *o; u32 a,b,c; o=*(char * *)&((struct ScriptCtx *)p)->system; a=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->vm); b=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->vm); c=VM_GetU32(*(struct Cursor * *)&((struct ScriptCtx *)p)->vm); STA_ACTING_ReplaceWaveData(*(char * *)&((struct ScriptOwner *)o)->scene,(u16)a,(u16)b,(u16)c); return 0; }

int SCRIPT_COMMAND_CmdPlayBgm(int unused, char **ctx)
{
    char *p = *ctx;
    int x = VM_GetU32((struct Cursor *)(((struct ScriptCtx *)ctx)->vm.s));

    STA_ACTING_PlayBgm(((struct ScriptOwner *)p)->scene, x);
    return 0;
}

int SCRIPT_COMMAND_CmdStopBgm(int unused, char **ctx)
{
    STA_ACTING_StopBgm(((struct ScriptOwner *)(*ctx))->scene);
    return 0;
}
