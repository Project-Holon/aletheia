#ifndef GAME_OV107_MB_WM_BASE_H
#define GAME_OV107_MB_WM_BASE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mb_wm_base.c, prototypes copied from their definitions. */

#include "../sdk_mb.h"
#include "../types.h"

int MB_Init(void *work, const MBUserInfo *user, u32 ggid, u32 tgid, u32 dma);
int MB_SetParentCommParam(unsigned short sendSize, unsigned short maxChildren);
int MBi_StartCommon(void);
int MBi_StartParentCore(int channel);
int MB_StartParentFromIdle(int channel);
int MBi_CallReset(void);
int MB_ResetWm(void);
int MBi_CommEnd(void);
void MB_EndToIdle(void);
void MB_DisconnectChild(u16 aid);
void MBi_SetMaxScanTime(u16 time);
int MBi_SendMP(unsigned short *buf, int len, int pollbmp);
u32 MBi_GetGgid(void);
u16 MBi_GetTgid(void);
unsigned char MBi_GetAttribute(void);
int MBi_IsStarted(void);
void MBi_CheckWmErrcode(u16 apiid, int errcode);
/* END mkheaders: generated region */

#endif
