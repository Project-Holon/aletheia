#ifndef GAME_OV174_LOCAL_TVT_SYS_H
#define GAME_OV174_LOCAL_TVT_SYS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of local_tvt_sys.c, prototypes copied from their definitions. */

struct BgTemplate;
struct LocalTvtSys;
struct Proc;

#include "../types.h"

void LOCAL_TVT_SYS_Create(u8 *p);
void LOCAL_TVT_SYS_Delete(u8 *p);
int LOCAL_TVT_SYS_Main(u8 *p);
void LOCAL_TVT_SYS_VBlankHandler(struct TcbTask *unused, void *work);
void LOCAL_TVT_SYS_SetupDisplay(u8 *p);
void LOCAL_TVT_SYS_ExitSystem(unsigned char *p);
void LOCAL_TVT_SYS_SetupBgLayer(const struct BgTemplate *p, int i, int type);
void LOCAL_TVT_SYS_LoadMenuData(char *p);
void LOCAL_TVT_SYS_CreateGraphics(u8 *p);
void LOCAL_TVT_SYS_PositionActor(u8 *p, int index);
void LOCAL_TVT_SYS_HideActor(char *p);
void LOCAL_TVT_SYS_CreateTextResources(u8 *p);
void LOCAL_TVT_SYS_DeleteTextResources(u8 *p);
void LOCAL_TVT_SYS_UpdateText(u8 *p);
int LOCAL_TVT_SYS_IsPrintIdle(char *p);
void LOCAL_TVT_SYS_CreateTextWindow(u8 *p,int mode);
void LOCAL_TVT_SYS_DeleteTextWindow(u8 *p);
void LOCAL_TVT_SYS_PrintMessage(u8 *p, int message);
void LOCAL_TVT_SYS_RunStep(struct LocalTvtSys *o);
void LOCAL_TVT_SYS_ApplyStep(u8 *p);
int LOCAL_TVT_SYS_OnSelect(char *p);
void LOCAL_TVT_SYS_ResetTimer(char *p);
int LOCAL_TVT_SYS_TickTimer(char *p);
int LOCAL_TVT_SYS_ProcInit(void *ctx,int unused,char *arg);
int LOCAL_TVT_SYS_ProcExit(struct Proc *a,unsigned unused,int own,unsigned char *p);
int LOCAL_TVT_SYS_ProcMain(int a, int b, int c, u8 *d);
/* END mkheaders: generated region */

#endif
