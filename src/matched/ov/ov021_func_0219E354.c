/*
 * function: FLDMMDL_RAIL_UpdateRailWork
 * address:  0x0219E354
 * packet:   pkt_ov021_0219E354
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetMoveProcWork  0x0216D69C  thumb  ov010
 *   FIELD_RAIL_WORK_UpdateStep  0x021B810C  thumb  ov021
 *   FLDMMDL_RAIL_StoreNowLocation  0x0219EA78  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void *FLDMMDL_GetMoveProcWork(void *p);
struct Sub;
extern void FIELD_RAIL_WORK_UpdateStep(struct Sub *o);
extern void FLDMMDL_RAIL_StoreNowLocation(u32 *p, u32 a1);

void FLDMMDL_RAIL_UpdateRailWork(u32 a)
{
    u32 *p = FLDMMDL_GetMoveProcWork((void *)a);
    FIELD_RAIL_WORK_UpdateStep((void *)*p);
    FLDMMDL_RAIL_StoreNowLocation(p, a);
}
