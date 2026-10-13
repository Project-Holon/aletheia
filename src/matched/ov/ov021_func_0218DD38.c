/*
 * function: FIELD_G3D_MAPPER_FreeGroundAnimeSlot
 * address:  0x0218DD38
 * packet:   pkt_ov021_0218DD38
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_GROUND_ANIME_UnbindAnm  0x021A7418  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void FIELD_GROUND_ANIME_UnbindAnm(void *p);

void FIELD_G3D_MAPPER_FreeGroundAnimeSlot(void **a)
{
    if (*a != 0) {
        FIELD_GROUND_ANIME_UnbindAnm(*a);
        *a = 0;
    }
}
