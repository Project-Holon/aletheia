/*
 * function: FIELD_SAVEANIME_DrawFrame
 * address:  0x021D1430
 * packet:   pkt_ov021_021D1430
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_GetCharOffset  0x02045768  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Blit  0x020439A0  arm
 *   BMP_GetPixels  0x020437D4  arm
 *   BMP_GetByteSize  0x020437EC  arm
 *   BG_SYS_LoadTileData  0x02040B1C  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01509.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Bmp;
struct Descriptor;
extern u16 BMP_WIN_GetCharOffset(struct Descriptor *p);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *a);
extern void BMP_Blit(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern u32 BMP_GetByteSize(const struct Bmp *bmp);
extern void BG_SYS_LoadTileData(int index, const void *src, u32 size, u32 tile);

void FIELD_SAVEANIME_DrawFrame(u8 *p, u32 n)
{
    u32 a = BMP_WIN_GetCharOffset((struct Descriptor *)(((struct Obj01509 *)p)->f4));
    u32 b = (u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj01509 *)p)->f4);
    u32 x;
    u32 y;

    BMP_Blit((struct Bmp *)(((struct Obj01509 *)p)->f10), (struct Bmp *)b, 0, n << 5, ((struct Obj01509 *)p)->f8, ((struct Obj01509 *)p)->fA, 0x20, 0x20, 0xFFFF);
    x = (u32)BMP_GetPixels((const struct Bmp *)b);
    y = BMP_GetByteSize((const struct Bmp *)b);
    BG_SYS_LoadTileData(3, (const void *)x, y, a);
}
