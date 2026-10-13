/*
 * function: FIELD_GROUND_ANIME_KeyTableGetLastKeyFrame
 * address:  0x021A7A90
 * packet:   pkt_ov021_021A7A90
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 *f0;
    u32 f4;
    u32 f8;
    u8 *fc;
    u32 f10;
    u32 f14;
} S;

u16 FIELD_GROUND_ANIME_KeyTableGetLastKeyFrame(S *s, int i)
{
    int k;
    if (i + 1 < s->f14) {
        k = *(s->fc + i + 1);
    } else {
        k = s->f10;
    }
    return *(s->f0 + k - 1);
}
