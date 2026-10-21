/*
 * function: SCRCMD_FLDMMDL_GetMmdlRailLocation
 * address:  0x021B20B0
 * packet:   pkt_ov021_021B20B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetMmdlSys  0x0215A5EC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   FLDMMDL_RAIL_GetRailWork  0x0219E348  thumb  ov021
 *   FIELD_RAIL_WORK_GetLocationParts  0x021B83FC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;
extern void *SCRCMD_WORK_GetMmdlSys(void *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern void *FLDMMDL_SysSearchObjId(void *map, u32 id);
extern unsigned short *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *FLDMMDL_RAIL_GetRailWork(void *a);
extern void FIELD_RAIL_WORK_GetLocationParts(struct Obj *o, u16 *out0, u16 *out1, u16 *out2);

int SCRCMD_FLDMMDL_GetMmdlRailLocation(u32 a, u32 b)
{
    u32 h;
    unsigned short *x;
    unsigned short *y;
    unsigned short *z;

    h = (u32)FLDMMDL_SysSearchObjId(SCRCMD_WORK_GetMmdlSys((void *)b), SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b));
    x = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    y = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    z = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    FIELD_RAIL_WORK_GetLocationParts(FLDMMDL_RAIL_GetRailWork((void *)h), x, y, z);
    return 0;
}
