/*
 * function: FIELD_PLAYER_NOGRID_ForcedSlideFaceRight
 * address:  0x021A6A8C
 * packet:   pkt_ov021_021A6A8C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_NOGRID_ForcedSlide  0x021A6908  thumb
 *   FIELD_PLAYER_NOGRID_SetFaceRight  0x021A6774  thumb
 */

typedef struct S S;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 FIELD_PLAYER_NOGRID_ForcedSlide(u8 *p, u32 a1);
extern void FIELD_PLAYER_NOGRID_SetFaceRight(void *a);

int FIELD_PLAYER_NOGRID_ForcedSlideFaceRight(S *a, int b, int c)
{
    int r = FIELD_PLAYER_NOGRID_ForcedSlide((u8 *)a, b);
    FIELD_PLAYER_NOGRID_SetFaceRight(a);
    return r;
}
