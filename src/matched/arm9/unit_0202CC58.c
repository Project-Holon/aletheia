/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: BGWINFRM_ShowFrame
 * address:  0x0202CC58
 * packet:   pkt_0202C794
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_0202CB4C  0x0202CB4C  thumb
 *
 * Re-blits a window at the position it already holds: it reads the record's
 * own x/y back out and hands them to src/matched/sub_0202CB4C.c. The two
 * `ldrsb` with a register offset are the evidence that the two fields are
 * `s8` (docs/idioms/ldrsh-register-offset-is-signedness.md), which is the
 * same signedness src/matched/sub_0202CB4C.c had to give them for an
 * unrelated reason.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BGWINFRM_ShowFrame.c \
 *       --func BGWINFRM_ShowFrame --addr 0x0202CC58 --cc 1.1p1 --thumb
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
    u8 pad_08[8];
};

struct WinMgr {
    struct Win *wins;
};

extern void sub_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);

void BGWINFRM_ShowFrame(struct WinMgr *mgr, u32 idx)
{
    sub_0202CB4C(mgr, idx, mgr->wins[idx].x, mgr->wins[idx].y);
}
