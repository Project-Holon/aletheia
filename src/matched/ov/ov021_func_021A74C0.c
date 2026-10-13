/*
 * function: FIELD_GROUND_ANIME_AnmSetUpdate
 * address:  0x021A74C0
 * packet:   pkt_ov021_021A74C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_GROUND_ANIME_AnmEntryUpdate  0x021A75BC  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELD_GROUND_ANIME_AnmEntryUpdate(u32 p, u32 t);

void FIELD_GROUND_ANIME_AnmSetUpdate(u32 *s, u32 dt)
{
    u32 i;
    s[3] += dt;
    if (s[2] != 0) {
        for (i = 0; i < s[1]; i++)
            s[3] = FIELD_GROUND_ANIME_AnmEntryUpdate(s[0] + i * 12, s[3]);
    }
}
