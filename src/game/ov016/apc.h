#ifndef GAME_OV016_APC_H
#define GAME_OV016_APC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of apc.c, prototypes copied from their definitions. */

struct WMBssDesc;

#include "../sdk_wm.h"

void APCi_Notify(WCMNotice *notice);
int APCi_MoveIdleState(void);
int APC_GetAPList(struct WMBssDesc *WMBssdescBuf, int list_max);
int APC_SearchStart(unsigned char *bssid, unsigned char *essid, int essid_len, unsigned long option);
int APC_SearchEnd(void);
int APC_Disconnect(void);
int APC_End(void);
int APC_Connect(struct WMBssDesc *wmbssdesc, unsigned char *wep_buf, unsigned long option);
int APC_Init(void (*user_callback)(int, void *), void *workbuffer, int work_size);
/* END mkheaders: generated region */

#endif
