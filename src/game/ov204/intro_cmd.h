#ifndef GAME_OV204_INTRO_CMD_H
#define GAME_OV204_INTRO_CMD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of intro_cmd.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov204/intro_types.h"

int INTRO_CMD_CmdFade(char *p,int *state,int *q);
u32 INTRO_CMD_CmdBrightnessSet(u32 a, u32 b, u32 *c);
int INTRO_CMD_CmdBrightnessChange(int ctx, int unused, int *src);
int INTRO_CMD_CmdBrightnessWait(void);
u32 INTRO_CMD_CmdBgmChange(u32 ctx, u32 unused, u32 *src);
u32 INTRO_CMD_CmdBgmWait(void);
int INTRO_CMD_CmdBgmFadeOut(int a, int b, int *p);
int INTRO_CMD_CmdBgmFadeIn(int a, int b, int *p);
int INTRO_CMD_CmdSe(char *p,int *state,unsigned *q);
int INTRO_CMD_CmdSeStop(int a, int b, int *p);
u32 INTRO_CMD_CmdWaitInput(void);
int INTRO_CMD_CmdSetMsgBank(char *p,int *state,unsigned *q);
int INTRO_CMD_CmdSub(char *p,int *state,int *q);
int INTRO_CMD_CmdPrintText(char *p,int *state,unsigned *q);
int INTRO_CMD_CmdDrawWindowBorder(char *p,int *state,int *q);
int INTRO_CMD_CmdAddSlot(char *p, int unused, unsigned *q);
int INTRO_CMD_CmdSetVanishFlag(char *p,int *state,int *q);
int INTRO_CMD_CmdSetSlotAnim(char *p,int *state,unsigned *q);
unsigned INTRO_CMD_CmdGetSlotAnimFinished(char *p,int *state,unsigned *q);
int INTRO_CMD_CmdClearSlotAnimFinished(char *p,int *state,unsigned *q);
int INTRO_CMD_CmdMoveSlot(char *p,int *state,int *q);
int INTRO_CMD_CmdSlotAlpha(char *p, int *state, unsigned *q);
int INTRO_CMD_CmdPrintAndMepachi(char *p, int *state, unsigned *q);
int INTRO_CMD_CmdSaveStart(char *a);
int INTRO_CMD_CmdSavePause(char *p,int *state,unsigned *q);
int INTRO_CMD_CmdSaveResume(char *a);
int INTRO_CMD_CmdSaveNoOp(char *a);
int INTRO_CMD_CmdSaveTimeIcon(char *p, int *state);
int INTRO_CMD_CmdSetAppliedFlag(u8*p,u32 unused,u32*q);
int INTRO_CMD_CmdSetConfig(u8*p,u32 unused,u32*q);
int INTRO_CMD_CmdMoveVoice(u8 *p, u32 *q);
int INTRO_CMD_CmdParticle(u8*p,u32 unused,u32*q);
int INTRO_CMD_CmdSetVisible(char *a, int b, int *p);
int INTRO_CMD_CmdSetAnimFrame(char *a, int b, int *p);
int INTRO_CMD_CmdUpdateIntro(u8*p);
int INTRO_CMD_CmdAnimMode(char *p,u32 *q);
int INTRO_CMD_CmdUpdateAnimFrame(u8*p);
int INTRO_CMD_CmdDrawTile(IntroCmdWork *p,u32 *q);
int INTRO_CMD_CmdSetTile(void *p,u32 *q);
int INTRO_CMD_CreateActors(char *p);
int INTRO_CMD_DeleteActors(char *p);
int INTRO_CMD_CmdActorFadeIn(char *p, unsigned *state, unsigned *q);
int INTRO_CMD_CmdActorFadeOut(char *p, unsigned *state, unsigned *q);
int INTRO_CMD_CmdCheckConfig(u8*p);
void INTRO_CMD_CmdSetWordSet(u8*p,u32 a);
char *INTRO_CMD_Create(void *a, void *b, void *c, char *d, void *e, unsigned short heap);
void INTRO_CMD_Delete(u8*p);
int INTRO_CMD_Main(char *p);
int INTRO_CMD_AddCommand(IntroCmdWork *p, IntroCommand *q);
int INTRO_CMD_RunCommands(IntroCmdWork *p);
void INTRO_CMD_ClearCommand(IntroCmdWork *p, u8 i);
IntroCommand *INTRO_CMD_GetScenarioRow(u32 n);
/* END mkheaders: generated region */

#endif
