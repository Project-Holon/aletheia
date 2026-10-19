/*
 * function: DEMO3D_DATA_GetExitCommandList
 * address:  0x021BE9A4
 * packet:   pkt_021BE9A4
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DEMO3D_ENGINE_ClampDemoId  0x021BE79C  thumb  ov203
 *   d_021C1864  0x021C1864  data
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
extern u32 DEMO3D_ENGINE_ClampDemoId(u32 id);
extern u8 d_021C1864[];

u32 DEMO3D_DATA_GetExitCommandList(u32 id)
{
    return *(u32 *)(d_021C1864 + DEMO3D_ENGINE_ClampDemoId(id) * 0x14);
}

