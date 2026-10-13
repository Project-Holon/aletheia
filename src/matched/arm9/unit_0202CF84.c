/*
 * unit:     yes
 * function: BGWINFRM_GetFrameBuffer
 * address:  0x0202CF84
 * packet:   pkt_0202CF84
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * bgwinfrm.c window-record accessors, 0x0202CF84..0x0202D01A: tile
 * pointer, bg index, scroll pair, the two 6-bit size bitfields, the clip
 * box setter and one empty function.  Same struct Win as
 * src/matched/BGWINFRM_UpdateMove.c.  All leaves; the unit calls nothing.
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
};

u32 BGWINFRM_GetFrameBuffer(struct WinMgr *mgr, u32 idx)
{
    return mgr->wins[idx].tiles;
}

u8 BGWINFRM_GetBgFrame(struct WinMgr *mgr, u32 idx)
{
    return mgr->wins[idx].bg;
}

void BGWINFRM_GetPos(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y)
{
    if (x != 0) {
        *x = mgr->wins[idx].x;
    }
    if (y != 0) {
        *y = mgr->wins[idx].y;
    }
}

void BGWINFRM_GetSize(struct WinMgr *mgr, u32 idx, u16 *w, u16 *h)
{
    if (w != 0) {
        *w = mgr->wins[idx].w;
    }
    if (h != 0) {
        *h = mgr->wins[idx].h;
    }
}

void BGWINFRM_SetClipArea(struct WinMgr *mgr, u32 idx, s8 xmin, s8 xmax,
                   s8 ymin, s8 ymax)
{
    mgr->wins[idx].xmin = xmin;
    mgr->wins[idx].xmax = xmax;
    mgr->wins[idx].ymin = ymin;
    mgr->wins[idx].ymax = ymax;
}

void func_0202D018(void)
{
}
