/*
 * function: FLDMMDL_RAIL_GetHitBitsLocation
 * address:  0x0219E398
 * packet:   pkt_ov021_0219E398
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetMoveProcWork  0x0216D69C  thumb  ov010
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetNogridMapper  0x0216D530  thumb  ov010
 *   FIELD_RAIL_WORK_IsLocationValid  0x021B7DE0  thumb  ov021
 *   FLDMMDL_CheckStatusBitAttrGetOff  0x0216DCB4  thumb  ov010
 *   FIELD_NOGRID_MAPPER_GetAttribute  0x021BB3C4  thumb  ov021
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb  ov021
 *   FLDMMDL_RAIL_CheckHitMmdl  0x0219E498  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *FLDMMDL_GetMoveProcWork(void *p);
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern void *FLDMMDL_SysGetNogridMapper(void *p);
extern int FIELD_RAIL_WORK_IsLocationValid();
extern int FLDMMDL_CheckStatusBitAttrGetOff(void *a0);
extern u32 FIELD_NOGRID_MAPPER_GetAttribute(u8 *p, char *a1);
extern u16 MAP_ATTR_GetFlags(u32 attr);
extern int FLDMMDL_RAIL_CheckHitMmdl(u32 o, u32 k);

u32 FLDMMDL_RAIL_GetHitBitsLocation(u32 o, u32 a, char *b, u32 *out)
{
    u32 r;
    u32 **p;
    u32 v;

    r = 0;
    p = FLDMMDL_GetMoveProcWork((void *)o);
    v = (u32)FLDMMDL_SysGetNogridMapper(FLDMMDL_GetMmdlSys((void *)o));
    if (!FIELD_RAIL_WORK_IsLocationValid(*p, a)) {
        r |= 1;
    }
    if (!FIELD_RAIL_WORK_IsLocationValid(*p, b)) {
        r |= 1;
    }
    if (!FLDMMDL_CheckStatusBitAttrGetOff((void *)o)) {
        p = (u32 **)FIELD_NOGRID_MAPPER_GetAttribute((u8 *)v, b);
        if (MAP_ATTR_GetFlags((u32)p) & 1) {
            r |= 2;
        }
        if (out) {
            *out = (u32)p;
        }
    }
    if (FLDMMDL_RAIL_CheckHitMmdl(o, (u32)b)) {
        r |= 4;
    }
    return r;
}
