/*
 * function: FIELD_LIGHT_GetKeyframeSeconds
 * address:  0x021A07F8
 * packet:   pkt_ov021_021A07F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   TIMEZONE_GetZoneLightLevel  0x02011400  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern u8 TIMEZONE_GetZoneLightLevel(int row, int col);

typedef struct {
    u16 h;
    s16 m;
} Time;

int FIELD_LIGHT_GetKeyframeSeconds(u32 a, Time *t)
{
    int h = TIMEZONE_GetZoneLightLevel(a, t->h);
    return h * 3600 + t->m * 60;
}
