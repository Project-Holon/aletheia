/*
 * function: SCRCMD_FLDMMDL_SetMmdlRailLocation
 * address:  0x021B21AC
 * packet:   pkt_ov021_021B21AC
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
 *   FLDMMDL_RAIL_GetRailWork  0x0219E348  thumb  ov021
 *   FIELD_RAIL_WORK_SetLineLocation  0x021B8484  thumb  ov021
 *   FIELD_RAIL_WORK_GetLocation  0x021B7DC0  thumb  ov021
 *   FLDMMDL_RAIL_SetLocation  0x0219E2C0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetMmdlSys(void *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern void *FLDMMDL_SysSearchObjId(void *map, u32 id);
extern void *FLDMMDL_RAIL_GetRailWork(void *a);
extern void FIELD_RAIL_WORK_SetLineLocation(u8 *p, u32 a, u32 b, int c);
extern void FIELD_RAIL_WORK_GetLocation(u32, void *);
extern void FLDMMDL_RAIL_SetLocation(void *a, void *r);

int SCRCMD_FLDMMDL_SetMmdlRailLocation(u32 a, u32 b)
{
    u16 buf[4];
    u32 h;
    u32 o;
    u32 x;
    u32 y;
    u32 z;

    h = (u32)FLDMMDL_SysSearchObjId(SCRCMD_WORK_GetMmdlSys((void *)b), SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b));
    x = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    y = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    z = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    o = (u32)FLDMMDL_RAIL_GetRailWork((void *)h);
    FIELD_RAIL_WORK_SetLineLocation((u8 *)o, x, y, z);
    FIELD_RAIL_WORK_GetLocation(o, buf);
    FLDMMDL_RAIL_SetLocation((void *)h, buf);
    return 0;
}
