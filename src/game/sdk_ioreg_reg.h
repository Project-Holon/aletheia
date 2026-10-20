#ifndef GAME_SDK_IOREG_REG_H
#define GAME_SDK_IOREG_REG_H

#include "sdk_ioreg.h"

/* Typed (volatile) hardware registers, SDK names. A DB_ prefix is the sub engine. */
#define REG_DISPCNT        (*(vu32 *)REG_DISPCNT_ADDR)
#define REG_BLDCNT         (*(vu16 *)REG_BLDCNT_ADDR)
#define REG_GXFIFO         (*(vu32 *)REG_GXFIFO_ADDR)
#define REG_MTX_MODE       (*(vu32 *)REG_MTX_MODE_ADDR)
#define REG_MTX_PUSH       (*(vu32 *)REG_MTX_PUSH_ADDR)
#define REG_MTX_POP        (*(vu32 *)REG_MTX_POP_ADDR)
#define REG_MTX_STORE      (*(vu32 *)REG_MTX_STORE_ADDR)
#define REG_MTX_RESTORE    (*(vu32 *)REG_MTX_RESTORE_ADDR)
#define REG_MTX_IDENTITY   (*(vu32 *)REG_MTX_IDENTITY_ADDR)
#define REG_MTX_SCALE      (*(vu32 *)REG_MTX_SCALE_ADDR)
#define REG_MTX_TRANS      (*(vu32 *)REG_MTX_TRANS_ADDR)
#define REG_NORMAL         (*(vu32 *)REG_NORMAL_ADDR)
#define REG_TEXCOORD       (*(vu32 *)REG_TEXCOORD_ADDR)
#define REG_VTX_16         (*(vu32 *)REG_VTX_16_ADDR)
#define REG_POLYGON_ATTR   (*(vu32 *)REG_POLYGON_ATTR_ADDR)
#define REG_DIF_AMB        (*(vu32 *)REG_DIF_AMB_ADDR)
#define REG_SPE_EMI        (*(vu32 *)REG_SPE_EMI_ADDR)
#define REG_LIGHT_COLOR    (*(vu32 *)REG_LIGHT_COLOR_ADDR)
#define REG_BEGIN_VTXS     (*(vu32 *)REG_BEGIN_VTXS_ADDR)
#define REG_END_VTXS       (*(vu32 *)REG_END_VTXS_ADDR)
#define REG_DB_DISPCNT     (*(vu32 *)REG_DB_DISPCNT_ADDR)
#define REG_DB_BLDCNT      (*(vu16 *)REG_DB_BLDCNT_ADDR)

#endif
