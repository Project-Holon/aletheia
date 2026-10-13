/*
 * function: FIELD_PLAYER_NOGRID_CheckSlowStep
 * address:  0x021A60DC
 * packet:   pkt_ov021_021A60DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Same body as ov021_func_021A5D04 with FIELD_PLAYER_NOGRID_CheckSlowFromStand as the e == 9 path.
 *
 * symbols:
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FIELD_PLAYER_NOGRID_CheckSlowFromStand  0x021A607C  thumb  ov021
 *   FIELD_PLAYER_NOGRID_GetHitBits  0x021A5B6C  thumb  ov021
 *   FLDMMDL_RAIL_GetLocationByDir  0x0219E664  thumb  ov021
 *   FLDMMDL_RAIL_MOVE_GetLocationAttr  0x0219D724  thumb  ov021
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb  ov021
 *   MAP_ATTR_IsLedgeNorth  0x021AB158  thumb  ov021
 *   MAP_ATTR_IsLedgeSouth  0x021AB164  thumb  ov021
 *   MAP_ATTR_IsLedgeWest  0x021AB170  thumb  ov021
 *   MAP_ATTR_IsLedgeEast  0x021AB17C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FLDMMDL_CheckPossibleAcmd(int a0);
extern int FIELD_PLAYER_NOGRID_CheckSlowFromStand(void *a, void *b, int c, int d, int e, int f);
extern int FIELD_PLAYER_NOGRID_GetHitBits(u32 a, u32 b, u32 c, u32 d);
extern int FLDMMDL_RAIL_GetLocationByDir(void *o, u32 k, void *buf);
extern int FLDMMDL_RAIL_MOVE_GetLocationAttr(u32 a, char *b);
extern u16 MAP_ATTR_GetTerrainId(u32);
extern u16 MAP_ATTR_GetFlags(u32 attr);
extern int MAP_ATTR_IsLedgeNorth(u16);
extern int MAP_ATTR_IsLedgeSouth(u16);
extern int MAP_ATTR_IsLedgeWest(u16);
extern int MAP_ATTR_IsLedgeEast(u16);

int FIELD_PLAYER_NOGRID_CheckSlowStep(void *a, void *b, int c, int d, int e, int f)
{
    u8 buf[8];
    u32 r;
    u32 t;
    u16 k;
    int cls;

    if (FLDMMDL_CheckPossibleAcmd((int)b) == 0) {
        return 0;
    }
    if (e == 9) {
        return FIELD_PLAYER_NOGRID_CheckSlowFromStand(a, b, c, d, e, f);
    }
    r = FIELD_PLAYER_NOGRID_GetHitBits((u32)a, (u32)b, e, 0);
    if (f == 1 && (r & 2)) {
        r = 0;
    }
    if (r == 0) {
        return 2;
    }
    if (r & 2) {
        FLDMMDL_RAIL_GetLocationByDir(b, e, buf);
        t = FLDMMDL_RAIL_MOVE_GetLocationAttr((u32)b, (char *)buf);
        cls = 9;
        k = MAP_ATTR_GetTerrainId(t);
        MAP_ATTR_GetFlags(t);
        if (MAP_ATTR_IsLedgeNorth(k)) {
            cls = 0;
        } else if (MAP_ATTR_IsLedgeSouth(k)) {
            cls = 1;
        } else if (MAP_ATTR_IsLedgeWest(k)) {
            cls = 2;
        } else if (MAP_ATTR_IsLedgeEast(k)) {
            cls = 3;
        }
        if (cls != 9 && cls == e) {
            return 5;
        }
    }
    return 4;
}
