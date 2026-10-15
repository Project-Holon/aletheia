/*
 * function: WF2DMAP_SCENE_CreateTextOams
 * address: 0x021DA42C
 * packet: pkt_ov129_021DA42C
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: Original calls visibly load r2/r3 and outgoing stack zero; retain those arguments despite the matched callee declaring only two.
 * symbols:
 *   WF2DMAP_SCENE_RegisterCompressedPalette 0x021DA3FC thumb ov129
 *   WF2DMAP_SCENE_CreateTextOam 0x021DA454 thumb ov129
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void WF2DMAP_SCENE_RegisterCompressedPalette(u8 *);
extern void WF2DMAP_SCENE_CreateTextOam(u8 *,int,int,int,int);
void WF2DMAP_SCENE_CreateTextOams(u8 *p) { int zero; WF2DMAP_SCENE_RegisterCompressedPalette(p); zero=0; WF2DMAP_SCENE_CreateTextOam(p,0,78,165,zero); WF2DMAP_SCENE_CreateTextOam(p,1,172,165,zero); }
