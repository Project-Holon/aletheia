/*
 * function: func_0216EE20
 * address:  0x0216EE20
 * packet:   pkt_ov010_0216EE20
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Dispatches through the two-column handler table d_021725C0, row chosen
 * by func_0216EDFC's classification of `id`.
 *
 * symbols:
 *   func_0216EDFC  0x0216EDFC  thumb  ov010
 *   d_021725C0     0x021725C0  data
 */

typedef unsigned short u16;

typedef void (*IdHandler)(u16 id);

extern int func_0216EDFC(u16 id);
extern const IdHandler d_021725C0[][2];

void func_0216EE20(u16 id, int col)
{
    d_021725C0[func_0216EDFC(id)][col](id);
}
