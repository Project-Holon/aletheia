/*
 * file:     sta_act_script.c
 * unit:     yes
 * function: STA_ACT_SCRIPT_Create, STA_ACT_SCRIPT_Delete, STA_ACT_SCRIPT_Update, STA_ACT_SCRIPT_AddScript, STA_ACT_SCRIPT_AddScriptFromTable, STA_ACT_SCRIPT_RunScript, STA_ACT_SCRIPT_CountScripts, STA_ACT_SCRIPT_AddTask, STA_ACT_SCRIPT_RemoveTask, STA_ACT_SCRIPT_StepTaskInt, STA_ACT_SCRIPT_StepTaskVec, STA_ACT_SCRIPT_StepTaskActor, STA_ACT_SCRIPT_TickSlot, STA_ACT_SCRIPT_SetWaitFlag, STA_ACT_SCRIPT_SkipArg, STA_ACT_SCRIPT_SetWaitFromArg, STA_ACT_SCRIPT_SetRemainingWait, STA_ACT_SCRIPT_SetPendingFlag
 * address:  0x021FAAF4
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
 *   func_02030734 0x02030734 arm
 *   STA_ACT_SCRIPT_Create 0x021FAAF4 thumb ov132
 *   STA_ACT_SCRIPT_Delete 0x021FAB58 thumb ov132
 *   func_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 *   STA_ACT_SCRIPT_Update 0x021FABD8 thumb ov132
 *   STA_ACT_SCRIPT_CountScripts 0x021FAD7C thumb ov132
 *   STA_ACT_LIGHT_CopyActorPos 0x021F8044 thumb ov112
 *   STA_ACT_SCRIPT_AddScript 0x021FAC74 thumb ov132
 *   STA_ACT_SCRIPT_AddScriptFromTable 0x021FAD0C thumb ov132
 *   STA_ACTING_GetActorSystem 0x021F9DA0 thumb ov132
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030CBC 0x02030CBC arm
 *   NNS_FndInitList 0x02060468 arm
 *   d_021FDCEC 0x021FDCEC data ov132 a4
 *   func_02011290 0x02011290 thumb
 *   VM_Delete 0x02011264 thumb
 *   NNS_FndGetNextListObject 0x02060614 arm
 *   TCB_Noop 0x02030DA4 arm
 *   TCB_Main 0x02030D28 arm
 *   VM_Create 0x0201121C thumb
 *   VM_Init 0x0201126C thumb
 *   VM_Start 0x0201127C thumb
 *   d_021FDC2C 0x021FDC2C data ov132 a4
 *   VM_Control 0x02011298 thumb
 *   func_02030DA8 0x02030DA8 arm
 *   NNS_FndAppendListObject 0x020604AC arm
 *   NNS_FndRemoveListObject 0x020605B4 arm
 *   VEC_MultAdd 0x0207CEE4 arm
 *   VEC_Add 0x0207C9D0 arm
 *   VM_GetU32 0x0201134C thumb
 *   STA_ACT_EFFECT_GetSceneOwner 0x021F9E44 thumb ov132
 */
#include "ov132_types.h"
#include "sta_acting_shared_types.h"
#include "sta_act_script_shared_types.h"

extern void func_02030EAC(struct Node *n);

extern void STA_ACT_LIGHT_CopyActorPos(void *unused, u32 *p, u32 *q);

struct ScriptVm;

struct DList;

struct ScriptVmParams;

extern void *func_02030734(unsigned, unsigned, int, const char *, u16);

extern u32 func_020307B0(void *p);

extern void *STA_ACTING_GetActorSystem(char *p);

extern u32 func_02030CB0(u32);

extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);

extern void NNS_FndInitList(int p0, int p1);

extern struct ScriptVm *func_02011290(struct ScriptVm *vm);

extern void VM_Delete(void *);

extern void *NNS_FndGetNextListObject(struct DList *list, void *elem);

extern void TCB_Noop(void *);

extern void TCB_Main(struct Ctx *c);

extern struct ScriptVm *VM_Create(u32 heapId, const struct ScriptVmParams *params);

extern void VM_Init(struct ScriptVm *vm, void *user);

extern void VM_Start(struct ScriptVm *vm, u8 *pc);

extern int VM_Control(struct ScriptVm *vm);

extern struct Node *func_02030DA8(struct Ctx *c, u32 a, u32 b, u32 key);

extern void NNS_FndAppendListObject(void *, void *);

extern void NNS_FndRemoveListObject(volatile struct DList *list, void *elem);

extern void VEC_MultAdd(int, void *, void *, void *);

extern void VEC_Add(const Vec *, const Vec *, Vec *);

extern u32 VM_GetU32(struct Cursor *p);

u32 STA_ACT_EFFECT_GetSceneOwner(u8 *p);

void *STA_ACT_SCRIPT_Create(u32 heap, void *owner);

void STA_ACT_SCRIPT_Delete(char *p);

void STA_ACT_SCRIPT_Update(char *p);

void *STA_ACT_SCRIPT_AddScript(char *p, void *arg, int flag);

char *STA_ACT_SCRIPT_AddScriptFromTable(char *p, char *base, unsigned index, unsigned char flag);

int STA_ACT_SCRIPT_RunScript(void *unused, char *p);

u8 STA_ACT_SCRIPT_CountScripts(char *p);

void *STA_ACT_SCRIPT_AddTask(char *p, u32 fn, u32 arg, u32 key);

void STA_ACT_SCRIPT_RemoveTask(char *p, char *q);

int STA_ACT_SCRIPT_StepTaskInt(char *p, int *out);

int STA_ACT_SCRIPT_StepTaskVec(char *p, int *out);

int STA_ACT_SCRIPT_StepTaskActor(char *p, void *out);

int STA_ACT_SCRIPT_TickSlot(char *p);

int STA_ACT_SCRIPT_SetWaitFlag(void *unused, char *p);

int STA_ACT_SCRIPT_SkipArg(void *a, char *p);

int STA_ACT_SCRIPT_SetWaitFromArg(void *a, u8 *p);

int STA_ACT_SCRIPT_SetRemainingWait(void *a, u8 *p);

int STA_ACT_SCRIPT_SetPendingFlag(int a, char *b);

extern char d_021FDCEC[];

extern char d_021FDC2C[];

void *STA_ACT_SCRIPT_Create(u32 heap, void *owner)
{
    u8 i;
    char *p;
    i = 0;
    p = func_02030734(heap, 0x44, 0, d_021FDCEC, 0x3f);
    ((struct ScriptSystem *)p)->f0 = heap;
    ((struct ScriptSystem *)p)->f34 = owner;
    ((struct ScriptSystem *)p)->f8 = func_02030734(((struct ScriptSystem *)p)->f0, func_02030CB0(16), 0, d_021FDCEC, 0x43);
    ((struct ScriptSystem *)p)->f4 = func_02030CBC(16, ((struct ScriptSystem *)p)->f8);
    NNS_FndInitList((int)(p + 0x38), 0);
    for (; i < 10; i++) *(void **)(p + 0xc + i * 4) = 0;
    return p;
}

void STA_ACT_SCRIPT_Delete(char *p)
{
    u8 i;
    char **slot;
    void *cur;
    void *next;
    for (i = 0; i < 10; i++) {
        slot = (char **)(p + i * 4);
        if (slot[3] != 0) {
            func_02011290(((struct ScriptEntry *)(slot[3]))->f4);
            VM_Delete(((struct ScriptEntry *)(slot[3]))->f4);
            if (((struct ScriptEntry *)(slot[3]))->f16 & 8) func_020307B0(((struct ScriptEntry *)(slot[3]))->fC);
            func_020307B0(slot[3]);
            slot[3] = 0;
        }
    }
    cur = NNS_FndGetNextListObject((struct DList *)(p + 0x38), 0);
    while (cur != 0) {
        next = NNS_FndGetNextListObject((struct DList *)(p + 0x38), cur);
        STA_ACT_SCRIPT_RemoveTask(p, cur);
        cur = next;
    }
    TCB_Noop(((struct ScriptSystem *)p)->f4);
    func_020307B0(((struct ScriptSystem *)p)->f8);
    func_020307B0(p);
}

/*
 * note: two bytes of zero padding follow the epilogue before 021FAC74.
 */
void STA_ACT_SCRIPT_Update(char *p)
{
    char **slot;
    u8 i;
    int ready;
    int count;
    ready = 1;
    count = STA_ACT_EFFECT_GetSceneOwner(((struct ScriptSystem *)p)->f34);
    while (count != 0) {
        for (i = 0; i < 10; i++) {
            slot = (char **)(p + i * 4);
            if (slot[3] != 0) {
                if (STA_ACT_SCRIPT_RunScript(p, slot[3]) == 1) {
                    func_020307B0(slot[3]);
                    slot[3] = 0;
                } else {
                    if ((((struct ScriptEntry *)(slot[3]))->f16 & 2) && !(((struct ScriptEntry *)(slot[3]))->f16 & 4)) ready = 0;
                }
            }
        }
        if (ready == 1) {
            for (i = 0; i < 10; i++) {
                char *q;
                q = *(char **)(p + 0xc + i * 4);
                if (q != 0 && (((struct ScriptEntry *)q)->f16 & 2) && (((struct ScriptEntry *)q)->f16 & 4)) ((struct ScriptEntry *)q)->f16 ^= 4;
            }
        }
        TCB_Main(((struct ScriptSystem *)p)->f4);
        count--;
    }
}

void *STA_ACT_SCRIPT_AddScript(char *p, void *arg, int flag)
{
    u8 i;
    for (i = 0; i < 10; i++) if (*(void **)(p + 0xc + i * 4) == 0) break;
    ((char **)(p + 0xc))[i] = func_02030734(((struct ScriptSystem *)p)->f0, 0x1c, 0, d_021FDCEC, 0xc4);
    ((struct ScriptEntry *)(((char **)(p + 0xc))[i]))->f8 = arg;
    ((struct ScriptEntry *)(((char **)(p + 0xc))[i]))->fC = 0;
    ((struct ScriptEntry *)(((char **)(p + 0xc))[i]))->f14 = 0;
    ((struct ScriptEntry *)(((char **)(p + 0xc))[i]))->f10 = 0;
    ((struct ScriptEntry *)(((char **)(p + 0xc))[i]))->f16 = 0;
    ((struct ScriptEntry *)(((char **)(p + 0xc))[i]))->f18 = 0;
    ((struct ScriptEntry *)(((char **)(p + 0xc))[i]))->f19 = i;
    if (flag == 1) ((struct ScriptEntry *)(((char **)(p + 0xc))[i]))->f16 |= 2;
    *(char **)((char **)(p + 0xc))[i] = p;
    ((struct ScriptEntry *)(((char **)(p + 0xc))[i]))->f4 = VM_Create(((struct ScriptSystem *)p)->f0, (const struct ScriptVmParams *)d_021FDC2C);
    VM_Init(((struct ScriptEntry *)(((char **)(p + 0xc))[i]))->f4, ((char **)(p + 0xc))[i]);
    VM_Start(((struct ScriptEntry *)(((char **)(p + 0xc))[i]))->f4, ((struct ScriptEntry *)(((char **)(p + 0xc))[i]))->f8);
    return ((char **)(p + 0xc))[i];
}

char *STA_ACT_SCRIPT_AddScriptFromTable(char *p, char *base, unsigned index, unsigned char flag)
{
    char *q = STA_ACT_SCRIPT_AddScript(p, base + *(unsigned *)(base + index * 4), 0);
    *(char * *)&((struct ScriptEntry *)q)->fC = base;
    ((struct ScriptEntry *)q)->f16 |= 8;
    ((struct ScriptEntry *)q)->f18 = flag;
    return q;
}

int STA_ACT_SCRIPT_RunScript(void *unused, char *p)
{
    if (((struct ScriptEntry *)p)->f14 != 0) (((struct ScriptEntry *)p)->f14)--;
    if (((struct ScriptEntry *)p)->f14 == 0 && !(((struct ScriptEntry *)p)->f16 & 4)) {
        VM_Control(((struct ScriptEntry *)p)->f4);
        if (((struct ScriptEntry *)p)->f16 & 1) {
            func_02011290(((struct ScriptEntry *)p)->f4);
            VM_Delete(((struct ScriptEntry *)p)->f4);
            if (((struct ScriptEntry *)p)->f16 & 8) func_020307B0(((struct ScriptEntry *)p)->fC);
            return 1;
        }
    }
    (((struct ScriptEntry *)p)->f10)++;
    return 0;
}

/*
 * note: unlabelled follower in 021FAD2C extent; counts ten nonnull slots.
 */
u8 STA_ACT_SCRIPT_CountScripts(char *p)
{
    u8 i;
    u8 count;
    count = 0;
    for (i = 0; i < 10; i++) if (*(void **)(p + 0xc + i * 4) != 0) count++;
    return count;
}

void *STA_ACT_SCRIPT_AddTask(char *p, u32 fn, u32 arg, u32 key)
{
    char *q;
    q = func_02030734(((struct ScriptSystem *)p)->f0, 16, 0, d_021FDCEC, 0x115);
    ((struct ScriptTaskNode *)q)->task = func_02030DA8(((struct ScriptSystem *)p)->f4, fn, arg, key);
    if (((struct ScriptTaskNode *)q)->task != 0) {
        ((struct ScriptTaskNode *)q)->arg = (void *)arg;
        NNS_FndAppendListObject(p + 0x38, q);
        return q;
    }
    func_020307B0(q);
    return 0;
}

void STA_ACT_SCRIPT_RemoveTask(char *p, char *q)
{
    func_020307B0(((struct ScriptTaskNode *)q)->arg);
    func_02030EAC(((struct ScriptTaskNode *)q)->task);
    NNS_FndRemoveListObject((volatile struct DList *)(p + 0x38), q);
    func_020307B0(q);
}

int STA_ACT_SCRIPT_StepTaskInt(char *p, int *out)
{
    int start;
    int delta;
    ((struct ScriptTask *)p)->fE += 1;
    if (((struct ScriptTask *)p)->fE >= ((struct ScriptTask *)p)->fC) {
        *out = ((struct ScriptTask *)p)->f8.s;
        return 1;
    }
    start = ((struct ScriptTask *)p)->f4.s;
    delta = ((struct ScriptTask *)p)->f8.s - start;
    *out = start + (delta * ((struct ScriptTask *)p)->fE) / ((struct ScriptTask *)p)->fC;
    return 0;
}

int STA_ACT_SCRIPT_StepTaskVec(char *p, int *out)
{
    int v;
    (((struct ScriptOwner *)p)->f2A)++;
    if (((struct ScriptOwner *)p)->f2A >= ((struct ScriptOwner *)p)->f28) {
        out[0] = ((struct ScriptOwner *)p)->f10;
        out[1] = ((struct ScriptOwner *)p)->f14;
        out[2] = ((struct ScriptOwner *)p)->f18;
        return 1;
    }
    if (((struct ScriptOwner *)p)->f2A != 0) v = (int)(0.5f + (float)(((struct ScriptOwner *)p)->f2A << 12));
    else v = (int)((float)(((struct ScriptOwner *)p)->f2A << 12) - 0.5f);
    VEC_MultAdd(v, p + 0x1c, p + 4, out);
    return 0;
}

/*
 * note: extent ends with two bytes of zero alignment padding.
 */
int STA_ACT_SCRIPT_StepTaskActor(char *p, void *out)
{
    int v[3];
    STA_ACT_LIGHT_CopyActorPos(STA_ACTING_GetActorSystem(((struct ScriptFollowStep *)p)->scene), (u32 *)(((struct ScriptFollowStep *)p)->actor), (u32 *)v);
    VEC_Add((const Vec *)v, (const Vec *)(p + 8), (Vec *)out);
    (((struct ScriptFollowStep *)p)->counter)++;
    if (((struct ScriptFollowStep *)p)->counter >= ((struct ScriptFollowStep *)p)->duration) return 1;
    return 0;
}

/*
 * follower: STA_ACT_SCRIPT_SetWaitFlag at 0x021FAF10
 */
int STA_ACT_SCRIPT_TickSlot(char *p)
{
    ((struct ScriptSlot *)p)->f4.u += 1;
    if (((struct ScriptSlot *)p)->f4.u >= ((struct ScriptSlot *)p)->f8.u) {
        ((struct ScriptSlot *)p)->fC -= 1;
        ((struct ScriptSlot *)p)->f4.u = 0;
        if (((struct ScriptSlot *)p)->fC == 0) return 2;
        return 1;
    }
    return 0;
}

int STA_ACT_SCRIPT_SetWaitFlag(void *unused, char *p)
{
    ((struct ScriptCtx *)p)->f16 = 1 | ((struct ScriptCtx *)p)->f16;
    return 1;
}

int STA_ACT_SCRIPT_SkipArg(void *a, char *p)
{
    VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    return 0;
}

/*
 * blocker resolved: VM_GetU32 was matched in arm9 (src/matched/
 * VM_GetU32.c, shard pkt_0201134C); the +0006 call now attests as
 * `matched`.  The symbols: line had it as `arm`; it is Thumb and now says so.
 *
 * Addresses are Black-image addresses.
 */
int STA_ACT_SCRIPT_SetWaitFromArg(void *a, u8 *p)
{
    ((struct ScriptCtx *)p)->f14 = (u16)VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    return 1;
}

/*
 * blocker resolved: VM_GetU32 was matched in arm9 (src/matched/
 * VM_GetU32.c, shard pkt_0201134C); the call now attests as `matched`.
 * The symbols: line had it as `arm`; it is Thumb and now says so.
 *
 * Addresses are Black-image addresses.
 */
int STA_ACT_SCRIPT_SetRemainingWait(void *a, u8 *p)
{
    int v = VM_GetU32(((struct ScriptCtx *)p)->f4.p);
    if (((struct ScriptCtx *)p)->f10 >= (u32)v)
        return 0;
    ((struct ScriptCtx *)p)->f14 = (u16)(v - ((struct ScriptCtx *)p)->f10);
    return 1;
}

int STA_ACT_SCRIPT_SetPendingFlag(int a, char *b)
{
    VM_GetU32(((struct ActingRecord *)b)->f4);
    if (((struct ActingRecord *)b)->f16 & 2)
        ((struct ActingRecord *)b)->f16 |= 4;
    return 1;
}
