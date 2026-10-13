/*
 * function: FIELD_GROUND_ANIME_Delete
 * address:  0x021A73C0
 * packet:   pkt_021A73C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELD_GROUND_ANIME_TexAnmSetFree  0x021A7620  thumb  ov021
 *   FIELD_GROUND_ANIME_AnmSetFree  0x021A7484  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(u32);
extern u32 FIELD_GROUND_ANIME_AnmSetFree(u32);
extern u32 FIELD_GROUND_ANIME_TexAnmSetFree(u32, u32, u32, u32);

int FIELD_GROUND_ANIME_Delete(u32 a, u32 b, u32 c, u32 d)
{
FIELD_GROUND_ANIME_TexAnmSetFree((a + 24), b, c, d);
FIELD_GROUND_ANIME_AnmSetFree((a + 8));
return func_020307B0(a);
}

