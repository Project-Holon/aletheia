/*
 * function: DEMO3D_ENGINE_CreateAnimeStream
 * address:  0x021BE7BC
 * packet:   pkt_021BE7BC
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   DEMO3D_ENGINE_GetCameraRecord  0x021BE7A8  thumb  ov203
 *   ICA_ANIME_CreateStream  0x02011510  thumb  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 DEMO3D_ENGINE_GetCameraRecord(u32);
extern void *ICA_ANIME_CreateStream(u32 heap, u32 a1, u32 a2, u32 a3);

void DEMO3D_ENGINE_CreateAnimeStream(u32 a, u32 b, u32 c)
{
    u16 *t = (u16 *)DEMO3D_ENGINE_GetCameraRecord(a);

    ICA_ANIME_CreateStream(b, 0xa0, *t, c);
}

