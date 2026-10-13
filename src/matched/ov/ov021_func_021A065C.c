/*
 * function: FIELD_LIGHT_IsColorFading
 * address:  0x021A065C
 * packet:   pkt_ov021_021A065C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub, filed for the ov026 lane.
 *
 * symbols:
 *   FIELD_LIGHT_IsColorFading 0x021A065C thumb ov021
 *   FIELD_LIGHT_FADE_IsActive 0x021A0CE4 thumb ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern int FIELD_LIGHT_FADE_IsActive(u16 *p);

int FIELD_LIGHT_IsColorFading(u8 *p)
{
    return FIELD_LIGHT_FADE_IsActive((u16 *)(p + 0x484));
}
