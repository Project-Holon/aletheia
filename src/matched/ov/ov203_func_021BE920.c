/*
 * function: DEMO3D_DATA_GetAnimId
 * address:  0x021BE920
 * packet:   pkt_021BE920
 * region:   ov203
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   DEMO3D_ENGINE_GetAnimeId  0x021BE7A8  thumb  ov203
 *
 * The width-1 bitfield must sit at bit 0 (`b0:1`), not bit 15: the original
 * extracts with the equal shift pair `lsls #0x1f / lsrs #0x1f`, so it is the
 * low bit of the halfword at +6 that is shifted by 0x1000.
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 DEMO3D_ENGINE_GetAnimeId(u32);

typedef struct {
    u16 b0 : 1;
    u16 rest : 15;
} bf_021BE920;

u32 DEMO3D_DATA_GetAnimId(u32 a)
{
    bf_021BE920 *p = (bf_021BE920 *)(DEMO3D_ENGINE_GetAnimeId(a) + 6);

    return 0x1000 >> p->b0;
}

