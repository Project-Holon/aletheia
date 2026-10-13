/*
 * function: FIELD_MSGBG_DrawFrameBmp
 * address:  0x021922A4
 * packet:   pkt_ov021_021922A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Nine-slice frame: loads each frame tile into an 8x8 scratch bitmap with
 * FIELD_MSGBG_LoadFrameTile and blits it over the centre, the four edges and the four
 * corners of the target bitmap.
 *
 * symbols:
 *   BMP_GetWidth  0x020437DC  arm
 *   BMP_GetHeight  0x020437E4  arm
 *   BMP_Create  0x02043678  arm
 *   BMP_Blit  0x020439A0  arm
 *   BMP_Delete  0x020437AC  arm
 *   FIELD_MSGBG_LoadFrameTile  0x02192264  thumb  ov021
 * Addresses are Black-image addresses.
 *
 * The edge loops use u16 locals truncated at their definition from the
 * CSE'd int w-1 / h-1 (spilled); the corners reuse the loop counters i
 * and j as the x/y tile positions, assigned before each tile load, so the
 * u16 truncation is scheduled ahead of the FIELD_MSGBG_LoadFrameTile call.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Bmp;
struct Obj020437AC;
extern u16 BMP_GetWidth(const struct Bmp *bmp);
extern u16 BMP_GetHeight(const struct Bmp *bmp);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u32 heap);
extern void BMP_Blit(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void BMP_Delete(struct Obj020437AC *p);
extern void FIELD_MSGBG_LoadFrameTile(u32 a, u32 b, u32 c, u32 d);

static inline void blit(u32 tmp, u32 bmp, u16 x, u16 y)
{
    BMP_Blit((struct Bmp *)tmp, (struct Bmp *)bmp, 0, 0, x * 8, y * 8, 8, 8, 0xFFFF);
}

void FIELD_MSGBG_DrawFrameBmp(u32 bmp, u32 b, u32 heap)
{
    u16 w;
    u16 j;
    u16 h;
    u16 i;
    u32 tmp;
    u16 hm1;
    u16 wm1;

    w = BMP_GetWidth((const struct Bmp *)bmp) >> 3;
    h = BMP_GetHeight((const struct Bmp *)bmp) >> 3;
    tmp = (u32)BMP_Create(1, 1, 0x20, heap);

    FIELD_MSGBG_LoadFrameTile(tmp, b, heap, 9);
    for (j = 0; j < h; j++)
        for (i = 0; i < w; i++)
            blit(tmp, bmp, i, j);

    FIELD_MSGBG_LoadFrameTile(tmp, b, heap, 1);
    for (i = 0; i < w; i++)
        blit(tmp, bmp, i, 0);

    FIELD_MSGBG_LoadFrameTile(tmp, b, heap, 0x11);
    hm1 = h - 1;
    for (i = 0; i < w; i++)
        blit(tmp, bmp, i, hm1);

    FIELD_MSGBG_LoadFrameTile(tmp, b, heap, 8);
    for (i = 0; i < h; i++)
        blit(tmp, bmp, 0, i);

    FIELD_MSGBG_LoadFrameTile(tmp, b, heap, 0xA);
    wm1 = w - 1;
    for (i = 0; i < h; i++)
        blit(tmp, bmp, wm1, i);

    FIELD_MSGBG_LoadFrameTile(tmp, b, heap, 0);
    blit(tmp, bmp, 0, 0);
    i = w - 1;
    FIELD_MSGBG_LoadFrameTile(tmp, b, heap, 2);
    blit(tmp, bmp, i, 0);
    i = h - 1;
    FIELD_MSGBG_LoadFrameTile(tmp, b, heap, 0x10);
    blit(tmp, bmp, 0, i);
    i = w - 1;
    j = h - 1;
    FIELD_MSGBG_LoadFrameTile(tmp, b, heap, 0x12);
    blit(tmp, bmp, i, j);

    BMP_Delete((struct Obj020437AC *)tmp);
}
