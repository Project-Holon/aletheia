#ifndef GAME_OV216_BEACON_DETAIL_GRA_H
#define GAME_OV216_BEACON_DETAIL_GRA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of beacon_detail_gra.c, prototypes copied from their definitions. */

struct ProcOwner;
struct GflHeap;
struct TouchBar;
struct ClactResConfig;
struct BeaconDetailGraWindow;
struct BeaconDetailGraWork;
struct TcblNode;

#include "../types.h"

int BEACON_DETAIL_GRA_Init(struct ProcOwner *obj,int unused1,void *config);
int BEACON_DETAIL_GRA_Exit(struct GflHeap *heap,int unused1,int unused2,char *p);
int BEACON_DETAIL_GRA_Main(int unused0,int *state,int unused2,char *p);
int BEACON_DETAIL_GRA_StateInteract(char *p);
int BEACON_DETAIL_GRA_StateClose(char *p);
int BEACON_DETAIL_GRA_StateInit(unsigned char *p);
int BEACON_DETAIL_GRA_StateFadeIn(char *p);
int BEACON_DETAIL_GRA_StateFadeOut(char *p);
void BEACON_DETAIL_GRA_LoadBeaconInfo(u8 *p);
void BEACON_DETAIL_GRA_Delete(char *p);
void BEACON_DETAIL_GRA_CreateObjects(char *p);
void BEACON_DETAIL_GRA_DeleteObjects(char *p);
void BEACON_DETAIL_GRA_LoadBackground(char *p,u16 heap);
void BEACON_DETAIL_GRA_FreeBackground(char *p);
struct TouchBar *BEACON_DETAIL_GRA_CreateTouchBar(int manager,int heap);
void BEACON_DETAIL_GRA_DeleteTouchBar(unsigned char *p);
void BEACON_DETAIL_GRA_UpdateTouchBar(struct TouchBar *p);
void BEACON_DETAIL_GRA_RegisterActorGfx(unsigned short *p,int *out,const struct ClactResConfig *cfg,void *handle);
void BEACON_DETAIL_GRA_ReleaseActorGfx(void *unused, char *p);
void BEACON_DETAIL_GRA_LoadTrainerGfx(char *p,u32 handle);
void BEACON_DETAIL_GRA_FreeTrainerGfx(char *p);
void BEACON_DETAIL_GRA_CreateWindow(struct BeaconDetailGraWindow *p,unsigned char layer,unsigned char palette,unsigned x,unsigned char y,unsigned char width,unsigned char height);
unsigned BEACON_DETAIL_GRA_CreatePositionedActor(unsigned short *p,void *manager,unsigned *r,short x,short y,unsigned char z,unsigned char a,unsigned char b,unsigned short flag);
void BEACON_DETAIL_GRA_CreateDetailActors(char *p);
void BEACON_DETAIL_GRA_DeleteDetailActors(struct BeaconDetailGraWork *p);
void BEACON_DETAIL_GRA_CreateInfoWindow(char *p);
u32 BEACON_DETAIL_GRA_DeleteInfoWindow(u32 *p);
void BEACON_DETAIL_GRA_CreateListWindows(char *p);
void BEACON_DETAIL_GRA_DeleteListWindows(char *p);
void BEACON_DETAIL_GRA_IsPmsActive(u32 *p);
void *BEACON_DETAIL_GRA_Create(int a,int heap);
void BEACON_DETAIL_GRA_Destroy(unsigned *p);
void BEACON_DETAIL_GRA_Draw(char *p);
void *BEACON_DETAIL_GRA_GetClactUnit(char *p);
void BEACON_DETAIL_GRA_Task(void *unused, char *p);
void BEACON_DETAIL_GRA_InitBgSystem(void *p,int heap);
void BEACON_DETAIL_GRA_ExitBgSystem(void *p);
void BEACON_DETAIL_GRA_Noop(void *p);
void BEACON_DETAIL_GRA_UpdateBg(void *work);
void BEACON_DETAIL_GRA_InitClact(void **p,void *a,int heap);
void BEACON_DETAIL_GRA_ExitClact(char *p);
void BEACON_DETAIL_GRA_DrawClact(void *work);
void BEACON_DETAIL_GRA_VBlankClact(void *work);
u32 BEACON_DETAIL_GRA_ReadPtr(u32*p);
void BEACON_DETAIL_GRA_SetupBeaconList(unsigned char *p);
int BEACON_DETAIL_GRA_UpdateInteract(unsigned char *p);
void BEACON_DETAIL_GRA_RefreshButtons(u8*p);
int BEACON_DETAIL_GRA_IsTouchOnActor(u8*p);
void BEACON_DETAIL_GRA_PlaySe(int a);
void BEACON_DETAIL_GRA_LoadPalette(void *p,unsigned mode,unsigned a,unsigned b);
void BEACON_DETAIL_GRA_UpdateButtons(unsigned char *p);
int BEACON_DETAIL_GRA_GetPmVersionClass(void *beaconData);
const u8*BEACON_DETAIL_GRA_FindAppearanceType(u32 n);
void BEACON_DETAIL_GRA_SetNameSlots(void *p,void *q);
void BEACON_DETAIL_GRA_SetActorAnim(void *p, unsigned short value);
void BEACON_DETAIL_GRA_SetActorPos(void *actor, short x, short y, int surface);
void BEACON_DETAIL_GRA_PrintMsg(u8*p, u8 n);
void BEACON_DETAIL_GRA_TransferChar(u8*p,u32 n);
void BEACON_DETAIL_GRA_InitWindows(char *p);
void BEACON_DETAIL_GRA_DrawWindowRecord(void *p,void **q,int v,short a,unsigned char b,unsigned char c,unsigned char d,unsigned char e);
void BEACON_DETAIL_GRA_SetSlotVisible(char *p, u8 index, u32 enable);
void BEACON_DETAIL_GRA_MoveActor(u8*p,int a);
void BEACON_DETAIL_GRA_SetupSlot(char *p,void *record,u16 unused,u8 slot);
void BEACON_DETAIL_GRA_UpdateSlotInfo(char *p);
void BEACON_DETAIL_GRA_AddFadeTask(char *owner, int direction, int *counter);
void BEACON_DETAIL_GRA_Callback(struct TcblNode*task,u8*p);
void BEACON_DETAIL_GRA_AddTimerTask(char*p);
void BEACON_DETAIL_GRA_AddTimerTaskEx(char *owner, int *counter);
int BEACON_DETAIL_GRA_UpdateTimer(char *p);
void BEACON_DETAIL_GRA_TimerCallback(struct TcblNode *task, void *data);
void BEACON_DETAIL_GRA_AddSlideTask(char *owner, u8 index, int position, u8 direction, int *counter);
void BEACON_DETAIL_GRA_SlideCallback(struct TcblNode *task, char *p);
void BEACON_DETAIL_GRA_AddSlotSlideTask(char*p,int a);
void BEACON_DETAIL_GRA_AddSlotSlideTaskEx(char *owner, int direction, int *counter);
void BEACON_DETAIL_GRA_SlotSlideCallback(struct TcblNode *task,char *work);
void BEACON_DETAIL_GRA_DrawRecord(char *owner, char *record, u32 b, u16 c, u32 d, u16 f);
void BEACON_DETAIL_GRA_AddPrintWaitTask(u8 *p,int arg,int *counter);
void BEACON_DETAIL_GRA_PrintWaitTask(int a, int **b);
/* END mkheaders: generated region */

#endif
