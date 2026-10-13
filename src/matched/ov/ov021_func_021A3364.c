/*
 * function: FIELD_PLAYER_GetPosInDir
 * address:  0x021A3364
 * packet:   pkt_ov021_021A3364
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb  ov021
 *   FIELD_PLAYER_GetGridPosInDir  0x021A330C  thumb  ov021
 *   FLDMMDL_MOVE_GridToVectorPos  0x02164280  thumb  ov010
 *   FIELDMAP_GetNogridMapper  0x02188C5C  thumb  ov021
 *   FIELD_NOGRID_MAPPER_GetRailMan  0x021BB480  thumb  ov021
 *   FLDMMDL_RAIL_GetNextLocation  0x0219E2F4  thumb  ov021
 *   FIELD_RAIL_GetLocationPos  0x021B7D38  thumb  ov021
 *   FLDMMDL_RAIL_GetDrawOffsetByDir  0x0219E784  thumb  ov021
 *   FIELD_RAIL_GetUnitScale  0x021B7C38  thumb  ov021
 *   _ll_mul        0x0209C054  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void *FIELD_PLAYER_CORE_GetMmdl(unsigned char *p);
extern u32 FIELDMAP_GetMoveKind(u8 *p);
extern void FIELD_PLAYER_GetGridPosInDir(unsigned char **a, u32 b, s16 *c, s16 *d, s16 *e);
extern void FLDMMDL_MOVE_GridToVectorPos(int x, int y, int *p);
extern u32 FIELDMAP_GetNogridMapper(u8 *p);
extern void *FIELD_NOGRID_MAPPER_GetRailMan(void *p);
extern void FLDMMDL_RAIL_GetNextLocation(void *o, void *out);
extern void FIELD_RAIL_GetLocationPos(u32, s16 *, int *);
extern void FLDMMDL_RAIL_GetDrawOffsetByDir(u32 o, u32 idx, s16 *v);
extern int FIELD_RAIL_GetUnitScale(u8 *o);

void FIELD_PLAYER_GetPosInDir(u32 *a, int b, int *out)
{
    int v[3];
    s16 d[3];
    s16 r[4];
    s16 z;
    s16 y;
    s16 x;
    void *e;
    u32 h;
    int m;

    e = FIELD_PLAYER_CORE_GetMmdl((void *)a[1]);
    if (FIELDMAP_GetMoveKind((u8 *)a[0]) == 0) {
        FIELD_PLAYER_GetGridPosInDir((unsigned char **)a, b, &z, &y, &x);
        FLDMMDL_MOVE_GridToVectorPos(z, x, out);
        out[1] = y << 16;
        return;
    }
    h = (u32)FIELD_NOGRID_MAPPER_GetRailMan((void *)FIELDMAP_GetNogridMapper((u8 *)a[0]));
    FLDMMDL_RAIL_GetNextLocation(e, r);
    FIELD_RAIL_GetLocationPos(h, r, v);
    FLDMMDL_RAIL_GetDrawOffsetByDir((u32)e, b, d);
    m = FIELD_RAIL_GetUnitScale((u8 *)h);
    out[0] = v[0] + (int)(((long long)d[0] * m + 0x800) >> 12);
    out[1] = v[1] + (int)(((long long)d[1] * m + 0x800) >> 12);
    out[2] = v[2] + (int)(((long long)d[2] * m + 0x800) >> 12);
}
