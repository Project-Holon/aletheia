/*
 * function: FLDMMDL_RAIL_MOVE_UpdateCurrentAttr
 * address:  0x0219D85C
 * packet:   pkt_ov021_0219D85C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_CheckStatusBitAttrGetOff  0x0216DCB4  thumb  ov010
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetNogridMapper  0x0216D530  thumb  ov010
 *   FLDMMDL_RAIL_GetNextLocation  0x0219E2F4  thumb  ov021
 *   FLDMMDL_RAIL_GetNowLocation  0x0219E334  thumb  ov021
 *   FIELD_NOGRID_MAPPER_GetAttribute  0x021BB3C4  thumb  ov021
 *   FLDMMDL_SetOldAttr  0x0216D7E0  thumb  ov010
 *   FLDMMDL_SetNowAttr  0x0216D7D8  thumb  ov010
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FLDMMDL_ClearMoveBit  0x0216D570  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
extern int FLDMMDL_CheckStatusBitAttrGetOff(void *a0);
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern void *FLDMMDL_SysGetNogridMapper(void *p);
extern void FLDMMDL_RAIL_GetNextLocation(void *o, void *out);
extern int FLDMMDL_RAIL_GetNowLocation(u32 a, u32 b);
typedef unsigned char  u8;
extern u32 FIELD_NOGRID_MAPPER_GetAttribute(u8 *p, char *a1);
extern void FLDMMDL_SetOldAttr(void *p, u32 v);
extern void FLDMMDL_SetNowAttr(void *p, u32 v);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);
extern char *FLDMMDL_ClearMoveBit(char *p, u32 v);

u32 FLDMMDL_RAIL_MOVE_UpdateCurrentAttr(u32 a)
{
    u32 v1[2];
    u32 v0[2];
    u32 r6 = -1;
    u32 r5 = -1;
    u32 t;
    if (FLDMMDL_CheckStatusBitAttrGetOff((void *)a) == 0) {
        t = (u32)FLDMMDL_SysGetNogridMapper(FLDMMDL_GetMmdlSys((void *)a));
        FLDMMDL_RAIL_GetNextLocation((void *)a, v0);
        FLDMMDL_RAIL_GetNowLocation(a, (u32)v1);
        r6 = FIELD_NOGRID_MAPPER_GetAttribute((u8 *)t, (char *)v1);
        r5 = FIELD_NOGRID_MAPPER_GetAttribute((u8 *)t, (char *)v0);
    }
    FLDMMDL_SetOldAttr((void *)a, r6);
    FLDMMDL_SetNowAttr((void *)a, r5);
    if (r5 == -1) {
        FLDMMDL_SetMoveBit((void *)a, 0x800);
        return 0;
    }
    FLDMMDL_ClearMoveBit((char *)a, 0x800);
    return 1;
}
