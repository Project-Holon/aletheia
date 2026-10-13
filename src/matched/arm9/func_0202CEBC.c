/*
 * unit:     no
 * function: BGWINFRM_PutBmpWin
 * address:  0x0202CEBC
 * packet:   pkt_0202CDD4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_WIN_GetCharOffset  0x02045768  arm
 *   BMP_WIN_GetPalette  0x02045778  arm
 *   BMP_WIN_GetWidth  0x02045738  arm
 *   BMP_WIN_GetHeight  0x02045740  arm
 *   BMP_WIN_GetPosX  0x02045758  arm
 *   BMP_WIN_GetPosY  0x02045760  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed int     s32;

struct Win {
    u16 *tiles;
    u16 w:6;
    u16 h:6;
    u16 dirty:1;
    u16 unk04_13:3;
    s8 x;
    s8 y;
    s8 dx;
    s8 dy;
    u8 bg;
    u8 frames;
    s8 xmin;
    s8 xmax;
    s8 ymin;
    s8 ymax;
};

struct WinMgr {
    struct Win *wins;
};

struct Descriptor;
extern u16 BMP_WIN_GetCharOffset(struct Descriptor *p);
extern u8 BMP_WIN_GetPalette(struct Descriptor *p);
extern u8 BMP_WIN_GetWidth(struct Descriptor *p);
extern u8 BMP_WIN_GetHeight(struct Descriptor *p);
extern u8 BMP_WIN_GetPosX(struct Descriptor *p);
extern u8 BMP_WIN_GetPosY(struct Descriptor *p);

void BGWINFRM_PutBmpWin(struct WinMgr *mgr, u32 idx, void *a)
{
    u16 *tiles = mgr->wins[idx].tiles;
    u32 stride = mgr->wins[idx].w;
    u32 row;
    u32 oy;
    u32 ox;
    u32 bits;
    u16 *dst;
    s32 ch;
    u32 base;
    s32 cw;

    base = BMP_WIN_GetCharOffset(a);
    bits = ((u32)BMP_WIN_GetPalette(a) << 0x1c) >> 0x10;
    cw = BMP_WIN_GetWidth(a);
    ch = BMP_WIN_GetHeight(a);
    ox = BMP_WIN_GetPosX(a);
    oy = BMP_WIN_GetPosY(a);
    row = 0;

    if (ch > 0) {
        dst = tiles + ox;

        do {
            s32 y = oy + row;
            s32 col;

            if (y >= mgr->wins[idx].h) {
                break;
            }
            col = 0;
            if (cw > 0) {
                u16 *line = dst + stride * y;

                do {
                    if ((s32)(ox + col) >= (s32)mgr->wins[idx].w) {
                        break;
                    }
                    line[col] = bits + (base + col);
                    col = (u16)(col + 1);
                } while (col < cw);
            }
            base = (u16)(base + cw);
            row = (u16)(row + 1);
        } while ((s32)row < ch);
    }
}
