#ifndef GAME_OV179_CDEMO_SCENE_H
#define GAME_OV179_CDEMO_SCENE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of cdemo_scene.c, prototypes copied from their definitions. */

#include "../types.h"

int CDEMO_SCENE_Create(char *p);
int CDEMO_SCENE_Destroy(char *p);
u32 CDEMO_SCENE_GetResult(char *p);
int CDEMO_SCENE_ReturnThree(void);
u32 CDEMO_SCENE_RunCommands(char *p);
int CDEMO_SCENE_Step(char *p);
void CDEMO_SCENE_LoadScreenBlock(void *a, int b, int c, int d, int e);
int CDEMO_SCENE_DispatchCommand(char *p);
int CDEMO_SCENE_CmdCount(char *p,int *q);
int CDEMO_SCENE_CmdStartWipe0(char *a, int *q);
int CDEMO_SCENE_CmdStartWipe1(char *a, int *q);
int CDEMO_SCENE_CmdStartWipe2(char *a, int *q);
int CDEMO_SCENE_CmdStartWipe3(char *a, int *q);
int CDEMO_SCENE_CmdSetDone(char *p);
int CDEMO_SCENE_CmdLoadBg(char *p,const int *q);
int CDEMO_SCENE_CmdSetPlaneVisible(int a, int *q);
int CDEMO_SCENE_CmdSetLayerVisible(int a, int *q);
int CDEMO_SCENE_CmdSetBlend(char *p, int *q);
int CDEMO_SCENE_CmdSetBlend2(char *p, int *q);
int CDEMO_SCENE_CmdResetBlend(char *p);
int CDEMO_SCENE_CmdNoop0(void);
int CDEMO_SCENE_CmdStopBgm(void);
int CDEMO_SCENE_CmdPlayFanfare(void *ctx, unsigned int *rec);
int CDEMO_SCENE_CmdNoop1(void);
int CDEMO_SCENE_CmdNoop2(void);
int CDEMO_SCENE_CmdNoop3(void);
int CDEMO_SCENE_CmdReset(char *p);
int CDEMO_SCENE_CmdNoop4(void);
/* END mkheaders: generated region */

#endif
