/*
 * file:     dwc_backup.c
 * unit:     yes
 * function: DWCi_BM_GetApInfo, DWCi_BM_GetApInfoEx, DWCi_BM_GetWiFiInfo, ReadSlotInfo, WriteSlotInfo, ReadSlotInfoEx, DWCi_BM_SetWiFiInfo, DWCi_BACKUPlRead, DWCi_BACKUPlWritePage, DWCi_BACKUPlSetWiFi, DWCi_BACKUPlConvMaskCidr, DWCi_BACKUPlConvMaskAddr, DWC_BACKUPlCheckIp, DWC_BACKUPlCheckAddress, writeDisable, DWCi_BACKUPlConvWifiInfo, DWCi_BACKUPlGetWifi
 * address:  0x020584E0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * sdk:      DWCi_BACKUPlConvWifiInfo (libdwcbm.TWL.HYB.a dwc_backup.o)
 * Getter for the Wi-Fi backup block (DWCi_BACKUPlGetWifi): returns the address of
 * a global.  Called twice from the ov016 scene-end function 0x021CD458.
 *
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 *   sDwcBackupWifi        0x02146A94 data
 *   NCFG_ReadBackupMemory 0x0205F72C arm
 *   DWCi_BACKUPlConvWifiInfo 0x02058904 arm
 *   MATHi_CRC16InitTableRev  0x020819FC arm
 *   ReadSlotInfo             0x020585DC arm
 *   OS_Terminate             0x02088234 arm
 *   MATH_CalcCRC16           0x02081B64 arm
 *   sDwcBackupAddress     0x02146A90 data a4
 *   g_02146A94  0x02146A94  data
 */
#define GAME_TYPES_U32_LONG
#define GAME_TYPES_S32_LONG
#include "../types.h"

#include "../sdk_dwc.h"

#include "../sdk_ncfg.h"

#include "../sdk_math.h"

typedef struct tagMEMSWI {
    NCFGSlotInfo   mem;
    u8             work[256];
    MATHCRC16Table tbl;
} MEMSWI;

#include "dwc_backup.h"

/* dwc_backup.o's statics from Address on, in their laid-out order: the object writes
 * sDwcBackupWifi[5], sDwcBackupWifi[10] and sDwcBackupWifi[11] off the .bss+0 literal while the copies take sDwcBackupWifi's own */
typedef struct {
    u32 Address;
    u8  Wifi[14];
} DWCBackupStatics;

extern int ReadSlotInfo(NCFGSlotInfo *buf, int offset, unsigned long num);
extern int ReadSlotInfoEx(NCFGSlotInfoEx *buf, int offset, unsigned long num);
#include "mi_memory.h"
#include "ncfg_backup.h"
extern u8  *DWCi_BACKUPlConvWifiInfo(const DWCWiFiInfo *info);
#include "crc.h"
#include "os_terminate_processor.h"
int DWCi_BM_GetApInfo(void *buf);
int DWCi_BM_GetApInfoEx(void *buf);
void DWCi_BM_GetWiFiInfo(DWCWiFiInfo *buf);
int WriteSlotInfo(NCFGSlotInfo *buf, int index, void *work);
int DWCi_BM_SetWiFiInfo(DWCWiFiInfo *info, void *work);
int DWCi_BACKUPlRead(void *mem);
int DWCi_BACKUPlWritePage(DWCMemMap *data, int *page, void *work);
void DWCi_BACKUPlSetWiFi(unsigned char *wifi);
u8 DWCi_BACKUPlConvMaskCidr(u8 *mask);
void DWCi_BACKUPlConvMaskAddr(int mask, unsigned char *buf);
int DWC_BACKUPlCheckIp(u8 *ip, u8 *mask);
int DWC_BACKUPlCheckAddress(unsigned char *address);
int writeDisable(void);
void *DWCi_BACKUPlGetWifi(void);
static u8 sDwcBackupWifi[14];
extern DWCBackupStatics sDwcBackupAddress;
extern char g_02146A94[];

int DWCi_BM_GetApInfo(void *buf)
{
    return ReadSlotInfo(buf, 0, 3);
}

int DWCi_BM_GetApInfoEx(void *buf)
{
    if (ReadSlotInfoEx(buf, 0, 3) != 0)
        return 1;
    return 0;
}

/*
 * sdk:      DWCi_BM_GetWiFiInfo (libdwcbm.TWL.HYB.a dwc_backup.o)
 */
void DWCi_BM_GetWiFiInfo(DWCWiFiInfo *buf)
{
    MI_CpuCopy8(&sDwcBackupWifi[0], &buf->attestedUserId, 6);
    buf->attestedUserId &= 0x7FFFFFFFFFFULL;
    MI_CpuCopy8(&sDwcBackupWifi[5], &buf->notAttestedId, 6);
    buf->notAttestedId >>= 3;
    buf->notAttestedId &= 0x7FFFFFFFFFFULL;
    MI_CpuCopy8(&sDwcBackupWifi[10], &buf->pass, 2);
    buf->pass = buf->pass >> 6;
    buf->pass &= 0x3FF;
    MI_CpuCopy8(&sDwcBackupWifi[12], &buf->randomHistory, 2);
}

/*
 * sdk:      ReadSlotInfo (libdwcbm.TWL.HYB.a dwc_backup.o)
 */
int ReadSlotInfo(NCFGSlotInfo *buf, int offset, u32 num)
{
    int i;

    for (i = offset; i < offset + num; i++) {
        if (NCFG_ReadBackupMemory(&buf[i - offset], sizeof(NCFGSlotInfo), i) == -1)
            return 0;
    }
    return 1;
}

int WriteSlotInfo(NCFGSlotInfo *buf, int index, void *work)
{
    return NCFG_WriteBackupMemory(index, buf, 256) != -1;
}

/*
 * sdk:      ReadSlotInfoEx (libdwcbm.TWL.HYB.a dwc_backup.o)
 */
int ReadSlotInfoEx(NCFGSlotInfoEx *buf, int offset, u32 num)
{
    int i;

    for (i = offset; i < offset + num; i++) {
        if (NCFG_ReadBackupMemory(&buf[i - offset], sizeof(NCFGSlotInfoEx), i + 0x11) == -1)
            return 0;
    }
    return 1;
}

/*
 * sdk:      DWCi_BM_SetWiFiInfo (libdwcbm.TWL.HYB.a dwc_backup.o)
 */
int DWCi_BM_SetWiFiInfo(DWCWiFiInfo *info, void *work)
{
    MEMSWI *wk;
    int i;

    DWCi_BACKUPlConvWifiInfo(info);
    wk = (MEMSWI *)work;
    MATHi_CRC16InitTableRev(&wk->tbl, 0xA001);
    for (i = 0; i < 2; i++) {
        if (!ReadSlotInfo(&wk->mem, i, 1)) {
            OS_Terminate();
            return 0;
        }
        MI_CpuCopy8(sDwcBackupWifi, wk->mem.wifi, sizeof(sDwcBackupWifi));
        wk->mem.crc = MATH_CalcCRC16(&wk->tbl, &wk->mem, 0xFE);
        while (!WriteSlotInfo(&wk->mem, i, wk->work))
            ;
    }
    return writeDisable() ? 1 : 0;
}

int DWCi_BACKUPlRead(void *mem)
{
    return ReadSlotInfo(mem, 0, 4);
}

/*
 * sdk:      DWCi_BACKUPlWritePage (libdwcbm.TWL.HYB.a dwc_backup.o)
 */
int DWCi_BACKUPlWritePage(DWCMemMap *data, int *page, void *work)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (page[i]) {
            while (!WriteSlotInfo(&data->page[i], i, work))
                ;
        }
    }
    return writeDisable() ? 1 : 0;
}

static unsigned char sDwcBackupWifi[14];

void DWCi_BACKUPlSetWiFi(unsigned char *wifi)
{
    MI_CpuCopy8(wifi, sDwcBackupWifi, 14);
}

/*
 * sdk:      DWCi_BACKUPlConvMaskCidr (libdwcbm.TWL.HYB.a dwc_backup.o)
 */
u8 DWCi_BACKUPlConvMaskCidr(u8 *mask)
{
    int snm;
    int i;
    int j;

    i = 0;
    snm = 0;
    for (; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            if ((mask[i] >> j) & 1)
                snm++;
        }
    }
    return (u8)snm;
}

void DWCi_BACKUPlConvMaskAddr(int mask, unsigned char *buf)
{
    int i;
    unsigned long snm = 0xffffffff ^ (0xffffffff >> mask);
    for (i = 0; i < 4; i++)
        buf[i] = (unsigned char)(snm >> (24 - i * 8));
}

/*
 * sdk:      DWC_BACKUPlCheckIp (libdwcbm.TWL.HYB.a dwc_backup.o)
 */
int DWC_BACKUPlCheckIp(u8 *ip, u8 *mask)
{
    u32 ipa;
    u32 snm;

    if (!DWC_BACKUPlCheckAddress(ip))
        return 0;
    MI_CpuCopy8(ip, &ipa, sizeof(ipa));
    MI_CpuCopy8(mask, &snm, sizeof(snm));
    return (ipa & ~snm) ? 1 : 0;
}

int DWC_BACKUPlCheckAddress(unsigned char *address)
{
    unsigned char v = *address;
    if (v == 127)
        return 0;
    if (v < 1)
        return 0;
    return v <= 223;
}

int writeDisable(void)
{
    return 1;
}

/* info is const: this DWARF drops const qualifiers (MI_CpuCopy8's srcp reads `void *`),
 * and without it the byte stores are assumed to clobber *info, which reorders the tmp stores */
u8 *DWCi_BACKUPlConvWifiInfo(const DWCWiFiInfo *info)
{
    u64 tmp;

    tmp = info->notAttestedId;
    MI_CpuCopy8(&info->attestedUserId, &sDwcBackupWifi[0], 5);
    sDwcBackupAddress.Wifi[5] = (u8)(((info->attestedUserId >> 40) & 7) | ((tmp & 0x1F) << 3));
    tmp >>= 5;
    MI_CpuCopy8(&tmp, &sDwcBackupWifi[6], 4);
    sDwcBackupAddress.Wifi[10] = (u8)(((tmp >> 32) & 0x3F) | ((info->pass & 3) << 6));
    sDwcBackupAddress.Wifi[11] = (u8)(info->pass >> 2);
    MI_CpuCopy8(&info->randomHistory, &sDwcBackupWifi[12], 2);
    return sDwcBackupWifi;
}

void *DWCi_BACKUPlGetWifi(void)
{
    return g_02146A94;
}
