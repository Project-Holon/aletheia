/*
 * unit:     no
 * function: BGWINFRM_IsMoving
 * address:  0x0202CE40
 * packet:   pkt_0202CE40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
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

u32 BGWINFRM_IsMoving(struct WinMgr *mgr, u32 idx)
{
    return mgr->wins[idx].unk04_13;
}
