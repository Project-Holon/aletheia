/*
 * function: FLD_SCENEAREA_LOADER_ApplyStripFullStop
 * address:  0x021ABC14
 * packet:   pkt_021ABC14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLD_SCENEAREA_LOADER_ApplyStripCameraStop  0x021ABB54  thumb  ov021
 *   FLD_SCENEAREA_LOADER_ApplyStripTarget  0x021ABC5C  thumb  ov021
 *   FLD_SCENEAREA_LOADER_ApplyStripFov  0x021ABD08  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FLD_SCENEAREA_LOADER_ApplyStripCameraStop(u32, u32, u32, u32);
extern void FLD_SCENEAREA_LOADER_ApplyStripTarget(u8 *a0, char *p, void *q);
extern u32 FLD_SCENEAREA_LOADER_ApplyStripFov(u32, u32, u32);

int FLD_SCENEAREA_LOADER_ApplyStripFullStop(u8 *a, u32 b, u32 c, u32 d)
{
FLD_SCENEAREA_LOADER_ApplyStripCameraStop((u32)a, b, c, d);
FLD_SCENEAREA_LOADER_ApplyStripTarget(a, (char *)b, (void *)c);
return FLD_SCENEAREA_LOADER_ApplyStripFov((u32)a, b, c);
}

