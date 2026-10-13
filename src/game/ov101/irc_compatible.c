/*
 * file:     irc_compatible.c
 * unit:     yes
 * function: func_021B6938, func_021B69C4, func_021B69F8, func_021B6A3C, func_021B6A44, func_021B6A4C, func_021B6A60, func_021B6A7C, func_021B6AD8, func_021B6BA8, func_021B6BE4, func_021B6BFC, func_021B6C08, func_021B6C20, func_021B6CA0, func_021B6D04, func_021B6D5C, func_021B6D90, func_021B6DAC, func_021B6E84, func_021B6E8C, func_021B6EBC, func_021B6ECC, func_021B6F9C, func_021B7090, func_021B70A8
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
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0203D378 0x0203D378 arm
 *   func_020120F4 0x020120F4 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005E64 0x02005E64 thumb
 *   d_021B753C 0x021B753C data a1
 *   func_02005E9C 0x02005E9C thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02005E50 0x02005E50 thumb
 *   func_02031324 0x02031324 arm
 *   func_0203133C 0x0203133C arm
 *   d_021B74B8 0x021B74B8 data a4
 *   func_02031348 0x02031348 arm
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200A8A0 0x0200A8A0 thumb
 *   func_02008530 0x02008530 thumb
 *   func_0200A9D4 0x0200A9D4 thumb
 *   func_020084F4 0x020084F4 thumb
 *   func_02045A98 0x02045A98 arm
 *   func_0200AA00 0x0200AA00 thumb
 *   func_021B6100 0x021B6100 thumb ov101
 *   func_021B6148 0x021B6148 thumb ov101
 *   func_021B658C 0x021B658C thumb ov101
 */
struct Proc;
struct GameSystem;
struct StepRunnerQueue;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

#define IRC_COMPATIBLE_HEAP_ID 58

/* Index of each screen step in the step table d_021B74B8. */
enum {
    IRC_STEP_MENU = 0,
    IRC_STEP_SECOND_TEST = 1,
    IRC_STEP_FIRST_TEST = 2,
    IRC_STEP_RESULT = 3,
    IRC_STEP_HELP = 4
};

/* One player's data for the compatibility score (44 bytes, filled by func_021B658C). */
typedef struct IrcCompatibleProfile {
    u32 packedDate;          /* RTC date of the day: year, month, day, weekday, one byte each */
    u8 birthMonth;
    u8 birthDay;
    u16 leadSpecies;
    u8 leadType2;
    u8 leadType1;
    u8 leadNature;
    unsigned char isDay14:4; /* set when the day of the month is 14 */
    unsigned char reserved:4;
    u8 myStatus[32];         /* trainer status block; the name string is read from here */
} IrcCompatibleProfile;

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
    void *view;
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

typedef struct IrcMenuArgs {
    void *gameSystem;
    void *view;
    int mode;                /* 0 first entry, 1 normal, 2 back from help */
    int choice;              /* out */
    IrcCompatibleProfile *profile;
} IrcMenuArgs;

typedef struct IrcSecondTestArgs {
    void *gameSystem;
    void *view;
    IrcCompatibleProfile *profile;
    int result;              /* out */
    u8 score;                /* out */
    u8 penalty;              /* out */
    u8 bonus;                /* out */
    u8 pad13;
} IrcSecondTestArgs;

typedef struct IrcFirstTestArgs {
    void *gameSystem;
    void *view;
    IrcCompatibleProfile *profile;
    int result;              /* out */
    u8 score;                /* out */
    u8 pad11[3];
    int penalty;             /* out */
} IrcFirstTestArgs;

typedef struct IrcResultArgs {
    void *gameSystem;
    void *view;
    IrcCompatibleProfile *profile;
    u8 compatibility;
} IrcResultArgs;

typedef struct IrcHelpArgs {
    void *gameSystem;
} IrcHelpArgs;

struct DateBytes { unsigned year, month, day, weekday; };

extern void *func_02030734(u32 heapId, u32 size, int align, const char *file, u16 line);
extern void func_02082BCC(void *dst, int value, u32 size);
extern u32 func_020307B0(void *mem);
extern u32 func_0203D378(void);
extern void *func_020120F4(const struct GameSystem *gameSystem);
extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Proc *proc, u32 size, u32 heapId);
extern void func_02005DE4(void *p);
extern int func_02005E64(void);
extern int func_02005E9C(void);
extern void func_020315D4(struct Proc *proc);
extern void func_020306F0(u32 heapId);
extern int func_02005E50(void);
extern void *func_02031324(int heapId);
extern unsigned int func_02031330(void *queue);
extern void func_0203133C(void *queue);
extern void func_02031348(void *queue, int taskProc, int priority, void *args);
extern void *func_02012EBC(void *gameData);
extern void *func_0200A8A0(void *saveBlock);
extern u32 func_02008530(const u8 *myStatus);
extern int func_0200A9D4(void *saveBlock, u32 nameKey);
extern u16 *func_020084F4(void *myStatus);
extern u16 func_02045A98(void);
extern unsigned char func_0200AA00(unsigned month, unsigned day, struct DateBytes *date);
void *func_021B6100(int a,int b,int c,int d);
void func_021B6148(void *view);
void func_021B658C(void *gameSystem, IrcCompatibleProfile *out);
int func_021B6938(struct Proc *proc, int seq, IrcCompatibleParam *param);
int func_021B69C4(struct Proc *proc, int seq, int pwk, IrcCompatibleWork *work);
int func_021B69F8(void *proc, u32 *seq, void *pwk, IrcCompatibleWork *work);
void func_021B6A3C(IrcCompatibleWork *work, IrcHandler handler);
void func_021B6A44(IrcCompatibleWork *work);
void func_021B6A4C(IrcCompatibleWork *work, u16 *state);
void func_021B6A60(IrcCompatibleWork *work, u16 *state);
void func_021B6A7C(IrcCompatibleWork *work, u16 *state);
void func_021B6AD8(IrcCompatibleWork *work, u16 *state);
void func_021B6BA8(IrcCompatibleWork *work, u16 *state);
void func_021B6BE4(IrcStepRunner *runner, int heapId);
unsigned int func_021B6BFC(IrcStepRunner *runner);
void func_021B6C08(IrcStepRunner *runner);
int func_021B6C20(IrcStepRunner *runner, int stepIndex, int heapId, IrcCompatibleWork *work);
void *func_021B6CA0(u32 heapId, IrcCompatibleWork *work);
void func_021B6CF8(void *args, IrcCompatibleWork *work);
void *func_021B6D04(u32 heapId, IrcCompatibleWork *work);
void func_021B6D3C(void *args, IrcCompatibleWork *work);
void *func_021B6D5C(u32 heapId, IrcCompatibleWork *work);
void func_021B6D90(void *args, IrcCompatibleWork *work);
void *func_021B6DAC(u32 heapId, IrcCompatibleWork *work);
void func_021B6E84(void *args, IrcCompatibleWork *work);
void *func_021B6E8C(u32 heapId, IrcCompatibleWork *work);
void func_021B6EBC(void *args, IrcCompatibleWork *work);
int func_021B6ECC(u32 firstScore, u32 secondScore, int firstPenalty, int secondPenalty, IrcCompatibleProfile *ownProfile, IrcCompatibleProfile *partnerProfile, int hasBonus, u32 packedDate, int heapId);
u32 func_021B6F9C(u16 *nameA, u16 *nameB);
unsigned func_021B7090(unsigned bits, unsigned width);
unsigned char func_021B70A8(IrcCompatibleProfile *profile, unsigned packedDate);
extern const char d_021B753C[];
extern const IrcStepEntry d_021B74B8[];









int func_021B6938(struct Proc *proc, int seq, IrcCompatibleParam *param)
{
    IrcCompatibleWork *work;
    int gameData;
    func_0203064C(1, IRC_COMPATIBLE_HEAP_ID, 0x8000);
    work = func_0203159C(proc, 64, IRC_COMPATIBLE_HEAP_ID);
    func_02082BCC(work, 0, 64);
    gameData = 0;
    work->param = param;
    work->partnerProfile = func_02030734(IRC_COMPATIBLE_HEAP_ID, 44, 0, d_021B753C, 0x119);
    func_02082BCC(work->partnerProfile, 0, 44);
    func_021B6BE4(&work->runner, IRC_COMPATIBLE_HEAP_ID);
    if (work->param->gameSystem) gameData = (int)func_020120F4(work->param->gameSystem);
    work->view = func_021B6100(-1, gameData, IRC_COMPATIBLE_HEAP_ID, 0);
    work->isFirstRun = 1;
    func_021B6A3C(work, func_021B6A4C);
    func_02005DE4((void *)1);
    func_02005E64();
    return 1;
}









int func_021B69C4(struct Proc *proc, int seq, int pwk, IrcCompatibleWork *work) {
 func_02005E9C(); func_02005DE4(0); func_021B6148(work->view); func_021B6C08(&work->runner); func_020307B0(work->partnerProfile); func_020315D4(proc); func_020306F0(IRC_COMPATIBLE_HEAP_ID); return 1;
}









int func_021B69F8(void *proc, u32 *seq, void *pwk, IrcCompatibleWork *work) {
    switch (*seq) {
    case 0:
        if (!func_02005E50()) *seq += 1;
        break;
    case 1:
        if (func_021B6BFC(&work->runner) == 0)
            work->handler(work, &work->handlerState);
        if (work->isFinished) return 1;
        break;
    }
    return 0;
}










void func_021B6A3C(IrcCompatibleWork *work, IrcHandler handler) { work->handler = handler; work->handlerState = 0; }










void func_021B6A44(IrcCompatibleWork *work) { work->isFinished = 1; }









void func_021B6A4C(IrcCompatibleWork *work, u16 *state) { if(*state==0) func_021B6A3C(work, func_021B6A7C); }









void func_021B6A60(IrcCompatibleWork *work, u16 *state) { switch(*state) { case 0: *state=1; break; case 1: func_021B6A44(work); break; } }









void func_021B6A7C(IrcCompatibleWork *work, u16 *state)
{
    switch(*state) {
    case 0:
        if(func_021B6C20(&work->runner, IRC_STEP_MENU, IRC_COMPATIBLE_HEAP_ID, work)) *state=1;
        break;
    case 1:
        switch(work->menuChoice) {
        case 0: func_021B6A3C(work, func_021B6AD8); break;
        case 1: func_021B6A3C(work, func_021B6BA8); break;
        case 2: func_021B6A3C(work, func_021B6A60); break;
        }
        break;
    }
}








void func_021B6AD8(IrcCompatibleWork *work, u16 *state)
{
    switch(*state) {
    case 0:
        work->secondTestScore=0;
        work->firstTestScore=0;
        *state=1;
        break;
    case 1:
        if(func_021B6C20(&work->runner, IRC_STEP_FIRST_TEST, IRC_COMPATIBLE_HEAP_ID, work)) *state=2;
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
        if(func_021B6C20(&work->runner, IRC_STEP_SECOND_TEST, IRC_COMPATIBLE_HEAP_ID, work)) *state=4;
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
        if(func_021B6C20(&work->runner, IRC_STEP_RESULT, IRC_COMPATIBLE_HEAP_ID, work)) *state=6;
        break;
    case 6:
        func_021B6A3C(work, func_021B6A7C);
        break;
    }
}








void func_021B6BA8(IrcCompatibleWork *work, u16 *state) { switch(*state) { case 0: *state=1; break; case 1: if(func_021B6C20(&work->runner, IRC_STEP_HELP, IRC_COMPATIBLE_HEAP_ID, work)) *state=2; break; case 2: func_021B6A3C(work, func_021B6A7C); break; } }








void func_021B6BE4(IrcStepRunner *runner, int heapId) { func_02082BCC(runner, 0, 12); runner->queue=func_02031324(heapId); }








unsigned int func_021B6BFC(IrcStepRunner *runner) { return func_02031330(runner->queue); }







void func_021B6C08(IrcStepRunner *runner) { func_0203133C(runner->queue); func_02082BCC(runner, 0, 12); }







int func_021B6C20(IrcStepRunner *runner, int stepIndex, int heapId, IrcCompatibleWork *work)
{
    void *result;
    switch(runner->phase) {
    case 0:
        if(d_021B74B8[stepIndex].createArgs) result=d_021B74B8[stepIndex].createArgs(heapId, work);
        else result=0;
        runner->stepArgs=result;
        runner->phase=1;
        break;
    case 1:
        func_02031348(runner->queue,d_021B74B8[stepIndex].taskProc,d_021B74B8[stepIndex].priority,runner->stepArgs);
        runner->phase=2;
        break;
    case 2:
        if(d_021B74B8[stepIndex].destroyArgs) d_021B74B8[stepIndex].destroyArgs(runner->stepArgs,work);
        runner->phase=3;
        break;
    case 3:
        runner->phase=0;
        return 1;
    }
    return 0;
}






/*
 * func_02030734 0x02030734 arm
 * func_020307B0 0x020307B0 arm
 * func_02082BCC 0x02082BCC arm
 * d_021B753C 0x021B753C data a1
 */
void *func_021B6CA0(u32 heapId, IrcCompatibleWork *work) {
 IrcMenuArgs *args;
 args=func_02030734(heapId,0x14,0,d_021B753C,0x36e);
 func_02082BCC(args,0,0x14);
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






void func_021B6CF8(void *args, IrcCompatibleWork *work) {
 work->menuChoice=((IrcMenuArgs *)args)->choice;
 func_020307B0(args);
}






void *func_021B6D04(u32 heapId, IrcCompatibleWork *work) {
 IrcSecondTestArgs *args;
 args=func_02030734(heapId,0x14,0,d_021B753C,0x3af);
 func_02082BCC(args,0,0x14);
 args->gameSystem=work->param->gameSystem;
 args->view=work->view;
 args->profile=work->partnerProfile;
 return args;
}






void func_021B6D3C(void *args, IrcCompatibleWork *work) {
 work->secondTestResult=((IrcSecondTestArgs *)args)->result;
 work->secondTestScore=((IrcSecondTestArgs *)args)->score;
 work->secondTestPenalty=((IrcSecondTestArgs *)args)->penalty;
 work->secondTestBonus=((IrcSecondTestArgs *)args)->bonus;
 func_020307B0(args);
}




void *func_021B6D5C(u32 heapId, IrcCompatibleWork *work) {
 IrcFirstTestArgs *args;
 args=func_02030734(heapId,0x18,0,d_021B753C,0x3e4);
 func_02082BCC(args,0,0x18);
 args->gameSystem=work->param->gameSystem;
 args->view=work->view;
 args->profile=work->partnerProfile;
 return args;
}




void func_021B6D90(void *args, IrcCompatibleWork *work) {
 work->firstTestResult=((IrcFirstTestArgs *)args)->result;
 work->firstTestScore=((IrcFirstTestArgs *)args)->score;
 work->firstTestPenalty=((IrcFirstTestArgs *)args)->penalty;
 func_020307B0(args);
}


/*
 * lever: reversed flag/both declarations preserve saved-register allocation.
 * trailing: 6E84..6E8C is Thumb free veneer; odd callback at 74F4 is code-start proof.
 * prototype: 6ECC reads eight arguments, but original caller explicitly supplies ninth 58; preserve it.
 * func_02030734 0x02030734 arm
 * func_020307B0 0x020307B0 arm
 * func_02082BCC 0x02082BCC arm
 * func_020120F4 0x020120F4 thumb
 * func_02012EBC 0x02012EBC thumb
 * func_0200A8A0 0x0200A8A0 thumb
 * func_02008530 0x02008530 thumb
 * func_0200A9D4 0x0200A9D4 thumb
 * func_021B658C 0x021B658C thumb ov101
 * func_0203D378 0x0203D378 arm
 * func_021B6ECC 0x021B6ECC thumb ov101
 * d_021B753C 0x021B753C data a1
 */
void *func_021B6DAC(u32 heapId, IrcCompatibleWork *work)
{
    IrcCompatibleProfile ownProfile;
    void *saveBlock;
    IrcResultArgs *args;
    u8 *partnerName;
    int useBonus,isNewPartner=0;
    u32 packedDate;
    args=func_02030734(heapId,16,0,d_021B753C,0x418);
    func_02082BCC(args,0,16);
    args->gameSystem=work->param->gameSystem;
    args->view=work->view;
    args->profile=work->partnerProfile;
    if(work->firstTestScore && work->secondTestScore) {
        partnerName=work->partnerProfile->myStatus;
        /* the first call below discards its result; kept as in the original code */
        func_020120F4(work->param->gameSystem);
        saveBlock=func_0200A8A0(func_02012EBC(func_020120F4(work->param->gameSystem)));
        if(func_0200A9D4(saveBlock,func_02008530(partnerName))==0) isNewPartner=1;
        useBonus=0;
        if(work->secondTestBonus && isNewPartner) useBonus=1;
        func_021B658C(work->param->gameSystem,&ownProfile);
        if(func_0203D378()) packedDate=ownProfile.packedDate;
        else packedDate=work->partnerProfile->packedDate;
        args->compatibility=func_021B6ECC(work->firstTestScore,work->secondTestScore,work->firstTestPenalty,work->secondTestPenalty,&ownProfile,work->partnerProfile,useBonus,packedDate,IRC_COMPATIBLE_HEAP_ID);
    }
    return args;
}


void func_021B6E84(void *args, IrcCompatibleWork *work)
{
    func_020307B0(args);
}



void *func_021B6E8C(u32 heapId, IrcCompatibleWork *work) { IrcHelpArgs *args; args=func_02030734(heapId,4,0,d_021B753C,0x49b); func_02082BCC(args,0,4); args->gameSystem=work->param->gameSystem; return args; }



void func_021B6EBC(void *args, IrcCompatibleWork *work) { func_020307B0(args); work->hasReturnedFromHelp=1; }



int func_021B6ECC(u32 firstScore, u32 secondScore, int firstPenalty, int secondPenalty, IrcCompatibleProfile *ownProfile, IrcCompatibleProfile *partnerProfile, int hasBonus, u32 packedDate, int heapId)
{
    int baseScore, nameRate, compatibility;
    u32 nameSimilarity;
    u16 *ownName;
    float rateFixed;
    baseScore = ((((u32)func_021B70A8(ownProfile, packedDate) + (u32)func_021B70A8(partnerProfile, packedDate)) >> 1) * 10) / 100;
    firstScore = firstScore * 50 / 100;
    secondScore = secondScore * 40 / 100;
    baseScore += firstScore + secondScore;
    ownName = func_020084F4(ownProfile->myStatus);
    nameSimilarity = func_021B6F9C(ownName, func_020084F4(partnerProfile->myStatus));
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
u32 func_021B6F9C(u16 *nameA, u16 *nameB)
{
    u32 charA, charB, bitIndexA, bitIndexB;
    u32 equalBits, totalBits, katakanaStartA, katakanaStartB;
    charA = *nameA;
    charB = *nameB;
    if (charA >= 0x30a1 && charA <= 0x30f4) charA -= 0x60;
    if (charB >= 0x30a1 && charB <= 0x30f4) charB -= 0x60;
    bitIndexA = func_021B7090(charA, 8);
    bitIndexB = func_021B7090(charB, 8);
    totalBits = 0;
    equalBits = 0;
    katakanaStartA = 0x30a1;
    katakanaStartB = 0x30a1;
    for (;;) {
        if (bitIndexA == 0) {
            charA = *++nameA;
            if (charA == func_02045A98()) break;
            if (charA >= katakanaStartA && charA <= 0x30f4) charA -= 0x60;
            bitIndexA = func_021B7090(charA, 8);
        }
        if (bitIndexB == 0) {
            charB = *++nameB;
            if (charB == func_02045A98()) break;
            if (charB >= katakanaStartB && charB <= 0x30f4) charB -= 0x60;
            bitIndexB = func_021B7090(charB, 8);
        }
        if (bitIndexA == 0 || bitIndexB == 0) continue;
        if (((charA >> bitIndexA) & 1) == ((charB >> bitIndexB) & 1)) ++equalBits;
        ++totalBits;
        --bitIndexA;
        --bitIndexB;
    }
    return equalBits * 100 / totalBits;
}



unsigned func_021B7090(unsigned bits, unsigned width) { unsigned bitIndex = width - 1; while (bitIndex) { if ((bits >> bitIndex) & 1) break; bitIndex--; } return bitIndex; }



unsigned char func_021B70A8(IrcCompatibleProfile *profile, unsigned packedDate) { struct DateBytes date; date.year=(unsigned char)(packedDate>>24); date.month=(unsigned char)(packedDate>>16); date.day=(unsigned char)(packedDate>>8); date.weekday=(unsigned char)packedDate; return func_0200AA00(profile->birthMonth,profile->birthDay,&date); }
