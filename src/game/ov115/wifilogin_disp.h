#ifndef GAME_OV115_WIFILOGIN_DISP_H
#define GAME_OV115_WIFILOGIN_DISP_H

struct TcbTask;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wifilogin_disp.c, prototypes copied from their definitions. */

struct Proc;
struct WifiloginPalTask;

#include "../types.h"

u8 *WIFILOGIN_DISP_CreateDisplay(u16 heap, u32 mode, int reconnect);
void WIFILOGIN_DISP_Draw(u8 *p);
void WIFILOGIN_DISP_DeleteDisplay(u8 *p);
void WIFILOGIN_DISP_InitBgLayersA(u32 unused,unsigned long base);
void WIFILOGIN_DISP_InitBgLayersB(void *unused, unsigned long base);
void WIFILOGIN_DISP_InitBgLayersC(void *unused, unsigned long base);
void WIFILOGIN_DISP_InitBgLayersD(void *unused, unsigned long base);
void WIFILOGIN_DISP_LoadPalette(char *p);
void WIFILOGIN_DISP_UpdatePalette(void *unused, struct WifiloginPalTask *p);
void WIFILOGIN_DISP_CreateActors(u8 *p);
void WIFILOGIN_DISP_CreateUnit(u8 *p);
void WIFILOGIN_DISP_DrawActors(u8 *p);
void WIFILOGIN_DISP_DeleteActors(u8 *p);
void WIFILOGIN_DISP_ScanlineEffect(struct TcbTask *unused, void *p);
void WIFILOGIN_DISP_VBlank(struct TcbTask *task, void *arg);
void WIFILOGIN_DISP_SetPaletteFlag(u8 *p);
void WIFILOGIN_DISP_SetupScreen(u8 *p);
/* END mkheaders: generated region */

#endif
