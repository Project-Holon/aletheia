/*
 * file:     unit_020584E0.c
 * unit:     yes
 * function: func_020584E0, func_020584F4, func_02058518, func_020585DC, func_02058634, func_02058664, func_020586BC, func_02058770, func_02058784, func_020587E0, func_020587F8, func_0205883C, func_02058868, func_020588D0
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
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 *   Wifi        0x02146A94 data
 *   NCFG_ReadBackupMemory 0x0205F72C arm
 *   DWCi_BACKUPlConvWifiInfo 0x02058904 arm
 *   MATHi_CRC16InitTableRev  0x020819FC arm
 *   ReadSlotInfo             0x020585DC arm
 *   OS_Terminate             0x02088234 arm
 *   MATH_CalcCRC16           0x02081B64 arm
 *   writeDisable             0x020588FC arm
 */
typedef unsigned char      u8;

typedef unsigned short     u16;

typedef unsigned long      u32;

typedef unsigned long long u64;

typedef struct tagDWCWiFiInfo {
    u64 attestedUserId;
    u64 notAttestedId;
    u16 pass;
    u16 randomHistory;
} DWCWiFiInfo;

typedef signed long    s32;

typedef struct NCFGApInfo {
    u8  ispId[32];
    u8  ispPass[32];
    u8  ssid[2][32];
    u8  wep[4][16];
    u8  ip[4];
    u8  gateway[4];
    u8  dns[2][4];
    u8  netmask;
    u8  wep2[4][5];
    u8  authType;
    u8  wepMode : 2;
    u8  wepNotation : 6;
    u8  setType;
    u8  ssidLength[2];
    u16 mtu;
    u8  rsv[2];
    u8  flags;
    u8  state;
} NCFGApInfo;

typedef struct NCFGSlotInfo {
    NCFGApInfo ap;
    u8  wifi[14];
    u16 crc;
} NCFGSlotInfo;

typedef struct NCFGApInfoEx {
    u8  security[0x82];
    u8  proxyMode;
    u8  proxyAuthType;
    u8  proxyHost[100];
    u16 proxyPort;
    u8  rsvEx[6];
} NCFGApInfoEx;

typedef struct NCFGSlotInfoEx {
    NCFGApInfo   ap;
    u8           wifi[14];
    u16          crc;
    NCFGApInfoEx apEx;
    u8           rsv[14];
    u16          crcEx;
} NCFGSlotInfoEx;

typedef struct NCFGConfig {
    NCFGSlotInfo slot[3];
    NCFGSlotInfo rsv;
} NCFGConfig;

typedef struct NCFGConfigEx {
    NCFGSlotInfoEx slotEx[3];
    union {
        NCFGConfig compat;
        struct {
            NCFGSlotInfo slot[3];
            NCFGSlotInfo rsv;
        };
    };
} NCFGConfigEx;

typedef struct MATHCRC16Table {
    u16 table[256];
} MATHCRC16Table;

typedef struct tagMEMSWI {
    NCFGSlotInfo   mem;
    u8             work[256];
    MATHCRC16Table tbl;
} MEMSWI;

typedef struct tagDWCMemMap {
    NCFGSlotInfo page[4];
} DWCMemMap;

extern int ReadSlotInfo(void *buf, int offset, unsigned long num);
extern int ReadSlotInfoEx(void *buf, int offset, unsigned long num);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern s32 NCFG_ReadBackupMemory(void *buf, u32 size, s32 index);
extern int NCFG_WriteBackupMemory(int index, void *buf, unsigned long size);
extern u8  *DWCi_BACKUPlConvWifiInfo(DWCWiFiInfo *info);
extern void MATHi_CRC16InitTableRev(MATHCRC16Table *table, u16 poly);
extern void OS_Terminate(void);
extern u16  MATH_CalcCRC16(MATHCRC16Table *table, void *data, u32 dataLength);
extern int  writeDisable(void);
int DWCi_BM_GetApInfo(void *buf);
int DWCi_BM_GetApInfoEx(void *buf);
void func_02058518(DWCWiFiInfo *buf);
int func_020585DC(NCFGSlotInfo *buf, int offset, u32 num);
int WriteSlotInfo(NCFGSlotInfo *buf, int index, void *work);
int func_02058664(NCFGSlotInfoEx *buf, int offset, u32 num);
int func_020586BC(DWCWiFiInfo *info, void *work);
int DWCi_BACKUPlRead(void *mem);
int func_02058784(DWCMemMap *data, int *page, void *work);
void DWCi_BACKUPlSetWiFi(unsigned char *wifi);
u8 func_020587F8(u8 *mask);
void DWCi_BACKUPlConvMaskAddr(int mask, unsigned char *buf);
int func_02058868(u8 *ip, u8 *mask);
int DWC_BACKUPlCheckAddress(unsigned char *address);
extern u8 Wifi[14];




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
void func_02058518(DWCWiFiInfo *buf)
{
    MI_CpuCopy8(&Wifi[0], &buf->attestedUserId, 6);
    buf->attestedUserId &= 0x7FFFFFFFFFFULL;
    MI_CpuCopy8(&Wifi[5], &buf->notAttestedId, 6);
    buf->notAttestedId >>= 3;
    buf->notAttestedId &= 0x7FFFFFFFFFFULL;
    MI_CpuCopy8(&Wifi[10], &buf->pass, 2);
    buf->pass = buf->pass >> 6;
    buf->pass &= 0x3FF;
    MI_CpuCopy8(&Wifi[12], &buf->randomHistory, 2);
}




/*
 * sdk:      ReadSlotInfo (libdwcbm.TWL.HYB.a dwc_backup.o)
 */
int func_020585DC(NCFGSlotInfo *buf, int offset, u32 num)
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
int func_02058664(NCFGSlotInfoEx *buf, int offset, u32 num)
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
int func_020586BC(DWCWiFiInfo *info, void *work)
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
        MI_CpuCopy8(Wifi, wk->mem.wifi, sizeof(Wifi));
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
int func_02058784(DWCMemMap *data, int *page, void *work)
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




static unsigned char Wifi[14];




void DWCi_BACKUPlSetWiFi(unsigned char *wifi)
{
    MI_CpuCopy8(wifi, Wifi, 14);
}




/*
 * sdk:      DWCi_BACKUPlConvMaskCidr (libdwcbm.TWL.HYB.a dwc_backup.o)
 */
u8 func_020587F8(u8 *mask)
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
int func_02058868(u8 *ip, u8 *mask)
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
