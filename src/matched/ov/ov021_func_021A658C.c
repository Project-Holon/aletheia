/*
 * function: FIELD_PLAYER_NOGRID_CheckRailStep
 * address:  0x021A658C
 * packet:   pkt_ov021_021A658C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * 
 *
 * symbols:
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FIELD_PLAYER_NOGRID_GetHitBits  0x021A5B6C  thumb  ov021
 *   FIELD_PLAYER_NOGRID_CheckRailFromStand  0x021A652C  thumb  ov021
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FLDMMDL_CheckPossibleAcmd(int a0);
extern int FIELD_PLAYER_NOGRID_GetHitBits(u32 a, u32 b, u32 c, u32 d);
extern int FIELD_PLAYER_NOGRID_CheckRailFromStand(void *a, void *b, int c, int d, u16 e, int f);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern u16 MAP_ATTR_GetFlags(u32 attr);

int FIELD_PLAYER_NOGRID_CheckRailStep(void *a, void *b, int c, int d, u16 e, int f)
{
    int r;
    int loc;
    if (FLDMMDL_CheckPossibleAcmd((int)b) == 0) {
        return 0;
    }
    if (e == 9) {
        return FIELD_PLAYER_NOGRID_CheckRailFromStand(a, b, c, d, e, f);
    }
    r = FIELD_PLAYER_NOGRID_GetHitBits((u32)a, (u32)b, e, (u32)(&loc));
    if (f == 1 && r != 0 && (r & 0x10) == 0) {
        r = 0;
    }
    if (loc != -1) {
        int t;
        MAP_ATTR_GetTerrainId(loc);
        t = MAP_ATTR_GetFlags(loc);
        if (r == 0) {
            if (t & 2) {
                return 2;
            }
            if (f == 1) {
                return 2;
            }
        }
    }
    return 4;
}
