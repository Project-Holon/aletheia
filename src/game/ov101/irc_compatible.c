/*
 * file:     irc_compatible.c
 * unit:     yes
 * function: IRC_COMPATIBLE_ProcInit, IRC_COMPATIBLE_ProcExit, IRC_COMPATIBLE_ProcMain, IRC_COMPATIBLE_SetHandler, IRC_COMPATIBLE_SetFinished, IRC_COMPATIBLE_HandleEntry, IRC_COMPATIBLE_HandleQuit, IRC_COMPATIBLE_HandleMenu, IRC_COMPATIBLE_HandleTests, IRC_COMPATIBLE_HandleHelp, IRC_COMPATIBLE_StepRunnerInit, IRC_COMPATIBLE_StepRunnerIsBusy, IRC_COMPATIBLE_StepRunnerExit, IRC_COMPATIBLE_StepRunnerRun, IRC_COMPATIBLE_MenuStepCreateArgs, IRC_COMPATIBLE_SecondTestCreateArgs, IRC_COMPATIBLE_FirstTestCreateArgs, IRC_COMPATIBLE_FirstTestDestroyArgs, IRC_COMPATIBLE_ResultStepCreateArgs, IRC_COMPATIBLE_ResultStepDestroyArgs, IRC_COMPATIBLE_HelpStepCreateArgs, IRC_COMPATIBLE_HelpStepDestroyArgs, IRC_COMPATIBLE_CalcCompatibility, IRC_COMPATIBLE_CalcNameSimilarity, IRC_COMPATIBLE_FindHighestSetBit, IRC_COMPATIBLE_CalcBirthdayScore
 * address:  0x021B6938
 * region:   ov101
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from compatible_irc_sys.c at 0x021B6938 (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GFL_NET_IsParentAid 0x0203D378 arm
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   GFL_USE_SetBgmPaused 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   IRC_COMPATIBLE_SourceFileName 0x021B753C data a1
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   PROCSYS_Create 0x02031324 arm
 *   PROCSYS_Delete 0x0203133C arm
 *   IRC_COMPATIBLE_StepTable 0x021B74B8 data a4
 *   PROCSYS_Push 0x02031348 arm
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   IRC_RANKING_GetFromSave 0x0200A8A0 thumb
 *   MYSTATUS_GetId 0x02008530 thumb
 *   IRC_RANKING_HasEntry 0x0200A9D4 thumb
 *   MYSTATUS_GetName 0x020084F4 thumb
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   IRC_RANKING_GetDateScore 0x0200AA00 thumb
 *   COMPATIBLE_IRC_SYS_Create 0x021B6100 thumb ov101
 *   COMPATIBLE_IRC_SYS_Delete 0x021B6148 thumb ov101
 *   COMPATIBLE_IRC_SYS_BuildProfile 0x021B658C thumb ov101
 *   PROCSYS_Main  0x02031330  arm  arm9
 */
struct Proc;
struct GameSystem;
struct StepRunnerQueue;
#include "compatible_irc_sys_types.h"

#define IRC_COMPATIBLE_HEAP_ID 58

/* Index of each screen step in the step table IRC_COMPATIBLE_StepTable. */
enum {
    IRC_STEP_MENU = 0,
    IRC_STEP_SECOND_TEST = 1,
    IRC_STEP_FIRST_TEST = 2,
    IRC_STEP_RESULT = 3,
    IRC_STEP_HELP = 4
};

/* Parameter block from the caller; only the first word is read. */
typedef struct IrcCompatibleParam {
    struct GameSystem *gameSystem;
} IrcCompatibleParam;

/* Runs one screen step at a time: create args, run the task, destroy args. */
typedef struct IrcStepRunner {
    struct StepRunnerQueue *queue;
    int phase;
    void *stepArgs;
} IrcStepRunner;

struct IrcCompatibleWork;

typedef void (*IrcHandler)(struct IrcCompatibleWork *work, u16 *state);

typedef struct IrcCompatibleWork {
    IrcSys *view;
    IrcStepRunner runner;
    IrcCompatibleParam *param;
    IrcHandler handler;
    u16 handlerState;
    u8 pad1A[2];
    u32 isFinished;
    int menuChoice;                       /* 0 run the tests, 1 help, 2 quit */
    int secondTestResult;
    int firstTestResult;
    u8 firstTestScore;
    u8 firstTestPenalty;
    u8 secondTestScore;
    u8 secondTestPenalty;
    int secondTestBonus;
    int isFirstRun;
    u32 hasReturnedFromHelp;
    IrcCompatibleProfile *partnerProfile;
} IrcCompatibleWork;

typedef struct IrcStepEntry {
    int taskProc;
    int priority;
    void *(*createArgs)(u32 heapId, IrcCompatibleWork *work);
    void (*destroyArgs)(void *args, IrcCompatibleWork *work);
} IrcStepEntry;

struct DateBytes { unsigned year, month, day, weekday; };

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int align, const char *file, u16 line);
extern void MI_CpuFill8(void *dst, int value, u32 size);
extern u32 GFL_HEAP_Free(void *mem);
extern u32 GFL_NET_IsParentAid(void);
extern void *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
extern void *PROCSYS_AllocProcWork(struct Proc *proc, u32 size, u32 heapId);
extern void GFL_USE_SetBgmPaused(void *p);
extern int GFL_USE_PushBgm(void);
extern int GFL_USE_PopBgm(void);
extern void PROCSYS_FreeProcWork(struct Proc *proc);
extern void GFL_HEAP_DeleteChecked(u32 heapId);
extern int GFL_USE_IsBgmFading(void);
extern void *PROCSYS_Create(int heapId);
extern unsigned int PROCSYS_Main(void *queue);
extern void PROCSYS_Delete(void *queue);
extern void PROCSYS_Push(void *queue, int taskProc, int priority, void *args);
extern void *GAME_DATA_GetSaveControl(void *gameData);
extern void *IRC_RANKING_GetFromSave(void *saveBlock);
extern u32 MYSTATUS_GetId(const u8 *myStatus);
extern int IRC_RANKING_HasEntry(void *saveBlock, u32 nameKey);
extern u16 *MYSTATUS_GetName(void *myStatus);
extern u16 STRBUF_GetEosChar(void);
extern unsigned char IRC_RANKING_GetDateScore(unsigned month, unsigned day, struct DateBytes *date);
void *COMPATIBLE_IRC_SYS_Create(int context,int playerRecords,int heapId,int offline);
void COMPATIBLE_IRC_SYS_Delete(void *view);
void COMPATIBLE_IRC_SYS_BuildProfile(void *gameSystem, IrcCompatibleProfile *out);
int IRC_COMPATIBLE_ProcInit(struct Proc *proc, int seq, IrcCompatibleParam *param);
int IRC_COMPATIBLE_ProcExit(struct Proc *proc, int seq, int pwk, IrcCompatibleWork *work);
int IRC_COMPATIBLE_ProcMain(void *proc, u32 *seq, void *pwk, IrcCompatibleWork *work);
void IRC_COMPATIBLE_SetHandler(IrcCompatibleWork *work, IrcHandler handler);
void IRC_COMPATIBLE_SetFinished(IrcCompatibleWork *work);
void IRC_COMPATIBLE_HandleEntry(IrcCompatibleWork *work, u16 *state);
void IRC_COMPATIBLE_HandleQuit(IrcCompatibleWork *work, u16 *state);
void IRC_COMPATIBLE_HandleMenu(IrcCompatibleWork *work, u16 *state);
void IRC_COMPATIBLE_HandleTests(IrcCompatibleWork *work, u16 *state);
void IRC_COMPATIBLE_HandleHelp(IrcCompatibleWork *work, u16 *state);
void IRC_COMPATIBLE_StepRunnerInit(IrcStepRunner *runner, int heapId);
unsigned int IRC_COMPATIBLE_StepRunnerIsBusy(IrcStepRunner *runner);
void IRC_COMPATIBLE_StepRunnerExit(IrcStepRunner *runner);
int IRC_COMPATIBLE_StepRunnerRun(IrcStepRunner *runner, int stepIndex, int heapId, IrcCompatibleWork *work);
void *IRC_COMPATIBLE_MenuStepCreateArgs(u32 heapId, IrcCompatibleWork *work);
void IRC_COMPATIBLE_MenuStepDestroyArgs(void *args, IrcCompatibleWork *work);
void *IRC_COMPATIBLE_SecondTestCreateArgs(u32 heapId, IrcCompatibleWork *work);
void IRC_COMPATIBLE_SecondTestDestroyArgs(void *args, IrcCompatibleWork *work);
void *IRC_COMPATIBLE_FirstTestCreateArgs(u32 heapId, IrcCompatibleWork *work);
void IRC_COMPATIBLE_FirstTestDestroyArgs(void *args, IrcCompatibleWork *work);
void *IRC_COMPATIBLE_ResultStepCreateArgs(u32 heapId, IrcCompatibleWork *work);
void IRC_COMPATIBLE_ResultStepDestroyArgs(void *args, IrcCompatibleWork *work);
void *IRC_COMPATIBLE_HelpStepCreateArgs(u32 heapId, IrcCompatibleWork *work);
void IRC_COMPATIBLE_HelpStepDestroyArgs(void *args, IrcCompatibleWork *work);
int IRC_COMPATIBLE_CalcCompatibility(u32 firstScore, u32 secondScore, int firstPenalty, int secondPenalty, IrcCompatibleProfile *ownProfile, IrcCompatibleProfile *partnerProfile, int hasBonus, u32 packedDate, int heapId);
u32 IRC_COMPATIBLE_CalcNameSimilarity(u16 *nameA, u16 *nameB);
unsigned IRC_COMPATIBLE_FindHighestSetBit(unsigned bits, unsigned width);
unsigned char IRC_COMPATIBLE_CalcBirthdayScore(IrcCompatibleProfile *profile, unsigned packedDate);
extern const char IRC_COMPATIBLE_SourceFileName[];
extern const IrcStepEntry IRC_COMPATIBLE_StepTable[];









int IRC_COMPATIBLE_ProcInit(struct Proc *proc, int seq, IrcCompatibleParam *param)
{
    IrcCompatibleWork *work;
    int gameData;
    GFL_HEAP_CreateChildHeap(1, IRC_COMPATIBLE_HEAP_ID, 0x8000);
    work = PROCSYS_AllocProcWork(proc, 64, IRC_COMPATIBLE_HEAP_ID);
    MI_CpuFill8(work, 0, 64);
    gameData = 0;
    work->param = param;
    work->partnerProfile = GFL_HEAP_Alloc(IRC_COMPATIBLE_HEAP_ID, 44, 0, IRC_COMPATIBLE_SourceFileName, 0x119);
    MI_CpuFill8(work->partnerProfile, 0, 44);
    IRC_COMPATIBLE_StepRunnerInit(&work->runner, IRC_COMPATIBLE_HEAP_ID);
    if (work->param->gameSystem) gameData = (int)GAMESYSTEM_GetGameData(work->param->gameSystem);
    work->view = COMPATIBLE_IRC_SYS_Create(-1, gameData, IRC_COMPATIBLE_HEAP_ID, 0);
    work->isFirstRun = 1;
    IRC_COMPATIBLE_SetHandler(work, IRC_COMPATIBLE_HandleEntry);
    GFL_USE_SetBgmPaused((void *)1);
    GFL_USE_PushBgm();
    return 1;
}









int IRC_COMPATIBLE_ProcExit(struct Proc *proc, int seq, int pwk, IrcCompatibleWork *work) {
 GFL_USE_PopBgm(); GFL_USE_SetBgmPaused(0); COMPATIBLE_IRC_SYS_Delete(work->view); IRC_COMPATIBLE_StepRunnerExit(&work->runner); GFL_HEAP_Free(work->partnerProfile); PROCSYS_FreeProcWork(proc); GFL_HEAP_DeleteChecked(IRC_COMPATIBLE_HEAP_ID); return 1;
}









int IRC_COMPATIBLE_ProcMain(void *proc, u32 *seq, void *pwk, IrcCompatibleWork *work) {
    switch (*seq) {
    case 0:
        if (!GFL_USE_IsBgmFading()) *seq += 1;
        break;
    case 1:
        if (IRC_COMPATIBLE_StepRunnerIsBusy(&work->runner) == 0)
            work->handler(work, &work->handlerState);
        if (work->isFinished) return 1;
        break;
    }
    return 0;
}










void IRC_COMPATIBLE_SetHandler(IrcCompatibleWork *work, IrcHandler handler) { work->handler = handler; work->handlerState = 0; }










void IRC_COMPATIBLE_SetFinished(IrcCompatibleWork *work) { work->isFinished = 1; }









void IRC_COMPATIBLE_HandleEntry(IrcCompatibleWork *work, u16 *state) { if(*state==0) IRC_COMPATIBLE_SetHandler(work, IRC_COMPATIBLE_HandleMenu); }









void IRC_COMPATIBLE_HandleQuit(IrcCompatibleWork *work, u16 *state) { switch(*state) { case 0: *state=1; break; case 1: IRC_COMPATIBLE_SetFinished(work); break; } }









void IRC_COMPATIBLE_HandleMenu(IrcCompatibleWork *work, u16 *state)
{
    switch(*state) {
    case 0:
        if(IRC_COMPATIBLE_StepRunnerRun(&work->runner, IRC_STEP_MENU, IRC_COMPATIBLE_HEAP_ID, work)) *state=1;
        break;
    case 1:
        switch(work->menuChoice) {
        case 0: IRC_COMPATIBLE_SetHandler(work, IRC_COMPATIBLE_HandleTests); break;
        case 1: IRC_COMPATIBLE_SetHandler(work, IRC_COMPATIBLE_HandleHelp); break;
        case 2: IRC_COMPATIBLE_SetHandler(work, IRC_COMPATIBLE_HandleQuit); break;
        }
        break;
    }
}








void IRC_COMPATIBLE_HandleTests(IrcCompatibleWork *work, u16 *state)
{
    switch(*state) {
    case 0:
        work->secondTestScore=0;
        work->firstTestScore=0;
        *state=1;
        break;
    case 1:
        if(IRC_COMPATIBLE_StepRunnerRun(&work->runner, IRC_STEP_FIRST_TEST, IRC_COMPATIBLE_HEAP_ID, work)) *state=2;
        break;
    case 2:
        if(work->firstTestResult==0) *state=3;
        else if(work->firstTestResult==2) {
            work->secondTestScore=0;
            work->firstTestScore=0;
            *state=5;
        } else *state=6;
        break;
    case 3:
        if(IRC_COMPATIBLE_StepRunnerRun(&work->runner, IRC_STEP_SECOND_TEST, IRC_COMPATIBLE_HEAP_ID, work)) *state=4;
        break;
    case 4:
        if(work->secondTestResult==0) *state=5;
        else if(work->secondTestResult==2) {
            work->secondTestScore=0;
            work->firstTestScore=0;
            *state=5;
        } else *state=6;
        break;
    case 5:
        if(IRC_COMPATIBLE_StepRunnerRun(&work->runner, IRC_STEP_RESULT, IRC_COMPATIBLE_HEAP_ID, work)) *state=6;
        break;
    case 6:
        IRC_COMPATIBLE_SetHandler(work, IRC_COMPATIBLE_HandleMenu);
        break;
    }
}








void IRC_COMPATIBLE_HandleHelp(IrcCompatibleWork *work, u16 *state) { switch(*state) { case 0: *state=1; break; case 1: if(IRC_COMPATIBLE_StepRunnerRun(&work->runner, IRC_STEP_HELP, IRC_COMPATIBLE_HEAP_ID, work)) *state=2; break; case 2: IRC_COMPATIBLE_SetHandler(work, IRC_COMPATIBLE_HandleMenu); break; } }








void IRC_COMPATIBLE_StepRunnerInit(IrcStepRunner *runner, int heapId) { MI_CpuFill8(runner, 0, 12); runner->queue=PROCSYS_Create(heapId); }








unsigned int IRC_COMPATIBLE_StepRunnerIsBusy(IrcStepRunner *runner) { return PROCSYS_Main(runner->queue); }







void IRC_COMPATIBLE_StepRunnerExit(IrcStepRunner *runner) { PROCSYS_Delete(runner->queue); MI_CpuFill8(runner, 0, 12); }







int IRC_COMPATIBLE_StepRunnerRun(IrcStepRunner *runner, int stepIndex, int heapId, IrcCompatibleWork *work)
{
    void *result;
    switch(runner->phase) {
    case 0:
        if(IRC_COMPATIBLE_StepTable[stepIndex].createArgs) result=IRC_COMPATIBLE_StepTable[stepIndex].createArgs(heapId, work);
        else result=0;
        runner->stepArgs=result;
        runner->phase=1;
        break;
    case 1:
        PROCSYS_Push(runner->queue,IRC_COMPATIBLE_StepTable[stepIndex].taskProc,IRC_COMPATIBLE_StepTable[stepIndex].priority,runner->stepArgs);
        runner->phase=2;
        break;
    case 2:
        if(IRC_COMPATIBLE_StepTable[stepIndex].destroyArgs) IRC_COMPATIBLE_StepTable[stepIndex].destroyArgs(runner->stepArgs,work);
        runner->phase=3;
        break;
    case 3:
        runner->phase=0;
        return 1;
    }
    return 0;
}






/*
 * GFL_HEAP_Alloc 0x02030734 arm
 * GFL_HEAP_Free 0x020307B0 arm
 * MI_CpuFill8 0x02082BCC arm
 * IRC_COMPATIBLE_SourceFileName 0x021B753C data a1
 */
void *IRC_COMPATIBLE_MenuStepCreateArgs(u32 heapId, IrcCompatibleWork *work) {
 IrcMenuArgs *args;
 args=GFL_HEAP_Alloc(heapId,0x14,0,IRC_COMPATIBLE_SourceFileName,0x36e);
 MI_CpuFill8(args,0,0x14);
 args->gameSystem=work->param->gameSystem;
 args->view=work->view;
 args->profile=work->partnerProfile;
 if(work->isFirstRun==1) {
  args->mode=0;
  work->isFirstRun=0;
 } else {
  if(work->hasReturnedFromHelp!=0) {
   work->hasReturnedFromHelp=0;
   args->mode=2;
  } else args->mode=1;
 }
 return args;
}






void IRC_COMPATIBLE_MenuStepDestroyArgs(void *args, IrcCompatibleWork *work) {
 work->menuChoice=((IrcMenuArgs *)args)->choice;
 GFL_HEAP_Free(args);
}






void *IRC_COMPATIBLE_SecondTestCreateArgs(u32 heapId, IrcCompatibleWork *work) {
 IrcSecondTestArgs *args;
 args=GFL_HEAP_Alloc(heapId,0x14,0,IRC_COMPATIBLE_SourceFileName,0x3af);
 MI_CpuFill8(args,0,0x14);
 args->gameSystem=work->param->gameSystem;
 args->view=work->view;
 args->profile=work->partnerProfile;
 return args;
}






void IRC_COMPATIBLE_SecondTestDestroyArgs(void *args, IrcCompatibleWork *work) {
 work->secondTestResult=((IrcSecondTestArgs *)args)->result;
 work->secondTestScore=((IrcSecondTestArgs *)args)->score;
 work->secondTestPenalty=((IrcSecondTestArgs *)args)->penalty;
 work->secondTestBonus=((IrcSecondTestArgs *)args)->bonus;
 GFL_HEAP_Free(args);
}




void *IRC_COMPATIBLE_FirstTestCreateArgs(u32 heapId, IrcCompatibleWork *work) {
 IrcFirstTestArgs *args;
 args=GFL_HEAP_Alloc(heapId,0x18,0,IRC_COMPATIBLE_SourceFileName,0x3e4);
 MI_CpuFill8(args,0,0x18);
 args->gameSystem=work->param->gameSystem;
 args->view=work->view;
 args->profile=work->partnerProfile;
 return args;
}




void IRC_COMPATIBLE_FirstTestDestroyArgs(void *args, IrcCompatibleWork *work) {
 work->firstTestResult=((IrcFirstTestArgs *)args)->result;
 work->firstTestScore=((IrcFirstTestArgs *)args)->score;
 work->firstTestPenalty=((IrcFirstTestArgs *)args)->penalty;
 GFL_HEAP_Free(args);
}


/*
 * lever: reversed flag/both declarations preserve saved-register allocation.
 * trailing: 6E84..6E8C is Thumb free veneer; odd callback at 74F4 is code-start proof.
 * prototype: 6ECC reads eight arguments, but original caller explicitly supplies ninth 58; preserve it.
 * GFL_HEAP_Alloc 0x02030734 arm
 * GFL_HEAP_Free 0x020307B0 arm
 * MI_CpuFill8 0x02082BCC arm
 * GAMESYSTEM_GetGameData 0x020120F4 thumb
 * GAME_DATA_GetSaveControl 0x02012EBC thumb
 * IRC_RANKING_GetFromSave 0x0200A8A0 thumb
 * MYSTATUS_GetId 0x02008530 thumb
 * IRC_RANKING_HasEntry 0x0200A9D4 thumb
 * COMPATIBLE_IRC_SYS_BuildProfile 0x021B658C thumb ov101
 * GFL_NET_IsParentAid 0x0203D378 arm
 * IRC_COMPATIBLE_CalcCompatibility 0x021B6ECC thumb ov101
 * IRC_COMPATIBLE_SourceFileName 0x021B753C data a1
 */
void *IRC_COMPATIBLE_ResultStepCreateArgs(u32 heapId, IrcCompatibleWork *work)
{
    IrcCompatibleProfile ownProfile;
    void *saveBlock;
    IrcResultArgs *args;
    u8 *partnerName;
    int useBonus,isNewPartner=0;
    u32 packedDate;
    args=GFL_HEAP_Alloc(heapId,16,0,IRC_COMPATIBLE_SourceFileName,0x418);
    MI_CpuFill8(args,0,16);
    args->gameSystem=work->param->gameSystem;
    args->view=work->view;
    args->profile=work->partnerProfile;
    if(work->firstTestScore && work->secondTestScore) {
        partnerName=work->partnerProfile->myStatus;
        /* the first call below discards its result; kept as in the original code */
        GAMESYSTEM_GetGameData(work->param->gameSystem);
        saveBlock=IRC_RANKING_GetFromSave(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(work->param->gameSystem)));
        if(IRC_RANKING_HasEntry(saveBlock,MYSTATUS_GetId(partnerName))==0) isNewPartner=1;
        useBonus=0;
        if(work->secondTestBonus && isNewPartner) useBonus=1;
        COMPATIBLE_IRC_SYS_BuildProfile(work->param->gameSystem,&ownProfile);
        if(GFL_NET_IsParentAid()) packedDate=ownProfile.packedDate;
        else packedDate=work->partnerProfile->packedDate;
        args->compatibility=IRC_COMPATIBLE_CalcCompatibility(work->firstTestScore,work->secondTestScore,work->firstTestPenalty,work->secondTestPenalty,&ownProfile,work->partnerProfile,useBonus,packedDate,IRC_COMPATIBLE_HEAP_ID);
    }
    return args;
}


void IRC_COMPATIBLE_ResultStepDestroyArgs(void *args, IrcCompatibleWork *work)
{
    GFL_HEAP_Free(args);
}



void *IRC_COMPATIBLE_HelpStepCreateArgs(u32 heapId, IrcCompatibleWork *work) { IrcHelpArgs *args; args=GFL_HEAP_Alloc(heapId,4,0,IRC_COMPATIBLE_SourceFileName,0x49b); MI_CpuFill8(args,0,4); args->gameSystem=work->param->gameSystem; return args; }



void IRC_COMPATIBLE_HelpStepDestroyArgs(void *args, IrcCompatibleWork *work) { GFL_HEAP_Free(args); work->hasReturnedFromHelp=1; }



int IRC_COMPATIBLE_CalcCompatibility(u32 firstScore, u32 secondScore, int firstPenalty, int secondPenalty, IrcCompatibleProfile *ownProfile, IrcCompatibleProfile *partnerProfile, int hasBonus, u32 packedDate, int heapId)
{
    int baseScore, nameRate, compatibility;
    u32 nameSimilarity;
    u16 *ownName;
    float rateFixed;
    baseScore = ((((u32)IRC_COMPATIBLE_CalcBirthdayScore(ownProfile, packedDate) + (u32)IRC_COMPATIBLE_CalcBirthdayScore(partnerProfile, packedDate)) >> 1) * 10) / 100;
    firstScore = firstScore * 50 / 100;
    secondScore = secondScore * 40 / 100;
    baseScore += firstScore + secondScore;
    ownName = MYSTATUS_GetName(ownProfile->myStatus);
    nameSimilarity = IRC_COMPATIBLE_CalcNameSimilarity(ownName, MYSTATUS_GetName(partnerProfile->myStatus));
    if (nameSimilarity) rateFixed = 0.5f + (float)(nameSimilarity << 12);
    else rateFixed = (float)(nameSimilarity << 12) - 0.5f;
    nameRate = (int)rateFixed / 150;
    if (hasBonus) nameRate = 0xccd;
    else {
        if (nameRate > 0x1000) nameRate = 0x1000;
        else if (nameRate < 0x800) nameRate = 0x800;
    }
    compatibility = baseScore + (((100 - baseScore) * nameRate) >> 12) - (secondPenalty + firstPenalty);
    if (compatibility > 100) return 100;
    if (compatibility < 0) compatibility = 0;
    return compatibility;
}



/*
 * lever: equal declared before count fixes the two spilled counter slots; literal double assignments reproduce the lower-bound stores.
 * note 2026-10-05 (wave D9r lane 131): removed the 2 dead first assignments
 * (`lower1 = 0x30f4;` before `lower1 = 0x30a1;`; `lower2 = 0x30f4;` before
 * `lower2 = 0x30a1;`). Game code has no line table, so these were stand-ins.
 * The plain single assignment gives EXACT in --lang c99 and --lang c: the
 * output bytes do not change. Older text in this header that asks for the
 * double assignment is superseded.
 */
u32 IRC_COMPATIBLE_CalcNameSimilarity(u16 *nameA, u16 *nameB)
{
    u32 charA, charB, bitIndexA, bitIndexB;
    u32 equalBits, totalBits, katakanaStartA, katakanaStartB;
    charA = *nameA;
    charB = *nameB;
    if (charA >= 0x30a1 && charA <= 0x30f4) charA -= 0x60;
    if (charB >= 0x30a1 && charB <= 0x30f4) charB -= 0x60;
    bitIndexA = IRC_COMPATIBLE_FindHighestSetBit(charA, 8);
    bitIndexB = IRC_COMPATIBLE_FindHighestSetBit(charB, 8);
    totalBits = 0;
    equalBits = 0;
    katakanaStartA = 0x30a1;
    katakanaStartB = 0x30a1;
    for (;;) {
        if (bitIndexA == 0) {
            charA = *++nameA;
            if (charA == STRBUF_GetEosChar()) break;
            if (charA >= katakanaStartA && charA <= 0x30f4) charA -= 0x60;
            bitIndexA = IRC_COMPATIBLE_FindHighestSetBit(charA, 8);
        }
        if (bitIndexB == 0) {
            charB = *++nameB;
            if (charB == STRBUF_GetEosChar()) break;
            if (charB >= katakanaStartB && charB <= 0x30f4) charB -= 0x60;
            bitIndexB = IRC_COMPATIBLE_FindHighestSetBit(charB, 8);
        }
        if (bitIndexA == 0 || bitIndexB == 0) continue;
        if (((charA >> bitIndexA) & 1) == ((charB >> bitIndexB) & 1)) ++equalBits;
        ++totalBits;
        --bitIndexA;
        --bitIndexB;
    }
    return equalBits * 100 / totalBits;
}



unsigned IRC_COMPATIBLE_FindHighestSetBit(unsigned bits, unsigned width) { unsigned bitIndex = width - 1; while (bitIndex) { if ((bits >> bitIndex) & 1) break; bitIndex--; } return bitIndex; }



unsigned char IRC_COMPATIBLE_CalcBirthdayScore(IrcCompatibleProfile *profile, unsigned packedDate) { struct DateBytes date; date.year=(unsigned char)(packedDate>>24); date.month=(unsigned char)(packedDate>>16); date.day=(unsigned char)(packedDate>>8); date.weekday=(unsigned char)packedDate; return IRC_RANKING_GetDateScore(profile->birthMonth,profile->birthDay,&date); }
