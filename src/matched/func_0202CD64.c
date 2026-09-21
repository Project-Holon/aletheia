/*
 * unit:     no
 * function: func_0202CD64
 * address:  0x0202CD64
 * packet:   pkt_0202CC70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * bgwinfrm.c.  Arms the scroll animation on one window record: stores the
 * per-frame delta pair and the frame count, sets the 3-bit unk04_13 field
 * to 1, and raises the manager's top bit at offset 6.  Same struct Win as
 * src/matched/func_0202CDD4.c, same struct WinMgr as
 * src/matched/sub_0202CB4C.c.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed int     s32;

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
    u8 frames;
    s8 xmin;
    s8 xmax;
    s8 ymin;
    s8 ymax;
};

struct WinMgr {
    struct Win *wins;
    u16 pad_04;
    u16 mode:15;
    u16 unk06_15:1;
};

void func_0202CD64(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames)
{
    struct Win *win = &mgr->wins[idx];

    win->dx = dx;
    win->dy = dy;
    win->frames = frames;
    win->unk04_13 = 1;
    mgr->unk06_15 = 1;
}
