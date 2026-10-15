/*
 * function: FIELD_GIMMICK_ROTATING_ROOM_SetExteriorHidden
 * address:  0x021F3FA8
 * packet:   pkt_ov046_021F3FA8
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DEMO3D_ENGINE_Delete  0x021BE4B4  thumb  ov203
 *   FIELD_GIMMICK_ROTATING_ROOM_SetMmdlVanish  0x021F4064  thumb  ov046
 */

typedef unsigned int u32;
extern void DEMO3D_ENGINE_Delete(char *ctx, int b, int c, u32 d);
extern void FIELD_GIMMICK_ROTATING_ROOM_SetMmdlVanish(u32, int, u32);

void FIELD_GIMMICK_ROTATING_ROOM_SetExteriorHidden(char *a, u32 b, u32 c)
{
    DEMO3D_ENGINE_Delete(a, 0, 15, c);
    DEMO3D_ENGINE_Delete(a, 0, 10, c);
    DEMO3D_ENGINE_Delete(a, 0, 11, c);
    DEMO3D_ENGINE_Delete(a, 0, 12, c);
    DEMO3D_ENGINE_Delete(a, 0, 13, c);
    DEMO3D_ENGINE_Delete(a, 0, 14, c);
    FIELD_GIMMICK_ROTATING_ROOM_SetMmdlVanish(b, 4, c);
    FIELD_GIMMICK_ROTATING_ROOM_SetMmdlVanish(b, 5, c);
    FIELD_GIMMICK_ROTATING_ROOM_SetMmdlVanish(b, 9, c);
    FIELD_GIMMICK_ROTATING_ROOM_SetMmdlVanish(b, 6, c);
}
