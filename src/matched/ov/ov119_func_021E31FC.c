/*
 * function: POKETRADE_3D_UploadCubeTextures
 * address:  0x021E31FC
 * packet:   pkt_ov119_021E31FC
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKETRADE_3D_UploadTexturePages  0x021E3838  thumb  ov119
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void POKETRADE_3D_UploadTexturePages(char *p, int count);
void POKETRADE_3D_UploadCubeTextures(void *p) { POKETRADE_3D_UploadTexturePages(p, 0x19); }
