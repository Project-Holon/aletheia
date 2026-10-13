/*
 * function: FIELD_G3D_MAPPER_CreateGroundAnime
 * address:  0x0218DC84
 * packet:   pkt_ov021_0218DC84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gFieldG3dMapperGroundAnimeParam     0x021DD9E0  data ov021 a2
 *   g_021DD9E0     0x021DD9E0  data ov021 a2
 *   FIELD_GROUND_ANIME_Create  0x021A7360  thumb ov021
 */

typedef unsigned short u16;

extern u16 gFieldG3dMapperGroundAnimeParam[];
extern u16 g_021DD9E0[];
typedef unsigned int   u32;
struct D;
extern u32 *FIELD_GROUND_ANIME_Create(const struct D *p, u32 c, u32 heap);

void FIELD_G3D_MAPPER_CreateGroundAnime(int a, int b, const int *q, int c)
{
    int x;
    int y;

    gFieldG3dMapperGroundAnimeParam[1] = a;
    x = q[0];
    if (x == -1) {
        gFieldG3dMapperGroundAnimeParam[0] = gFieldG3dMapperGroundAnimeParam[0] & ~0xff;
    } else {
        gFieldG3dMapperGroundAnimeParam[0] = (gFieldG3dMapperGroundAnimeParam[0] & ~0xff) | 1;
        gFieldG3dMapperGroundAnimeParam[3] = x;
    }
    y = q[1];
    if (y == -1) {
        gFieldG3dMapperGroundAnimeParam[0] = gFieldG3dMapperGroundAnimeParam[0] & 0xffff00ff;
    } else {
        gFieldG3dMapperGroundAnimeParam[0] = (gFieldG3dMapperGroundAnimeParam[0] & 0xffff00ff) | 0x100;
        gFieldG3dMapperGroundAnimeParam[5] = y;
    }
    FIELD_GROUND_ANIME_Create((const struct D *)g_021DD9E0, b, (u16)c);
}
