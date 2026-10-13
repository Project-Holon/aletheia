/*
 * function: FLDMMDL_MOVE_HitCheckAttr
 * address:  0x02163D04
 * packet:   pkt_ov010_02163D04
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * note: 2026-10-05 wave P8 lane W8. The older draft was DIFF 6 B (row copy src/dst r2/r3 swapped).
 *   Closed by writing the inner loop init as "for (j = 0, cur = row; ...)" (copy inside the for-init,
 *   after j = 0). All other spellings of the copy stayed DIFF 6 B.
 * symbols:
 *   FLDMMDL_CheckStatusBitAttrGetOff  0x0216DCB4  thumb  ov010
 *   FLDMMDL_GetSizeWidth  0x0216D91C  thumb  ov010
 *   FLDMMDL_GetSizeDepth  0x0216D924  thumb  ov010
 *   FLDMMDL_MOVE_GetMapAttr  0x02163E34  thumb  ov010
 *   MAP_ATTR_IsBlocked  0x021AB11C  thumb  ov021
 *   FLDMMDL_GetNowAttr  0x0216D7DC  thumb  ov010
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   d_021714A0     0x021714A0  data
 *   d_02171490     0x02171490  data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef int (*AttrTest)(u16 attr);

extern int FLDMMDL_CheckStatusBitAttrGetOff(void *m);
extern u8 FLDMMDL_GetSizeWidth(int a0);
extern u8 FLDMMDL_GetSizeDepth(int a0);
extern int FLDMMDL_MOVE_GetMapAttr(void *m, VecFx32 *pos, u32 *attr);
extern int MAP_ATTR_IsBlocked(u32 attr);
extern u32 FLDMMDL_GetNowAttr(void *m);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern const AttrTest d_021714A0[];
extern const AttrTest d_02171490[];

int FLDMMDL_MOVE_HitCheckAttr(void *m, u32 kind, VecFx32 pos)
{
    int found;
    VecFx32 row;
    VecFx32 cur;
    u32 attr;
    u32 first;
    u8 i;
    u32 h;
    u8 j;
    u32 w;
    u16 a;

    if (FLDMMDL_CheckStatusBitAttrGetOff(m) == 0) {
        found = 0;
        w = FLDMMDL_GetSizeWidth((int)m);
        h = FLDMMDL_GetSizeDepth((int)m);
        row = pos;
        for (i = 0; i < h; i++, row.z -= 0x10000) {
            for (j = 0, cur = row; j < w; j++, cur.x += 0x10000) {
                if (FLDMMDL_MOVE_GetMapAttr(m, &cur, &attr) == 0)
                    return 1;
                if (MAP_ATTR_IsBlocked(attr) == 1)
                    return 1;
                if (found == 0) {
                    first = attr;
                    found = 1;
                }
            }
        }
        a = MAP_ATTR_GetTerrainId(FLDMMDL_GetNowAttr(m));
        if (d_021714A0[kind](a) == 1)
            return 1;
        if (d_02171490[kind](MAP_ATTR_GetTerrainId(first)) == 1)
            return 1;
        return 0;
    }
    return 1;
}
