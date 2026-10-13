/*
 * function: FLDMMDL_RAIL_GetLocationByDir
 * address:  0x0219E664
 * packet:   pkt_ov021_0219E664
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
 *   FLDMMDL_RAIL_GetNextLocation  0x0219E2F4  thumb  ov021
 *   ZONEDATA_DirToRailKey  0x0201441C  thumb
 *   FIELD_RAIL_TryStepLocation  0x021B7CD8  thumb  ov021
 *   FIELD_RAIL_WORK_QueryStep  0x021B7E60  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *FLDMMDL_GetMmdlSys(void *);
extern void *FLDMMDL_SysGetNogridMapper(void *);
extern void *FLDMMDL_GetMoveProcWork(void *);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern void *FIELD_NOGRID_MAPPER_GetRailMan(void *);
extern void FLDMMDL_RAIL_GetNextLocation(void *o, void *out);
extern u8 ZONEDATA_DirToRailKey(int i);
extern int FIELD_RAIL_TryStepLocation(void *m, void *r, u32 key, void *out);
extern int FIELD_RAIL_WORK_QueryStep(void *c, u32 key, void *out, void *pos);

int FLDMMDL_RAIL_GetLocationByDir(void *o, u32 k, void *buf)
{
    void *h;
    u32 t;
    void **p;

    h = FIELD_NOGRID_MAPPER_GetRailMan(FLDMMDL_SysGetNogridMapper(FLDMMDL_GetMmdlSys(o)));
    t = FLDMMDL_GetDirDisp(o);
    p = FLDMMDL_GetMoveProcWork(o);
    if (t != k) {
        FLDMMDL_RAIL_GetNextLocation(o, buf);
        return FIELD_RAIL_TryStepLocation(h, buf, ZONEDATA_DirToRailKey(k), buf);
    }
    return FIELD_RAIL_WORK_QueryStep(*p, ZONEDATA_DirToRailKey(k), buf, 0);
}
