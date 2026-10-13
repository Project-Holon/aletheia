/*
 * function: FIELD_GROUND_ANIME_BindAnm
 * address:  0x021A7410
 * packet:   pkt_021A7410
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
 *   FIELD_GROUND_ANIME_AnmEntryBind  0x021A753C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Ctx;
extern u32 FIELD_GROUND_ANIME_AnmEntryBind(struct Ctx *s, u32 b, u32 c, u32 d);

int FIELD_GROUND_ANIME_BindAnm(u32 a, u32 b, u32 c, u32 d)
{
return FIELD_GROUND_ANIME_AnmEntryBind((struct Ctx *)a, b, c, d);
}

