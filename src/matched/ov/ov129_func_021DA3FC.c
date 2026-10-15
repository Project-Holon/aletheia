/*
 * function: WF2DMAP_SCENE_RegisterCompressedPalette
 * address: 0x021DA3FC
 * packet: pkt_ov129_021DA3FC
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * trailing: Two zero alignment bytes.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj23118.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void *func_020490F4(u32 id, u32 heap);
extern int CLACT_RegisterPaletteCompressed(void *,u32,u32,u32,u16);
extern void ARC_TOOL_DeleteHandle(void *);
void WF2DMAP_SCENE_RegisterCompressedPalette(u8 *p) { void *f; f=func_020490F4(23,50); ((struct Obj23118 *)p)->f30C=CLACT_RegisterPaletteCompressed(f,5,0,128,50); ARC_TOOL_DeleteHandle(f); }
