#ifndef GAME_ARM9_NVRAM_H
#define GAME_ARM9_NVRAM_H

#include "../types.h"

/* Result codes of the firmware memory commands. */

typedef enum NVRAMResult {
    NVRAM_RESULT_SUCCESS = 0,
    NVRAM_RESULT_BUSY,
    NVRAM_RESULT_ILLEGAL_PARAMETER,
    NVRAM_RESULT_SEND_ERROR,
    NVRAM_RESULT_INVALID_COMMAND,
    NVRAM_RESULT_ILLEGAL_STATUS,
    NVRAM_RESULT_FATAL_ERROR,
    NVRAM_RESULT_UNKNOWN
} NVRAMResult;

void NVRAMi_Init(void);
void NVRAMi_ReadCallback(u32 data, BOOL err);
NVRAMResult NVRAMi_Read(u32 address, u32 size, void *pData);
void NVRAMi_WriteCallback(u32 data, BOOL err);
NVRAMResult NVRAMi_Write(u32 address, u32 size, void *pData);
void NVRAMi_VerifyCallback(u32 data, BOOL err);
NVRAMResult NVRAMi_Verify(u32 address, u32 size, void *pData);
BOOL NVRAMi_IsInitialized(void);
void NVRAMi_Callback(int tag, u32 data, BOOL err);
void NVRAMi_SyncCallback(NVRAMResult result, void *arg);
void NVRAMi_AlarmHandler(void *arg);
BOOL NVRAMi_VerifyDataArray(u8 *data0, u8 *data1, u32 size);
BOOL NVRAMi_WriteEnable(void);
BOOL NVRAMi_WriteDisable(void);
BOOL NVRAMi_ReadStatusRegister(u8 *pData);
BOOL NVRAMi_ReadDataBytes(u32 address, u32 size, u8 *pData);
BOOL NVRAMi_PageWrite(u32 address, u16 size, u8 *pData);
BOOL NVRAMi_SoftwareReset(void);

#endif
