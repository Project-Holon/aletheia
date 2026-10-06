/*
 * unit:     no
 * function: func_0202CEBC
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
 *   func_02045768  0x02045768  arm
 *   func_02045778  0x02045778  arm
 *   func_02045738  0x02045738  arm
 *   func_02045740  0x02045740  arm
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
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
extern u16 func_02045768(struct Descriptor *p);
extern u8 func_02045778(struct Descriptor *p);
extern u8 func_02045738(struct Descriptor *p);
extern u8 func_02045740(struct Descriptor *p);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);

void func_0202CEBC(struct WinMgr *mgr, u32 idx, void *a)
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

    base = func_02045768(a);
    bits = ((u32)func_02045778(a) << 0x1c) >> 0x10;
    cw = func_02045738(a);
    ch = func_02045740(a);
    ox = func_02045758(a);
    oy = func_02045760(a);
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
