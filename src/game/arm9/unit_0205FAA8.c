/*
 * file:     unit_0205FAA8.c
 * unit:     yes
 * function: func_0205FAA8, func_0205FAC0, func_0205FB1C, func_0205FB8C, func_0205FDAC, func_0205FF6C, func_0205FF98, func_0205FFC4, func_02060040, func_02060094, func_02060140
 * address:  0x0205FAA8
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
 *   MI_CpuFill8             0x02082BCC arm
 *   NCFGi_InitBackupMemory  0x0205F648 arm
 *   MATHi_CRC16InitTableRev 0x020819FC arm
 *   readAllSlots            0x0205FFC4 arm
 *   checkConfig             0x0205FB8C arm
 *   readAllExSlots          0x02060040 arm
 *   checkConfigEx           0x0205FDAC arm
 *   MATH_CalcCRC16    0x02081B64 arm
 *   NCFGi_CheckApInfo 0x020601D4 arm
 *   initPage          0x0205FF6C arm
 *   MI_CpuCopy8       0x02082D44 arm
 *   MIi_CpuClear16    0x02082A48 arm
 *   writeAllSlots     0x02060094 arm
 *   NCFGi_CheckApInfoEx 0x02060224 arm
 *   initPageEx          0x0205FF98 arm
 *   writeAllExSlots     0x02060140 arm
 *   NCFG_ReadBackupMemory 0x0205F72C arm
 *   NCFG_WriteBackupMemory 0x0205F7C8 arm
 */
struct NCFGConfig;
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

extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern s32  NCFGi_InitBackupMemory(void);
extern void MATHi_CRC16InitTableRev(MATHCRC16Table *table, u16 poly);
extern int  readAllSlots(NCFGConfig *config);
extern s32  checkConfig(NCFGConfig *config, MATHCRC16Table *tbl);
extern int  readAllExSlots(NCFGConfigEx *configEx);
extern s32  checkConfigEx(NCFGConfigEx *configEx, MATHCRC16Table *tbl);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern void MIi_CpuClear16(u16 data, void *destp, u32 size);
extern u16  MATH_CalcCRC16(MATHCRC16Table *table, void *data, u32 dataLength);
extern int  NCFGi_CheckApInfo(NCFGApInfo *info);
extern void initPage(NCFGConfig *config, int page);
extern int  writeAllSlots(NCFGConfig *config, MATHCRC16Table *tbl);
extern int  NCFGi_CheckApInfoEx(NCFGApInfo *info, NCFGApInfoEx *infoEx);
extern void initPageEx(NCFGConfigEx *configEx, int page);
extern int  writeAllExSlots(NCFGConfigEx *configEx, MATHCRC16Table *tbl);
extern s32 NCFG_ReadBackupMemory(void *buf, u32 size, s32 index);
extern s32 NCFG_WriteBackupMemory(s32 index, void *buf, u32 size);
asm void NCFG_ReadConfig(void);
s32 func_0205FAC0(void *work);
s32 func_0205FB1C(void *work);
s32 func_0205FB8C(NCFGConfig *config, MATHCRC16Table *tbl);
s32 func_0205FDAC(NCFGConfigEx *configEx, MATHCRC16Table *tbl);
void func_0205FF6C(NCFGConfig *config, int page);
void func_0205FF98(NCFGConfigEx *config, int page);
int func_0205FFC4(NCFGConfig *config);
int func_02060040(NCFGConfigEx *configEx);
int func_02060094(NCFGConfig *config, MATHCRC16Table *tbl);
int func_02060140(NCFGConfigEx *configEx, MATHCRC16Table *tbl);


asm void NCFG_ReadConfig(void)
{
    stmfd sp!, {r3, lr}
    bl func_0205FFC4
    cmp	r0, #0
    movne	r0, #0
    mvneq	r0, #0
    ldmfd sp!, {r3, pc}
}


#define NCFG_CHECKCONFIG_WORK_SIZE   0x700

#define NCFG_CHECKCONFIGEX_WORK_SIZE 0x1000

#define NCFG_RESULT_FAILURE          (-10001)


/*
 * sdk:      NCFG_CheckConfig (libncfg.TWL.HYB.a info.o)
 */
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


#define NCFG_CHECKCONFIG_WORK_SIZE   0x700

#define NCFG_CHECKCONFIGEX_WORK_SIZE 0x1000

#define NCFG_RESULT_FAILURE          (-10001)


/*
 * sdk:      NCFG_CheckConfigEx (libncfg.TWL.HYB.a info.o)
 */
s32 func_0205FB1C(void *work)
{
    MEMCHECKEX *wk;

    MI_CpuFill8(work, 0, NCFG_CHECKCONFIGEX_WORK_SIZE);
    if (NCFGi_InitBackupMemory() != 0)
        return NCFG_RESULT_FAILURE;
    wk = (MEMCHECKEX *)work;
    MATHi_CRC16InitTableRev(&wk->tbl, 0xA001);
    if (!readAllSlots(&wk->configEx.compat))
        return NCFG_RESULT_FAILURE;
    if (!readAllExSlots(&wk->configEx))
        return NCFG_RESULT_FAILURE;
    return checkConfigEx(&wk->configEx, &wk->tbl);
}


/*
 * sdk:      checkConfig (libncfg.TWL.HYB.a info.o)
 */
s32 func_0205FB8C(NCFGConfig *config, MATHCRC16Table *tbl)
{
    int c[4];
    int i;
    int clear = 1;
    u8  prevState;
    u8  state;

    MI_CpuFill8(c, 0, sizeof(c));
    for (i = 0; i < 3; i++) {
        u16 hash = MATH_CalcCRC16(tbl, &config->slot[i], 0xFE);
        if (hash == config->slot[i].crc && NCFGi_CheckApInfo(&config->slot[i].ap))
            c[i] = 1;
    }
    {
        u16 hash = MATH_CalcCRC16(tbl, &config->rsv, 0xFE);
        if (hash == config->rsv.crc)
            c[3] = 1;
    }

    if (c[0] && c[1] && c[2] && c[3])
        return 0;

    prevState = config->slot[0].ap.state;
    if (!c[0]) {
        prevState = 0;
        initPage(config, 0);
        if (c[1]) {
            prevState = config->slot[1].ap.state;
            MI_CpuCopy8(config->slot[1].wifi, config->slot[0].wifi, sizeof(config->slot[0].wifi));
        }
    }
    if (!c[1]) {
        initPage(config, 1);
        if (c[0])
            MI_CpuCopy8(config->slot[0].wifi, config->slot[1].wifi, sizeof(config->slot[0].wifi));
    }
    if (!c[2])
        initPage(config, 2);
    if (!c[3])
        MIi_CpuClear16(0, &config->rsv, sizeof(NCFGSlotInfo));

    clear = 0;
    state = 0;
    for (i = 0; i < 3; i++) {
        if (config->slot[i].ap.setType != 0xFF)
            state |= (u8)(1 << i);
        else if (prevState & (1 << i))
            clear = 1;
    }
    config->slot[0].ap.state = state;
    config->slot[1].ap.state = state;

    if (!writeAllSlots(config, tbl))
        return -10000;
    if (!c[0] && !c[1] && !c[2])
        return 0;
    if (!c[0] && !c[1])
        return -10003;
    return clear ? -10002 : 0;
}


/*
 * sdk:      checkConfigEx (libncfg.TWL.HYB.a info.o)
 */
s32 func_0205FDAC(NCFGConfigEx *configEx, MATHCRC16Table *tbl)
{
    u8  state;
    u8  prevState;
    int clear;
    int c[3];
    int result;
    int i;

    result = checkConfig(&configEx->compat, tbl);
    MI_CpuFill8(c, 0, sizeof(c));
    for (i = 0; i < 3; i++) {
        u16 hash = MATH_CalcCRC16(tbl, &configEx->slotEx[i], 0xFE);
        u16 hashEx = MATH_CalcCRC16(tbl, &configEx->slotEx[i].apEx, 0xFE);
        if (hash == configEx->slotEx[i].crc && hashEx == configEx->slotEx[i].crcEx
            && NCFGi_CheckApInfoEx(&configEx->slotEx[i].ap, &configEx->slotEx[i].apEx))
            c[i] = 1;
    }

    if (c[0] && c[1] && c[2])
        return result;

    prevState = configEx->slotEx[0].ap.state;
    if (!c[0]) {
        initPageEx(configEx, 0);
        if (c[1])
            prevState = configEx->slotEx[1].ap.state;
        else
            prevState = 7;
    }
    if (!c[1])
        initPageEx(configEx, 1);
    if (!c[2])
        initPageEx(configEx, 2);

    clear = 0;
    state = 0;
    for (i = 0; i < 3; i++) {
        if (configEx->slotEx[i].ap.setType != 0xFF)
            state |= (u8)(1 << i);
        else if (prevState & (1 << i))
            clear = 1;
    }
    configEx->slotEx[0].ap.state = state;
    configEx->slotEx[1].ap.state = state;

    if (!writeAllExSlots(configEx, tbl))
        return -10000;
    if (!c[0] && !c[1] && !c[2])
        clear = 0;
    if (result != 0)
        return result;
    return clear ? -10002 : 0;
}


/*
 * sdk:      initPage (libncfg.TWL.HYB.a info.o)
 */
void func_0205FF6C(NCFGConfig *config, int page)
{
    MIi_CpuClear16(0, &config->slot[page], sizeof(NCFGSlotInfo));
    config->slot[page].ap.setType = 0xFF;
}


/*
 * sdk:      initPageEx (libncfg.TWL.HYB.a info.o)
 */
void func_0205FF98(NCFGConfigEx *config, int page)
{
    MIi_CpuClear16(0, &config->slotEx[page], sizeof(NCFGSlotInfoEx));
    config->slotEx[page].ap.setType = 0xFF;
}


/*
 * sdk:      readAllSlots (libncfg.TWL.HYB.a info.o)
 */
int func_0205FFC4(NCFGConfig *config)
{
    int result = 1;
    int i;

    for (i = 0; i < 3; i++) {
        result = result && NCFG_ReadBackupMemory(&config->slot[i], sizeof(NCFGSlotInfo), i) >= 0;
    }
    return result && NCFG_ReadBackupMemory(&config->rsv, sizeof(NCFGSlotInfo), 3) >= 0;
}


/*
 * sdk:      readAllExSlots (libncfg.TWL.HYB.a info.o)
 */
int func_02060040(NCFGConfigEx *configEx)
{
    int result = 1;
    int i;

    for (i = 0; i < 3; i++) {
        result = result && NCFG_ReadBackupMemory(&configEx->slotEx[i], sizeof(NCFGSlotInfoEx), i + 0x11) >= 0;
    }
    return result;
}


/*
 * sdk:      writeAllSlots (libncfg.TWL.HYB.a info.o)
 */
int func_02060094(NCFGConfig *config, MATHCRC16Table *tbl)
{
    int result = 1;
    int i;

    for (i = 0; i < 3; i++) {
        config->slot[i].crc = MATH_CalcCRC16(tbl, &config->slot[i], 0xFE);
        result = result && NCFG_WriteBackupMemory(i, &config->slot[i], sizeof(NCFGSlotInfo)) >= 0;
    }
    config->rsv.crc = MATH_CalcCRC16(tbl, &config->rsv, 0xFE);
    return result && NCFG_WriteBackupMemory(3, &config->rsv, sizeof(NCFGSlotInfo)) >= 0;
}


/*
 * sdk:      writeAllExSlots (libncfg.TWL.HYB.a info.o)
 */
int func_02060140(NCFGConfigEx *configEx, MATHCRC16Table *tbl)
{
    int result = 1;
    int i;

    for (i = 0; i < 3; i++) {
        configEx->slotEx[i].crc = MATH_CalcCRC16(tbl, &configEx->slotEx[i], 0xFE);
        configEx->slotEx[i].crcEx = MATH_CalcCRC16(tbl, &configEx->slotEx[i].apEx, 0xFE);
        result = result && NCFG_WriteBackupMemory(i + 0x11, &configEx->slotEx[i], sizeof(NCFGSlotInfoEx)) >= 0;
    }
    return result;
}
