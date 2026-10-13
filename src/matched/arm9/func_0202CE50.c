/*
 * unit:     no
 * function: BGWINFRM_ChangePalette
 * address:  0x0202CE50
 * packet:   pkt_0202CDD4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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

void BGWINFRM_ChangePalette(struct WinMgr *mgr, u32 idx, s32 x, s32 y,
                   u8 w, u8 h, u8 pal)
{
    u16 *tiles = mgr->wins[idx].tiles;
    u32 stride = mgr->wins[idx].w;
    s32 yend = y + h;
    s32 i;

    if (y < yend) {
        u32 bits = pal << 12;
        s32 xend = x + w;

        do {
            for (i = x; i < xend; i = (u16)(i + 1)) {
                tiles[y * stride + i] = (tiles[y * stride + i] & 0x0fff)
                                      | bits;
            }
            y = (u16)(y + 1);
        } while (y < yend);
    }
}
