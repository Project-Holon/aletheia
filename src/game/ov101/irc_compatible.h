#ifndef GAME_OV101_IRC_COMPATIBLE_H
#define GAME_OV101_IRC_COMPATIBLE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of irc_compatible.c, prototypes copied from their definitions. */

struct Proc;
struct IrcCompatibleParam;
struct IrcCompatibleWork;
struct IrcStepRunner;
typedef struct IrcCompatibleParam IrcCompatibleParam;
typedef struct IrcCompatibleWork IrcCompatibleWork;
typedef struct IrcStepRunner IrcStepRunner;

#include "../types.h"
#include "../ov101/compatible_irc_sys_types.h"
#include "../ov101/compatible_irc_sys_types.h"

int IRC_COMPATIBLE_ProcInit(struct Proc *proc, int seq, IrcCompatibleParam *param);
int IRC_COMPATIBLE_ProcExit(struct Proc *proc, int seq, int pwk, IrcCompatibleWork *work);
int IRC_COMPATIBLE_ProcMain(void *proc, u32 *seq, void *pwk, IrcCompatibleWork *work);
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
u32 IRC_COMPATIBLE_CalcNameSimilarity(const u16 *nameA, const u16 *nameB);
unsigned IRC_COMPATIBLE_FindHighestSetBit(unsigned bits, unsigned width);
unsigned char IRC_COMPATIBLE_CalcBirthdayScore(IrcCompatibleProfile *profile, unsigned packedDate);
/* END mkheaders: generated region */

#endif
