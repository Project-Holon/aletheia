/*
 * function: SCRCMD_FLDMMDL_GetPlayerRailLocation
 * address:  0x021B2070
 * packet:   pkt_ov021_021B2070
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_FLDMMDL_GetPlayerMmdl  0x021B1E74  thumb  ov021
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   FLDMMDL_RAIL_GetRailWork  0x0219E348  thumb  ov021
 *   FIELD_RAIL_WORK_GetLocationParts  0x021B83FC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int SCRCMD_FLDMMDL_GetPlayerMmdl(u32 a);
extern unsigned short *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
struct Obj;
extern void *FLDMMDL_RAIL_GetRailWork(void *a);
extern void FIELD_RAIL_WORK_GetLocationParts(struct Obj *o, u16 *out0, u16 *out1, u16 *out2);

int SCRCMD_FLDMMDL_GetPlayerRailLocation(u32 a, u32 b)
{
    u32 h;
    unsigned short *x;
    unsigned short *y;
    unsigned short *z;

    h = SCRCMD_FLDMMDL_GetPlayerMmdl(b);
    x = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    y = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    z = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    FIELD_RAIL_WORK_GetLocationParts(FLDMMDL_RAIL_GetRailWork((void *)h), x, y, z);
    return 0;
}
