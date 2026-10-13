/*
 * function: FLDMMDL_RAIL_ApplyStoredLocation
 * address:  0x0219EAEC
 * packet:   pkt_ov021_0219EAEC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_RAIL_WORK_SetLocation  0x021B7EE4  thumb  ov021
 *   FIELD_RAIL_WORK_GetPos  0x021B8028  thumb  ov021
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07482.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void FIELD_RAIL_WORK_SetLocation(void *p, void *r);
extern void FIELD_RAIL_WORK_GetPos(void *p, void *out);
extern void FLDMMDL_SetPos(u32, void *);

void FLDMMDL_RAIL_ApplyStoredLocation(u8 *p, u32 a)
{
    u8 buf[12];
    if (p[6] != 2) {
        FIELD_RAIL_WORK_SetLocation(((struct Obj07482 *)p)->f0, p + 4);
        FIELD_RAIL_WORK_GetPos(((struct Obj07482 *)p)->f0, buf);
        FLDMMDL_SetPos(a, buf);
    }
}
