/*
 * file:     unit_0205F648.c
 * unit:     yes
 * function: func_0205F648, func_0205F700, func_0205F72C, func_0205F7C8, func_0205F8A0, func_0205F970, func_0205F9D8, func_0205FA40
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
 *   BaseAddress         0x020A813C data a4
 *   FormatVersionNumber 0x02146B00 data a1
 *   nvramBuf            0x02146B20 data a16
 *   nvramBuf2           0x02146B40 data a16
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
 *   func_02083DC8 0x02083DC8 arm
 *   func_020840F8 0x020840F8 arm
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32;

typedef signed long    s32;

/* backup.o's .bss statics from FormatVersionNumber on, in their laid-out order: the object
 * reads nvramBuf[0] and nvramBuf2[0] off the .bss base (FormatVersionNumber) while the
 * calls take each buffer's own literal */
typedef struct {
    u8  FormatVersionNumber;
    u8  pad[31];
    u8  nvramBuf[32];
    u16 nvramBuf2[16];
} NCFGBackupBss;

typedef int           BOOL;

typedef enum NVRAMResult {
    NVRAM_RESULT_SUCCESS = 0,
    NVRAM_RESULT_BUSY = 1
} NVRAMResult;

extern void NVRAMi_Init(void);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);
extern int  ReadNVRAM(u32 address, u32 size, void *pData);
extern s32  NCFGi_InitBackupMemory(void);
extern int  getSlotInfo(s32 index, u32 *address, u32 *size);
extern void DC_StoreRange(void *startAddr, u32 nBytes);
extern int  WriteNVRAM(u32 address, u32 size, void *pData);
extern int  VerifyNVRAM(u32 address, u32 size, void *pData);
extern u8  NCFG_GetFormatVersion(void);
extern NVRAMResult NVRAMi_Read(u32 address, u32 size, void *pData);
extern BOOL OS_IsTickAvailable(void);
extern BOOL OS_IsAlarmAvailable(void);
extern void OS_Sleep(u32 msec);
extern NVRAMResult func_02083DC8(u32 address, u32 size, void *pData);
extern NVRAMResult func_020840F8(u32 address, u32 size, void *pData);
s32 func_0205F648(void);
unsigned char func_0205F700(void);
s32 func_0205F72C(void *buf, u32 size, s32 index);
s32 func_0205F7C8(s32 index, void *buf, u32 size);
int func_0205F8A0(s32 index, u32 *address, u32 *size);
NVRAMResult func_0205F970(u32 address, u32 size, void *pData);
NVRAMResult func_0205F9D8(u32 address, u32 size, void *pData);
NVRAMResult func_0205FA40(u32 address, u32 size, void *pData);
extern u32 BaseAddress;
extern NCFGBackupBss FormatVersionNumber;
extern u8 nvramBuf[32];
extern u8 nvramBuf2[32];


/*
 * sdk:      NCFGi_InitBackupMemory (libncfg.TWL.HYB.a backup.o)
 */
s32 func_0205F648(void)
{
    s32 result;

    if (BaseAddress != (u32)-1)
        return 0;
    NVRAMi_Init();
    result = 0;
    DC_InvalidateRange(nvramBuf, sizeof(nvramBuf));
    if (ReadNVRAM(0x1FE, sizeof(nvramBuf), nvramBuf) == 0) {
        FormatVersionNumber.FormatVersionNumber = FormatVersionNumber.nvramBuf[0];
    } else {
        result = -1;
        goto end;
    }
    DC_InvalidateRange(nvramBuf2, sizeof(nvramBuf2));
    if (ReadNVRAM(0x20, sizeof(nvramBuf2), nvramBuf2) == 0)
        BaseAddress = (FormatVersionNumber.nvramBuf2[0] << 3) - 0x400;
    else
        result = -1;
end:
    return result;
}




/*
 * sdk:      NCFG_GetFormatVersion (backup.o)
 */
unsigned char func_0205F700(void)
{
    long result;
    unsigned char version;

    result = func_0205F648();
    if (result != 0) {
        return 0;
    }
    version = FormatVersionNumber.FormatVersionNumber;
    if (version == 0xFF) {
        version = 0x10;
    }
    return version;
}





/*
 * sdk:      NCFG_ReadBackupMemory (libncfg.TWL.HYB.a backup.o)
 */
s32 func_0205F72C(void *buf, u32 size, s32 index)
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
s32 func_0205F7C8(s32 index, void *buf, u32 size)
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
int func_0205F8A0(s32 index, u32 *address, u32 *size)
{
    switch (index) {
    case 0:
    case 1:
    case 2:
    case 3:
        *address = BaseAddress + index * 0x100;
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
        *address = BaseAddress - 0x600 + (index - 0x11) * 0x200;
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
NVRAMResult func_0205F970(u32 address, u32 size, void *pData)
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
NVRAMResult func_0205F9D8(u32 address, u32 size, void *pData)
{
    NVRAMResult nvramResult;
    s32 i;

    for (i = 0; i < 5; i++) {
        nvramResult = func_02083DC8(address, size, pData);
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
NVRAMResult func_0205FA40(u32 address, u32 size, void *pData)
{
    NVRAMResult nvramResult;
    s32 i;

    for (i = 0; i < 5; i++) {
        nvramResult = func_020840F8(address, size, pData);
        if (nvramResult != NVRAM_RESULT_BUSY)
            break;
        if (OS_IsTickAvailable() && OS_IsAlarmAvailable())
            OS_Sleep(1);
    }
    return nvramResult;
}
