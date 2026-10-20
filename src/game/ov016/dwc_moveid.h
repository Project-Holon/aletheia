#ifndef GAME_OV016_DWC_MOVEID_H
#define GAME_OV016_DWC_MOVEID_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_moveid.c, prototypes copied from their definitions. */

#include "../ov016/dwc_moveid_types.h"
#include "../ov016/dwc_moveid_types.h"
#include "../types.h"
#include "../sdk_mb.h"

void DWCi_MOVInit(Wk *wm, MovData *md);
int DWCi_MOVFinalize(void);
int DWCi_MOVStartAdmitChild(void);
int DWCi_MOVStartDownloadandBootChild(void);
void DWCi_MOVFramework(void);
void DWCi_MOVGetStatus(u8 *stt, u8 *change_f);
MBUserInfo *DWCi_GetChildInfo(void);
void _DWCi_MOV_EraseFlashData(void);
u16 Parent_get_child_data_kind(void);
/* END mkheaders: generated region */

#endif
