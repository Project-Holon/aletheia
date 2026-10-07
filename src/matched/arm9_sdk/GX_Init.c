/*
 * function: GX_Init
 * address:  0x0207D204
 * packet:   pkt_0207D204
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libgx gx.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Powers the 2D/3D engines and the LCD, initialises the GX state, takes a
 * lock ID for VRAM once, clears DISPSTAT and DISPCNT, zeroes the main BG
 * registers from BG0CNT and the sub engine's from DB_DISPCNT (by DMA when one
 * is assigned, else by CPU) and the master brightness, and resets the BG2/BG3
 * affine diagonals to 1.0.  The NDMA/DMA split is tested once for both fills.
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
 */

#include "../include/G_GXBssState.h"
#include "../include/G_GXDataState.h"

typedef unsigned short u16;
typedef unsigned long u32;
typedef long s32;
typedef int BOOL;
typedef volatile u16 vu16;
typedef volatile u32 vu32;

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

extern struct GXBssState sDispMode;
extern struct GXDataState sIsDispOn;

extern void GX_InitGXState(void);
extern s32 OS_GetLockID(void);
extern void OS_Terminate(void);
extern void MI_NDmaFill(u32 ndmaNo, void *dest, u32 data, u32 size);
extern void MIi_DmaFill32(u32 dmaNo, void *dest, u32 data, u32 size, BOOL dmaEnable);
extern void MIi_CpuClear32(u32 data, void *destp, u32 size);

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
            MI_NDmaFill(sIsDispOn.dmaId - 4, (void *)REG_BG0CNT_ADDR, 0, 0x60);
            reg_GX_MASTER_BRIGHT = 0;
            MI_NDmaFill(sIsDispOn.dmaId - 4, (void *)REG_DB_DISPCNT_ADDR, 0, 0x70);
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
