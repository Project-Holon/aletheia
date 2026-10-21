#ifndef GAME_OV203_DEMO3D_DATA_H
#define GAME_OV203_DEMO3D_DATA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of demo3d_data.c, prototypes copied from their definitions. */

struct Demo3dDataConfig;
struct TcbTask;
struct CaptureConfig;
struct TcblNode;
struct Demo3dBgmFadeWork;
struct Demo3dMessageContext;
struct Demo3dFadeContext;
typedef struct Demo3dDataConfig Demo3dDataConfig;
typedef struct CaptureConfig CaptureConfig;
typedef struct Demo3dBgmFadeWork Demo3dBgmFadeWork;

#include "../types.h"
#include "../ov203/demo3d_data_shared_types.h"

void *DEMO3D_DATA_Create(unsigned heap);
void DEMO3D_DATA_Delete(char *a);
void DEMO3D_DATA_BuildTable(char *ctx, const char *config, u8 type);
void *DEMO3D_DATA_GetPair(char *p,u8 *q);
u32 DEMO3D_DATA_GetTimeStep(u32 a);
int DEMO3D_DATA_IsDouble3dDisplay(void *a);
void DEMO3D_DATA_GetTextureSize(void *ctx, int mode, unsigned char *width, unsigned char *height);
u32 DEMO3D_DATA_GetCommandList(u32 id);
u32 DEMO3D_DATA_GetExitCommandList(u32 id);
void *DEMO3D_DATA_CreateCapture(void *p,unsigned a,unsigned b);
void DEMO3D_DATA_DeleteCapture(int a);
void *DEMO3D_DATA_CreateTask(void *manager, const Demo3dDataConfig *source);
void DEMO3D_DATA_DeleteTask(int *s,unsigned a,unsigned b,unsigned c);
void DEMO3D_DATA_ApplyCapture(void *task, const int *ctx);
void DEMO3D_DATA_FinishTask(struct TcbTask *node, void *work_);
void DEMO3D_DATA_StartCapture(CaptureConfig *s);
void DEMO3D_DATA_PlaySe(void *unused,int ignored,int *s);
void DEMO3D_DATA_StopSe(u32 a, u32 b, int *c);
void DEMO3D_DATA_FadeSeVolume(int ctx, int unused, int *src);
void DEMO3D_DATA_FadeSeSlotParam1(Demo3dCmdContext *p,int unused,int *v);
void DEMO3D_DATA_FadeSeSlotParam2(Demo3dCmdContext *p,int unused,int *s);
void DEMO3D_DATA_CreateSeFade(Demo3dCmdContext *owner,u8 kind,u16 target,int start,int end,int duration,int flag);
void DEMO3D_DATA_UpdateSeFade(struct TcblNode *p,char *q);
void DEMO3D_DATA_ApplySeFade(int mode,int channel,int value);
void DEMO3D_DATA_PlayBgm(int a,int b,int *s);
void DEMO3D_DATA_StopBgm(void);
void DEMO3D_DATA_TaskFadeOutBgm(char *p,int unused,int *s);
void DEMO3D_DATA_TaskPlayBgm(char *p,int unused,int *s);
void DEMO3D_DATA_CreateBgmFade(char *p,int channel,int start,int end,unsigned mode);
void DEMO3D_DATA_BgmFadeMain(struct TcblNode *node,Demo3dBgmFadeWork *t);
void DEMO3D_DATA_TaskFadeBrightness(char *p,int unused,int *s);
void DEMO3D_DATA_CreateBrightnessFade(Demo3dCmdContext *owner,int mask,int kind,int start,int end,int duration,int *counter);
void DEMO3D_DATA_BrightnessFadeMain(struct TcblNode *node,int *s);
void DEMO3D_DATA_TaskBrightnessSeq(char *p,int unused,int *s);
void DEMO3D_DATA_CreateBrightnessSeq(char *p,unsigned char engineMask,signed char firstLevel,signed char secondLevel,signed char thirdLevel,int firstDuration,int secondDuration);
void DEMO3D_DATA_BrightnessSeqMain(void *task,char *work);
void DEMO3D_DATA_TaskSetLightSlot(unsigned unused,char **q,unsigned *v);
void DEMO3D_DATA_TaskSetLightVector(unsigned unused,char **q,unsigned *v);
void DEMO3D_DATA_TaskShowMessage(int a, int b, int *s);
void DEMO3D_DATA_CreateMessage(char *p,int a,int b,int c,unsigned char d,unsigned char e,unsigned char f,unsigned char g);
void DEMO3D_DATA_MessageMain(struct TcblNode *task, struct Demo3dMessageContext *ctx);
void DEMO3D_DATA_DeleteMessageWindow(char *p);
void DEMO3D_DATA_TaskFade(char *p,int unused,int *record);
void DEMO3D_DATA_CreateFade(char *p,int a,int b,int c,int d,int e,int f);
void DEMO3D_DATA_FadeMain(struct TcblNode *task,struct Demo3dFadeContext *ctx);
void DEMO3D_DATA_DeleteFadeWork(void *p);
void DEMO3D_DATA_TaskCreateCapture(char *a, int unused, int *p);
void DEMO3D_DATA_TaskDeleteCapture(char *a);
int DEMO3D_DATA_ScaleTime(char *p, int v);
/* END mkheaders: generated region */

#endif
