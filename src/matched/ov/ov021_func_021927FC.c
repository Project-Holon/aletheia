/*
 * function: func_021927FC
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
 *   func_020437DC  0x020437DC  arm  arm9
 *   func_020437E4  0x020437E4  arm  arm9
 *   func_02043AF4  0x02043AF4  arm  arm9
 *   d_021D3E50     0x021D3E50  data   ov021  a1
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

extern const Tri d_021D3E50;

struct Bmp;
extern u16 func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);

void func_021927FC(Cur *c, u32 win, u32 col)
{
    Tri t = d_021D3E50;
    u16 x;
    u16 y;

    x = func_020437DC((const struct Bmp *)win) - 8;
    y = func_020437E4((const struct Bmp *)win) - 8 - t.v[c->f01];
    func_02043AF4((struct Bmp *)win, (s16)x, (s16)y, (u16)8, (u16)8, (u8)col);
    c->f00 = 0;
}
