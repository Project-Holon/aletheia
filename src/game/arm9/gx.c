/*
 * file:     gx.c
 * unit:     yes
 * function: GX_Init, GX_SetVCountEqVal, GX_HBlankIntr, GX_VBlankIntr, GX_IsDispOn, GX_DispOff, GX_DispOn, GX_SetGraphicsMode, GXS_SetGraphicsMode, GXx_SetMasterBrightness_, GXx_GetMasterBrightness_
 * address:  0x0207D204
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
 *   GX_InitGXState  0x02080CC4  arm
 *   OS_GetLockID    0x02084EB8  arm
 *   OS_Terminate    0x02088234  arm
 *   MI_NDmaFill     0x0272FB28  arm
 *   MIi_DmaFill32   0x020821C0  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 *   sDispMode       0x02150E0C  data
 *   sIsDispOn       0x020A84BC  data
 *   PMi_SetDispOffCount              0x0208c944 arm
 *   .word 0x04001000
 */
#include "../types.h"

/* gx.o's .bss statics from sDispMode on */
typedef struct {
    u16 dispMode;
    u16 lockId;
} GXBssState;

/* gx.o's .data statics from sIsDispOn on */
typedef struct {
    u16 isDispOn;
    u32 dmaId;
} GXDataState;

#include "gxstate.h"
#include "os_spinlock.h"
#include "os_terminate_processor.h"
#include "../twl/mi_ndma.h"
#include "mi_dma.h"
#include "mi_memory.h"
void GX_Init(void);
void GX_SetVCountEqVal(s32 val);
extern GXBssState sDispMode;
extern GXDataState sIsDispOn;

#define GX_DMA_NOT_USE      ((u32)-1)

#define OS_LOCK_ID_ERROR    (-3)

#define reg_GX_DISPCNT      (*(vu32 *)0x04000000)

#define reg_GX_DISPSTAT     (*(vu16 *)0x04000004)

#define REG_BG0CNT_ADDR     0x04000008

#define reg_G2_BG2PA        (*(vu16 *)0x04000020)

#define reg_G2_BG2PD        (*(vu16 *)0x04000026)

#define reg_G2_BG3PA        (*(vu16 *)0x04000030)

#define reg_G2_BG3PD        (*(vu16 *)0x04000036)

#define reg_GX_MASTER_BRIGHT (*(vu16 *)0x0400006C)

#define reg_GX_POWCNT       (*(vu16 *)0x04000304)

#define REG_DB_DISPCNT_ADDR 0x04001000

#define reg_G2S_DB_BG2PA    (*(vu16 *)0x04001020)

#define reg_G2S_DB_BG2PD    (*(vu16 *)0x04001026)

#define reg_G2S_DB_BG3PA    (*(vu16 *)0x04001030)

#define reg_G2S_DB_BG3PD    (*(vu16 *)0x04001036)
#include "pm.h"
long GX_HBlankIntr(int enable);
long GX_VBlankIntr(int enable);
u16 GX_IsDispOn(void);
void GX_DispOff(void);
void GX_DispOn(void);
void GX_SetGraphicsMode(int dispMode, int bgMode, int bg0_2d3d);
void GXS_SetGraphicsMode(u32 mode);
void GXx_SetMasterBrightness_(vu16 *reg, int brightness);
int GXx_GetMasterBrightness_(vu16 *reg);

void GX_Init(void)
{
    s32 lockResult;

    reg_GX_POWCNT |= 0x8000;
    reg_GX_POWCNT = (u16)((reg_GX_POWCNT & ~0x20e) | 0xe | 0x200);
    reg_GX_POWCNT |= 0x1;

    GX_InitGXState();

    while (sDispMode.lockId == 0) {
        lockResult = OS_GetLockID();
        if (lockResult == OS_LOCK_ID_ERROR) {
            OS_Terminate();
        }
        sDispMode.lockId = (u16)lockResult;
    }

    reg_GX_DISPSTAT = 0;
    reg_GX_DISPCNT = 0;

    if (sIsDispOn.dmaId != GX_DMA_NOT_USE) {
        if (sIsDispOn.dmaId > 3) {
            MI_NDmaFill((s32)(sIsDispOn.dmaId - 4), (s32)REG_BG0CNT_ADDR, 0, 0x60);
            reg_GX_MASTER_BRIGHT = 0;
            MI_NDmaFill((s32)(sIsDispOn.dmaId - 4), (s32)REG_DB_DISPCNT_ADDR, 0, 0x70);
        } else {
            MIi_DmaFill32(sIsDispOn.dmaId, (void *)REG_BG0CNT_ADDR, 0, 0x60, 1);
            reg_GX_MASTER_BRIGHT = 0;
            MIi_DmaFill32(sIsDispOn.dmaId, (void *)REG_DB_DISPCNT_ADDR, 0, 0x70, 1);
        }
    } else {
        MIi_CpuClear32(0, (void *)REG_BG0CNT_ADDR, 0x60);
        reg_GX_MASTER_BRIGHT = 0;
        MIi_CpuClear32(0, (void *)REG_DB_DISPCNT_ADDR, 0x70);
    }

    reg_G2_BG2PA = 0x100;
    reg_G2_BG2PD = 0x100;
    reg_G2_BG3PA = 0x100;
    reg_G2_BG3PD = 0x100;
    reg_G2S_DB_BG2PA = 0x100;
    reg_G2S_DB_BG2PD = 0x100;
    reg_G2S_DB_BG3PA = 0x100;
    reg_G2S_DB_BG3PD = 0x100;
}

/*
 * sdk:      GX_SetVCountEqVal (libgx.TWL.HYB.a gx.o)
 */
void GX_SetVCountEqVal(s32 val)
{
    reg_GX_DISPSTAT = (u16)((reg_GX_DISPSTAT & 0x3f) | ((val & 0xff) << 8) | ((val & 0x100) >> 1));
}

/*
 * sdk:      GX_HBlankIntr (gx.o)
 */
long GX_HBlankIntr(int enable)
{
    long rval = reg_GX_DISPSTAT & 0x10;

    if (enable) {
        reg_GX_DISPSTAT |= 0x10;
    } else {
        reg_GX_DISPSTAT &= ~0x10;
    }
    return rval;
}

/*
 * sdk:      GX_VBlankIntr (gx.o)
 */
long GX_VBlankIntr(int enable)
{
    long rval = reg_GX_DISPSTAT & 0x8;

    if (enable) {
        reg_GX_DISPSTAT |= 0x8;
    } else {
        reg_GX_DISPSTAT &= ~0x8;
    }
    return rval;
}

u16 GX_IsDispOn(void)
{
    return sIsDispOn.isDispOn;
}

/*
 * sdk:      GX_DispOff (gx.o)
 */
void GX_DispOff(void)
{
    unsigned long tmp = reg_GX_DISPCNT;

    sIsDispOn.isDispOn = 0;
    sDispMode.dispMode = (unsigned short)((tmp & 0x30000) >> 16);
    reg_GX_DISPCNT = tmp & ~0x30000;
    PMi_SetDispOffCount();
}

/*
 * sdk:      GX_DispOn (libgx.TWL.HYB.a gx.o)
 */
void GX_DispOn(void)
{
    sIsDispOn.isDispOn = 1;
    if (sDispMode.dispMode)
    {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x30000) | (sDispMode.dispMode << 16);
    }
    else
    {
        reg_GX_DISPCNT = reg_GX_DISPCNT | 0x10000;
    }
}

/*
 * sdk:      GX_SetGraphicsMode (libgx.TWL.HYB.a gx.o)
 */
void GX_SetGraphicsMode(int dispMode, int bgMode, int bg0_2d3d)
{
    u32 cnt = reg_GX_DISPCNT;

    sDispMode.dispMode = (u16)dispMode;
    if (!sIsDispOn.isDispOn)
    {
        dispMode = 0;
    }
    reg_GX_DISPCNT = bgMode | ((cnt & 0xFFF0FFF0) | (dispMode << 16)) | (bg0_2d3d << 3);
    if (!sDispMode.dispMode)
    {
        sIsDispOn.isDispOn = 0;
    }
}

void GXS_SetGraphicsMode(u32 mode)
{
    *(volatile u32 *)0x04001000 = (*(volatile u32 *)0x04001000 & ~7) | mode;
}

/*
 * sdk:      GXx_SetMasterBrightness_ (libgx.TWL.HYB.a gx.o)
 */
void GXx_SetMasterBrightness_(vu16 *reg, int brightness)
{
    if (brightness == 0) {
        *reg = 0;
    } else if (brightness > 0) {
        *reg = (u16)(0x4000 | brightness);
    } else {
        *reg = (u16)(0x8000 | -brightness);
    }
}

/*
 * sdk:      GXx_GetMasterBrightness_ (libgx.TWL.HYB.a gx.o)
 */
int GXx_GetMasterBrightness_(vu16 *reg)
{
    u16 mode = (u16)(*reg & 0xC000);

    if (mode == 0)
    {
        return 0;
    }
    else if (mode == 0x4000)
    {
        return *reg & 0x1F;
    }
    else if (mode == 0x8000)
    {
        return -(*reg & 0x1F);
    }
    return 0;
}
