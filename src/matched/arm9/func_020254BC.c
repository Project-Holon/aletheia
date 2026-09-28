/*
 * function: func_020254BC
 * address:  0x020254BC
 * packet:   pkt_020254BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02025440   0x02025440  thumb
 *   func_02025508   0x02025508  thumb
 *   func_020216D4   0x020216D4  thumb
 *
 * The wide-tile twin of func_02025470: identical body, but the tile builder
 * is func_02025440 rather than func_02025404.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020254BC.c \
 *       --func func_020254BC --addr 0x020254BC --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02025440(u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern u32 func_02025508(u32 a1, u32 a2, u32 a3);
extern void func_020216D4(u32 a0, u32 a1, u32 a2, u32 a3);

u32 func_020254BC(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6)
{
    u32 mode = 2;
    u32 p;
    u32 v;

    if (a4 != 0) {
        mode = 3;
    }
    p = func_02025440(a1, a2, a3, a4, a5, a6);
    v = func_02025508(a1, p, a4);
    func_020216D4(a0, mode, (u16)(v << 4), a5 << 5);
    return p;
}
