/*
 * function: FIELD_MSGBG_ClearCursor
 * address:  0x021927FC
 * packet:   pkt_ov021_021927FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_GetWidth  0x020437DC  arm  arm9
 *   BMP_GetHeight  0x020437E4  arm  arm9
 *   BMP_FillRect  0x02043AF4  arm  arm9
 *   sCursorOffsetY     0x021D3E50  data   ov021  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Cur {
    u8 f00;
    u8 f01;
    u8 f02;
} Cur;

typedef struct Tri {
    u16 v[3];
} Tri;

extern const Tri sCursorOffsetY;

struct Bmp;
extern u16 BMP_GetWidth(const struct Bmp *bmp);
extern u16 BMP_GetHeight(const struct Bmp *bmp);
extern void BMP_FillRect(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);

void FIELD_MSGBG_ClearCursor(Cur *c, u32 win, u32 col)
{
    Tri t = sCursorOffsetY;
    u16 x;
    u16 y;

    x = BMP_GetWidth((const struct Bmp *)win) - 8;
    y = BMP_GetHeight((const struct Bmp *)win) - 8 - t.v[c->f01];
    BMP_FillRect((struct Bmp *)win, (s16)x, (s16)y, (u16)8, (u16)8, (u8)col);
    c->f00 = 0;
}
