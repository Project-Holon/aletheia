#ifndef GAME_OV219_BEACON_DETAIL_H
#define GAME_OV219_BEACON_DETAIL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of beacon_detail.c, prototypes copied from their definitions. */

struct Proc;
struct BeaconDetailMenuTemplate;

#include "../types.h"

int BEACON_DETAIL_Init(void *obj,void *unused,void *ctx);
int BEACON_DETAIL_Main(void *unused, char *state, int unused2, char *ctx);
void BEACON_DETAIL_WinActivate(u8 *p,u32 i);
void BEACON_DETAIL_WinUpdate(u8 *p);
int BEACON_DETAIL_Update(u8 *p, int *state);
int BEACON_DETAIL_Exit(struct Proc *controller,void *unused1,void *unused2,char *p);
void BEACON_DETAIL_InitVram(void);
void BEACON_DETAIL_InitGraphics(unsigned heap);
void BEACON_DETAIL_ExitGraphics(int a);
void BEACON_DETAIL_LoadRecords(char *p);
u32 BEACON_DETAIL_GetRecordIndex(u32 key);
void BEACON_DETAIL_ReadTouchInput(char *p);
void BEACON_DETAIL_CalcTouchDelta(const char *p,int x,int y,int *xflag,int *xdistance,int *yflag,int *ydistance);
u32 BEACON_DETAIL_CreateBmpWin(const u8 *p,int flag);
void BEACON_DETAIL_InitMainScreen(char *p,void *arc);
void BEACON_DETAIL_CreateTaskMenu(char *p);
void BEACON_DETAIL_CreateTaskMenuWin(char *p,int i);
void BEACON_DETAIL_DeleteTaskMenuWin(u8 *p,u32 i);
void BEACON_DETAIL_DeleteMainScreen(char *p);
int BEACON_DETAIL_PrintMessage(char *p,u32 message,int force);
void BEACON_DETAIL_OnMessageDone(int a, int b, int c);
void BEACON_DETAIL_SetupMenuList(char *p,const struct BeaconDetailMenuTemplate *source,unsigned count);
void BEACON_DETAIL_CreateMenuItems(u8 *p, const u8 *a, uptr b, u32 c);
void BEACON_DETAIL_CreateMenuItemsFromIds(char *p,const unsigned char *descriptor,const struct BeaconDetailMenuTemplate *cfg,unsigned file,const unsigned char *ids,unsigned count);
void BEACON_DETAIL_CloseMenu(u8*p);
void BEACON_DETAIL_DrawCurrentArea(char *p);
void BEACON_DETAIL_DrawEntryDetail(char *p,unsigned key,unsigned member);
void BEACON_DETAIL_CloseDetailWin(char *p);
int BEACON_DETAIL_FindNearestRecord(char *p, u32 *out);
void BEACON_DETAIL_DrawCurrentInfo(char *p);
void BEACON_DETAIL_Create3DObjects(char *p, void *arc);
void BEACON_DETAIL_Delete3DObjects(char *p);
void BEACON_DETAIL_Init3DParams(u8 *p);
void BEACON_DETAIL_CreateCamera(char *p);
void BEACON_DETAIL_SetupCamera(char *p);
void BEACON_DETAIL_CreateLight(char *p);
int BEACON_DETAIL_MoveCursor(u8 *p, u32 a, u32 b);
int BEACON_DETAIL_UpdateCamera(char *p);
void BEACON_DETAIL_Draw3D(char *p);
int BEACON_DETAIL_GetEntryText(unsigned key,unsigned optional,void *first,void *second,unsigned heap);
int BEACON_DETAIL_HasEntry(int a);
void BEACON_DETAIL_WrapAngle(int *p);
int BEACON_DETAIL_CalcDistance(int *p, int *q);
/* END mkheaders: generated region */

#endif
