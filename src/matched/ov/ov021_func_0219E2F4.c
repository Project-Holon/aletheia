/*
 * function: FLDMMDL_RAIL_GetNextLocation
 * address:  0x0219E2F4
 * packet:   pkt_ov021_0219E2F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   FLDMMDL_SysGetNogridMapper  0x0216D530  thumb  ov010
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_GetMoveProcWork  0x0216D69C  thumb  ov010
 *   FIELD_RAIL_WORK_GetLocation  0x021B7DC0  thumb
 *   FIELD_RAIL_WORK_QueryStep  0x021B7E60  thumb
 *   FIELD_RAIL_WORK_GetLastKey  0x021B8038  thumb
 *   FIELD_RAIL_WORK_IsMoving  0x021B8040  thumb
 *   FIELD_NOGRID_MAPPER_GetRailMan  0x021BB480  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void *FLDMMDL_GetMmdlSys(void *o);
extern void *FLDMMDL_SysGetNogridMapper(void *p);
extern void *FIELD_NOGRID_MAPPER_GetRailMan(void *p);
extern void *FLDMMDL_GetMoveProcWork(void *p);
extern u8 FIELD_RAIL_WORK_IsMoving(u8 *p);
extern u8 FIELD_RAIL_WORK_GetLastKey(u8 *p);
extern void FIELD_RAIL_WORK_QueryStep(void *p, u32 a, void *out, u32 b);
extern void FIELD_RAIL_WORK_GetLocation(void *p, void *out);

void FLDMMDL_RAIL_GetNextLocation(void *o, void *out)
{
    void **h;

    FIELD_NOGRID_MAPPER_GetRailMan(FLDMMDL_SysGetNogridMapper(FLDMMDL_GetMmdlSys(o)));
    h = FLDMMDL_GetMoveProcWork(o);
    if (FIELD_RAIL_WORK_IsMoving(*h))
        FIELD_RAIL_WORK_QueryStep(*h, FIELD_RAIL_WORK_GetLastKey(*h), out, 0);
    else
        FIELD_RAIL_WORK_GetLocation(*h, out);
}
