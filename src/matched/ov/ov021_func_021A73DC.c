/*
 * function: FIELD_GROUND_ANIME_Update
 * address:  0x021A73DC
 * packet:   pkt_ov021_021A73DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_GROUND_ANIME_AnmSetUpdate  0x021A74C0  thumb
 *   FIELD_GROUND_ANIME_TexAnmSetUpdate  0x021A7654  thumb
 */

typedef unsigned int u32;

extern void FIELD_GROUND_ANIME_AnmSetUpdate(u32 *p, u32 v);
extern void FIELD_GROUND_ANIME_TexAnmSetUpdate(u32 *p, u32 v);

void FIELD_GROUND_ANIME_Update(u32 *s)
{
    u32 v;
    if (s[0] != 0) {
        v = s[1];
    } else {
        v = 0;
    }
    FIELD_GROUND_ANIME_AnmSetUpdate(s + 2, v);
    FIELD_GROUND_ANIME_TexAnmSetUpdate(s + 6, v);
}
