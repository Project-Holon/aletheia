/*
 * function: FIELD_PLAYER_CheckNotWaterForm
 * address:  0x021A3208
 * packet:   pkt_ov021_021A3208
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_GetFormCode  0x021A3098  thumb  ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
u32 FIELD_PLAYER_GetFormCode(u8 *p);

int FIELD_PLAYER_CheckNotWaterForm(u8 *a)
{
    switch (FIELD_PLAYER_GetFormCode(a)) {
    case 2:
    case 3:
        return 0;
    }
    return 1;
}
