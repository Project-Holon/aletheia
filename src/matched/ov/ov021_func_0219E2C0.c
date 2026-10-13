/*
 * function: FLDMMDL_RAIL_SetLocation
 * address:  0x0219E2C0
 * packet:   pkt_ov021_0219E2C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMoveProcWork  0x0216D69C  thumb  ov010
 *   FIELD_RAIL_WORK_SetLocation  0x021B7EE4  thumb  ov021
 *   FLDMMDL_RAIL_StoreLocation  0x0219EAD8  thumb  ov021
 *   FIELD_RAIL_WORK_GetPos  0x021B8028  thumb  ov021
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void *FLDMMDL_GetMoveProcWork(void *);
extern void FIELD_RAIL_WORK_SetLocation(void *p, void *r);
extern void FLDMMDL_RAIL_StoreLocation(void *p, void *r);
extern void FIELD_RAIL_WORK_GetPos(void *p, void *out);
extern void FLDMMDL_SetPos(void *, void *);

void FLDMMDL_RAIL_SetLocation(void *a, void *r)
{
    void **p = FLDMMDL_GetMoveProcWork(a);
    u8 buf[12];
    FIELD_RAIL_WORK_SetLocation(*p, r);
    FLDMMDL_RAIL_StoreLocation(p, r);
    FIELD_RAIL_WORK_GetPos(*p, buf);
    FLDMMDL_SetPos(a, buf);
}
