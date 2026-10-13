/*
 * function: FIELDMAP_CTRL_HYBRID_FindGridPos
 * address:  0x021A7198
 * packet:   pkt_ov021_021A7198
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FLDMMDL_MOVE_AddDirVector  0x02164208  thumb  ov010
 *   MAP_ATTR_GetAt  0x021AB0D4  thumb  ov021
 *   MAP_ATTR_IsBlocked  0x021AB11C  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct V { u32 x, y, z; } V;

extern u32 FIELDMAP_GetG3dMapper(u8 *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *a, struct VecFx32 *b);
extern void FLDMMDL_MOVE_AddDirVector(int dir, int *p, int amt);
extern int MAP_ATTR_GetAt(void *a, void *b);
extern int MAP_ATTR_IsBlocked(u32 attr);

int FIELDMAP_CTRL_HYBRID_FindGridPos(u32 a, u32 *b, V *c, u32 d)
{
    u32 h;
    V v;
    h = FIELDMAP_GetG3dMapper((u8 *)a);
    FIELD_PLAYER_GetPos((unsigned char *)b[1], (struct VecFx32 *)c);
    v = *c;
    FLDMMDL_MOVE_AddDirVector(d, (int *)(&v), 0x10000);
    if (MAP_ATTR_IsBlocked(MAP_ATTR_GetAt((void *)h, &v)) == 0)
        return 1;
    return 0;
}
