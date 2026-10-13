/*
 * function: FIELD_PLAYER_CheckEncountAttr
 * address:  0x021A3504
 * packet:   pkt_ov021_021A3504
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_GetFormCode  0x021A3098  thumb  ov021
 *   MAP_ATTR_IsHopTransition  0x021AB5AC  thumb  ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
u32 FIELD_PLAYER_GetFormCode(u8 *p);
int MAP_ATTR_IsHopTransition(unsigned long a, unsigned long b);

int FIELD_PLAYER_CheckEncountAttr(u8 *a, int b, int c)
{
    int r = FIELD_PLAYER_GetFormCode(a);

    if (r == 2 || r == 3)
        return 0;
    return MAP_ATTR_IsHopTransition(b, c);
}
