/*
 * file:     ncfg_backup.c
 * unit:     yes
 * function: NCFGi_InitBackupMemory, NCFG_GetFormatVersion, NCFG_ReadBackupMemory, NCFG_WriteBackupMemory, getSlotInfo, ReadNVRAM, WriteNVRAM, VerifyNVRAM
 * address:  0x0205F648
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   NVRAMi_Init         0x02083644 arm
 *   DC_InvalidateRange  0x020862B8 arm
 *   ReadNVRAM           0x0205F970 arm
 *   sNcfgBackupBaseAddress         0x020A813C data a4
 *   sNcfgBackupFormatVersionNumber 0x02146B00 data a1
 *   sNcfgBackupNvramBuf            0x02146B20 data a16
 *   sNcfgBackupNvramBuf2           0x02146B40 data a16
 *   NCFGi_InitBackupMemory           0x0205f648 arm
 *   getSlotInfo            0x0205F8A0 arm
 *   DC_StoreRange          0x020862D4 arm
 *   WriteNVRAM             0x0205F9D8 arm
 *   VerifyNVRAM            0x0205FA40 arm
 *   NCFG_GetFormatVersion 0x0205F700 arm
 *   NVRAMi_Read 0x02083844 arm
 *   OS_IsTickAvailable  0x02087058 arm
 *   OS_IsAlarmAvailable 0x02087244 arm
 *   OS_Sleep            0x02085A38 arm
 *   NVRAMi_Write 0x02083DC8 arm
 *   NVRAMi_Verify 0x020840F8 arm
 */
#include "../types.h"

/* backup.o's .bss statics from sNcfgBackupFormatVersionNumber on, in their laid-out order: the object
 * reads sNcfgBackupNvramBuf[0] and sNcfgBackupNvramBuf2[0] off the .bss base (sNcfgBackupFormatVersionNumber) while the
 * calls take each buffer's own literal */
typedef struct {
    u8  FormatVersionNumber;
    u8  pad[31];
    u8  nvramBuf[32];
    u16 nvramBuf2[16];
} NCFGBackupBss;

#include "nvram.h"

#include "os_cache.h"
extern NVRAMResult ReadNVRAM(u32 address, u32 size, void *pData);
extern s32  NCFGi_InitBackupMemory(void);
extern int  getSlotInfo(s32 index, u32 *address, u32 *size);
extern NVRAMResult WriteNVRAM(u32 address, u32 size, void *pData);
extern NVRAMResult VerifyNVRAM(u32 address, u32 size, void *pData);
extern u8  NCFG_GetFormatVersion(void);
typedef unsigned long long OSTick;
#include "os_tick.h"
#include "os_alarm.h"
#include "os_thread.h"
s32 NCFG_ReadBackupMemory(void *buf, u32 size, s32 index);
s32 NCFG_WriteBackupMemory(s32 index, void *buf, u32 size);
extern u32 sNcfgBackupBaseAddress;
extern NCFGBackupBss sNcfgBackupFormatVersionNumber;
extern u8 sNcfgBackupNvramBuf[32];
extern u8 sNcfgBackupNvramBuf2[32];

/*
 * sdk:      NCFGi_InitBackupMemory (libncfg.TWL.HYB.a backup.o)
 */
s32 NCFGi_InitBackupMemory(void)
{
    s32 result;

    if (sNcfgBackupBaseAddress != (u32)-1)
        return 0;
    NVRAMi_Init();
    result = 0;
    DC_InvalidateRange(sNcfgBackupNvramBuf, sizeof(sNcfgBackupNvramBuf));
    if (ReadNVRAM(0x1FE, sizeof(sNcfgBackupNvramBuf), sNcfgBackupNvramBuf) == 0) {
        sNcfgBackupFormatVersionNumber.FormatVersionNumber = sNcfgBackupFormatVersionNumber.nvramBuf[0];
    } else {
        result = -1;
        goto end;
    }
    DC_InvalidateRange(sNcfgBackupNvramBuf2, sizeof(sNcfgBackupNvramBuf2));
    if (ReadNVRAM(0x20, sizeof(sNcfgBackupNvramBuf2), sNcfgBackupNvramBuf2) == 0)
        sNcfgBackupBaseAddress = (sNcfgBackupFormatVersionNumber.nvramBuf2[0] << 3) - 0x400;
    else
        result = -1;
end:
    return result;
}

/*
 * sdk:      NCFG_GetFormatVersion (backup.o)
 */
unsigned char NCFG_GetFormatVersion(void)
{
    long result;
    unsigned char version;

    result = NCFGi_InitBackupMemory();
    if (result != 0) {
        return 0;
    }
    version = sNcfgBackupFormatVersionNumber.FormatVersionNumber;
    if (version == 0xFF) {
        version = 0x10;
    }
    return version;
}

/*
 * sdk:      NCFG_ReadBackupMemory (libncfg.TWL.HYB.a backup.o)
 */
s32 NCFG_ReadBackupMemory(void *buf, u32 size, s32 index)
{
    s32 result;
    u32 address;
    u32 readSize;

    result = NCFGi_InitBackupMemory();
    if (result != 0)
        return result;
    if (buf == 0)
        return -1;
    if (!getSlotInfo(index, &address, &readSize))
        return -1;
    if (readSize > size)
        readSize = size;
    DC_InvalidateRange(buf, readSize);
    if (ReadNVRAM(address, (u16)readSize, buf) == 0)
        return (s32)readSize;
    return -1;
}

/*
 * sdk:      NCFG_WriteBackupMemory (libncfg.TWL.HYB.a backup.o)
 */
s32 NCFG_WriteBackupMemory(s32 index, void *buf, u32 size)
{
    s32 result;
    u32 address;
    u32 writeSize;
    int iRetry;
    s32 nvramResult;

    result = NCFGi_InitBackupMemory();
    if (result != 0)
        return result;
    if (buf == 0) {
        result = -1;
    } else if (!getSlotInfo(index, &address, &writeSize)) {
        result = -1;
    } else {
        if (writeSize > size)
            writeSize = size;
        DC_StoreRange(buf, writeSize);
        result = -1;
        for (iRetry = 0; iRetry < 3; iRetry++) {
            nvramResult = WriteNVRAM(address, (u16)writeSize, buf);
            if (nvramResult != 0) {
                result = -1;
                break;
            }
            nvramResult = VerifyNVRAM(address, (u16)writeSize, buf);
            if (nvramResult == 0) {
                result = (s32)writeSize;
                break;
            }
            if (nvramResult != 6) {
                result = -1;
                break;
            }
        }
    }
    return result;
}

/*
 * sdk:      getSlotInfo (libncfg.TWL.HYB.a backup.o)
 */
int getSlotInfo(s32 index, u32 *address, u32 *size)
{
    switch (index) {
    case 0:
    case 1:
    case 2:
    case 3:
        *address = sNcfgBackupBaseAddress + index * 0x100;
        *size = 0x100;
        return 1;
    case 0x11:
    case 0x12:
    case 0x13:
        if (NCFG_GetFormatVersion() < 0x20) {
            *address = (u32)-1;
            *size = 0;
            return 0;
        }
        *address = sNcfgBackupBaseAddress - 0x600 + (index - 0x11) * 0x200;
        *size = 0x200;
        return 1;
    default:
        *address = (u32)-1;
        *size = 0;
        return 0;
    }
}

/*
 * sdk:      ReadNVRAM (libncfg.TWL.HYB.a backup.o)
 */
NVRAMResult ReadNVRAM(u32 address, u32 size, void *pData)
{
    NVRAMResult nvramResult;
    s32 i;

    for (i = 0; i < 5; i++) {
        nvramResult = NVRAMi_Read(address, size, pData);
        if (nvramResult != NVRAM_RESULT_BUSY)
            break;
        if (OS_IsTickAvailable() && OS_IsAlarmAvailable())
            OS_Sleep(1);
    }
    return nvramResult;
}

/*
 * sdk:      WriteNVRAM (libncfg.TWL.HYB.a backup.o); the catalog row says ReadNVRAM,
 *           NCFG_WriteBackupMemory's PC24 relocation names this address WriteNVRAM
 */
NVRAMResult WriteNVRAM(u32 address, u32 size, void *pData)
{
    NVRAMResult nvramResult;
    s32 i;

    for (i = 0; i < 5; i++) {
        nvramResult = NVRAMi_Write(address, size, pData);
        if (nvramResult != NVRAM_RESULT_BUSY)
            break;
        if (OS_IsTickAvailable() && OS_IsAlarmAvailable())
            OS_Sleep(1);
    }
    return nvramResult;
}

/*
 * sdk:      VerifyNVRAM (libncfg.TWL.HYB.a backup.o); the catalog row says ReadNVRAM,
 *           NCFG_WriteBackupMemory's PC24 relocation names this address VerifyNVRAM
 */
NVRAMResult VerifyNVRAM(u32 address, u32 size, void *pData)
{
    NVRAMResult nvramResult;
    s32 i;

    for (i = 0; i < 5; i++) {
        nvramResult = NVRAMi_Verify(address, size, pData);
        if (nvramResult != NVRAM_RESULT_BUSY)
            break;
        if (OS_IsTickAvailable() && OS_IsAlarmAvailable())
            OS_Sleep(1);
    }
    return nvramResult;
}
