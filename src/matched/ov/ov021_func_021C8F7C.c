/*
 * function: func_021C8F7C
 * address:  0x021C8F7C
 * packet:   pkt_ov021_021C8F7C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-01: EXACT once the own-overlay ov021 hint was dropped from the d_021DABA4
 * symbols line (own-window rule). Old note: the ABS32 to d_021DABA4 was unresolved (the ov021
 * hint is contested: another overlay in the window starts an object at
 * 0x021DABA4, and this function loads no ov021 overlay_id). Needs an
 * independent data witness for 0x021DABA4 in ov021.
 *
 * symbols:
 *   d_021DABA4  0x021DABA4  data  a4
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } V;
typedef struct { u32 a; V v; } T;
extern void func_0216D88C(u32 a, V *v);
extern int func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(u32 a, void *tbl, u32 c, u32 d, void *t, u32 f);
extern u8 d_021DABA4[];
void func_021C8F7C(u32 a, u32 b)
{
    V pos;
    T t;
    func_0216D88C(a, &pos);
    t.a = func_021ABEA0(b, 0xb);
    t.v = pos;
    func_021ABFA8(b, d_021DABA4, 0, 0, &t, 0);
}
