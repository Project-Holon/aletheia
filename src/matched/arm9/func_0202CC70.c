/*
 * unit:     no
 * function: func_0202CC70
 * address:  0x0202CC70
 * packet:   pkt_0202CC70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02041300 0x02041300 arm
 *   g_020A0058    0x020A0058 data
 *
 * bgwinfrm.c.  Marks a window record dirty, rejects it when it lies wholly
 * outside its clip box (xmin..xmax, ymin..ymax), clips the origin and the
 * size against the box, then blits it through func_02041300 and runs the
 * manager's mode callback.  Same struct Win as src/matched/func_0202CD64.c.
 *
 * What closed it (wave 19): four spelling choices, all required.
 *  - xmax is a named local; the first guard and the right-edge clip read it.
 *  - sx = win->x is written before ow = w, so the sx spill store lands
 *    ahead of ow's sign extension.
 *  - sy is s8: it only ever holds win->y or win->ymin, both s8 fields, so
 *    the narrow type is value-preserving.  With s32 sy the clip copies ymin
 *    between registers; with s8 sy it reloads ymin from its spill slot, as
 *    the image does, and the call's argument stores fall into order.
 *  - Declarations with oh first and sy last.  mwcc numbers spill slots from
 *    the last declared local upward, so sx, h, y, sy must keep that relative
 *    order (slots 0x20, 0x1c, 0x18, 0x14).
 * The callee prototype is the one func_02041300's own body declares.
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
    u8 pad_08[2];
    u8 bg;
    u8 pad_0b;
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

extern void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void (*g_020A0058[])(u32);

void func_0202CC70(struct WinMgr *mgr, u32 idx)
{
    struct Win *win = &mgr->wins[idx];
    s8 oh, ow;
    s32 sx;
    s32 w, h;
    s32 x1, xmax;
    s32 y, y1;
    s8 sy;

    win->dirty = 1;
    xmax = win->xmax;
    if (win->x >= xmax) {
        return;
    }
    if (win->y >= win->ymax) {
        return;
    }
    w = win->w;
    x1 = win->x + w;
    if (x1 < win->xmin) {
        return;
    }
    h = win->h;
    sy = win->y;
    y = sy;
    y1 = y + h;
    if (y1 < win->ymin) {
        return;
    }

    sx = win->x;
    ow = w;
    if (win->x < win->xmin) {
        sx = win->xmin;
        ow = ow - (s8)(win->xmin - win->x);
    }
    if (x1 >= xmax) {
        ow = ow - (s8)(x1 - xmax);
    }

    oh = h;
    if (sy < win->ymin) {
        sy = win->ymin;
        oh = oh - (s8)(win->ymin - y);
    }
    if (y1 >= win->ymax) {
        oh = oh - (s8)(y1 - win->ymax);
    }

    func_02041300(win->bg, 0, (u8)sx, (u8)sy, (u8)ow, (u8)oh, 0x10);
    g_020A0058[mgr->mode](win->bg);
}
