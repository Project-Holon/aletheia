/*
 * function: FIELD_EVENT_CHECK_CheckTileMoveTask
 * address:  0x0218AD28
 * packet:   pkt_ov021_0218AD28
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Looks up the tile attribute under the position and starts the matching tile
 * task (FIELD_TILE_MOVE_StartSpinTask or FIELD_TILE_MOVE_StartSlideTask); returns the task or 0.
 *
 * symbols:
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb
 *   MAP_ATTR_GetAt  0x021AB0D4  thumb
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb
 *   FIELD_TILE_MOVE_IsSpinTile  0x021C8A74  thumb
 *   FIELD_TILE_MOVE_StartSpinTask  0x021C8A30  thumb
 *   FIELD_TILE_MOVE_IsSlideTile  0x021C8CF0  thumb
 *   FIELD_TILE_MOVE_StartSlideTask  0x021C8C88  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct FieldCtx {
    u16 f0;
    u16 pad02;
    void *f4;
    void *f8;
    void *fC;
    u16 f10;
    char pad12[0x06];
    void *f18;
    char pad1C[0x20];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
};

struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern u32 FIELDMAP_GetG3dMapper(u8 *p);
extern int MAP_ATTR_GetAt(void *a, void *b);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern int FIELD_TILE_MOVE_IsSpinTile(u32 a);
struct Obj00020;
extern void *FIELD_TILE_MOVE_StartSpinTask(u32 prio, void *sys, struct Obj00020 *owner);
extern int FIELD_TILE_MOVE_IsSlideTile(u32 a);
extern void *FIELD_TILE_MOVE_StartSlideTask(u32 prio, void *sys, struct Obj00020 *owner);

void *FIELD_EVENT_CHECK_CheckTileMoveTask(struct FieldCtx *p, struct Obj00020 *pos)
{
    int buf[3];
    u16 attr;

    FIELD_PLAYER_GetPos(p->f18, (struct VecFx32 *)buf);
    attr = MAP_ATTR_GetTerrainId(MAP_ATTR_GetAt((void *)FIELDMAP_GetG3dMapper((u8 *)pos), buf));
    if (FIELD_TILE_MOVE_IsSpinTile(attr))
        return FIELD_TILE_MOVE_StartSpinTask(0, p->f4, pos);
    if (FIELD_TILE_MOVE_IsSlideTile(attr))
        return FIELD_TILE_MOVE_StartSlideTask(0, p->f4, pos);
    return 0;
}
