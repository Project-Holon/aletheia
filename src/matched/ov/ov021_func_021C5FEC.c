/*
 * function: FISHING_ShowBiteMark
 * address:  0x021C5FEC
 * packet:   pkt_ov021_021C5FEC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Switches the window to mode 2 and opens the message box.
 *
 * symbols:
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDEFF_GYOE_SetMMdl  0x021BB528  thumb  ov021
 *   FLDEFF_FISHING_SetAnimeSpeed  0x021AE01C  thumb  ov021
 */
#include "../include/Obj06080.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 FIELDMAP_GetEffect(u8 *p);
extern void FLDMMDL_SetDrawStatus(void *p, unsigned short v);
extern u32 FLDEFF_GYOE_SetMMdl(u32 a, u32 b, u32 c, u32 d);
typedef unsigned short u16;
extern void FLDEFF_FISHING_SetAnimeSpeed(u32 a, u16 v);

void FISHING_ShowBiteMark(u8 *p)
{
    u32 o = FIELDMAP_GetEffect((u8 *)(((struct Obj06080 *)p)->f8));

    FLDMMDL_SetDrawStatus((void *)(((struct Obj06080 *)p)->f1C), 2);
    ((struct Obj06080 *)p)->f2C = FLDEFF_GYOE_SetMMdl(o, ((struct Obj06080 *)p)->f1C, 0, 1);
    FLDEFF_FISHING_SetAnimeSpeed(((struct Obj06080 *)p)->f30, 1);
}
