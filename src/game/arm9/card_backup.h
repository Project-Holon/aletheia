#ifndef GAME_ARM9_CARD_BACKUP_H
#define GAME_ARM9_CARD_BACKUP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of card_backup.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../arm9/card_common.h"

void CARDi_OnFifoRecv(int tag, u32 data, BOOL err);
BOOL CARDi_Request(CARDiCommon *p, int req_type, int retry_count);
void CARDi_RequestStreamCommandCore(CARDiCommon *p);
void CARDi_IdentifyBackupCore(CARDiCommon *p);
void CARDi_BeginBackupCommand(u32 level, void (*callback)(void *), void *arg);
BOOL CARDi_RequestStreamCommand(uptr src, uptr dst, u32 len, void (*callback)(void *), void *arg, BOOL is_async, int req_type, int req_retry, int req_mode);
BOOL CARD_IdentifyBackup(int type);
u32 CARD_GetBackupSectorSize(void);
BOOL CARD_WaitBackupAsync(void);
u32 CARD_TryWaitBackupAsync(void);
void CARD_CancelBackupAsync(void);
/* END mkheaders: generated region */

#endif
