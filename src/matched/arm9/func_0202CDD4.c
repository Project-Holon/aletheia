/*
 * unit:     no
 * function: func_0202CDD4
 * address:  0x0202CDD4
 * packet:   pkt_0202CDD4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202CC70  0x0202CC70  thumb
 *   sub_0202CC58   0x0202CC58  thumb
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

extern void func_0202CC70(struct WinMgr *mgr, u32 idx);
extern void sub_0202CC58(struct WinMgr *mgr, u32 idx);

u32 func_0202CDD4(struct WinMgr *mgr, u32 idx)
{
    if (mgr->wins[idx].unk04_13 == 0) {
        return 0;
    }

    func_0202CC70(mgr, idx);
    mgr->wins[idx].x = mgr->wins[idx].x + mgr->wins[idx].dx;
    mgr->wins[idx].y = mgr->wins[idx].y + mgr->wins[idx].dy;
    sub_0202CC58(mgr, idx);
    mgr->wins[idx].frames = mgr->wins[idx].frames - 1;
    if (mgr->wins[idx].frames == 0) {
        mgr->wins[idx].unk04_13 = 0;
        return 0;
    }
    return 1;
}
