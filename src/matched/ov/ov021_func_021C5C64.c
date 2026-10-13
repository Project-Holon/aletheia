/*
 * function: FISHING_CheckFacingWater
 * address:  0x021C5C64
 * packet:   pkt_ov021_021C5C64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FIELD_PLAYER_GetPosInDir  0x021A3364  thumb  ov021
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb  ov021
 *   FIELD_G3D_MAPPER_QueryNearestHit  0x0218DAEC  thumb
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   MAP_ATTR_IsLongHopEdge  0x021AB2E8  thumb  ov021
 *   MAP_ATTR_IsFishableWater  0x021AB3B0  thumb
 *   FLDMMDL_MOVE_AddDirVector  0x02164208  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELDMAP_GetG3dMapper(u8 *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern void FIELD_PLAYER_GetPosInDir(u32 *a, int b, int *out);
extern u32 FIELDMAP_GetMoveKind(u8 *p);
extern int FIELD_G3D_MAPPER_QueryNearestHit(u32 a, int *b, u32 *out);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern int MAP_ATTR_IsLongHopEdge(int id);
extern int MAP_ATTR_IsFishableWater(u16 id);
extern void FLDMMDL_MOVE_AddDirVector(int dir, int *p, int amt);

int FISHING_CheckFacingWater(u32 unused, u32 a, u32 *out)
{
    int v[3];
    u32 w[4];
    void *h1;
    u32 r;
    u8 s;

    r = FIELDMAP_GetG3dMapper((u8 *)a);
    h1 = FIELDMAP_GetFieldPlayer((void *)a);
    s = FLDMMDL_GetDirDisp(FIELD_PLAYER_GetMmdl((void *)h1));
    FIELD_PLAYER_GetPosInDir(h1, s, v);
    if (FIELDMAP_GetMoveKind((u8 *)a) == 1)
        return 0;
    if (FIELD_G3D_MAPPER_QueryNearestHit(r, v, w) == 0)
        return 0;
    if (MAP_ATTR_IsLongHopEdge(MAP_ATTR_GetTerrainId(w[2])) == 1) {
        FLDMMDL_MOVE_AddDirVector(s, v, 0x10000);
        if (FIELD_G3D_MAPPER_QueryNearestHit(r, v, w) == 0)
            return 0;
    }
    if (MAP_ATTR_IsFishableWater(MAP_ATTR_GetTerrainId(w[2])) == 0)
        return 0;
    if (out != 0) {
        out[0] = v[0];
        out[1] = w[3];
        out[2] = v[2];
    }
    return 1;
}
