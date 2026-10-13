/*
 * function: FLDMMDL_RAIL_GetHitBitsDir
 * address:  0x0219E424
 * packet:   pkt_ov021_0219E424
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetNogridMapper  0x0216D530  thumb  ov010
 *   FLDMMDL_GetMoveProcWork  0x0216D69C  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FIELD_NOGRID_MAPPER_GetRailMan  0x021BB480  thumb  ov021
 *   func_021B7DC0  0x021B7DC0  thumb  ov021
 *   FIELD_RAIL_WORK_QueryStep  0x021B7E60  thumb  ov021
 *   FIELD_RAIL_TryStepLocation  0x021B7CD8  thumb  ov021
 *   FLDMMDL_RAIL_DirToRailKey  0x0219E938  thumb  ov021
 *   FLDMMDL_RAIL_GetHitBitsLocation  0x0219E398  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *FLDMMDL_GetMmdlSys(void *a0);
extern void *FLDMMDL_SysGetNogridMapper(void *p);
extern void *FLDMMDL_GetMoveProcWork(void *p);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern void *FIELD_NOGRID_MAPPER_GetRailMan(void *p);
extern void func_021B7DC0();
extern int FIELD_RAIL_WORK_QueryStep();
extern int FIELD_RAIL_TryStepLocation();
extern u32 FLDMMDL_RAIL_DirToRailKey(int a0);
extern u32 FLDMMDL_RAIL_GetHitBitsLocation(u32 o, u32 a, char *b, u32 *out);

int FLDMMDL_RAIL_GetHitBitsDir(u32 o, u32 k, u32 x)
{
    u32 v;
    u32 **p;
    u32 a[2];
    u32 b[2];
    int r;
    u32 t;

    v = (u32)FIELD_NOGRID_MAPPER_GetRailMan(FLDMMDL_SysGetNogridMapper(FLDMMDL_GetMmdlSys((void *)o)));
    p = FLDMMDL_GetMoveProcWork((void *)o);
    func_021B7DC0(*p, a);
    t = FLDMMDL_GetDirDisp((void *)o);
    if (t == k) {
        r = FIELD_RAIL_WORK_QueryStep(*p, FLDMMDL_RAIL_DirToRailKey(k), b, 0);
    } else {
        r = FIELD_RAIL_TryStepLocation(v, a, FLDMMDL_RAIL_DirToRailKey(k), b);
    }
    if (r) {
        return FLDMMDL_RAIL_GetHitBitsLocation(o, (u32)a, (char *)b, (u32 *)x);
    }
    return 1;
}
