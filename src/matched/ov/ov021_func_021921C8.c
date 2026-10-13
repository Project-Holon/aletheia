/*
 * function: FIELD_MSGBG_RollLines
 * address:  0x021921C8
 * packet:   pkt_ov021_021921C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_GetWidth  0x020437DC  arm  arm9
 *   BMP_GetHeight  0x020437E4  arm  arm9
 *   BMP_Blit  0x020439A0  arm  arm9
 *   BMP_Clear  0x02043B5C  arm  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

struct Bmp;
struct CharBuf;
extern u16 BMP_GetWidth(const struct Bmp *bmp);
extern u16 BMP_GetHeight(const struct Bmp *bmp);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_Blit(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u16 i);

int FIELD_MSGBG_RollLines(u32 a, u32 b, u32 c, int n, u16 col)
{
    int w;
    int h;
    int rest;

    w = BMP_GetWidth((const struct Bmp *)a);
    h = BMP_GetHeight((const struct Bmp *)a);
    BMP_Clear((struct CharBuf *)a, col);
    if (n > h)
        n = h;
    rest = h - n;
    BMP_Blit(b, a, 0, n, 0, 0, w, rest, col);
    BMP_Blit(c, a, 0, 0, 0, rest, w, n, col);
    if (n >= h) return 1;
    return 0;
}
