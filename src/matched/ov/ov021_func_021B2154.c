/*
 * function: SCRCMD_FLDMMDL_SetPlayerRailLocation
 * address:  0x021B2154
 * packet:   pkt_ov021_021B2154
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_FLDMMDL_GetPlayerMmdl  0x021B1E74  thumb  ov021
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   FLDMMDL_RAIL_GetRailWork  0x0219E348  thumb  ov021
 *   FIELD_RAIL_WORK_SetLineLocation  0x021B8484  thumb  ov021
 *   func_021B7DC0  0x021B7DC0  thumb  ov021
 *   FLDMMDL_RAIL_SetLocation  0x0219E2C0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int SCRCMD_FLDMMDL_GetPlayerMmdl(u32 a);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern void *FLDMMDL_RAIL_GetRailWork(void *a);
extern void FIELD_RAIL_WORK_SetLineLocation(u8 *p, u32 a, u32 b, int c);
extern void func_021B7DC0(u32, void *);
extern void FLDMMDL_RAIL_SetLocation(void *a, void *r);

int SCRCMD_FLDMMDL_SetPlayerRailLocation(u32 a, u32 b)
{
    u16 buf[4];
    u32 h;
    u32 o;
    u32 x;
    u32 y;
    u32 z;

    h = SCRCMD_FLDMMDL_GetPlayerMmdl(b);
    x = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    y = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    z = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    o = (u32)FLDMMDL_RAIL_GetRailWork((void *)h);
    FIELD_RAIL_WORK_SetLineLocation((u8 *)o, x, y, z);
    func_021B7DC0(o, buf);
    FLDMMDL_RAIL_SetLocation((void *)h, buf);
    return 0;
}
