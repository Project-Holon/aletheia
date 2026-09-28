/*
 * function: func_020586BC
 * address:  0x020586BC
 * packet:   pkt_020586BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_BM_SetWiFiInfo (libdwcbm.TWL.HYB.a dwc_backup.o)
 *
 * symbols:
 *   DWCi_BACKUPlConvWifiInfo 0x02058904 arm
 *   MATHi_CRC16InitTableRev  0x020819FC arm
 *   ReadSlotInfo             0x020585DC arm
 *   OS_Terminate             0x02088234 arm
 *   MI_CpuCopy8              0x02082D44 arm
 *   MATH_CalcCRC16           0x02081B64 arm
 *   WriteSlotInfo            0x02058634 arm
 *   writeDisable             0x020588FC arm
 *   Wifi                     0x02146A94 data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
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
typedef unsigned long long u64;

typedef struct tagDWCWiFiInfo {
    u64 attestedUserId;
    u64 notAttestedId;
    u16 pass;
    u16 randomHistory;
} DWCWiFiInfo;

typedef struct MATHCRC16Table {
    u16 table[256];
} MATHCRC16Table;

typedef struct tagMEMSWI {
    NCFGSlotInfo   mem;
    u8             work[256];
    MATHCRC16Table tbl;
} MEMSWI;

extern u8  *DWCi_BACKUPlConvWifiInfo(DWCWiFiInfo *info);
extern void MATHi_CRC16InitTableRev(MATHCRC16Table *table, u16 poly);
extern int  ReadSlotInfo(NCFGSlotInfo *buf, int offset, u32 num);
extern void OS_Terminate(void);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern u16  MATH_CalcCRC16(MATHCRC16Table *table, void *data, u32 dataLength);
extern int  WriteSlotInfo(NCFGSlotInfo *buf, int index, void *work);
extern int  writeDisable(void);
extern u8 Wifi[14];

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
