/*
 * function: func_02025470
 * address:  0x02025470
 * packet:   pkt_02025470
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02025404   0x02025404  thumb
 *   func_02025508   0x02025508  thumb
 *   func_020216D4   0x020216D4  thumb
 *
 * Create one map tile: a4's flag word picks the 3-versus-2 mode, the tile is
 * built by func_02025404 over (a1, a2, a3, a4, a5, a6), its width comes back
 * from func_02025508 packed into the low half of a5's shifted word and the
 * tile is handed to func_020216D4 with a5 shifted up five.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02025470.c \
 *       --func func_02025470 --addr 0x02025470 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef signed int     s32;
extern s32 func_02025404(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
extern unsigned int func_02025508(int a0, int a1, int a2);
struct PalAnmSlot;
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);

u32 func_02025470(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6)
{
    u32 mode = 2;
    u32 p;
    u32 v;

    if (a4 != 0) {
        mode = 3;
    }
    p = func_02025404(a1, a2, a3, a4, a5, a6);
    v = func_02025508(a1, p, a4);
    func_020216D4((struct PalAnmSlot *)a0, mode, (u16)(v << 4), a5 << 5);
    return p;
}
