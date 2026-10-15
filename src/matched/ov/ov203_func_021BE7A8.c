/*
 * function: DEMO3D_ENGINE_GetAnimeId
 * address:  0x021BE7A8
 * packet:   pkt_021BE7A8
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DEMO3D_ENGINE_ClampAnimeId  0x021BE79C  thumb  ov203
 *   d_021C185C  0x021C185C  data
 * closed: dropping the contested ov203 token lets the function's own region
 * pick the object; the +0010 ABS32 resolves as sole-ref/data and the file is
 * EXACT.  See docs/idioms/omitting-an-overlay-hint-can-attest-where-naming-it-cannot.md.
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 DEMO3D_ENGINE_ClampAnimeId(u32 id);
extern u8 d_021C185C[];

u32 DEMO3D_ENGINE_GetAnimeId(u32 id)
{
    return *(u32 *)(d_021C185C + DEMO3D_ENGINE_ClampAnimeId(id) * 0x14);
}

