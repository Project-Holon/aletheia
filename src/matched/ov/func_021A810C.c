/*
 * function: FIELD_GROUND_ANIME_GetPlayerPos
 * address:  0x021A810C
 * packet:   pkt_021A810C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct VecFx32;
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void FIELD_PLAYER_GetPos(u8 *p, struct VecFx32 *out);

void FIELD_GROUND_ANIME_GetPlayerPos(struct Obj00020 *p, struct VecFx32 *out)
{
    FIELD_PLAYER_GetPos((u8 *)FIELDMAP_GetFieldPlayer(p), out);
}

