/*
 * file:     dwc_bm_init.c
 * function: DWC_BM_Init
 * address:  0x020589D0
 * packet:   pkt_020589D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_BM_Init (libdwcbm.TWL.HYB.a dwc_bm_init.o)
 *
 * symbols:
 *   MI_CpuFill8          0x02082BCC arm
 *   OS_IsRunOnTwl        0x02085D3C arm
 *   NCFG_CheckConfigEx   0x0205FB1C arm
 *   NCFG_CheckConfig     0x0205FAC0 arm
 *   DWCi_BACKUPlRead     0x02058770 arm
 *   DWCi_BACKUPlSetWiFi  0x020587E0 arm
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

typedef struct MATHCRC16Table {
    u16 table[256];
} MATHCRC16Table;

typedef struct tagDWCMemMap {
    NCFGSlotInfo page[4];
} DWCMemMap;

typedef struct tagMEMINIT {
    DWCMemMap      mm;
    u8             work[256];
    MATHCRC16Table tbl;
} MEMINIT;

#define DWC_INIT_WORK_SIZE 0x1000

extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern int  OS_IsRunOnTwl(void);
extern s32  NCFG_CheckConfigEx(void *work);
extern s32  NCFG_CheckConfig(void *work);
extern int  DWCi_BACKUPlRead(void *mem);
extern void DWCi_BACKUPlSetWiFi(u8 *wifi);

int DWC_BM_Init(void *work)
{
    s32 ret;
    MEMINIT *wk;

    MI_CpuFill8(work, 0, DWC_INIT_WORK_SIZE);
    if (OS_IsRunOnTwl())
        ret = NCFG_CheckConfigEx(work);
    else
        ret = NCFG_CheckConfig(work);
    MI_CpuFill8(work, 0, DWC_INIT_WORK_SIZE);
    wk = (MEMINIT *)work;
    if (!DWCi_BACKUPlRead(&wk->mm))
        return -10001;
    DWCi_BACKUPlSetWiFi(wk->mm.page[0].wifi);
    return ret;
}
