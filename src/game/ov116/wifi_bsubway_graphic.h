#ifndef GAME_OV116_WIFI_BSUBWAY_GRAPHIC_H
#define GAME_OV116_WIFI_BSUBWAY_GRAPHIC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wifi_bsubway_graphic.c, prototypes copied from their definitions. */

struct WifiBsubwayWork;
struct WifiBsubwayGraphic;
struct WifiBsubwayAnim;
struct WifiBsubwayBg;

#include "../types.h"

void WIFI_BSUBWAY_GRAPHIC_SetupTextParam(struct WifiBsubwayWork *p, u32 heap);
void WIFI_BSUBWAY_GRAPHIC_DeleteTextParam(struct WifiBsubwayWork *p);
u32 WIFI_BSUBWAY_GRAPHIC_ParseCodeIn(struct WifiBsubwayWork *p);
void WIFI_BSUBWAY_GRAPHIC_StartSaveProc(struct WifiBsubwayWork *p);
void WIFI_BSUBWAY_GRAPHIC_Noop(void *work);
int WIFI_BSUBWAY_GRAPHIC_GetSaveState(struct WifiBsubwayWork *p);
void WIFI_BSUBWAY_GRAPHIC_StartRetryProc(struct WifiBsubwayWork *p);
void WIFI_BSUBWAY_GRAPHIC_NoopRetry(void *work);
int WIFI_BSUBWAY_GRAPHIC_DispatchTable(int **p, int x);
int WIFI_BSUBWAY_GRAPHIC_Step(struct WifiBsubwayWork *p,int b);
int WIFI_BSUBWAY_GRAPHIC_StepWithInput(struct WifiBsubwayWork *p,short heap);
int WIFI_BSUBWAY_GRAPHIC_StepRetry(struct WifiBsubwayWork *p,short heap);
void WIFI_BSUBWAY_GRAPHIC_InitBt(struct WifiBsubwayWork *p);
int WIFI_BSUBWAY_GRAPHIC_PollBt(struct WifiBsubwayWork *p);
void WIFI_BSUBWAY_GRAPHIC_CancelBt(struct WifiBsubwayWork *p);
int WIFI_BSUBWAY_GRAPHIC_EndBt(struct WifiBsubwayWork *p);
int WIFI_BSUBWAY_GRAPHIC_CheckNetError(struct WifiBsubwayWork *p);
int WIFI_BSUBWAY_GRAPHIC_IsPrintDone(struct WifiBsubwayWork *p);
void WIFI_BSUBWAY_GRAPHIC_CreateWindow(struct WifiBsubwayGraphic *p, short heap);
void WIFI_BSUBWAY_GRAPHIC_DeleteWindow(struct WifiBsubwayGraphic *p);
void WIFI_BSUBWAY_GRAPHIC_UpdateText(struct WifiBsubwayGraphic *p);
void WIFI_BSUBWAY_GRAPHIC_SetupBgAnim(struct WifiBsubwayGraphic *p, short heap);
void WIFI_BSUBWAY_GRAPHIC_StepBgAnim(void *unused,struct WifiBsubwayAnim *p);
void WIFI_BSUBWAY_GRAPHIC_DeleteBgAnim(struct WifiBsubwayGraphic *p);
void WIFI_BSUBWAY_GRAPHIC_PrintMessage(struct WifiBsubwayGraphic *p,unsigned int a);
int WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(struct WifiBsubwayGraphic *p);
void WIFI_BSUBWAY_GRAPHIC_SetWord(struct WifiBsubwayGraphic *p, unsigned int i, unsigned int a, unsigned int b);
void WIFI_BSUBWAY_GRAPHIC_CreateYesNo(struct WifiBsubwayGraphic *p);
unsigned int WIFI_BSUBWAY_GRAPHIC_ProcessYesNo(struct WifiBsubwayGraphic *p);
void WIFI_BSUBWAY_GRAPHIC_CreateTimeIcon(struct WifiBsubwayGraphic *p);
void WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(struct WifiBsubwayGraphic *p);
void WIFI_BSUBWAY_GRAPHIC_StartSave(struct WifiBsubwayWork *p);
int WIFI_BSUBWAY_GRAPHIC_UpdateSave(struct WifiBsubwayWork *p);
void *WIFI_BSUBWAY_GRAPHIC_Create(int a,unsigned heap);
void WIFI_BSUBWAY_GRAPHIC_Delete(struct WifiBsubwayBg *p);
void WIFI_BSUBWAY_GRAPHIC_OnRedraw(void *a,void *b);
void WIFI_BSUBWAY_GRAPHIC_SetupBg(struct WifiBsubwayBg *p,unsigned heap);
void WIFI_BSUBWAY_GRAPHIC_TeardownBg(void *work);
void WIFI_BSUBWAY_GRAPHIC_Draw(void *p);
/* END mkheaders: generated region */

#endif
