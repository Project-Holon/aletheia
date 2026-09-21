/*
 * unit:     no
 * function: func_0202CA3C
 * address:  0x0202CA3C
 * packet:   pkt_0202CA3C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   str_020A7790   0x020A7790  data
 *
 * Initialises one 16-byte window record: allocates w*h*2 bytes of tile
 * storage from the debug allocator on the manager's own heap id, then
 * writes the two 6-bit size bitfields, the bg index, the scroll pair, the
 * dirty bit and the default clip box (0, 0x20, 0, 0x18).  Same struct Win
 * as src/matched/sub_0202CAC4.c and src/matched/func_0202CDD4.c.
 *
 * The __FILE__ pool word 0x020A7790 spells "bgwinfrm.c"
 * (layout/file_anchors.txt line 119), which names this unit's source file.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;

struct Win {
    u32 tiles;
    u16 w:6;
    u16 h:6;
    u16 dirty:1;
    u16 unk04_13:3;
    s8 x;
    s8 y;
    s8 dx;
    s8 dy;
    u8 bg;
    u8 pad_0b;
    s8 xmin;
    s8 xmax;
    s8 ymin;
    s8 ymax;
};

struct WinMgr {
    struct Win *wins;
    u32 pad_04;
    u32 heap;
};

extern void *func_02030734(u32 heap, u32 size, u32 align, const char *file,
                           u32 line);
extern const char str_020A7790[];

void func_0202CA3C(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h)
{
    struct Win *win = &mgr->wins[idx];

    win->tiles = (u32)func_02030734((u16)mgr->heap, w * h * 2, 1,
                                    str_020A7790, 0x8a);
    win->w = (u16)w;
    win->h = (u16)h;
    win->bg = (u8)bg;
    win->x = 0;
    win->y = 0;
    win->unk04_13 = 0;
    win->dirty = 1;
    win->xmin = 0;
    win->xmax = 0x20;
    win->ymin = 0;
    win->ymax = 0x18;
}
