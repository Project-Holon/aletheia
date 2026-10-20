#ifndef GAME_ARM9_BACKUP_SYSTEM_H
#define GAME_ARM9_BACKUP_SYSTEM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of backup_system.c, prototypes copied from their definitions. */

struct BackupSaveData;
struct SaveDataParam;
struct SaveFooter;
typedef struct BackupSaveData BackupSaveData;
typedef struct SaveDataParam SaveDataParam;
typedef struct SaveFooter SaveFooter;

#include "../types.h"

void BACKUP_SYSTEM_Init(u32 heap_id, u32 read_error_func, u32 write_error_func);
BackupSaveData *BACKUP_SYSTEM_CreateCore(const SaveDataParam *param, u32 heap_id, void *svwk, u32 svwk_size, u32 init_mode);
BackupSaveData *BACKUP_SYSTEM_Create(const SaveDataParam *param, u32 heap_id);
BackupSaveData *BACKUP_SYSTEM_CreateWithWork(const SaveDataParam *param, u32 heap_id, void *svwk, u32 svwk_size, u32 init_mode);
void BACKUP_SYSTEM_Delete(BackupSaveData *sv);
u8 *BACKUP_SYSTEM_GetWork(BackupSaveData *sv, u32 *size);
u8 *BACKUP_SYSTEM_GetRecordWork(BackupSaveData *sv, u32 id);
void BACKUP_SYSTEM_ClearWork(BackupSaveData *sv);
void BACKUP_SYSTEM_GetDiffSize(BackupSaveData *sv, u32 *diff_size, u32 *total_size);
int BACKUP_SYSTEM_Erase(BackupSaveData *sv, u32 heap_id);
int BACKUP_SYSTEM_Load(BackupSaveData *sv, u32 heap_id);
void BACKUP_SYSTEM_StartSave(BackupSaveData *sv);
int BACKUP_SYSTEM_MainSave(BackupSaveData *sv);
void BACKUP_SYSTEM_CancelSave(BackupSaveData *sv);
void BACKUP_SYSTEM_InitLinkedSave(BackupSaveData *main_sv, BackupSaveData *link_sv, u32 *link_count);
int BACKUP_SYSTEM_MainLinkedSave(BackupSaveData *main_sv, BackupSaveData *link_sv);
int BACKUP_SYSTEM_LoadLinked(BackupSaveData *sv, u32 heap_id, u32 link_count);
u32 BACKUP_SYSTEM_GetWrittenSize(const BackupSaveData *sv);
void *BACKUP_SYSTEM_IsFlashBusy(void);
u16 BACKUP_SYSTEM_CalcCrcTableCrc(BackupSaveData *sv, u8 *buf);
u32 BACKUP_SYSTEM_GetAreaAddr(BackupSaveData *sv, u32 area);
u16 *BACKUP_SYSTEM_GetCrcTable(BackupSaveData *sv);
SaveFooter *BACKUP_SYSTEM_GetFooter(BackupSaveData *sv, u8 *buf);
u32 BACKUP_SYSTEM_CheckFooter(BackupSaveData *sv, u8 *buf, u32 area);
void BACKUP_SYSTEM_SetFooter(const BackupSaveData *sv, u8 *buf);
void BACKUP_SYSTEM_SetSaveCount(BackupSaveData *sv, u32 save_count);
void BACKUP_SYSTEM_GetFooterInfo(u32 *result, BackupSaveData *sv, u8 *buf, u32 area);
int BACKUP_SYSTEM_LoadDoubleCopy(BackupSaveData *sv, u32 heap_id, u32 mode, u32 link_count);
int BACKUP_SYSTEM_LoadSingleCopy(BackupSaveData *sv, int mode, int link_count);
int BACKUP_SYSTEM_WriteFooterBody(BackupSaveData *sv, u32 area);
int BACKUP_SYSTEM_WriteFooterLastByte(BackupSaveData *sv, u32 area);
void BACKUP_SYSTEM_InitSaveSeq(BackupSaveData *sv, u32 set_busy);
void BACKUP_SYSTEM_CalcDiffSize(BackupSaveData *sv, u32 *diff_size, u32 *total_size);
u32 BACKUP_SYSTEM_CompareRecordStep(BackupSaveData *sv, u32 id, u32 area, u32 *rest, u32 *budget, u32 *done_size, u32 *yield);
u16 BACKUP_SYSTEM_WriteRecord(BackupSaveData *sv, u32 id, u32 area, u32 pass);
int BACKUP_SYSTEM_WriteCrcTable(BackupSaveData *sv, u32 area);
int BACKUP_SYSTEM_SaveSeqMain(BackupSaveData *sv, u32 *pass_done);
void BACKUP_SYSTEM_EndSave(BackupSaveData *sv, u32 result, u32 clear_busy);
void BACKUP_SYSTEM_CancelSaveSeq(BackupSaveData *sv);
u32 BACKUP_SYSTEM_EraseFooter(BackupSaveData *sv, u32 area);
u16 BACKUP_SYSTEM_IncRecordCount(BackupSaveData *sv, u32 id);
u16 BACKUP_SYSTEM_UpdateRecordCrc(BackupSaveData *sv, u32 id);
u32 BACKUP_SYSTEM_GetBlockArea(BackupSaveData *sv, u32 block);
void BACKUP_SYSTEM_SetBlockArea(BackupSaveData *sv, u32 block, u32 area);
void BACKUP_SYSTEM_SwapBlockAreas(BackupSaveData *sv);
void BACKUP_SYSTEM_ClearBlockAreas(BackupSaveData *sv);
void BACKUP_SYSTEM_FillBlockAreas(BackupSaveData *sv, u32 area);
void BACKUP_SYSTEM_WriteFlash(u32 flash_addr, u32 src, u32 size);
u16 BACKUP_SYSTEM_WriteFlashAsync(u32 flash_addr, u32 src, u32 size);
int BACKUP_SYSTEM_CheckFlashAsync(u16 lock_id, u32 *success);
int BACKUP_SYSTEM_ReadFlash(u32 flash_addr, u32 dst, u32 size);
int BACKUP_SYSTEM_ReadRecordFromFlash(BackupSaveData *sv, u32 id, u32 area_index, u32 dst, u32 size);
/* END mkheaders: generated region */

typedef struct BackupSaveData BackupSaveData;
typedef struct SaveDataParam SaveDataParam;
typedef struct SaveFooter SaveFooter;

#endif
