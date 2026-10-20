/*
 * file:     btl_dsi_overlay.c
 * unit:     yes
 * function: BTLV_CORE_LoadDsiOverlay, BTLV_CORE_UnloadDsiOverlay
 * address:  0x021E88CC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from btl_dsi_overlay.c, btlv_core.c by tools/splitfile.py.
 *
 * symbols:
 *   OS_GetConsoleType  0x02085CBC  arm
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   gBtlvCoreDsiOverlayLoaded  0x021F6380  data
 *   ov140_id  0x0000008C  data  a1
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 */
#include "btlv_core_types.h"

#include "../arm9/os_emulator.h"

#include "../arm9/gf_overlay.h"




void BTLV_CORE_LoadDsiOverlay(void);

void BTLV_CORE_UnloadDsiOverlay(void);

extern u8 ov140_id[];

extern int gBtlvCoreDsiOverlayLoaded;

void BTLV_CORE_LoadDsiOverlay(void)
{
    if (OS_GetConsoleType() & 0x02000000) {
        GF_OVERLAY_Load((sptr)ov140_id);
        gBtlvCoreDsiOverlayLoaded = 1;
    } else {
        gBtlvCoreDsiOverlayLoaded = 0;
    }
}

void BTLV_CORE_UnloadDsiOverlay(void)
{
    if (gBtlvCoreDsiOverlayLoaded != 0) {
        GF_OVERLAY_Unload((sptr)ov140_id);
        gBtlvCoreDsiOverlayLoaded = 0;
    }
}
