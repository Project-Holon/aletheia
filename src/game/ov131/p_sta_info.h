#ifndef GAME_OV131_P_STA_INFO_H
#define GAME_OV131_P_STA_INFO_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of p_sta_info.c, prototypes copied from their definitions. */

struct PStaInfoWork;
typedef struct PStaInfoWork PStaInfoWork;

#include "../ov131/p_status_types.h"

PStaInfoWork *P_STA_INFO_AllocWork(PStatusWork *wk);
void P_STA_INFO_FreeWork(PStatusWork *wk, PStaInfoWork *work);
void P_STA_INFO_Main(PStatusWork *wk, PStaInfoWork *work);
void P_STA_INFO_LoadResources(PStatusWork *wk, PStaInfoWork *work, void *arc);
void P_STA_INFO_FreeResources(PStatusWork *wk, PStaInfoWork *work);
void P_STA_INFO_Setup(PStatusWork *wk, PStaInfoWork *work);
void P_STA_INFO_ShowPage(PStatusWork *wk, PStaInfoWork *work);
void P_STA_INFO_DeleteWindows(PStatusWork *wk, PStaInfoWork *work);
void P_STA_INFO_HidePage(PStatusWork *wk, PStaInfoWork *work);
void P_STA_INFO_DrawStats(PStatusWork *wk, PStaInfoWork *work, void *mon);
void P_STA_INFO_DrawMemo(PStatusWork *wk, PStaInfoWork *work, void *mon);
void *P_STA_INFO_GetPlaceName(PStatusWork *wk, PStaInfoWork *work, unsigned int placeId);
/* END mkheaders: generated region */

#endif
