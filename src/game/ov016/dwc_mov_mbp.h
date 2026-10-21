#ifndef GAME_OV016_DWC_MOV_MBP_H
#define GAME_OV016_DWC_MOV_MBP_H

typedef enum {
    CS_NONE,
    CS_CONNECT,
    CS_REQUEST,
    CS_ENTRY,
    CS_DOWNLOAD,
    CS_BOOTABLE,
    CS_REBOOT
} ChildState;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_mov_mbp.c, prototypes copied from their definitions. */

struct DWCi_MOV_MBPChildInfo;
typedef struct DWCi_MOV_MBPChildInfo DWCi_MOV_MBPChildInfo;

#include "../types.h"
#include "../sdk_mb.h"

void DWCi_MOV_MBP_MemInit(void *x);
void DWCi_MOV_MBP_Init(u32 ggid, u16 tgid);
void DWCi_MOV_MBP_Start(MBGameRegistry *gameInfo, u16 channel);
int DWCi_MOV_MBP_RegistFile(MBGameRegistry *gameInfo);
void DWCi_MOV_MBP_AcceptChild(u16 aid);
void DWCi_MOV_MBP_KickChild(u16 child_aid);
void DWCi_MOV_MBP_StartDownload(u16 child_aid);
void DWCi_MOV_MBP_StartDownloadAll(void);
int DWCi_MOV_MBP_IsBootableAll(void);
void DWCi_MOV_MBP_StartRebootAll(void);
void DWCi_MOV_MBP_Cancel(void);
void DWCi_MOV_MBP_ChangeState(unsigned short v);
unsigned short DWCi_MOV_MBP_GetState(void);
u16 DWCi_MOV_MBP_GetChildBmp(int bmpType);
ChildState DWCi_MOV_MBP_GetChildState(u16 aid);
DWCi_MOV_MBPChildInfo *DWCi_MOV_MBP_GetChildInfo(u16 child_aid);
u16 DWCi_MOV_MBP_GetPlayerNo(u8 *macAddress);
/* END mkheaders: generated region */

#endif
