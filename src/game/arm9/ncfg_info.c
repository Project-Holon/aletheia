/*
 * file:     ncfg_info.c
 * unit:     yes
 * function: NCFG_ReadConfig, NCFG_CheckConfig, NCFG_CheckConfigEx, checkConfig, checkConfigEx, initPage, initPageEx, readAllSlots, readAllExSlots, writeAllSlots, writeAllExSlots
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
#define GAME_TYPES_U32_LONG
#define GAME_TYPES_S32_LONG
#include "../types.h"

#include "../sdk_ncfg.h"

#include "../sdk_math.h"

typedef struct MEMCHECK {
    NCFGConfig     config;
    MATHCRC16Table tbl;
} MEMCHECK;

typedef struct MEMCHECKEX {
    NCFGConfigEx   configEx;
    MATHCRC16Table tbl;
} MEMCHECKEX;

#include "mi_memory.h"
typedef int NVRAMResult;
#include "ncfg_backup.h"
#include "crc.h"
extern int  readAllSlots(NCFGConfig *config);
extern s32  checkConfig(NCFGConfig *config, MATHCRC16Table *tbl);
extern int  readAllExSlots(NCFGConfigEx *configEx);
extern s32  checkConfigEx(NCFGConfigEx *configEx, MATHCRC16Table *tbl);
#include "ncfg_check.h"
extern void initPage(NCFGConfig *config, int page);
extern int  writeAllSlots(NCFGConfig *config, MATHCRC16Table *tbl);
extern void initPageEx(NCFGConfigEx *configEx, int page);
extern int  writeAllExSlots(NCFGConfigEx *configEx, MATHCRC16Table *tbl);
u32 NCFG_ReadConfig(NCFGConfig *config);
s32 NCFG_CheckConfig(void *work);
s32 NCFG_CheckConfigEx(void *work);

u32 NCFG_ReadConfig(NCFGConfig *config)
{
    return readAllSlots(config) ? 0 : 0xFFFFFFFF;
}

#define NCFG_CHECKCONFIG_WORK_SIZE   0x700

#define NCFG_CHECKCONFIGEX_WORK_SIZE 0x1000

#define NCFG_RESULT_FAILURE          (-10001)

/*
 * sdk:      NCFG_CheckConfig (libncfg.TWL.HYB.a info.o)
 */
s32 NCFG_CheckConfig(void *work)
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
s32 NCFG_CheckConfigEx(void *work)
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
s32 checkConfig(NCFGConfig *config, MATHCRC16Table *tbl)
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
s32 checkConfigEx(NCFGConfigEx *configEx, MATHCRC16Table *tbl)
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
void initPage(NCFGConfig *config, int page)
{
    MIi_CpuClear16(0, &config->slot[page], sizeof(NCFGSlotInfo));
    config->slot[page].ap.setType = 0xFF;
}

/*
 * sdk:      initPageEx (libncfg.TWL.HYB.a info.o)
 */
void initPageEx(NCFGConfigEx *config, int page)
{
    MIi_CpuClear16(0, &config->slotEx[page], sizeof(NCFGSlotInfoEx));
    config->slotEx[page].ap.setType = 0xFF;
}

/*
 * sdk:      readAllSlots (libncfg.TWL.HYB.a info.o)
 */
int readAllSlots(NCFGConfig *config)
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
int readAllExSlots(NCFGConfigEx *configEx)
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
int writeAllSlots(NCFGConfig *config, MATHCRC16Table *tbl)
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
int writeAllExSlots(NCFGConfigEx *configEx, MATHCRC16Table *tbl)
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
