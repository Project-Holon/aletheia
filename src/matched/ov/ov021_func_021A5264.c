/*
 * function: FIELD_PLAYER_GRID_GetStepHitFlags
 * address:  0x021A5264
 * packet:   pkt_ov021_021A5264
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowY  0x0216D854  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridX  0x021641E8  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridZ  0x021641F8  thumb  ov010
 *   FLDMMDL_MOVE_HitCheckMoveCurrent  0x02163994  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_MOVE_AddDirVector  0x02164208  thumb  ov010
 *   FLDMMDL_MOVE_GetMapAttr  0x02163E34  thumb  ov010
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   MAP_ATTR_IsHole  0x021AB2DC  thumb  ov021
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_CheckMovedPosAtMapPos  0x0216E5B0  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } VecFx32;

extern int FLDMMDL_GetGridNowX(void *);
extern int FLDMMDL_GetGridNowY(void *);
extern int FLDMMDL_GetGridNowZ(void *);
extern int FLDMMDL_MOVE_GetDirAddGridX(int a);
extern int FLDMMDL_MOVE_GetDirAddGridZ(int a);
extern int FLDMMDL_MOVE_HitCheckMoveCurrent(void *, int, int, int, u32);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *, struct VecFx32 *);
extern void FLDMMDL_MOVE_AddDirVector(int dir, int *p, int amt);
extern int FLDMMDL_MOVE_GetMapAttr(void *, VecFx32 *, int *);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern int MAP_ATTR_IsHole(u16 id);
extern void *FLDMMDL_GetMmdlSys(void *);
extern int FLDMMDL_CheckMovedPosAtMapPos(void *map, const struct VecFx32 *pos);

int FIELD_PLAYER_GRID_GetStepHitFlags(u8 *a, void *b, u32 c, int *d)
{
    VecFx32 buf;
    int s2;
    int s1;
    int r4;
    int r3;
    r4 = FLDMMDL_GetGridNowX(b);
    s1 = FLDMMDL_GetGridNowY(b);
    s2 = FLDMMDL_GetGridNowZ(b);
    r4 = (short)(r4 + FLDMMDL_MOVE_GetDirAddGridX(c));
    r3 = (short)(s2 + FLDMMDL_MOVE_GetDirAddGridZ(c));
    r4 = FLDMMDL_MOVE_HitCheckMoveCurrent(b, r4, s1, r3, c);
    FLDMMDL_GetPos(b, (struct VecFx32 *)&buf);
    FLDMMDL_MOVE_AddDirVector(c, (int *)(&buf), 0x10000);
    if (FLDMMDL_MOVE_GetMapAttr(b, &buf, d) == 0) {
        *d = -1;
    }
    if (r4 & 2) {
        if (MAP_ATTR_IsHole(MAP_ATTR_GetTerrainId(*d)) == 1) {
            if (FLDMMDL_CheckMovedPosAtMapPos(FLDMMDL_GetMmdlSys(b), (const struct VecFx32 *)(&buf)) == 1) {
                r4 &= ~2;
            }
        }
    }
    return r4;
}
