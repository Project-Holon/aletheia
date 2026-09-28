/*
 * function: func_0205FAC0
 * address:  0x0205FAC0
 * packet:   pkt_0205FAC0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NCFG_CheckConfig (libncfg.TWL.HYB.a info.o)
 *
 * symbols:
 *   MI_CpuFill8             0x02082BCC arm
 *   NCFGi_InitBackupMemory  0x0205F648 arm
 *   MATHi_CRC16InitTableRev 0x020819FC arm
 *   readAllSlots            0x0205FFC4 arm
 *   checkConfig             0x0205FB8C arm
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

typedef struct MEMCHECK {
    NCFGConfig     config;
    MATHCRC16Table tbl;
} MEMCHECK;

typedef struct MEMCHECKEX {
    NCFGConfigEx   configEx;
    MATHCRC16Table tbl;
} MEMCHECKEX;

#define NCFG_CHECKCONFIG_WORK_SIZE   0x700
#define NCFG_CHECKCONFIGEX_WORK_SIZE 0x1000
#define NCFG_RESULT_FAILURE          (-10001)

extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern s32  NCFGi_InitBackupMemory(void);
extern void MATHi_CRC16InitTableRev(MATHCRC16Table *table, u16 poly);
extern int  readAllSlots(NCFGConfig *config);
extern s32  checkConfig(NCFGConfig *config, MATHCRC16Table *tbl);

s32 func_0205FAC0(void *work)
{
    MEMCHECK *wk;

    MI_CpuFill8(work, 0, NCFG_CHECKCONFIG_WORK_SIZE);
    if (NCFGi_InitBackupMemory() != 0)
        return NCFG_RESULT_FAILURE;
    wk = (MEMCHECK *)work;
    MATHi_CRC16InitTableRev(&wk->tbl, 0xA001);
    if (!readAllSlots(&wk->config))
        return NCFG_RESULT_FAILURE;
    return checkConfig(&wk->config, &wk->tbl);
}
