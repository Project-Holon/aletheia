/*
 * function: FIELD_PLAYER_GRID_EVENT_GetHoleCoverage
 * address:  0x021C0D08
 * packet:   pkt_ov021_021C0D08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_MOVE_AddDirVector  0x02164208  thumb  ov010
 *   FLDMMDL_GetSizeWidth  0x0216D91C  thumb  ov010
 *   FLDMMDL_GetSizeDepth  0x0216D924  thumb  ov010
 *   MAP_ATTR_GetAt  0x021AB0D4  thumb  ov021
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   MAP_ATTR_IsBlocked  0x021AB11C  thumb  ov021
 *   MAP_ATTR_IsHole  0x021AB2DC  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } Vec;

struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *obj, struct VecFx32 *out);
extern void FLDMMDL_MOVE_AddDirVector(int dir, int *p, int amt);
extern u8 FLDMMDL_GetSizeWidth(int a0);
extern u8 FLDMMDL_GetSizeDepth(int a0);
extern int MAP_ATTR_GetAt(void *a, void *b);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern int MAP_ATTR_IsBlocked(u32 attr);
extern int MAP_ATTR_IsHole(u16 id);

int FIELD_PLAYER_GRID_EVENT_GetHoleCoverage(void *obj, u32 dir, void *map)
{
    Vec pos;
    Vec cur;
    int flagB;
    int flagA;
    u8 i;
    u8 m;
    u8 n;
    u8 j;
    u32 attr;
    u16 id;

    FLDMMDL_GetPos(obj, (struct VecFx32 *)&pos);
    FLDMMDL_MOVE_AddDirVector(dir, (int *)(&pos), 0x10000);
    n = FLDMMDL_GetSizeWidth((int)obj);
    m = FLDMMDL_GetSizeDepth((int)obj);
    flagB = 0;
    flagA = 0;
    for (i = 0; i < m; i++, pos.z -= 0x10000) {
        cur = pos;
        for (j = 0; j < n; j++, cur.x += 0x10000) {
            attr = MAP_ATTR_GetAt(map, &cur);
            id = MAP_ATTR_GetTerrainId(attr);
            if (MAP_ATTR_IsBlocked(attr)) {
                if (MAP_ATTR_IsHole(id) == 0)
                    return 1;
                flagA = 1;
            } else {
                flagB = 1;
            }
        }
    }
    if (flagA == 1) {
        if (flagB == 0)
            return 3;
        return 2;
    }
    return 0;
}
